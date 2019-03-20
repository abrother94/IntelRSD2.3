#ifndef PSME_REST_METADATA_DRIVE_HPP
#define PSME_REST_METADATA_DRIVE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Drive_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!---->
<!--################################################################################       -->
<!--# Redfish Schema:  Drive  v1.0.0-->
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
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Storage.xml">
    <edmx:Include Namespace="Storage.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Volume.xml">
    <edmx:Include Namespace="Volume"/>
    <edmx:Include Namespace="Volume.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Chassis.xml">
    <edmx:Include Namespace="Chassis"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Drive">

      <EntityType Name="Drive" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="Drive contains properties describing a single physical disk drive for any system, along with links to associated Volumes."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a disk drive or other physical storage medium for a Redfish implementation."/>
      </EntityType>

      <Action Name="SecureErase" IsBound="true">
        <Parameter Name="Drive" Type="Drive.v1_0_0.Actions"/>
        <Annotation Term="OData.Description" String="This action is used to securely erase the contents of the drive."/>
        <Annotation Term="OData.LongDescription"
                    String="This defines the name of the custom action supported on this resource."/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Drive.v1_0_0">

      <EntityType Name="Drive" BaseType="Drive.Drive">
        <Property Name="StatusIndicator" Type="Drive.v1_0_0.StatusIndicator">
          <Annotation Term="OData.Description"
                      String="The state of the status indicator, used to communicate status information about this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the status indicator state for the status indicator associated with this drive. The valid values for this property are specified through the Redfish.AllowableValues annotation."/>
        </Property>
        <Property Name="IndicatorLED" Type="Resource.v1_1_0.IndicatorLED">
          <Annotation Term="OData.Description" String="The state of the indicator LED, used to identify the drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This value of this property shall contain the indicator light state for the indicator light associated with this drive."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the model number for the drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name by which the manufacturer generally refers to the drive."/>
        </Property>
        <Property Name="Revision" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The revision of this Drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the revision as defined by the manufacturer for the associated drive."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Status of resource"/>
          <Annotation Term="OData.LongDescription"
                      String="Resource status."/>
        </Property>
        <Property Name="CapacityBytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The size in bytes of this Drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the raw size in bytes of the associated drive."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="FailurePredicted" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Is this drive currently predicting a failure in the near future"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain failure information as defined by the manufacturer for the associated drive."/>
        </Property>
        <Property Name="Protocol" Type="Storage.v1_0_0.Protocol">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The protocol this drive is using to communicate to the storage controller"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the protocol the associated drive is using to communicate to the storage controller for this system."/>
        </Property>
        <Property Name="MediaType" Type="Drive.v1_0_0.MediaType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of media contained in this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the type of media contained in the associated drive."/>
        </Property>
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the manufacturer of this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name of the organization responsible for producing the drive. This organization might be the entity from whom the drive is purchased, but this is not necessarily true."/>
        </Property>
        <Property Name="SKU" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the SKU for this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the stock-keeping unit number for this drive."/>
        </Property>
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number for this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a manufacturer-allocated number used to identify the drive."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The part number for this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a part number assigned by the organization that is responsible for producing or manufacturing the drive."/>
        </Property>
        <Property Name="AssetTag" Type="Edm.String">
          <Annotation Term="OData.Description" String="The user assigned asset tag for this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an identifying string used to track the drive for inventory purposes."/>
        </Property>
        <Property Name="Identifiers" Type="Collection(Resource.v1_1_0.Identifier)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Durable names for the drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain a list of all known durable names for the associated drive."/>
        </Property>
        <Property Name="Location" Type="Collection(Resource.v1_1_0.Location)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Location of the drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain location information of the associated drive."/>
        </Property>
        <Property Name="HotspareType" Type="Drive.v1_0_0.HotspareType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of hotspare this drive is currently serving as."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the hot spare type for the associated drive. If the drive is currently serving as a hot spare its Status.State field shall be 'StandbySpare' and 'Enabled' when it is being used as part of a Volume."/>
        </Property>
        <Property Name="EncryptionAbility" Type="Drive.v1_0_0.EncryptionAbility">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The encryption abilities of this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the encryption ability for the associated drive."/>
        </Property>
        <Property Name="EncryptionStatus" Type="Drive.v1_0_0.EncryptionStatus">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The status of the encryption of this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the encrytion status for the associated drive."/>
        </Property>
        <Property Name="RotationSpeedRPM" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The rotation speed of this Drive in Revolutions per Minute (RPM)"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain rotation speed of the associated drive."/>
          <Annotation Term="Measures.Unit" String="RPM"/>
        </Property>
        <Property Name="BlockSizeBytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The size of the smallest addressible unit (Block) of this drive in bytes"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain size of the smallest addressible unit of the associated drive."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
        <Property Name="CapableSpeedGbs" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The speed which this drive can communicate to a storage controller in ideal conditions in Gigabits per second"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain fastest capable bus speed of the associated drive."/>
          <Annotation Term="Measures.Unit" String="Gbit/s"/>
        </Property>
        <Property Name="NegotiatedSpeedGbs" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The speed which this drive is currently communicating to the storage controller in Gigabits per second"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain current bus speed of the associated drive."/>
          <Annotation Term="Measures.Unit" String="Gbit/s"/>
        </Property>
        <Property Name="PredictedMediaLifeLeftPercent" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The percentage of reads and writes that are predicted to still be available for the media"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an indicator of the percentage of life remaining in the Drive's media."/>
        </Property>
        <Property Name="Links" Type="Drive.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Contains references to other resources that are related to this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Links property, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        </Property>
        <Property Name="Actions" Type="Drive.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Actions property shall contain the available actions for this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="Volumes" Type="Collection(Volume.Volume)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the volumes contained in this drive. This will reference Volumes that are either wholly or only partly contained by this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this drive is associated with and shall reference a resource of type Volume. This shall include all Volume resources of which this Drive is a member and all Volumes for which this Drive is acting as a spare if the HotspareType is Dedicated."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="Drive.v1_0_0.OemActions" Nullable="false">
          <Annotation Term="OData.Description"
                      String="Representation of OEM extensions"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent OEM extensions."/>
        </Property>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <EnumType Name="MediaType">
        <Member Name="HDD">
          <Annotation Term="OData.Description" String="Hard Disk Drive"/>
          <Annotation Term="OData.LongDescription" String="Hard Disk Drive"/>
        </Member>
        <Member Name="SSD">
          <Annotation Term="OData.Description" String="The drive media type is solid state or flash memory."/>
          <Annotation Term="OData.LongDescription" String="Solid State Drive"/>
        </Member>
        <Member Name="SMR">
          <Annotation Term="OData.Description" String="The drive media type is shingled magnetic recording."/>
          <Annotation Term="OData.LongDescription" String="Shingled Magnetic Recording"/>
        </Member>
      </EnumType>

      <EnumType Name="HotspareType">
        <Member Name="None">
          <Annotation Term="OData.Description" String="The drive is not currently a hotspare."/>
        </Member>
        <Member Name="Global">
          <Annotation Term="OData.Description"
                      String="The drive is currently serving as a hotspare for all other drives in the storage system"/>
        </Member>
        <Member Name="Chassis">
          <Annotation Term="OData.Description"
                      String="The drive is currently serving as a hotspare for all other drives in the chassis"/>
        </Member>
        <Member Name="Dedicated">
          <Annotation Term="OData.Description"
                      String="The drive is currently serving as a hotspare for a user defined set of drives"/>
        </Member>
      </EnumType>

      <EnumType Name="EncryptionAbility">
        <Member Name="None">
          <Annotation Term="OData.Description" String="The drive is not capable of self encryption."/>
        </Member>
        <Member Name="SelfEncryptingDrive">
          <Annotation Term="OData.Description"
                      String="The drive is capable of self encryption per the Trusted Computing Group's Self Encrypting Drive Standard"/>
        </Member>
        <Member Name="Other">
          <Annotation Term="OData.Description"
                      String="The drive is capable of self encryption through some other means"/>
        </Member>
      </EnumType>

      <EnumType Name="EncryptionStatus">
        <Member Name="Unecrypted">
          <Annotation Term="OData.Description"
                      String="The drive is not currently encrypted. Deprecated: Use Unencrypted"/>
        </Member>
        <Member Name="Unlocked">
          <Annotation Term="OData.Description"
                      String="The drive is currently encrypted but the data is accessible to the user unencrypted"/>
        </Member>
        <Member Name="Locked">
          <Annotation Term="OData.Description"
                      String="The drive is currently encrypted and the data is not accessible to the user, however the system has the ability to unlock the drive automatically"/>
        </Member>
        <Member Name="Foreign">
          <Annotation Term="OData.Description"
                      String="The drive is currently encrypted, the data is not accessible to the user, and the system requires user intervention to expose the data"/>
        </Member>
        <Member Name="Unencrypted">
          <Annotation Term="OData.Description" String="The drive is not currently encrypted."/>
        </Member>
      </EnumType>

      <EnumType Name="StatusIndicator">
        <Member Name="OK">
          <Annotation Term="OData.Description" String="The drive is OK."/>
        </Member>
        <Member Name="Fail">
          <Annotation Term="OData.Description" String="The drive has failed."/>
        </Member>
        <Member Name="Rebuild">
          <Annotation Term="OData.Description" String="The drive is being rebuilt."/>
        </Member>
        <Member Name="PredictiveFailureAnalysis">
          <Annotation Term="OData.Description" String="The drive is still working but predicted to fail soon."/>
        </Member>
        <Member Name="Hotspare">
          <Annotation Term="OData.Description"
                      String="The drive is marked to be automatically rebuilt and used as a replacement for a failed drive."/>
        </Member>
        <Member Name="InACriticalArray">
          <Annotation Term="OData.Description" String="The array that this drive is a part of is degraded."/>
        </Member>
        <Member Name="InAFailedArray">
          <Annotation Term="OData.Description" String="The array that this drive is a part of is failed."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Drive.v1_0_1">
      <Annotation Term="OData.Description" String="This version was created to show the EncryptionStatus enumerated list was updated."/>
      <EntityType Name="Drive" BaseType="Drive.v1_0_0.Drive"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Drive.v1_1_0">
      <EntityType Name="Drive" BaseType="Drive.v1_0_1.Drive"/>
      <ComplexType Name="Links" BaseType="Drive.v1_0_0.Links">
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the endpoints that connect to this drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this drive is associated with and shall reference a resource of type Endpoint."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Drive.v1_1_1">
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="Drive" BaseType="Drive.v1_1_0.Drive"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Drive.v1_1_2">
      <Annotation Term="OData.Description" String="This version was created to fix supported types to remove the Nullable facet on NavigationProperties of type Collection and to use Redfish.Deprecated on certain enum values."/>
      <EntityType Name="Drive" BaseType="Drive.v1_1_1.Drive"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Drive.v1_2_0">
      <EntityType Name="Drive" BaseType="Drive.v1_1_2.Drive"/>
      <ComplexType Name="Links" BaseType="Drive.v1_1_0.Links">
        <NavigationProperty Name="Chassis" Type="Chassis.Chassis" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the Chassis which contains this Drive."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a reference to a resource of type Chassis that represent the physical container associated with this Drive."/>
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


#endif /* PSME_REST_METADATA_DRIVE_HPP */
