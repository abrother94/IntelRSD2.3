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

package com.intel.podm.business.redfish.services;

import com.intel.podm.business.ContextResolvingException;
import com.intel.podm.business.dto.ComputerSystemMetricsDto;
import com.intel.podm.business.dto.redfish.CollectionDto;
import com.intel.podm.business.entities.redfish.ComputerSystem;
import com.intel.podm.business.redfish.EntityTreeTraverser;
import com.intel.podm.business.redfish.services.mappers.EntityToDtoMapper;
import com.intel.podm.business.services.context.Context;
import com.intel.podm.business.services.redfish.ReaderService;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import javax.transaction.Transactional;

import static javax.transaction.Transactional.TxType.REQUIRED;

@RequestScoped
public class ComputerSystemMetricsReaderServiceImpl implements ReaderService<ComputerSystemMetricsDto> {
    @Inject
    private EntityTreeTraverser traverser;

    @Inject
    private EntityToDtoMapper entityToDtoMapper;

    @Override
    public CollectionDto getCollection(Context context) throws ContextResolvingException {
        throw new UnsupportedOperationException("Computer System Metrics is a singleton resource!");
    }

    @Transactional(REQUIRED)
    @Override
    public ComputerSystemMetricsDto getResource(Context context) throws ContextResolvingException {
        ComputerSystem computerSystem = (ComputerSystem) traverser.traverse(context);
        if (computerSystem.getComputerSystemMetrics() == null) {
            throw new ContextResolvingException("Computer System Metrics Resource not found for specified Computer System.", context, null);
        }

        return (ComputerSystemMetricsDto) entityToDtoMapper.map(computerSystem.getComputerSystemMetrics());
    }
}
