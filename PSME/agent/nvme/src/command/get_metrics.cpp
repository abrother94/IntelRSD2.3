/*!
 * @header{License}
 * @copyright Copyright (c) 2017-2018 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @header{Filesystem}
 * @file get_metrics.cpp
 */

#include "nvme_agent_commands.hpp"

using namespace agent::nvme;
using namespace agent_framework;

REGISTER_NVME_COMMAND(GetMetrics,
    [] (GetMetrics::ContextPtr, const GetMetrics::Request& request, GetMetrics::Response& response) {
        log_debug("nvme-agent", "Getting collection of metrics");
        const auto entries = module::get_manager<agent_framework::model::Metric>().get_entries(
            agent_framework::model::utils::is_requested_metric_filter(request)
        );
        response.set_array({entries});
    }
);
