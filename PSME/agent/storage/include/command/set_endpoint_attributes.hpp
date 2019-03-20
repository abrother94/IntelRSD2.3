/*!
 * @brief Declaration of function processing Set Component Attributes command on Endpoint
 *
 * @header{License}
 * @copyright Copyright (c) 2017-2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @header{Files}
 * @file set_endpoint_attributes.hpp
 */

#pragma once



#include "agent-framework/command/storage_commands.hpp"



namespace agent {
namespace storage {

struct ConfigurableEndpointAttributes {
    OptionalField<std::string> username{};
    OptionalField<std::string> password{};
};

static const constexpr char EMPTY_VALUE[] = "";


/*!
 * @brief Implementation of process Endpoint
 * @param[in] uuid the uuid of the Endpoint
 * @param[in] attributes the attributes to be set
 * @param[in] response the response to SetComponentAttributes request
 * */
void process_endpoint_attributes(const Uuid& uuid, const agent_framework::model::attribute::Attributes& attributes,
                                 agent_framework::command::SetComponentAttributes::Response& response);

}
}
