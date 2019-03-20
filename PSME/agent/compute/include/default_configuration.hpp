/*!
 * @brief Application default configuration
 *
 * @header{License}
 * @copyright Copyright (c) 2018 Intel Corporation.
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
 * @file default_configuration.hpp
 */

#pragma once
namespace agent {
namespace generic {

static constexpr const char DEFAULT_CONFIGURATION[] = R"({
    "service" : "compute",
    "agent": {
        "vendor" : "Intel Corporation",
        "capabilities" : [ "Compute" ]
    },
    "server": {
        "port": 7777
    },
    "registration": {
        "ipv4": "localhost",
        "port": 8383,
        "interval": 3
    },
    "managers": [
        {
            "slot" : 1,
            "ipv4": "1.1.2.1",
            "username": "put_username_hash_here",
            "password": "put_password_hash_here",
            "port": 623
        },
        {
            "slot" : 2,
            "ipv4": "1.1.2.2",
            "username": "put_username_hash_here",
            "password": "put_password_hash_here",
            "port": 623
        },
        {
            "slot" : 3,
            "ipv4": "1.1.2.3",
            "username": "put_username_hash_here",
            "password": "put_password_hash_here",
            "port": 623
        },
        {
            "slot" : 4,
            "ipv4": "1.1.2.4",
            "username": "put_username_hash_here",
            "password": "put_password_hash_here",
            "port": 623
        }
    ],
    "cyMux": {
        "ipv4": "127.0.0.1",
        "port": 5623
    },
    "database": {
        "location": "/var/opt/psme/compute"
    },
    "loggers" : [
        {
            "name" : "compute-agent",
            "level" : "INFO",
            "timeformat" : "DATE_NS",
            "color" : true,
            "output" : true,
            "tagging" : true,
            "moredebug" : false,
            "streams" : [
                {
                    "type" : "STDOUT"
                }
            ]
        }
    ]
}
)";

static constexpr char DEFAULT_VALIDATOR_JSON[] = R"({
    "title": "PSME Compute Agent Configuration Schema",
    "description": "Detailed description of the PSME Compute Agent configuration file.",
    "name": "/",
    "type": "object",
    "properties": {
        "service": {
            "description": "Name of DB entry with service UUID.",
            "name": "service",
            "type": "string"
        },
        "agent": {
            "description": "Container for agent specific information.",
            "name": "agent",
            "type": "object",
            "properties": {
                "vendor": {
                    "description": "Information about agent vendor.",
                    "name": "vendor",
                    "type": "string"
                },
                "capabilities": {
                    "description": "Capabilities of the agent (compute, network, chassis, storage or multiple).",
                    "name": "capabilities",
                    "type": "array",
                    "items" : {
                        "type" : "string"
                    }
                }
            },
            "required": [
                "capabilities"
            ]
        },
        "server": {
            "description": "Information for agent about access to REST server.",
            "name": "server",
            "type": "object",
            "properties": {
                "port": {
                    "description": "Port number to register to REST server. Must be the same as configured in PSME REST Server.",
                    "name": "port",
                    "type": "integer"
                }
            },
            "required": [
                "port"
            ]
        },
        "cyMUX" : {
            "description" : "cyMUX connection data.",
            "name" : "cyMUX",
            "type" : "object",
            "properties" : {
                "ipv4" : {
                    "description" : "cyMUX server IP.",
                    "name" : "ipv4",
                    "type" : "string"
                },
                "port" : {
                    "description" : "cyMUX server port.",
                    "name" : "port",
                    "type" : "string"
                }
            }
        },
        "registration": {
            "description": "Registration to server configuration container.",
            "name": "registration",
            "type": "object",
            "properties": {
                "ipv4": {
                    "description": "PSME REST server IP address or hostname.",
                    "name": "ipv4",
                    "type": "string"
                },
                "port": {
                    "description": "PSME REST server registration port number.",
                    "name": "port",
                    "type": "integer"
                },
                "interval": {
                    "description": "Delay between next registration try in seconds.",
                    "name": "interval",
                    "type": "integer"
                }
            },
            "required": [
                "ipv4",
                "port",
                "interval"
            ]
        },
        "managers": {
            "description": "List of all managers. Each entry represents single manager.",
            "name": "managers",
            "type": "array",
            "items": {
                "type": "object",
                "properties": {
                    "ipv4": {
                        "description": "Internal IP address of the module.",
                        "name": "ipv4",
                        "type": "string"
                    },
                    "username": {
                        "description": "Module's BMC username.",
                        "name": "username",
                        "type": "string"
                    },
                    "password": {
                        "description": "Module's BMC password.",
                        "name": "password",
                        "type": "string"
                    },
                    "port": {
                        "description": "Module's BMC port number.",
                        "name": "port",
                        "type": "integer"
                    },
                    "slot": {
                        "description": "Slot number in drawer.",
                        "name": "slot",
                        "type": "integer"
                    }
                },
                "required": [
                    "slot"
                ]
            }
        },
        "loggers": {
            "description": "Logger configuration.",
            "name": "loggers",
            "type": "array",
            "items": {
                "description": "Settings of a specific logger.",
                "type": "object",
                "properties": {
                    "name": {
                        "description": "Set the name of the logger.",
                        "name": "name",
                        "type": "string"
                    },
                    "default": {
                        "description": "Set the logger as default. Only one can be default.",
                        "name": "default",
                        "type": "boolean"
                    },
                    "level": {
                        "description": "Choose severity level compatible with syslog.",
                        "name": "level",
                        "type": "string"
                    },
                    "timeformat": {
                        "description": "Define format used for timestamps in log file.",
                        "name": "timeformat",
                        "type": "string"
                    },
                    "color": {
                        "description": "Enable or disable colors in log file.",
                        "name": "color",
                        "type": "boolean"
                    },
                    "output": {
                        "description": "Turn on, off logging.",
                        "name": "output",
                        "type": "boolean"
                    },
                    "tagging": {
                        "description": "Turn on/turn off tagging in application.",
                        "name": "tagging",
                        "type": "boolean"
                    },
                    "moredebug": {
                        "description": "Enable/disable additional debug info in log file.",
                        "name": "moredebug",
                        "type": "boolean"
                    },
                    "streams": {
                        "description": "Configuration of output methods for logger.",
                        "name": "streams",
                        "type": "array",
                        "items": {
                            "type": "object",
                            "properties": {
                                "type": {
                                    "description": "Choose one of the output methods. Like FILE of STDOUT.",
                                    "name": "type",
                                    "type": "string"
                                },
                                "file": {
                                    "description": "Path to the file, if stream type is set to FILE.",
                                    "name": "file",
                                    "type": "string"
                                }
                            },
                            "required": [
                                "type"
                            ]
                        }
                    }
                }
            }
        }
    },
    "required": [
        "service",
        "agent",
        "server",
        "registration",
        "loggers"
    ]
}
)";

/*! @brief Default environment variable for configuration file */
static constexpr const char DEFAULT_ENV_FILE[] = "AGENT_COMPUTE_CONFIGURATION_FILE";

/*!
 * @brief Default configuration file to load when environment
 * isn't present or valid
 * */
static constexpr const char DEFAULT_FILE[] = "configuration.json";

}
}
