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
    "service" : "storage",
    "agent" : {
        "vendor" : "Intel Corporation",
        "capabilities" : [ "Storage" ]
    },
    "server" : {
        "port" : 7778
    },
    "registration" : {
        "ipv4" : "localhost",
        "port" : 8383,
        "interval" : 3
    },
    "managers" : [
        {
            "storageServices" : [
                {
                    "iscsi" : {
                        "config-path" : "/etc/tgt/conf.d",
                        "portal-interface" : "eth0",
                        "port" : 3260,
                        "username" : "",
                        "password" : "",
                        "initiator" : "psme-storage"
                    }
                }
            ]
        }
    ],
    "tgt-socket": "/var/run/tgtd/socket.0",
    "database": {
        "location": "/var/opt/psme/storage"
    },
    "loggers" : [
        {
            "name" : "storage-agent",
            "level" : "WARNING",
            "timeformat" : "DATE_NS",
            "color" : true,
            "output" : true,
            "tagging" : true,
            "moredebug" : false,
            "streams" : [
                {
                    "type": "STDOUT"
                }
            ]
        }
    ]
}
)";

static constexpr char DEFAULT_VALIDATOR_JSON[] = R"({
    "title": "PSME Storage Agent Configuration Schema",
    "description": "Detailed description of the PSME Storage Agent configuration file.",
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
                "type": {
                    "description": "Type of the agent: storage, compute, network.",
                    "name": "type",
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
                    "description": "Interval between next registration try in seconds.",
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
        "modules": {
            "description": "List of modules. For Storage Agent there should be only one entry in this array.",
            "name": "modules",
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
                        "description": "Module's BMC username. Not used in PSME Storage Agent.",
                        "name": "username",
                        "type": "string"
                    },
                    "password": {
                        "description": "Module's BMC password. Not used in PSME Storage Agent.",
                        "name": "password",
                        "type": "string"
                    },
                    "port": {
                        "description": "Module's BMC port number. Not used in PSME Storage Agent.",
                        "name": "port",
                        "type": "integer"
                    },
                    "submodules": {
                        "description": "Configuration for each submodule. For Storage Agent there should be only one entry in this array.",
                        "name": "submodules",
                        "type": "array",
                        "items": {
                            "type": "object",
                            "properties": {
                                "type": {
                                    "description": "Submodule type: StorageServices",
                                    "name": "type",
                                    "type": "string"
                                },
                                "port": {
                                    "description": "Submodule port number. Not used in PSME Storage Agent.",
                                    "name": "port",
                                    "type": "integer"
                                },
                                "iscsi": {
                                    "description": "iSCSI configuration container.",
                                    "name": "iscsi",
                                    "type": "object",
                                    "properties": {
                                        "config-path": {
                                            "description": "Path within filesystem where tgt configuration files are located.",
                                            "name": "config-path",
                                            "type": "string"
                                        },
                                        "portal-interface": {
                                            "description": "Network interface of iSCSI portal.",
                                            "name": "portal-interface",
                                            "type": "string"
                                        },
                                        "port": {
                                            "description": "Port on which iSCSI portal is listening.",
                                            "name": "port",
                                            "type": "integer"
                                        },

                                        "username": {
                                            "description": "Username used to authentication to iSCSI.",
                                            "name": "username",
                                            "type": "string"
                                        },

                                        "password": {
                                            "description": "Password used to authentication to iSCSI.",
                                            "name": "password",
                                            "type": "string"
                                        },

                                        "initiator": {
                                            "description": "iSCSI initiator name: psme-storage",
                                            "name": "initiator",
                                            "type": "string"
                                        }
                                    },
                                    "required": [
                                        "config-path",
                                        "portal-interface",
                                        "port",
                                        "username",
                                        "password",
                                        "initiator"
                                    ]
                                },
                                "networkInterfaces": {
                                    "description": "List of network interfaces. Should be empty array.",
                                    "name": "networkInterfaces",
                                    "type": "array",
                                    "items": {
                                        "type": "string"
                                    }
                                },
                                "storageControllers": {
                                    "description": "List of storage controllers. For Storage Agent there should be only one entry.",
                                    "name": "storageControllers",
                                    "type": "array",
                                    "items": {
                                        "type": "object",
                                        "properties": {
                                            "status": {
                                                "description": "Storage controller status.",
                                                "name": "status",
                                                "type": "object",
                                                "properties": {

                                                    "state": {
                                                        "description": "Storage controller state: Enabled",
                                                        "name": "state",
                                                        "type": "string"
                                                    },
                                                    "health": {
                                                        "description": "Storage controller health: OK",
                                                        "name": "health",
                                                        "type": "string"
                                                    }
                                                },

                                                "required": [
                                                    "state",
                                                    "health"
                                                ]
                                            },
                                            "interface": {
                                                "description": "Storage controller interface: SATA, SAS, etc.",
                                                "name": "interface",
                                                "type": "string"
                                            },
                                            "fruInfo": {
                                                "description": "FRU information.",
                                                "name": "fruInfo",
                                                "type": "object",
                                                "properties": {
                                                    "serialNumber": {
                                                        "description": "Serial number.",
                                                        "name": "serialNumber",
                                                        "type": "string"
                                                    },
                                                    "manufacturer": {
                                                        "description": "Manufacturer name.",
                                                        "name": "manufacturer",
                                                        "type": "string"
                                                    },
                                                    "modelNumber": {
                                                        "description": "Model number.",
                                                        "name": "modelNumber",
                                                        "type": "string"
                                                    },
                                                    "partNumber": {
                                                        "description": "Part number.",
                                                        "name": "partNumber",
                                                        "type": "string"
                                                    }
                                                },
                                                "required": [
                                                    "serialNumber",
                                                    "manufacturer",
                                                    "modelNumber",
                                                    "partNumber"
                                                ]
                                            },
                                            "driveCount": {
                                                "description": "Number of drives. Will be override on runtime.",
                                                "name": "driveCount",
                                                "type": "integer"
                                            },
                                            "drives": {
                                                "description": "List of drives. Should be empty array, will be override on runtime.",
                                                "name": "drives",
                                                "type": "array",
                                                "items": {
                                                    "type": "string"
                                                }
                                            },

                                            "oem": {
                                                "description": "OEM specific data.",
                                                "name": "oem",
                                                "type": "object",
                                                "properties": {
                                                },
                                                "required": [
                                                ]
                                            }
                                        },
                                        "required": [
                                            "status",
                                            "interface",
                                            "fruInfo",
                                            "driveCount",
                                            "drives",
                                            "oem"
                                        ]
                                    }
                                }
                            },
                            "required": [
                                "type",
                                "port",
                                "iscsi",
                                "networkInterfaces",
                                "storageControllers"
                            ]
                        }
                    }
                },

                "required": [
                    "ipv4",
                    "username",
                    "password",
                    "port",
                    "submodules"
                ]
            }
        },
        "tgt-socket": {
            "description": "Path to tgt socket file.",
            "name": "tgt-socket",
            "type": "string"
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
        "tgt-socket",
        "loggers"
    ]
}
)";

/*! @brief Default environment variable for configuration file */
static constexpr const char DEFAULT_ENV_FILE[] = "AGENT_STORAGE_CONFIGURATION_FILE";

/*!
 * @brief Default configuration file to load when environment
 * isn't present or valid
 * */
static constexpr const char DEFAULT_FILE[] = "configuration.json";

}
}
