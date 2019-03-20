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
    "service" : "rmm",
    "agent": {
        "vendor" : "Intel Corporation",
        "capabilities" : [ "Rmm" ]
    },
    "server": {
        "port": 7791
    },
    "registration": {
        "ipv4": "localhost",
        "port": 8383,
        "interval": 3
    },
    "certificate-files": {
        "podm" : "/etc/psme/certs/ca.crt"
    },
    "managers": [
        {
            "locationOffset": 0,
            "device": "/dev/ttyCm1IPMI"
        },
        {
            "locationOffset": 4,
            "device": "/dev/ttyCm2IPMI"
        }
    ],
    "database": {
        "location": "/var/opt/psme/rmm"
    },
    "loggers" : [
        {
            "name" : "rmm-agent",
            "level" : "DEBUG",
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
    "title": "PSME Rmm Agent Configuration Schema",
    "description": "Detailed description of the PSME Rmm Agent configuration file.",
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
        "certificate-files": {
            "description": "Certificate files paths container.",
            "name": "certificate-files",
            "type": "object",
            "properties": {
                "podm": {
                    "description": "Absolute path to PODM certificate file.",
                    "name": "podm",
                    "type": "string"
                },
                "rmm": {
                    "description": "Absolute path to RMM certificate file.",
                    "name": "rmm",
                    "type": "string"
                }
            },
            "required": [
                "podm",
                "rmm"
            ]
        },
        "managers": {
            "description": "List of all modules. Each entry represents single module.",
            "name": "managers",
            "type": "array",
            "items": {
                "type": "object",
                "properties": {
                    "locationOffset": {
                        "description": "Location offset of the manager",
                        "name": "locationOffset",
                        "type": "integer"
                    },
                    "device": {
                        "description": "Path to the device used for ipmi communication.",
                        "name": "device",
                        "type": "string"
                    }
                },
                "required": [
                    "locationOffset",
                    "device"
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
        "managers",
        "loggers"
    ]
}
)";

/*! @brief Default environment variable for configuration file */
static constexpr const char DEFAULT_ENV_FILE[] = "AGENT_RMM_CONFIGURATION_FILE";

/*!
 * @brief Default configuration file to load when environment
 * isn't present or valid
 * */
static constexpr const char DEFAULT_FILE[] = "configuration.json";

}
}
