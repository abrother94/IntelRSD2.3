#ifndef PSME_REST_METADATA_ETHERNET_SWITCH_STATIC_MAC_HPP
#define PSME_REST_METADATA_ETHERNET_SWITCH_STATIC_MAC_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string EthernetSwitchStaticMAC_XML =
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
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface.xml">
    <edmx:Include Namespace="EthernetInterface.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchStaticMAC">

      <EntityType Name="EthernetSwitchStaticMAC" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="A Ethernet Switch ACL represents Access Control List for switch."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent resources that represent a ethernet switch ACL"/>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchStaticMAC.v1_0_0">

      <EntityType Name="EthernetSwitchStaticMAC" BaseType="EthernetSwitchStaticMAC.EthernetSwitchStaticMAC">
        <Property Name="VLANId" Type="Edm.Int32">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="MACAddress" Type="EthernetInterface.v1_0_0.MACAddress">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
        </Property>
      </EntityType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ETHERNET_SWITCH_STATIC_MAC_HPP */