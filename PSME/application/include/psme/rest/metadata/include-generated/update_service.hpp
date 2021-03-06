#ifndef PSME_REST_METADATA_UPDATE_SERVICE_HPP
#define PSME_REST_METADATA_UPDATE_SERVICE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string UpdateService_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  UpdateService  v1.2.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>


  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="UpdateService">
      <EntityType Name="UpdateService" BaseType="Resource.v1_0_0.Resource">
        <Annotation Term="OData.Description" String="This is the schema definition for the Update Service. It represents the properties for the service itself and has links to collections of firmware and software inventory."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent an Update Service for a Redfish implementation. It represents the properties that affect the service itself."/>
      </EntityType>

      <Action Name="SimpleUpdate" IsBound="true">
        <Annotation Term="OData.Description" String="This action is used to update software components."/>
        <Annotation Term="OData.LongDescription" String="This action shall perform an update of installed software component(s) as contained within a software image file located at a URI referenced by the ImageURI parameter."/>
        <Parameter Name="UpdateService" Type="UpdateService.v1_0_0.Actions"/>
        <Parameter Name="ImageURI" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description" String="The URI of the software image to be installed."/>
          <Annotation Term="OData.LongDescription" String="This parameter shall contain a URI referencing a software image to be retreived by the UpdateService for the purpose of installing software contained within the image."/>
        </Parameter>
        <Parameter Name="TransferProtocol" Type="UpdateService.v1_0_0.TransferProtocolType">
          <Annotation Term="OData.Description" String="The network protocol used by the Update Service to retrieve the software image file located at the URI provided in ImageURI, if the URI does not contain a scheme."/>
          <Annotation Term="OData.LongDescription" String="This parameter shall contain the network protocol that the Update Service shall use to retreive the software image located at the ImageURI.  If this parameter is not provided (or supported), and a transfer protocol is not specified by a scheme contained within ImageURI, the Update Service shall use HTTP to retrieve the image."/>
        </Parameter>
        <Parameter Name="Targets" Type="Collection(Edm.String)">
          <Annotation Term="OData.Description" String="The array of URIs indicating where the update image is to be applied."/>
          <Annotation Term="OData.LongDescription" String="This array property shall contain zero or more URIs indicating where the update image is to be applied."/>
          <!--TODO: why it can't be defined here? <Annotation Term="OData.IsURL"/>-->
        </Parameter>
      </Action>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="UpdateService.v1_0_0">

      <EntityType Name="UpdateService" BaseType="UpdateService.UpdateService">
        <Annotation Term="OData.Description" String="This is the schema definition for the Update Service. It represents the properties for the service itself and has links to collections of firmware and software inventory."/>
        <Annotation Term="OData.LongDescription" String="This resource shall be used to represent an Update Service for a Redfish implementation. It represents the properties that affect the service itself."/>
        <Property Name="Status" Type="Resource.Status"/>
        <Property Name="ServiceEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates whether this service is enabled."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a boolean indicating whether this service is enabled."/>
        </Property>
        <Property Name="Actions" Type="UpdateService.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Description" String="The Actions object contains the available custom actions on this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="UpdateService.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <EnumType Name="TransferProtocolType">
        <Member Name="CIFS">
          <Annotation Term="OData.Description" String="Common Internet File System protocol."/>
        </Member>
        <Member Name="FTP">
          <Annotation Term="OData.Description" String="File Transfer Protocol."/>
        </Member>
        <Member Name="SFTP">
          <Annotation Term="OData.Description" String="Secure File Transfer Protocol."/>
        </Member>
        <Member Name="HTTP">
          <Annotation Term="OData.Description" String="Hypertext Transfer Protocol."/>
        </Member>
        <Member Name="HTTPS">
          <Annotation Term="OData.Description" String="HTTP Secure protocol."/>
        </Member>
        <Member Name="NSF">
          <Annotation Term="OData.Description" String="Network File System protocol."/>
        </Member>
        <Member Name="SCP">
          <Annotation Term="OData.Description" String="Secure File Copy protocol."/>
        </Member>
        <Member Name="TFTP">
          <Annotation Term="OData.Description" String="Trivial File Transfer Protocol."/>
        </Member>
        <Member Name="OEM">
          <Annotation Term="OData.Description" String="A protocol defined by the manufacturer."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="UpdateService.v1_0_1">
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="UpdateService" BaseType="UpdateService.v1_0_0.UpdateService"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="UpdateService.v1_0_2">
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="UpdateService" BaseType="UpdateService.v1_0_1.UpdateService"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="UpdateService.v1_1_0">
      <EntityType Name="UpdateService" BaseType="UpdateService.v1_0_1.UpdateService">
        <Property Name="HttpPushUri" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="The URI used to perform an HTTP or HTTPS push update to the Update Service." />
          <Annotation Term="OData.LongDescription" String="This property shall contain a URI at which the UpdateService supports an HTTP or HTTPS POST of a software image for the purpose of installing software contained within the image." />
          <Annotation Term="OData.IsURL" />
        </Property>
      </EntityType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_UPDATE_SERVICE_HPP */
