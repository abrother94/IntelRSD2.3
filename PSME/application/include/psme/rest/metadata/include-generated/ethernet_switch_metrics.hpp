#ifndef PSME_REST_METADATA_ETHERNET_SWITCH_METRICS_HPP
#define PSME_REST_METADATA_ETHERNET_SWITCH_METRICS_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string EthernetSwitchMetrics_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  EthernetSwitchMetrics  v1.1.0-->
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
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchMetrics">

      <EntityType Name="EthernetSwitchMetrics" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="EthernetSwitchMetrics contains usage and health statistics for a Processor (all Cores) ."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent the Processor Metrics for a single Processor in a Redfish implementation."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
      </EntityType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EthernetSwitchMetrics.v1_0_0">

      <EntityType Name="EthernetSwitchMetrics" BaseType="EthernetSwitchMetrics.EthernetSwitchMetrics">
        <Property Name="Health" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Health of Ethernet Switch as a discrete sensor reading."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Health of EthernetSwitch as a discrete sensor reading."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
      </EntityType>


      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Oem" Type="EthernetSwitchMetrics.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
      </ComplexType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ETHERNET_SWITCH_METRICS_HPP */
