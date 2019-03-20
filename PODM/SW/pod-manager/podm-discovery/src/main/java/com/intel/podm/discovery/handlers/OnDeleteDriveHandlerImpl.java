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

package com.intel.podm.discovery.handlers;

import com.intel.podm.business.entities.handlers.OnDeleteDriveHandler;
import com.intel.podm.business.entities.redfish.ComposedNode;
import com.intel.podm.business.entities.redfish.Drive;
import com.intel.podm.business.entities.redfish.Volume;
import com.intel.podm.discovery.external.finalizers.ComposedNodeDisableService;

import javax.enterprise.context.Dependent;
import javax.inject.Inject;
import javax.transaction.Transactional;

import static javax.transaction.Transactional.TxType.MANDATORY;

@Dependent
@Transactional(MANDATORY)
public class OnDeleteDriveHandlerImpl implements OnDeleteDriveHandler {
    @Inject
    private ComposedNodeDisableService composedNodeDisableService;

    @Override
    public void preRemove(Drive drive) {
        ComposedNode composedNode = drive.getComposedNode();
        if (composedNode != null) {
            composedNodeDisableService.disableComposedNode(composedNode);
        } else {
            Volume volume = drive.getVolume();
            if (isVolumeAttachedToNode(volume)) {
                composedNodeDisableService.disableComposedNode(volume.getComposedNode());
            }
        }
    }

    private boolean isVolumeAttachedToNode(Volume volume) {
        return volume != null && volume.getComposedNode() != null;
    }
}
