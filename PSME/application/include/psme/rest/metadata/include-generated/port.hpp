#ifndef PSME_REST_METADATA_PORT_HPP
#define PSME_REST_METADATA_PORT_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Port_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Port  v1.0.0-->
<!--#                                                                                      -->
<!--# For a detailed change log, see the README file contained in the DSP8010 bundle,      -->
<!--# available at http://www.dmtf.org/standards/redfish                                   -->
<!--# Copyright 2014-2016 Distributed Management Task Force, Inc. (DMTF).                  -->
<!--# For the full DMTF copyright policy, see http://www.dmtf.org/about/policies/copyright -->
<!--################################################################################       -->
<!---->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
    <edmx:Include Namespace="Resource.v1_1_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Storage.xml">
    <edmx:Include Namespace="Storage.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Switch.xml">
    <edmx:Include Namespace="Switch"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Port">

      <EntityType Name="Port" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="Port contains properties describing a port of a switch."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a simple switch port for a Redfish implementation."/>
      </EntityType>

      <Action Name="Reset" IsBound="true">
        <Parameter Name="Port" Type="Port.v1_0_0.Actions"/>
        <Parameter Name="ResetType" Type="Resource.ResetType">
          <Annotation Term="OData.Description" String="The type of reset to be performed."/>
          <Annotation Term="OData.LongDescription" String="This defines the property name for the action."/>
        </Parameter>
        <Annotation Term="OData.Description" String="This action is used to reset this switch."/>
        <Annotation Term="OData.LongDescription"
                    String="This defines the name of the custom action supported on this resource."/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Port.v1_0_0">

      <EntityType Name="Port" BaseType="Port.Port">
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
        <Property Name="PortId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the label of this port on the physical switch package."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name of the switch port as indicated on the outside of the switch."/>
        </Property>
        <Property Name="PortProtocol" Type="Storage.v1_0_0.Protocol">
          <Annotation Term="OData.Description" String="The protocol being sent over this port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the protocol being sent over this port."/>
        </Property>
        <Property Name="PortType" Type="Port.v1_0_0.PortType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the type of this port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the port type for this port."/>
        </Property>
        <Property Name="CurrentSpeedGbps" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The current speed of this port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the speed of this port currently negotiated and running."/>
          <Annotation Term="Measures.Unit" String="Gbit/s"/>
        </Property>
        <Property Name="MaxSpeedGbps" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum speed of this port as currently configured."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the maximum speed of which this port is capable of being configured.  If capable of auto-negotiation, the system shall attempt to negotiate at the maximum speed set."/>
          <Annotation Term="Measures.Unit" String="Gbit/s"/>
        </Property>
        <Property Name="Width" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The number of lanes, phys, or other physical transport links that this port contains."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the number of physical transport links that this port contains."/>
        </Property>
        <Property Name="Links" Type="Port.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
        <Property Name="Actions" Type="Port.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <NavigationProperty Name="AssociatedEndpoints" Type="Collection(Endpoint.Endpoint)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the endpoints that connect to the switch through this port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this port is associated with and shall reference a resource of type Endpoint."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ConnectedSwitches" Type="Collection(Switch.Switch)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the switches that connect to the switch through this port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this port is associated with and shall reference a resource of type Switch."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ConnectedSwitchPorts" Type="Collection(Port.Port)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the ports that connect to the switch through this port."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this port is associated with and shall reference a resource of type Port."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Oem" Type="Port.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
      </ComplexType>

      <EnumType Name="PortType">
        <Member Name="UpstreamPort">
          <Annotation Term="OData.Description" String="This port connects to a host device."/>
        </Member>
        <Member Name="DownstreamPort">
          <Annotation Term="OData.Description" String="This port connects to a target device."/>
        </Member>
        <Member Name="InterswitchPort">
          <Annotation Term="OData.Description" String="This port connects to another switch."/>
        </Member>
        <Member Name="ManagementPort">
          <Annotation Term="OData.Description" String="This port connects to a switch manager."/>
        </Member>
        <Member Name="BidirectionalPort">
          <Annotation Term="OData.Description" String="This port connects to any type of device."/>
        </Member>
        <Member Name="UnconfiguredPort">
          <Annotation Term="OData.Description" String="This port has not yet been configured."/>
        </Member>
      </EnumType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_PORT_HPP */
