#ifndef PSME_REST_METADATA_VIRTUAL_MEDIA_HPP
#define PSME_REST_METADATA_VIRTUAL_MEDIA_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string VirtualMedia_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VirtualMedia">

      <EntityType Name="VirtualMedia" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This resource allows monitoring and control of an instance of virtual media (e.g. a remote CD, DVD, or USB device) functionality provided by a Manager for a system or device."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a virtual media service for a Redfish implementation."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VirtualMedia.v1_0_0">

      <EntityType Name="VirtualMedia" BaseType="VirtualMedia.VirtualMedia">
        <Property Name="ImageName" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The current image name."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name of the image. "/>
        </Property>
        <Property Name="Image" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A URI providing the location of the selected image."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this string shall be an URI.  A null value indicated no image connection."/>
          <Annotation Term="OData.IsURL"/>
        </Property>
        <Property Name="MediaTypes" Type="Collection(VirtualMedia.v1_0_0.MediaType)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the media types supported as virtual media."/>
          <Annotation Term="OData.LongDescription"
                      String="The values of this array shall be the supported media types for this connection."/>
        </Property>
        <Property Name="ConnectedVia" Type="VirtualMedia.v1_0_0.ConnectedVia">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Current virtual media connection methods."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the current connection method from a client to the virtual media represented by this resource.  A value of NotConnected shall indicate no connection is present.  A value of URI shall indicate that a remote connection via a URI reference type is being used. "/>
        </Property>
        <Property Name="Inserted" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Indicates if virtual media is inserted in the virtual device."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be used to indicate if media is present in the virtual media device.  This is usually only applicable to remoting of devices and not for image virtual media usage. "/>
        </Property>
        <Property Name="WriteProtected" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Indicates the media is write protected."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be used to indicate if the remote device media prevents writing to that media. "/>
        </Property>
      </EntityType>

      <!-- These are all supported media types. -->
      <EnumType Name="MediaType">
        <Member Name="CD">
          <Annotation Term="OData.Description" String="A CD-ROM format (ISO) image."/>
        </Member>
        <Member Name="Floppy">
          <Annotation Term="OData.Description" String="A floppy disk image."/>
        </Member>
        <Member Name="USBStick">
          <Annotation Term="OData.Description" String="An emulation of a USB storage device."/>
        </Member>
        <Member Name="DVD">
          <Annotation Term="OData.Description" String="A DVD-ROM format image."/>
        </Member>
      </EnumType>

      <!-- These are all supported types of connection for virtual media. -->
      <EnumType Name="ConnectedVia">
        <Member Name="NotConnected">
          <Annotation Term="OData.Description" String="No current connection."/>
        </Member>
        <Member Name="URI">
          <Annotation Term="OData.Description" String="Connected to a URI location."/>
        </Member>
        <Member Name="Applet">
          <Annotation Term="OData.Description" String="Connected to a client application."/>
        </Member>
        <Member Name="Oem">
          <Annotation Term="OData.Description" String="Connected via an OEM-defined method."/>
        </Member>
      </EnumType>

    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VirtualMedia.v1_0_2">
      <EntityType Name="VirtualMedia" BaseType="VirtualMedia.v1_0_0.VirtualMedia"/>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_VIRTUAL_MEDIA_HPP */
