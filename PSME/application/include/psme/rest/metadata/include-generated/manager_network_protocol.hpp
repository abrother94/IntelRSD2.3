#ifndef PSME_REST_METADATA_MANAGER_NETWORK_PROTOCOL_HPP
#define PSME_REST_METADATA_MANAGER_NETWORK_PROTOCOL_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string ManagerNetworkProtocol_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ManagerNetworkProtocol">

      <EntityType Name="ManagerNetworkProtocol" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This resource is used to obtain or modify the network services managed by a given manager."/>
        <Annotation Term="OData.LongDescription"
                    String="This object shall be used to represent the network service settings for the manager."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ManagerNetworkProtocol.v1_0_0">

      <EntityType Name="ManagerNetworkProtocol" BaseType="ManagerNetworkProtocol.ManagerNetworkProtocol">
        <Property Name="HostName" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The DNS Host Name of this manager, without any domain information"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the host name without any domain information."/>
        </Property>
        <Property Name="FQDN" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is the fully qualified domain name for the manager obtained by DNS including the host name and top-level domain name."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the fully qualified domain name for the manager."/>
        </Property>
        <Property Name="HTTP" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's HTTP protocol support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the HTTP protocol settings for the manager. The default value of the Port property should be 80 for compatibility with established client implementations."/>
        </Property>
        <Property Name="HTTPS" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's HTTPS protocol support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the HTTPS/SSL protocol settings for the manager. The default value of the Port property should be 443 for compatibility with established client implementations."/>
        </Property>
        <Property Name="SNMP" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's SNMP support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the SNMP protocol settings for the manager. The default value of the Port property should be 161 for compatibility with established client implementations."/>
        </Property>
        <Property Name="VirtualMedia" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's Virtual Media support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the Virtual Media protocol settings for the manager. The value of the Port property shall contain the TCP port assigned for virtual media usage."/>
        </Property>
        <Property Name="Telnet" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's Telnet protocol support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the Telnet protocol settings for this manager. The default value of the Port property should be 23 for compatibility with established client implementations."/>
        </Property>
        <Property Name="SSDP" Type="ManagerNetworkProtocol.v1_0_0.SSDProtocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's SSDP support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the Simple Service Discovery Protocol (SSDP) protocol settings for this manager. SSDP is for network discovery of devices supporting the Redfish service. The default value of the Port property should be 1900 for compatibility with established client implementations."/>
        </Property>
        <Property Name="IPMI" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's IPMI-over-LAN protocol support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the IPMI over LAN protocol settings for the manager. The default value of the Port property should be 623 for compatibility with established client implementations."/>
        </Property>
        <Property Name="SSH" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="Settings for this Manager's SSH (Secure Shell) protocol support"/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain information for the SSH protocol settings for the manager. The default value of the Port property should be 22 for compatibility with established client implementations."/>
        </Property>
        <Property Name="KVMIP" Type="ManagerNetworkProtocol.v1_0_0.Protocol" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Settings for this Manager's KVM-IP protocol support."/>
          <Annotation Term="OData.LongDescription"
                      String="This object contains information for the KVM-IP (Keyboard, Video, Mouse) protocol settings for the manager."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Resource status."/>
          <Annotation Term="OData.LongDescription"
                      String="Resource status."/>
        </Property>
      </EntityType>

      <ComplexType Name="Protocol">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="ProtocolEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Indicates if the protocol is enabled or disabled."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the enabled status of the protocol.  The value shall be true if enabled and false if disabled."/>
        </Property>
        <Property Name="Port" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Indicates the protocol port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the port assigned for the protocol."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
      </ComplexType>

      <ComplexType Name="SSDProtocol" BaseType="ManagerNetworkProtocol.v1_0_0.Protocol">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="NotifyMulticastIntervalSeconds" Type="Edm.Int64">
          <Annotation Term="OData.Description"
                      String="Indicates how often the Multicast is done from this service for SSDP."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the time interval, in seconds, between transmissions of the multicast NOTIFY ALIVE message.  A setting of 0 seconds shall disable this functionality.  The recommended value is 600 seconds."/>
          <Annotation Term="Measures.Unit" String="s"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="NotifyTTL" Type="Edm.Int64">
          <Annotation Term="OData.Description"
                      String="Indicates the time to live hop count for SSDPs Notify messages."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the Time-To-Live hop count used for multicast NOTIFY messages.  The recommended value is 2."/>
          <Annotation Term="Validation.Minimum" Int="1"/>
        </Property>
        <Property Name="NotifyIPv6Scope" Type="ManagerNetworkProtocol.v1_0_0.NotifyIPv6Scope">
          <Annotation Term="OData.Description" String="Indicates the scope for the IPv6 Notify messages for SSDP."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the IPv6 scope used for multicast NOTIFY messages.  The valid enumerations are a subset of the available IPv6 Scope types."/>
        </Property>
      </ComplexType>

      <EnumType Name="NotifyIPv6Scope">
        <Member Name="Link">
          <Annotation Term="OData.Description"
                      String="SSDP Notify messages are sent to addresses in the IPv6 Local Link scope"/>
        </Member>
        <Member Name="Site">
          <Annotation Term="OData.Description"
                      String="SSDP Notify messages are sent to addresses in the IPv6 Local Site scope"/>
        </Member>
        <Member Name="Organization">
          <Annotation Term="OData.Description"
                      String="SSDP Notify messages are sent to addresses in the IPv6 Local Organization scope"/>
        </Member>
      </EnumType>

    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ManagerNetworkProtocol.v1_0_2">
      <EntityType Name="ManagerNetworkProtocol" BaseType="ManagerNetworkProtocol.v1_0_0.ManagerNetworkProtocol"/>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_MANAGER_NETWORK_PROTOCOL_HPP */
