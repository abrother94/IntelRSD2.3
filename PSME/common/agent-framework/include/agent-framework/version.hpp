/*!
 * @copyright
 * Copyright (c) 2015-2018 Intel Corporation
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
 *
 * @file version.hpp
 *
 * @brief Declaration of Version class
 * */
#ifndef AGENT_FRAMEWORK_GENERIC_VERSION
#define AGENT_FRAMEWORK_GENERIC_VERSION

#include <string>

namespace agent_framework {
namespace generic {

class Version {
public:
    enum build_type {
        ENG,
        REL,
        MAN
    };

    static constexpr int MAJOR_INDEX = 0;
    static constexpr int MINOR_INDEX = 1;
    static constexpr int BUILD_INDEX = 3;
    static constexpr const char* BUILD_TIME = "01:51:20, 20-03-2019";
    static constexpr const build_type BUILD_TYPE = build_type::MAN;
    static constexpr const char* VERSION_STRING = "2.3.0.288.0";

    static std::string build_info();
};

/*!
 * Returns version string component as integer value.
 *
 * Version string consists of parts separated with period, ex. "2.1.2.123.0"
 * Calling get_version_part("2.1.2.123.0", 3) returns 123 integer value.
 *
 * @param version_string version string.
 * @param index Index of version string component to be converted to integer value (0 indexed).
 * @return Integer representaion of version string part at index position,
 *         zero value if conversion is not possible or invalid index is given.
 */
int get_version_component(const char* version_string, int index);

}
}

#endif /* AGENT_FRAMEWORK_GENERIC_VERSION */
