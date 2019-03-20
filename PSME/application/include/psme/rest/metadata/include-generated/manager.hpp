#ifndef PSME_REST_METADATA_MANAGER_HPP
#define PSME_REST_METADATA_MANAGER_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Manager_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
    <edmx:Include Namespace="Resource.v1_2_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystem.xml">
    <edmx:Include Namespace="ComputerSystem"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Chassis.xml">
    <edmx:Include Namespace="Chassis"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterfaceCollection.xml">
    <edmx:Include Namespace="EthernetInterfaceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ManagerNetworkProtocol.xml">
    <edmx:Include Namespace="ManagerNetworkProtocol"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/LogService.xml">
    <edmx:Include Namespace="LogService"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VirtualMediaCollection.xml">
    <edmx:Include Namespace="VirtualMediaCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/SerialInterfaceCollection.xml">
    <edmx:Include Namespace="SerialInterfaceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Redundancy.xml">
    <edmx:Include Namespace="Redundancy"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/LogServiceCollection.xml">
    <edmx:Include Namespace="LogServiceCollection"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Manager">

      <EntityType Name="Manager" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="In Redfish, a Manager is a systems management entity which may implement or provide access to a Redfish service.  Examples of managers are BMCs, Enclosure Managers, Management Controllers and other subsystems assigned managability functions.  There may be multiple Managers in an implementation, and they may or may not be directly accessible via a Redfish-defined interface."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a management subsystem for a Redfish implementation."/>
      </EntityType>

      <Action Name="Reset" IsBound="true">
        <Parameter Name="Manager" Type="Manager.v1_0_0.Actions"/>
        <Parameter Name="ResetType" Type="Resource.ResetType">
          <Annotation Term="OData.Description" String="This is the type of reset to be performed."/>
          <Annotation Term="OData.LongDescription" String="This defines the property name for the action."/>
        </Parameter>
        <Annotation Term="OData.Description" String="The reset action resets/reboots the manager."/>
        <Annotation Term="OData.LongDescription"
                    String="This defines the name of the custom action supported when used in conjunction with a POST operation to this resource. When issued, this operation will perform a reset of the manager."/>
      </Action>

      <Action Name="ForceFailover" IsBound="true">
        <Annotation Term="OData.Description"
                    String="The ForceFailover action forces a failover of this manager to the manager used in the parameter"/>
        <Annotation Term="OData.LongDescription"
                    String="This defines the name of the custom action supported when used in conjunction with a POST operation to this resource. When issued, this operation will perform a forced failover of the manager's redundancy to the manager supplied as a parameter."/>
        <Parameter Name="Manager" Type="Manager.v1_0_0.Actions"/>
        <Parameter Name="NewManager" Type="Manager.Manager" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This Parameter specifies the Manager to fail over to.  In this case, a valid reference is supported."/>
        </Parameter>
      </Action>

      <Action Name="ModifyRedundancySet" IsBound="true">
        <Annotation Term="OData.Description"
                    String="The ModifyRedundancySet operation is used to add or remove members to a redundant group of manager."/>
        <Annotation Term="OData.LongDescription"
                    String="This defines the name of the custom action for which the following properties are supported on this resource.  The ModifyRedundancySet operation shall be used to add or remove members to a redundant group of manager."/>
        <Parameter Name="Manager" Type="Manager.v1_0_0.Actions"/>
        <Parameter Name="Add" Type="Collection(Manager.Manager)" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This array defines the Managers to add to the redundancy set.  In this case, a valid reference is supported."/>
        </Parameter>
        <Parameter Name="Remove" Type="Collection(Manager.Manager)" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This array defines the Managers to remove from the redundancy set.  In this case, a valid reference is supported."/>
        </Parameter>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Manager.v1_0_0">

      <EntityType Name="Manager" BaseType="Manager.Manager">
        <Annotation Term="OData.Description"
                    String="This is the schema definition for a Manager.  Examples of managers are BMCs, Enclosure Managers, Management Controllers and other subsystems assigned managability functions."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a management subsystem for a Redfish implementation."/>
        <Property Name="ManagerType" Type="Manager.v1_0_0.ManagerType" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property represents the type of manager that this resource represents."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall describe the function of the manager. The value EnclosureManager shall be used if the manager controls one or more services through aggregation. The value BMC shall be used if the manager represents a traditional server management controller. The value ManagementController shall be used if none of the other enumerations apply."/>
        </Property>
        <Property Name="Links" Type="Manager.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), the resource."/>
        </Property>
        <NavigationProperty Name="EthernetInterfaces" Type="EthernetInterfaceCollection.EthernetInterfaceCollection"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is a reference to a collection of NICs that this manager uses for network communication.  It is here that clients will find NIC configuration options and settings."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type EthernetInterfaceCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="SerialInterfaces" Type="SerialInterfaceCollection.SerialInterfaceCollection"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is a reference to a collection of serial interfaces that this manager uses for serial and console communication. It is here that clients will find serial configuration options and settings."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type SerialInterfaceCollection, which are for the use of the manager."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="NetworkProtocol" Type="ManagerNetworkProtocol.ManagerNetworkProtocol"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is a reference to the network services and their settings that the manager controls. It is here that clients will find network configuration options as well as network services."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain a reference to a resource of type ManagerNetworkProtocol, which represents the network services for the manager."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="LogServices" Type="LogServiceCollection.LogServiceCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is a reference to a collection of Logs used by the manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain a reference to a collection of type LogServiceCollection, which are for the use of the manager."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="VirtualMedia" Type="VirtualMediaCollection.VirtualMediaCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is a reference to the Virtual Media services for this particular manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain a reference to a collection of type VirtualMediaCollection, which is for the use of the manager."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="ServiceEntryPointUUID" Type="Resource.UUID" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The UUID of the Redfish Service provided by this manager."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the UUID of the Redfish Service provided by the manager. Each Manager providing an entry point to the same Redfish Service shall report the same UUID value (even though the name of the property may imply otherwise). This property shall not be present if the manager does not provide a Redfish Service entry point."/>
        </Property>
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Universal Unique Identifier (UUID) for this Manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the universal unique identifier number for the manager."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The model information of this Manager as defined by the manufacturer"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the information about how the manufacturer references the manager."/>
        </Property>
        <Property Name="DateTime" Type="Edm.DateTimeOffset">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The current DateTime (with offset) for the manager, used to set or read time."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall represent the current DateTime value for the manager, with offset from UTC, in Redfish Timestamp format."/>
        </Property>
        <Property Name="DateTimeLocalOffset" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The time offset from UTC the DateTime property is set to in format: +06:00 ."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall represent the offset from UTC time that the current value of DataTime property contains."/>
          <Annotation Term="Validation.Pattern" String="([-+][0-1][0-9]:[0-5][0-9])"/>
        </Property>
        <Property Name="FirmwareVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The firmware version of this Manager."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the firmware version as defined by the manufacturer for the associated manager."/>
        </Property>
        <Property Name="SerialConsole" Type="Manager.v1_0_0.SerialConsole" Nullable="false">
          <Annotation Term="OData.Description"
                      String="Information about the Serial Console service provided by this manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain information about the Serial Console service of the manager."/>
        </Property>
        <Property Name="CommandShell" Type="Manager.v1_0_0.CommandShell" Nullable="false">
          <Annotation Term="OData.Description"
                      String="Information about the Command Shell service provided by this manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain information about the Command Shell service of the manager."/>
        </Property>
        <Property Name="GraphicalConsole" Type="Manager.v1_0_0.GraphicalConsole" Nullable="false">
          <Annotation Term="OData.Description"
                      String="The value of this property shall contain the information about the Graphical Console (KVM-IP) service of this manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the information about the Graphical Console (KVM-IP) service of the manager."/>
        </Property>
        <Property Name="Actions" Type="Manager.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Actions property shall contain the available actions for the resource."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Resource status."/>
          <Annotation Term="OData.LongDescription"
                      String="Resource status."/>
        </Property>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Redundancy information for the managers of this system."/>
          <Annotation Term="OData.LongDescription" String="The value of the property shall contain redundancy information for the managers of the system."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Oem" Type="Manager.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
      </ComplexType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <NavigationProperty Name="ManagerForServers" Type="Collection(ComputerSystem.ComputerSystem)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property is an array of references to the systems that this manager has control over."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an array of references to ComputerSystem resources of which this Manager instance has control."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ManagerForChassis" Type="Collection(Chassis.Chassis)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property is an array of references to the chassis that this manager has control over."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an array of references to Chassis resources of which this Manager instance has control."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <!-- This type defines the type of manager that given resource represents. -->
      <EnumType Name="ManagerType">
        <Member Name="ManagementController">
          <Annotation Term="OData.Description"
                      String="A controller used primarily to monitor or manage the operation of a device or system"/>
        </Member>
        <Member Name="EnclosureManager">
          <Annotation Term="OData.Description"
                      String="A controller which provides management functions for a chassis or group of devices or systems"/>
        </Member>
        <Member Name="BMC">
          <Annotation Term="OData.Description"
                      String="A controller which provides management functions for a single computer system"/>
        </Member>
        <Member Name="RackManager">
          <Annotation Term="OData.Description"
                      String="A controller which provides management functions for a whole or part of a rack"/>
        </Member>
        <Member Name="AuxiliaryController">
          <Annotation Term="OData.Description"
                      String="A controller which provides management functions for a particular subsystem or group of devices"/>
        </Member>
      </EnumType>

      <ComplexType Name="ManagerService" Abstract="true">
        <Annotation Term="OData.Description"
                    String="Used for describing services like Serial Console, Command Shell or Graphical Console"/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="ServiceEnabled" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Description" String="Indicates if the service is enabled for this manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the enabled status of the protocol used for the service.  The value shall be true if enabled and false if disabled."/>
        </Property>
        <Property Name="MaxConcurrentSessions" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Indicates the maximum number of service sessions, regardless of protocol, this manager is able to support."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the maximum number of concurrent service sessions supported by the implementation."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
      </ComplexType>

      <!-- This schema defines Serial Console connection types allowed by the implementation. -->
      <EnumType Name="SerialConnectTypesSupported">
        <Member Name="SSH">
          <Annotation Term="OData.Description"
                      String="The controller supports a Serial Console connection using the SSH protocol"/>
        </Member>
        <Member Name="Telnet">
          <Annotation Term="OData.Description"
                      String="The controller supports a Serial Console connection using the Telnet protocol"/>
        </Member>
        <Member Name="IPMI">
          <Annotation Term="OData.Description"
                      String="The controller supports a Serial Console connection using the IPMI Serial-over-LAN (SOL) protocol"/>
        </Member>
        <Member Name="Oem">
          <Annotation Term="OData.Description"
                      String="The controller supports a Serial Console connection using an OEM-specific protocol"/>
        </Member>
      </EnumType>

      <!-- Need other enumerations because enumeration descriptions differ by type -->
      <EnumType Name="CommandConnectTypesSupported">
        <Member Name="SSH">
          <Annotation Term="OData.Description"
                      String="The controller supports a Command Shell connection using the SSH protocol"/>
        </Member>
        <Member Name="Telnet">
          <Annotation Term="OData.Description"
                      String="The controller supports a Command Shell connection using the SSH protocol"/>
        </Member>
        <Member Name="IPMI">
          <Annotation Term="OData.Description"
                      String="The controller supports a Command Shell connection using the SSH protocol"/>
        </Member>
        <Member Name="Oem">
          <Annotation Term="OData.Description"
                      String="The controller supports a Command Shell connection using an OEM-specific protocol"/>
        </Member>
      </EnumType>

      <EnumType Name="GraphicalConnectTypesSupported">
        <Member Name="KVMIP">
          <Annotation Term="OData.Description"
                      String="The controller supports a Graphical Console connection using a KVM-IP (redirection of Keyboard, Video, Mouse over IP) protocol"/>
        </Member>
        <Member Name="Oem">
          <Annotation Term="OData.Description"
                      String="The controller supports a Graphical Console connection using an OEM-specific protocol"/>
        </Member>
      </EnumType>

      <!-- This type contains information about the Serial Console service of a given manager. -->
      <ComplexType Name="SerialConsole" BaseType="Manager.v1_0_0.ManagerService">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="ConnectTypesSupported" Type="Collection(Manager.v1_0_0.SerialConnectTypesSupported)"
                  Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This object is used to enumerate the Serial Console connection types allowed by the implementation."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of ConnectTypesSupported shall be an array of the enumerations provided here.  SSH shall be included if the Secure Shell (SSH) protocol is supported.  Telnet shall be included if the Telnet protocol is supported.  IPMI shall be included if the IPMI (Serial-over-LAN) protocol is supported."/>
        </Property>
      </ComplexType>

      <!-- This type contains information about the Command Shell service of a given manager. -->
      <ComplexType Name="CommandShell" BaseType="Manager.v1_0_0.ManagerService">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="ConnectTypesSupported" Type="Collection(Manager.v1_0_0.CommandConnectTypesSupported)"
                  Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This object is used to enumerate the Command Shell connection types allowed by the implementation."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of ConnectTypesSupported shall be an array of the enumerations provided here.  SSH shall be included if the Secure Shell (SSH) protocol is supported.  Telnet shall be included if the Telnet protocol is supported.  IPMI shall be included if the IPMI (Serial-over-LAN) protocol is supported."/>
        </Property>
      </ComplexType>

      <!-- This type contains information about the Graphical Console (KVM-IP) service of a given manager. -->
      <ComplexType Name="GraphicalConsole" BaseType="Manager.v1_0_0.ManagerService">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="ConnectTypesSupported" Type="Collection(Manager.v1_0_0.GraphicalConnectTypesSupported)"
                  Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This object is used to enumerate the Graphical Console connection types allowed by the implementation."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of ConnectTypesSupported shall be an array of the enumerations provided here.  RDP shall be included if the Remote Desktop (RDP) protocol is supported.  KVMIP shall be included if a vendor-define KVM-IP protocol is supported."/>
        </Property>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Manager.v1_0_1">
      <EntityType Name="Manager" BaseType="Manager.v1_0_0.Manager"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Manager.v1_0_2">
      <EntityType Name="Manager" BaseType="Manager.v1_0_1.Manager"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Manager.v1_1_0">
      <EntityType Name="Manager" BaseType="Manager.v1_0_2.Manager"/>
      <ComplexType Name="Links" BaseType="Manager.v1_0_0.Links">
        <NavigationProperty Name="ManagerInChassis" Type="Chassis.Chassis" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property is a reference to the chassis that this manager is located in."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain a reference to the chassis that this manager is located in."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Manager.v1_2_0">
      <EntityType Name="Manager" BaseType="Manager.v1_1_0.Manager">
        <Property Name="PowerState" Type="Resource.v1_2_0.PowerState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the current power state of the manager."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the power state of the manager."/>
        </Property>
      </EntityType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_MANAGER_HPP */
