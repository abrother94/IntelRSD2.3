/*
 * Copyright (c) 2016-2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.podm.business.redfish.services;

import com.intel.podm.business.BusinessApiException;
import com.intel.podm.business.ResourceStateMismatchException;
import com.intel.podm.business.entities.redfish.Chassis;
import com.intel.podm.business.entities.redfish.ExternalLink;
import com.intel.podm.business.entities.redfish.ExternalService;
import com.intel.podm.business.redfish.EntityTreeTraverser;
import com.intel.podm.business.services.context.Context;
import com.intel.podm.business.services.redfish.UpdateService;
import com.intel.podm.common.synchronization.TaskCoordinator;
import com.intel.podm.common.synchronization.ThrowingRunnable;
import com.intel.podm.common.types.redfish.RedfishChassis;
import com.intel.podm.config.base.Config;
import com.intel.podm.config.base.Holder;
import com.intel.podm.config.base.dto.ServiceConfig;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import javax.transaction.Transactional;
import java.util.Set;
import java.util.UUID;
import java.util.concurrent.TimeoutException;

import static com.intel.podm.common.types.ChassisType.POD;
import static com.intel.podm.common.types.ChassisType.RACK;
import static java.util.Arrays.asList;
import static java.util.stream.Collectors.toSet;
import static javax.transaction.Transactional.TxType.REQUIRED;

@RequestScoped
@SuppressWarnings("checkstyle:ClassFanOutComplexity")
public class ChassisUpdateServiceImpl implements UpdateService<RedfishChassis> {
    @Inject
    private ChassisActionsService updateService;

    @Inject
    private TaskCoordinator taskCoordinator;

    @Inject
    private EntityTreeTraverser traverser;

    @Inject
    @Config
    private Holder<ServiceConfig> config;

    @Override
    @Transactional(REQUIRED)
    public void perform(Context target, RedfishChassis representation) throws TimeoutException, BusinessApiException {
        Chassis targetChassis = (Chassis) traverser.traverse(target);

        if (representation.getLocationId() != null) {
            checkIfLocationIdCanBePatchedOnChassis(targetChassis);
        }

        if (representation.getGeoTag() != null) {
            checkIfGeoTagCanBePatchedOnChassis(targetChassis);
        }

        Set<UUID> affectedServices = targetChassis.getExternalLinks().stream()
            .map(ExternalLink::getExternalService)
            .map(ExternalService::getUuid)
            .collect(toSet());

        if (affectedServices.isEmpty()) {
            performForPodm(target, representation);
        } else {
            performForExternalServices(affectedServices, target, representation);
        }
    }

    private void performForExternalServices(Set<UUID> externalServices, Context chassis, RedfishChassis representation)
        throws TimeoutException, BusinessApiException {
        for (UUID externalService : externalServices) {
            taskCoordinator.run(externalService, () -> updateService.updateChassisOnSingleExternalService(externalService, chassis, representation));
        }
    }

    @SuppressWarnings("unchecked")
    private void performForPodm(Context target, RedfishChassis representation) throws TimeoutException {
        taskCoordinator.run(config.get().getUuid(), (ThrowingRunnable) () -> updateService.updateLocalChassis(target, representation));
    }

    private void checkIfLocationIdCanBePatchedOnChassis(Chassis targetChassis) throws BusinessApiException {
        if (!(targetChassis.is(POD) || targetChassis.is(RACK))) {
            throw new ResourceStateMismatchException("Oem.Intel_RackScale.Location.Id is PATCHable only for Chassis of type: " + asList(POD, RACK));
        }

        if (targetChassis.is(RACK) && targetChassis.getExternalLinks().isEmpty()) {
            throw new ResourceStateMismatchException(
                "Oem.Intel_RackScale.Location.Id is PATCHable only for Chassis of type Rack which are not created by PodM"
            );
        }
    }

    private void checkIfGeoTagCanBePatchedOnChassis(Chassis targetChassis) throws ResourceStateMismatchException {
        if (!targetChassis.is(RACK)) {
            throw new ResourceStateMismatchException("Oem.Intel_RackScale.GeoTag is PATCHable only for Chassis of type: " + RACK);
        }
    }
}
