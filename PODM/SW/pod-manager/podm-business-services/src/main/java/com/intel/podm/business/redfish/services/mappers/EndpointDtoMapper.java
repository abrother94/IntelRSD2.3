/*
 * Copyright (c) 2017-2018 Intel Corporation
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

package com.intel.podm.business.redfish.services.mappers;

import com.intel.podm.business.dto.EndpointDto;
import com.intel.podm.business.dto.EndpointDto.IpTransportDetailsDto;
import com.intel.podm.business.dto.RedundancyDto;
import com.intel.podm.business.entities.dao.ComputerSystemDao;
import com.intel.podm.business.entities.redfish.Endpoint;
import com.intel.podm.business.entities.redfish.IpTransportDetails;
import com.intel.podm.business.entities.redfish.Port;
import com.intel.podm.business.entities.redfish.Redundancy;
import com.intel.podm.business.entities.redfish.base.ConnectedEntity;
import com.intel.podm.business.redfish.Contexts;
import com.intel.podm.business.services.context.Context;
import com.intel.podm.common.types.EntityRole;
import com.intel.podm.mappers.BrilliantMapper;

import javax.enterprise.context.Dependent;
import javax.inject.Inject;
import java.util.Collection;
import java.util.Objects;

import static com.intel.podm.business.redfish.ContextCollections.asEthernetInterfaceContexts;
import static com.intel.podm.business.redfish.ContextCollections.asPortContexts;
import static com.intel.podm.business.redfish.ContextCollections.asZoneContexts;
import static com.intel.podm.business.redfish.Contexts.toContext;
import static java.util.Collections.singleton;

@Dependent
@SuppressWarnings({"checkstyle:ClassFanOutComplexity"})
class EndpointDtoMapper extends DtoMapper<Endpoint, EndpointDto> {
    @Inject
    private ConnectedEntityDtoMapper connectedEntityDtoMapper;

    @Inject
    private RedundancyDtoMapper redundancyDtoMapper;

    @Inject
    private IpTransportDetailsDtoMapper transportDtoMapper;

    @Inject
    private ComputerSystemDao computerSystemDao;

    EndpointDtoMapper() {
        super(Endpoint.class, EndpointDto.class);
        this.ignoredProperties("redundancies", "transports", "connectedEntities", "actions", "links", "oem");
    }

    @Override
    protected void performNotAutomatedMapping(Endpoint source, EndpointDto target) {
        super.performNotAutomatedMapping(source, target);

        mapConnectedEntities(source, target);
        mapRedundancies(source, target);
        mapTransports(source, target);
        mapAuthentication(source, target);
        target.getLinks().getPorts().addAll(asPortContexts(source.getPorts()));
        EndpointDto.Links.Oem.RackScaleOem rackScaleOem = target.getLinks().getOem().getRackScaleOem();
        rackScaleOem.setZones(asZoneContexts(singleton(source.getZone())));
        rackScaleOem.getInterfaces().addAll(asEthernetInterfaceContexts(source.getEthernetInterfaces()));
    }

    private void mapConnectedEntities(Endpoint source, EndpointDto target) {
        for (ConnectedEntity connectedEntity : source.getConnectedEntities()) {
            EndpointDto.ConnectedEntityDto dto = new EndpointDto.ConnectedEntityDto();
            connectedEntityDtoMapper.ignoredProperties("entityLink");
            connectedEntityDtoMapper.map(connectedEntity, dto);
            mapEntityLink(connectedEntity, dto);
            target.getConnectedEntities().add(dto);
        }
    }

    private void mapEntityLink(ConnectedEntity connectedEntity, EndpointDto.ConnectedEntityDto dto) {
        if (connectedEntity.getEntityLink() != null) {
            dto.setEntityLink(toContext(connectedEntity.getEntityLink()));
        } else {
            if (isInitiator(connectedEntity)) {
                dto.setEntityLink(getAttachedComputerSystemContext(connectedEntity));
            }
        }
    }

    private boolean isInitiator(ConnectedEntity connectedEntity) {
        return connectedEntity.getEntityRole() == EntityRole.INITIATOR;
    }

    private Context getAttachedComputerSystemContext(ConnectedEntity connectedEntity) {
        return connectedEntity.getEndpoint().getPorts().stream()
            .map(Port::getPcieConnectionIds)
            .flatMap(Collection::stream)
            .map(connectionId -> computerSystemDao.tryGetUniqueComputerSystemByPcieConnectionId(connectionId))
            .filter(Objects::nonNull)
            .map(Contexts::toContext)
            .findFirst()
            .orElse(null);
    }

    private void mapRedundancies(Endpoint source, EndpointDto target) {
        for (Redundancy redundancy : source.getRedundancies()) {
            RedundancyDto dto = new RedundancyDto();
            redundancyDtoMapper.map(redundancy, dto);
            target.getRedundancies().add(dto);
        }
    }

    private void mapTransports(Endpoint source, EndpointDto target) {
        for (IpTransportDetails transport : source.getIpTransportsDetails()) {
            IpTransportDetailsDto dto = new IpTransportDetailsDto();
            transportDtoMapper.map(transport, dto);
            target.getIpTransportDetails().add(dto);
        }
    }

    private void mapAuthentication(Endpoint source, EndpointDto target) {
        if (source.getAuthentication() != null) {
            target.getOem().getRackScaleOem().getAuthentication().setUsername(source.getAuthentication().getUsername());
            target.getOem().getRackScaleOem().getAuthentication().setPassword(source.getAuthentication().getPassword());
        }
    }

    @Dependent
    public static class ConnectedEntityDtoMapper extends BrilliantMapper<ConnectedEntity, EndpointDto.ConnectedEntityDto> {
        protected ConnectedEntityDtoMapper() {
            super(ConnectedEntity.class, EndpointDto.ConnectedEntityDto.class);
        }
    }
}
