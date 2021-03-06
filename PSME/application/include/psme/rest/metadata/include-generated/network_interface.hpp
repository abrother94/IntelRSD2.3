#ifndef PSME_REST_METADATA_NETWORK_INTERFACE_HPP
#define PSME_REST_METADATA_NETWORK_INTERFACE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string NetworkInterface_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  NetworkInterface  v1.0.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkDeviceFunctionCollection.xml">
    <edmx:Include Namespace="NetworkDeviceFunctionCollection"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkInterface">

      <EntityType Name="NetworkInterface" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="A NetworkInterface contains references linking NetworkDeviceFunction resources and represents the functionality available to the containing system."/>
        <Annotation Term="OData.LongDescription" String="A NetworkInterface contains references linking NetworkDeviceFunction resources and represents the functionality available to the containing system."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="NetworkInterface.v1_0_0">

      <EntityType Name="NetworkInterface" BaseType="NetworkInterface.NetworkInterface">
        <Annotation Term="OData.Description" String="A NetworkInterface contains references linking  NetworkDeviceFunction resources and represents the functionality available to the containing system."/>
        <Annotation Term="OData.LongDescription" String="A NetworkInterface contains references linking NetworkDeviceFunction resources and represents the functionality available to the containing system."/>
        <Property Name="Status" Type="Resource.Status"/>
        <Property Name="Links" Type="NetworkInterface.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Description" String="Links."/>
          <Annotation Term="OData.LongDescription" String="Links for this controller."/>
        </Property>
        <NavigationProperty Name="NetworkDeviceFunctions" Type="NetworkDeviceFunctionCollection.NetworkDeviceFunctionCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains the members of this collection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
      </ComplexType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_NETWORK_INTERFACE_HPP */
