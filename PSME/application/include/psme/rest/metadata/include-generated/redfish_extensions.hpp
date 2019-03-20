#ifndef PSME_REST_METADATA_REDFISH_EXTENSIONS_HPP
#define PSME_REST_METADATA_REDFISH_EXTENSIONS_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string RedfishExtensions_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Settings.xml">
    <edmx:Include Namespace="Settings"/>
  </edmx:Reference>

  <edmx:DataServices>

    <!--These terms extend the schema language for Redfish-specific information-->
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="RedfishExtensions.v1_0_0">

      <Term Name="AllowableValues" Type="Collection(Edm.String)" Nullable="false">
        <Annotation Term="OData.Description" String="The set of allowable values for a parameter."/>
      </Term>
      <Term Name="Required" Type="Edm.Boolean" DefaultValue="true">
        <Annotation Term="OData.Description"
                    String="The term specifies that a property is required to be supported by services. Properties not annotated as required are optional."/>
      </Term>
      <Term Name="RequiredOnCreate" Type="Edm.Boolean" DefaultValue="true">
        <Annotation Term="OData.Description"
                    String="The term specifies that a property is required to be specified in the body of a POST request to create the resource."/>
      </Term>
      <Term Name="Settings" Type="Settings.Settings">
        <Annotation Term="OData.Description"
                    String="Reference to the resource that represents the settings to be applied to this object."/>
      </Term>
      <Term Name="AutoExpandReferences" Type="Edm.Boolean" DefaultValue="true">
        <Annotation Term="OData.Description"
                    String="The term can be applied to a navigation property in order to specify that the default behavior for the service is to expand the references for the related resource or collection of resources in responses."/>
      </Term>
      <Term Name="AutoExpand" Type="Edm.Boolean" DefaultValue="true">
        <Annotation Term="OData.Description"
                    String="The term can be applied to a navigation property in order to specify that the default behavior for the service is to expand the related resource or collection of resources in responses."/>
      </Term>
      <Term Name="IPv6Format" Type="Edm.Boolean" DefaultValue="true">
        <Annotation Term="OData.Description"
                    String="The term can be applied to a property or parameter in order to specify that IPv6 addressing rules apply to that property or parameter."/>
      </Term>
      <Term Name="Copyright" Type="Edm.String">
        <Annotation Term="OData.Description"
                    String="The term is applied to Redfish payload samples in order to specify copyright information. It would not generally be used in production payloads."/>
      </Term>
      <Term Name="Deprecated" Type="Edm.String">
        <Annotation Term="OData.Description"
                    String="The term shall be applied to a property in order to specify that the property is deprecated.  The value of the string should explain the deprecation, including new property or properties to be used. The property can be supported in new and existing implementations, but usage in new implementations is discouraged.  Deprecated properties are likely to be removed in a future major version of the schema."/>
      </Term>
      <Term Name="ActionInfo" Type="Edm.String">
        <Annotation Term="OData.Description"
                    String="The term can be applied to an Action to specify a URI to an ActionInfo resource which describes the parameters supported by this instance of the Action."/>
        <Annotation Term="OData.IsURL"/>
      </Term>
      <Term Name="DynamicPropertyPatterns" Type="Collection(RedfishExtensions.v1_0_0.PropertyPattern)"
            Nullable="false"/>

      <ComplexType Name="PropertyPattern">
        <Property Name="Pattern" Type="Edm.String">
          <Annotation Term="OData.Description" String="The pattern that the property name shall match."/>
        </Property>
        <Property Name="Type" Type="Edm.String">
          <Annotation Term="OData.Description" String="The type that the name shall have."/>
        </Property>
      </ComplexType>

      <Term Name="Enumeration" Type="Collection(RedfishExtensions.v1_0_0.EnumerationMember)" Nullable="false">
        <Annotation Term="OData.Description"
                    String="The term enumerates the allowable set of legacy, non-standard string values where a standard enumeration cannot be used.  This annotation should not be used for any new values."/>
      </Term>

      <ComplexType Name="EnumerationMember">
        <Property Name="Member" Type="Edm.String">
          <Annotation Term="OData.Description" String="An allowable string member."/>
        </Property>
      </ComplexType>

    </Schema>

    <!--These terms are used for validating a property value-->
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Validation.v1_0_0">

      <Term Name="Pattern" Type="Edm.String">
        <Annotation Term="OData.Description" String="The pattern that a string property or parameter must match."/>
      </Term>
      <Term Name="Minimum" Type="Edm.Int64">
        <Annotation Term="OData.Description" String="Minimum value that an integer property or parameter can have."/>
      </Term>
      <Term Name="Maximum" Type="Edm.Int64">
        <Annotation Term="OData.Description" String="Maximum value that an integer property or parameter can have."/>
      </Term>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>

)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_REDFISH_EXTENSIONS_HPP */