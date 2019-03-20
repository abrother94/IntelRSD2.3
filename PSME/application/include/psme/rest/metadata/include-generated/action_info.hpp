#ifndef PSME_REST_METADATA_ACTION_INFO_HPP
#define PSME_REST_METADATA_ACTION_INFO_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string ActionInfo_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  ActionInfo  v1.0.2-->
<!--#                                                                                      -->
<!--# For a detailed change log, see the README file contained in the DSP8010 bundle,      -->
<!--# available at http://www.dmtf.org/standards/redfish                                   -->
<!--# Copyright 2014-2017 Distributed Management Task Force, Inc. (DMTF).                  -->
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

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ActionInfo">

      <EntityType Name="ActionInfo" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="ActionInfo describes the parameters and other information necessary to perform a Redfish Action to a particular Action target.  As parameter support may differ between implementations and even among instances of a resource, this data can be used to ensure Action requests from applications contain supported parameters."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent information about the supported parameters for an Action within a Redfish implementation."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ActionInfo.v1_0_0">

      <EntityType Name="ActionInfo" BaseType="ActionInfo.ActionInfo">
        <Property Name="Parameters" Type="Collection(ActionInfo.v1_0_0.Parameters)" Nullable="false">
          <Annotation Term="OData.Description" String="The parameters associated with the specified Redfish Action."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain a list of parameters associated with a Redfish Action associated with this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Parameters">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="A parameter associated with the specified Redfish Action."/>
        <Annotation Term="OData.LongDescription" String="This property shall contain information about a specific parameter associated with a Redfish Action associated with this resource."/>
        <Property Name="Name" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"  String="The name of the parameter for this Action."/>
          <Annotation Term="OData.LongDescription" String="This property shall contain the name of the parameter used by the associated Redfish Action."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Required" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Indicates whether the parameter is required to perform this Action."/>
          <Annotation Term="OData.LongDescription" String="This property shall return true if the parameter is required to be present to perform the associated Action, and shall be false if the parameter is not required (optional) to perform the associated Action."/>
        </Property>
        <Property Name="DataType" Type="ActionInfo.v1_0_0.ParameterTypes">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The JSON property type used for this parameter."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the JSON property type of the parameter."/>
        </Property>
        <Property Name="ObjectDataType" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The OData Type of an object-based parameter."/>
          <Annotation Term="OData.LongDescription" String="This property shall describe the entity type definition (in @odata.type format) for the parameter.  This property shall be required for parameters with a DataType of Object or ObjectArray, and shall not be present for parameters with other DataType(s)."/>
        </Property>
        <Property Name="AllowableValues" Type="Collection(Edm.String)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A list of values for this parameter supported by this Action target."/>
          <Annotation Term="OData.LongDescription" String="This property shall indicate the allowable values for this parameter as applied to this Action target."/>
        </Property>
      </ComplexType>

      <EnumType Name="ParameterTypes">
        <Member Name="Boolean">
          <Annotation Term="OData.Description" String="A boolean (true or false)."/>
        </Member>
        <Member Name="Number">
          <Annotation Term="OData.Description" String="A number."/>
        </Member>
        <Member Name="NumberArray">
          <Annotation Term="OData.Description" String="An array of numbers."/>
        </Member>
        <Member Name="String">
          <Annotation Term="OData.Description" String="A string."/>
        </Member>
        <Member Name="StringArray">
          <Annotation Term="OData.Description" String="An array of strings."/>
        </Member>
        <Member Name="Object">
          <Annotation Term="OData.Description" String="An embedded JSON object."/>
        </Member>
        <Member Name="ObjectArray">
          <Annotation Term="OData.Description" String="An array of JSON objects."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ActionInfo.v1_0_1">
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity."/>
      <EntityType Name="ActionInfo" BaseType="ActionInfo.v1_0_0.ActionInfo"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ActionInfo.v1_0_2">
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ActionInfo" BaseType="ActionInfo.v1_0_1.ActionInfo"/>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ACTION_INFO_HPP */