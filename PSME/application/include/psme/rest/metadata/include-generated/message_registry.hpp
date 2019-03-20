#ifndef PSME_REST_METADATA_MESSAGE_REGISTRY_HPP
#define PSME_REST_METADATA_MESSAGE_REGISTRY_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string MessageRegistry_XML =
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

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry">

      <EntityType Name="MessageRegistry" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This is the schema definition for all Message Registries.  It represents the properties for the registries themselves.  The MessageId is formed per the Redfish specification.  It consists of the RegistryPrefix concatenated with the version concatenated with the unique identifier for the message registry entry."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a message registry for a Redfish implementation."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_0">

      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.MessageRegistry">
        <Property Name="Language" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the RFC 5646 compliant language code for the registry."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a string consisting of an RFC 5646 language code"/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="RegistryPrefix" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is the single word prefix used to form a messageID structure."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the prefix used in messageIDs which uniquely identifies all of the messages in this registry as belonging to this registry."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="RegistryVersion" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is the message registry version which is used in the middle portion of a messageID."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the version of this message registry.   The format of this string shall be of the format majorversion.minorversion.errata in compliance with Protocol Version section of the Redfish specification"/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="OwningEntity" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is the organization or company that publishes this registry."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a string that represents the publisher of this registry."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Messages" Type="MessageRegistry.v1_0_0.MessageProperty" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The pattern property indicates that a free-form string is the unique identifier for the message within the registry."/>
          <Annotation Term="OData.LongDescription"
                      String="The pattern property shall represent the suffix to be used in the MessageId and shall be unique within this message registry."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
      </EntityType>

      <ComplexType Name="MessageProperty" OpenType="true">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="Redfish.DynamicPropertyPatterns">
          <Collection>
            <Record>
              <PropertyValue Property="Pattern" String="[A-Za-z0-9]+"/>
              <PropertyValue Property="Type" String="MessageRegistry.v1_0_0.Message"/>
            </Record>
          </Collection>
        </Annotation>
      </ComplexType>

      <ComplexType Name="Message">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Description" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is a short description of how and when this message is to be used."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate how and when this message is returned by the Redfish service."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Message" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The actual message."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the message to be displayed.  If a %integer is included in part of the string, it shall be used to represent a string substitution for any MessageArgs accompanying the message, in order."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Severity" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the severity of the message."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the severity of the condition resulting in the message, as defined in the Status section of the Redfish specification."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="NumberOfArgs" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The number of arguments to be expected to be passed in as MessageArgs for this message."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the number of MessageArgs that are expected to be substituted in the Message in the locations within the Message marked by %&lt;integer&gt;."/>
          <Annotation Term="Redfish.Required"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="ParamTypes" Type="Collection(MessageRegistry.v1_0_0.ParamType)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The MessageArg types, in order, for the message."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an ordered array of parameter types which match the types of the MessageArgs, in order."/>
        </Property>
        <Property Name="Resolution" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Used to provide suggestions on how to resolve the situation that caused the error."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an override of the Resolution of the message in message registry, if present."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription"
                      String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
      </ComplexType>

      <EnumType Name="ParamType">
        <Member Name="string"/>
        <Member Name="number"/>
      </EnumType>

    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="MessageRegistry.v1_0_2">
      <EntityType Name="MessageRegistry" BaseType="MessageRegistry.v1_0_0.MessageRegistry"/>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_MESSAGE_REGISTRY_HPP */
