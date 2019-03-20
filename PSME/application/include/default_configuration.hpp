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
namespace psme {
namespace app {

static constexpr const char DEFAULT_CONFIGURATION[] = R"({
    "service" : "rest-server",
    "server": {
        "network-interface-name" : ["enp0s20f0.4094"],
        "connectors" : [
            {
                "use-ssl" : true,
                "certs-directory" : "/etc/psme/certs",
                "port": 8443,
                "thread-mode" : "select",
                "client-cert-required" : true
            },
            {
                "use-ssl" : false,
                "port": 8888,
                "redirect-port" : 8443,
                "thread-mode" : "select",
                "thread-pool-size" : 1
            }
        ]
    },
    "event-service" : {
        "delivery-retry-attempts" : 3,
        "delivery-retry-interval-seconds" : 60
    },
    "ssdp-service" : {
        "enabled" : true,
        "announce-interval-seconds" : 0,
        "ttl" : 2
    },
    "rmm-present" : true,
    "registration": {
        "port": 8383,
        "minDelay": 3
    },
    "eventing" : {
        "address": "localhost",
        "port" : 5567,
        "poll-interval-sec" : 20
    },
    "rest" : {
        "service-root-name" : "PSME Service Root"
    },
    "database": {
        "location": "/var/opt/psme",
        "retention-interval-sec": 600,
        "retention-outdated-sec": 2419200
    },
    "loggers" : [
        {
            "name" : "app",
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
    "title": "PSME Rest Server",
    "description": "Detailed JSON schema documentation used for PSME REST server configuration file. Configuration file is pure JSON format.",
    "name": "/",
    "type": "object",
    "properties": {
        "service": {
            "description": "Name of DB entry with service UUID.",
            "name": "service",
            "type": "string"
        },
        "server": {
            "description": "Information about REST server communication. Port numbers, addresses.",
            "name": "server",
            "type": "object",
            "properties": {
                "network-interface-name": {
                    "description": "List of network interface names used to send and receive packets.",
                    "name": "network-interface-name",
                    "type": "array",
                    "items" : {
                        "type": "string"
                    }
                },
                "connectors": {
                    "description": "Connectors server listens on",
                    "name": "connectors",
                    "type": "array",
                    "items": [
                        {
                            "type": "object",
                            "properties": {
                                "use-ssl": {
                                    "description": "Indicates if connection should be over ssl",
                                    "name": "use-ssl",
                                    "type": "boolean"
                                },
                                "certs-directory": {
                                    "description": "Path to directory containing files for ssl connector.",
                                    "name": "certs-directory",
                                    "type": "string"
                                },
                                "port": {
                                    "description": "Port on which connector listens on",
                                    "name": "port",
                                    "type": "integer"
                                },
                                "redirect-port": {
                                    "description": "In case of http connector traffic may be redirected to secured connection when accessing secured resources",
                                    "name": "redirect-port",
                                    "type": "integer"
                                },
                                "thread-mode": {
                                    "description": "Enumeration of available threading modes of connector",
                                    "name": "thread-mode",
                                    "type": "string",
                                    "enum": [
                                        "select",
                                        "thread-per-connection"
                                    ]
                                },
                                "thread-pool-size": {
                                    "description": "Thread pool size used by connector in SELECT thread-mode. THREAD_PER_CONNECTION does not use this property.",
                                    "name": "thrad-pool-size",
                                    "type": "integer"
                                },
                                "client-cert-required": {
                                    "description": "Client is required to send certificate when connecting",
                                    "name": "client-cert-required",
                                    "type": "boolean"
                                }
                            }
                        }
                    ],
                    "required": [
                        "network-interface-name",
                        "connectors"
                    ]
                }
            },
            "event-service": {
                "description": "Configuration of EventService.",
                "name": "event-service",
                "type": "object",
                "properties": {
                    "delivery-retry-attempts": {
                        "description": "This is the number of attempts an event posting is retried before the subscription is terminated.",
                        "name": "delivery-retry-attempts",
                        "type": "integer"
                    },
                    "delivery-retry-interval-seconds": {
                        "description": "This represents the number of seconds between retry attempts for sending any given Event.",
                        "name": "delivery-retry-interval-seconds",
                        "type": "integer"
                    }
                },
                "required": [
                    "delivery-retry-attempts",
                    "delivery-retry-interval-seconds"
                ]
            },
            "task-service": {
                "description": "Configuration of Task service.",
                "name": "task-service",
                "type": "object",
                "properties": {
                    "enabled": {
                        "description": "Specifies if Task service should be enabled.",
                        "name": "enabled",
                        "type": "boolean"
                    }
                }
            },
            "ssdp-service": {
                "description": "Configuration of SSDP service.",
                "name": "ssdp-service",
                "type": "object",
                "properties": {
                    "enabled": {
                        "description": "Specifies if SSDP service should be enabled.",
                        "name": "enabled",
                        "type": "boolean"
                    },
                    "announce-interval-seconds": {
                        "description": "This represents the number of seconds between announcement notifications. Zero value means no notifications will be send.",
                        "name": "announce-interval-seconds",
                        "type": "integer"
                    },
                    "ttl": {
                        "description": "This represents time to live value of notifying multicast sockets.",
                        "name": "ttl",
                        "type": "integer"
                    }
                },
                "required": [
                    "enabled"
                ]
            },
            "rmm-present": {
                "description": "Indicates RMM dependency.",
                "name": "rmm-present",
                "type": "boolean"
            },
            "registration": {
                "description": "Configuration for the agent registration process.",
                "name": "registration",
                "type": "object",
                "properties": {
                    "port": {
                        "description": "Port number used by agents to register.",
                        "name": "port",
                        "type": "integer"
                    },
                    "minDelay": {
                        "description": "Minimum delay between heart-beat checks.",
                        "name": "minDelay",
                        "type": "integer"
                    }
                },
                "required": [
                    "port",
                    "minDelay"
                ]
            },
            "eventing": {
                "description": "Eventing feature configuration.",
                "name": "eventing",
                "type": "object",
                "properties": {
                    "address": {
                        "description": "URL of the listening address used for eventing.",
                        "name": "address",
                        "type": "string"
                    },
                    "port": {
                        "description": "Listen port number used for eventing.",
                        "name": "port",
                        "type": "integer"
                    },
                    "poll-interval-sec": {
                        "description": "Delay between polling tries. Busy waiting interval.",
                        "name": "poll-interval-sec",
                        "type": "integer"
                    }
                },
                "required": [
                    "enabled",
                    "address",
                    "port",
                    "poll-interval-sec"
                ]
            },
            "rest": {
                "description": "REST specific configuration.",
                "name": "rest",
                "type": "object",
                "properties": {
                    "service-root-name": {
                        "description": "Value of Name property on ServiceRoot resource",
                        "name": "service-root-name",
                        "type": "string"
                    }
                },
                "required": [
                    "service-root-name"
                ]
            },
            "metadata-file": {
                "description": "Path to metadata file.",
                "name": "metadata-file",
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
        }
    },
    "required": [
        "service",
        "server",
        "rmm-present",
        "registration",
        "eventing",
        "loggers"
    ]
}
)";

/*! @brief Default environment variable for configuration file */
static constexpr const char DEFAULT_ENV_FILE[] = "CORE_CONFIGURATION_FILE";

/*!
 * @brief Default configuration file to load when environment
 * isn't present or valid
 * */
static constexpr const char DEFAULT_FILE[] = "configuration.json";

}
}
