/*!
 * @copyright
 * Copyright (c) 2017-2018 Intel Corporation
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
 * */

#include "psme/rest/endpoints/storage/drive_collection.hpp"
#include "psme/rest/constants/constants.hpp"



using namespace psme::rest::endpoint;
using namespace psme::rest::constants;
using namespace agent_framework::module;

namespace {
json::Value make_prototype() {
    json::Value r(json::Value::Type::OBJECT);

    r[Common::ODATA_CONTEXT] = "/redfish/v1/$metadata#DriveCollection.DriveCollection";
    r[Common::ODATA_ID] = json::Value::Type::NIL;
    r[Common::ODATA_TYPE] = "#DriveCollection.DriveCollection";
    r[Common::NAME] = "Drives Collection";
    r[Common::DESCRIPTION] = "Collection of Drives";
    r[Collection::ODATA_COUNT] = json::Value::Type::NIL;
    r[Collection::MEMBERS] = json::Value::Type::ARRAY;

    return r;
}
}


DriveCollection::DriveCollection(const std::string& path) : EndpointBase(path) {}


DriveCollection::~DriveCollection() {}


void DriveCollection::get(const server::Request& req, server::Response& res) {
    auto json = ::make_prototype();

    json[Common::ODATA_ID] = PathBuilder(req).build();

    auto storage_service_uuid =
        psme::rest::model::Find<agent_framework::model::StorageService>(req.params[PathParam::SERVICE_ID]).get_uuid();

    const auto& drives_uuids =
        get_m2m_manager<agent_framework::model::StorageService, agent_framework::model::Drive>()
            .get_children(storage_service_uuid);

    json[Collection::ODATA_COUNT] = static_cast<std::uint32_t>(drives_uuids.size());
    for (const auto& uuid : drives_uuids) {
        json::Value link(json::Value::Type::OBJECT);
        link[Common::ODATA_ID] = utils::get_component_url(agent_framework::model::enums::Component::Drive, uuid);
        json[Collection::MEMBERS].push_back(std::move(link));
    }

    set_response(res, json);
}
