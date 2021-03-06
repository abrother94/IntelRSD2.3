#ifndef PSME_REST_METADATA_MESSAGE_HPP
#define PSME_REST_METADATA_MESSAGE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Message_XML =
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

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Message">

      <Term Name="ExtendedInfo" Type="Collection(Message.Message)" Nullable="false">
        <Annotation Term="OData.Description"
                    String="The ExtendedInfo annotation can be applied to any object or property to provide additional information about the item."/>
      </Term>

      <ComplexType Name="Message">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Message.v1_0_0">

      <ComplexType Name="Message" BaseType="Message.Message">
        <Property Name="MessageId" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This is the key for this message which can be used to look up the message in a message registry."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall be a key into message registry as described in the Redfish specification."/>
          <Annotation Term="Redfish.Required"/>
        </Property>
        <Property Name="Message" Type="Edm.String">
          <Annotation Term="OData.Description" String="This is the human readable message, if provided."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an optional human readable message."/>
        </Property>
        <Property Name="RelatedProperties" Type="Collection(Edm.String)" Nullable="false">
          <Annotation Term="OData.Description" String="This is an array of properties described by the message."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an array of JSON Pointers indicating the properties described by the message, if appropriate for the message."/>
        </Property>
        <Property Name="MessageArgs" Type="Collection(Edm.String)" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This array of message arguments are substituted for the arguments in the message when looked up in the message registry."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the message substitution arguments for the specific message referenced by the MessageId and shall only be included if the MessageId is present."/>
        </Property>
        <Property Name="Severity" Type="Edm.String">
          <Annotation Term="OData.Description" String="This is the severity of the errors."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the severity of the error, as defined in the Status section of the Redfish specificaiton."/>
        </Property>
        <Property Name="Resolution" Type="Edm.String">
          <Annotation Term="OData.Description"
                      String="Used to provide suggestions on how to resolve the situation that caused the error."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an override of the Resolution of the message in message registry, if present."/>
        </Property>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false">
          <Annotation Term="OData.Description" String="Oem extension object."/>
          <Annotation Term="OData.LongDescription"
                      String="This object represents the Oem property.  All values for resources described by this schema shall comply to the requirements as described in the Redfish specification."/>
        </Property>
      </ComplexType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_MESSAGE_HPP */
