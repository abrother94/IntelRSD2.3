/*!
 * @section LICENSE
 *
 * @copyright
 * Copyright (c) 2016-2018 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @section DESCRIPTION
 */

#include "agent-framework/module/managers/generic_manager_registry.hpp"


namespace agent_framework {
namespace module {

GenericManagerRegistry::~GenericManagerRegistry() { }

void GenericManagerRegistry::for_each_table(GenericManagerRegistry::TableClientFunc func) {
    for (auto& table : tables) {
        if (!func(table)) {
            break;
        }
    }
}

}
}
