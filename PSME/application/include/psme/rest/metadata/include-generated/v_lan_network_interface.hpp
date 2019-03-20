#ifndef PSME_REST_METADATA_V_LAN_NETWORK_INTERFACE_HPP
#define PSME_REST_METADATA_V_LAN_NETWORK_INTERFACE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string VLanNetworkInterface_XML =
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
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/IntelRackScaleExtensions.xml">
    <edmx:Include Namespace="IntelRackScale.Extensions" Alias="IntelRackScale"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface">

      <EntityType Name="VLanNetworkInterface" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This resource contains information for a Virtual LAN (VLAN) network instance available on a manager, system or other device."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_0">

      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.VLanNetworkInterface">
        <Property Name="VLANEnable" Type="Edm.Boolean">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Description" String="This indicates if this VLAN is enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be used to indicate if this VLAN is enabled for this interface."/>
        </Property>
        <Property Name="VLANId" Type="VLanNetworkInterface.v1_0_0.VLANId">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="IntelRackScale.Nontrivial"
                      String="Ability to write this property value is implementation specific."/>
          <Annotation Term="OData.Description" String="This indicates the VLAN identifier for this VLAN."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be used to indicate the VLAN identifier for this VLAN."/>
        </Property>
      </EntityType>

      <ComplexType Name="VLAN">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="VLANEnable" Type="Edm.Boolean">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Description" String="This indicates if this VLAN is enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be used to indicate if this VLAN is enabled for this interface."/>
        </Property>
        <Property Name="VLANId" Type="VLanNetworkInterface.v1_0_0.VLANId">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Description" String="This indicates the VLAN identifier for this VLAN."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be used to indicate the VLAN identifier for this VLAN."/>
        </Property>
      </ComplexType>

      <TypeDefinition Name="VLANId" UnderlyingType="Edm.Int64">
        <Annotation Term="Validation.Minimum" Int="0"/>
        <Annotation Term="Validation.Maximum" Int="4094"/>
      </TypeDefinition>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_1">

      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_0.VLanNetworkInterface"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VLanNetworkInterface.v1_0_2">
      <EntityType Name="VLanNetworkInterface" BaseType="VLanNetworkInterface.v1_0_1.VLanNetworkInterface"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_V_LAN_NETWORK_INTERFACE_HPP */
