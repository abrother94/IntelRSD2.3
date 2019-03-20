/*
 * Copyright (c) 2015-2018 Intel Corporation
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

package com.intel.podm.discovery.external.event;

import com.intel.podm.business.entities.redfish.ExternalService;
import com.intel.podm.client.events.EventServiceDefinition;
import com.intel.podm.common.types.ServiceType;
import com.intel.podm.config.base.Config;
import com.intel.podm.config.base.Holder;
import com.intel.podm.config.base.dto.EventsConfig;
import com.intel.podm.config.base.dto.EventsConfig.EventConfiguration;
import com.intel.podm.config.base.dto.ServiceConfig;
import com.intel.podm.config.base.dto.ServiceConnectionConfig;
import com.intel.podm.discovery.external.ExternalServiceRepository;

import javax.annotation.PostConstruct;
import javax.enterprise.context.ApplicationScoped;
import javax.inject.Inject;
import javax.transaction.Transactional;
import java.net.URI;
import java.util.UUID;

import static javax.transaction.Transactional.TxType.REQUIRES_NEW;
import static javax.ws.rs.core.UriBuilder.fromUri;

@ApplicationScoped
class EventServiceDefinitionFactory {
    @Inject
    @Config
    private Holder<EventsConfig> eventsConfig;

    @Inject
    @Config
    private Holder<ServiceConfig> serviceConfig;

    @Inject
    @Config
    private Holder<ServiceConnectionConfig> connectionConfig;

    @Inject
    private ExternalServiceRepository repository;

    private UUID podManagerServiceUuid;

    @PostConstruct
    public void initialize() {
        podManagerServiceUuid = serviceConfig.get().getUuid();
    }

    @Transactional(REQUIRES_NEW)
    EventServiceDefinition create(UUID serviceUuid) {
        ExternalService service = repository.find(serviceUuid);
        URI podManagerEventServiceUri = buildPodManagerEventServiceUri(service.getServiceType(), service.getUuid());
        return new EventServiceDefinition(podManagerEventServiceUri, service.getBaseUri(), podManagerServiceUuid);
    }

    private URI buildPodManagerEventServiceUri(ServiceType serviceType, UUID serviceUuid) {
        EventsConfig config = this.eventsConfig.get();
        EventConfiguration serviceTypeEventConfig = config.getEventConfigForServiceType(serviceType);
        boolean sslEnabled = connectionConfig.get().getConnectionSecurity().isSslEnabledForServicesOfType(serviceType);
        URI baseEndpoint = sslEnabled ? serviceTypeEventConfig.getSecurePodManagerEventReceivingEndpoint()
            : serviceTypeEventConfig.getDefaultPodManagerEventReceivingEndpoint();

        return fromUri(baseEndpoint).path("/" + serviceUuid).build();
    }
}
