#ifndef PSME_REST_METADATA_ZONE_HPP
#define PSME_REST_METADATA_ZONE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Zone_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Zone  v1.0.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Switch.xml">
    <edmx:Include Namespace="Switch"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Zone">

      <EntityType Name="Zone" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="Switch contains properties describing a simple fabric zone."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a simple zone for a Redfish implementation."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Zone.v1_0_0">

      <EntityType Name="Zone" BaseType="Zone.Zone">
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Description"
                      String="Resource status."/>
          <Annotation Term="OData.LongDescription"
                      String="Resource status."/>
        </Property>
        <Property Name="Links" Type="Zone.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the endpoints that are contained in this zone."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a reference to the resources that the zone is associated with and shall reference a resource of type Endpoint."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="InvolvedSwitches" Type="Collection(Switch.Switch)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the switchs that are utilized in this zone."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a reference to the resources that the zone is associated with and shall reference a resource of type Switch."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ZONE_HPP */
