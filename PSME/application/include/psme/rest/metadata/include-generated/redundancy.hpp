#ifndef PSME_REST_METADATA_REDUNDANCY_HPP
#define PSME_REST_METADATA_REDUNDANCY_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Redundancy_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
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
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy">

      <EntityType Name="Redundancy" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Annotation Term="OData.Description"
                    String="This is the common redundancy definition and structure used in other Redfish schemas."/>
        <Annotation Term="OData.LongDescription"
                    String="This object represents the Redundancy element property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification.  The value of this string shall be of the format for the reserved word *Redundancy*"/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_0">

      <EntityType Name="Redundancy" BaseType="Redundancy.Redundancy">
        <Annotation Term="OData.Description"
                    String="This is the redundancy definition to be used in other resource schemas."/>
        <Annotation Term="OData.LongDescription"
                    String="This object represents the Redundancy element property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification.  The value of this string shall be of the format for the reserved word *Redundancy*"/>
        <Property Name="Name" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The name of the resource or array element."/>
          <Annotation Term="OData.LongDescription"
                      String="This object represents the Name property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification. The value of this string shall be of the format for the reserved word *Name*."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Mode" Type="Redundancy.v1_0_0.RedundancyMode">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the redundancy mode of the group."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the information about the redundancy mode of this manager.  Failover shall indicate a master/slave type arrangement where status indicates the role of this manager.  N+1 indicates an arrangement where the redundancy set needs MaxNumSupported-1 number of resources in order to be redundant.  Load Balanced indicates all members are active. However, there functionality is not independent of each other. Their functioning is determined by some sort of load balancing algorithm. Sparing is implied (i.e. each member can be a spare for the other(s). Sparing indicates that all members are active and are aware of each others. However, their functionality is independent until failover. Each member can be a spare for the other(s). Limited Sparing indicates that all members are active, and they may or may not be aware of each and they are not spares for each other."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="MaxNumSupported" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is the maximum number of members allowable for this particular redundancy group."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the maximum number of members allowed in the redundancy group."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="MinNumNeeded" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is the minumum number of members needed for this group to be redundant."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the minimum number of members allowed in the redundancy group for the current redundancy mode to still be fault tolerant."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="Redfish.Required"/>
        </Property>
        <NavigationProperty Name="RedundancySet" Type="Collection(Resource.Item)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Contains any ids that represent components of this redundancy set."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the ids of components that are part of this redundancy set. The id values may or may not be dereferenceable."/>
          <Annotation Term="OData.AutoExpandReferences"/>
          <Annotation Term="Redfish.Required"/>
        </NavigationProperty>
      </EntityType>

      <TypeDefinition Name="RedundancyMode" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="Failover"/>
              <Annotation Term="OData.Description"
                          String="Failure of one unit will automatically cause its functions to be taken over by a standby or offline unit in the redundancy set"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="N+m"/>
              <Annotation Term="OData.Description"
                          String="Multiple units are available and active such that normal operation will continue if one or more units fail"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Sharing"/>
              <Annotation Term="OData.Description"
                          String="Multiple units contribute or share such that operation will continue, but at a reduced capacity, if one or more units fail"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="Sparing"/>
              <Annotation Term="OData.Description"
                          String="One or more spare units are available to take over the function of a failed unit, but takeover is not automatic"/>
            </Record>
          </Collection>
        </Annotation>
      </TypeDefinition>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_1">
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_0.Redundancy"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_0_2">
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_1.Redundancy"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Redundancy.v1_1_0">
      <EntityType Name="Redundancy" BaseType="Redundancy.v1_0_2.Redundancy">
        <Property Name="RedundancyEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="This indicates whether redundancy is enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a boolean indicating whether the redundancy is enabled."/>
        </Property>
      </EntityType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_REDUNDANCY_HPP */
