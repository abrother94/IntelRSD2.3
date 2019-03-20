#ifndef PSME_REST_METADATA_P_CIE_FUNCTION_HPP
#define PSME_REST_METADATA_P_CIE_FUNCTION_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string PCIeFunction_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface.xml">
    <edmx:Include Namespace="EthernetInterface"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Drive.xml">
    <edmx:Include Namespace="Drive"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Storage.xml">
    <edmx:Include Namespace="Storage.v1_0_0"/>
  </edmx:Reference>
  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction">

      <EntityType Name="PCIeFunction" BaseType="Resource.v1_0_0.Resource">
        <Annotation Term="OData.Description"
                    String="This is the schema definition for the PCIeFunction resource.  It represents the properties of a PCIeFunction attached to a System."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PCIeFunction.v1_0_0">

      <EntityType Name="PCIeFunction" BaseType="PCIeFunction.PCIeFunction">
        <Annotation Term="OData.Description"
                    String="This is the schema definition for the PCIeFunction resource.  It represents the properties of a PCIeFunction attached to a System."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>


        <Property Name="FunctionId" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The the PCIe Function identifier."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall the PCIe device function number within a given PCIe device."/>
        </Property>
        <Property Name="FunctionType" Type="PCIeFunction.v1_0_0.FunctionType" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of the PCIe Function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the function type of the PCIe device function such as Physical or Virtual."/>
        </Property>
        <Property Name="DeviceClass" Type="PCIeFunction.v1_0_0.DeviceClass" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The class for this PCIe Function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the device class of the PCIe device function such as Storage, Network, Memory etc."/>
        </Property>
        <Property Name="DeviceId" Type="Edm.String">
          <Annotation Term="OData.Description" String="The Device ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the PCI Device ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="VendorId" Type="Edm.String">
          <Annotation Term="OData.Description" String="The Vendor ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the PCI Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="ClassCode" Type="Edm.String">
          <Annotation Term="OData.Description" String="The Class Code of this PCIe function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the PCI Class Code of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){3}$"/>
        </Property>
        <Property Name="RevisionId" Type="Edm.String">
          <Annotation Term="OData.Description" String="The Revision ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the PCI Revision ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){1}$"/>
        </Property>
        <Property Name="SubsystemId" Type="Edm.String">
          <Annotation Term="OData.Description" String="The Subsystem ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the PCI Subsystem ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="SubsystemVendorId" Type="Edm.String">
          <Annotation Term="OData.Description" String="The Subsystem Vendor ID of this PCIe function."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the PCI Subsystem Vendor ID of the PCIe device function."/>
          <Annotation Term="Validation.Pattern" String="^0[xX](([a-fA-F]|[0-9]){2}){2}$"/>
        </Property>
        <Property Name="Status" Type="Resource.Status"/>
        <Property Name="Links" Type="PCIeFunction.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The links object contains the links to other resources that are related to this resource."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <NavigationProperty Name="EthernetInterfaces" Type="Collection(EthernetInterface.EthernetInterface)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the ethernet interfaces which the PCIe device produces"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall reference a resource of type EthernetInterface that represents the network interfaces associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Drives" Type="Collection(Drive.Drive)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the drives which the PCIe device produces"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall reference a resource of type Drive that represents the storage drives associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="StorageControllers" Type="Collection(Storage.v1_0_0.StorageController)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the storage controllers which the PCIe device produces"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall reference a resource of type StorageController that represents the storage controllers associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PCIeDevice" Type="PCIeDevice.PCIeDevice">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to the PCIeDevice on which this function resides."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resource that this function is a part of and shall reference a resource of type PCIeDevice."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <EnumType Name="DeviceClass">
        <Member Name="UnclassifiedDevice">
          <Annotation Term="OData.Description" String="An unclassified device."/>
        </Member>
        <Member Name="MassStorageController">
          <Annotation Term="OData.Description" String="A mass storage controller."/>
        </Member>
        <Member Name="NetworkController">
          <Annotation Term="OData.Description" String="A network controller."/>
        </Member>
        <Member Name="DisplayController">
          <Annotation Term="OData.Description" String="A display controller."/>
        </Member>
        <Member Name="MultimediaController">
          <Annotation Term="OData.Description" String="A multimedia controller."/>
        </Member>
        <Member Name="MemoryController">
          <Annotation Term="OData.Description" String="A memory controller."/>
        </Member>
        <Member Name="Bridge">
          <Annotation Term="OData.Description" String="A bridge."/>
        </Member>
        <Member Name="CommunicationController">
          <Annotation Term="OData.Description" String="A communication controller."/>
        </Member>
        <Member Name="GenericSystemPeripheral">
          <Annotation Term="OData.Description" String="A generic system peripheral."/>
        </Member>
        <Member Name="InputDeviceController">
          <Annotation Term="OData.Description" String="An input device controller."/>
        </Member>
        <Member Name="DockingStation">
          <Annotation Term="OData.Description" String="A docking station."/>
        </Member>
        <Member Name="Processor">
          <Annotation Term="OData.Description" String="A processor."/>
        </Member>
        <Member Name="SerialBusController">
          <Annotation Term="OData.Description" String="A serial bus controller."/>
        </Member>
        <Member Name="WirelessController">
          <Annotation Term="OData.Description" String="A wireless controller."/>
        </Member>
        <Member Name="IntelligentController">
          <Annotation Term="OData.Description" String="An intelligent controller."/>
        </Member>
        <Member Name="SatelliteCommunicationsController">
          <Annotation Term="OData.Description" String="A satellite communications controller."/>
        </Member>
        <Member Name="EncryptionController">
          <Annotation Term="OData.Description" String="An encryption controller."/>
        </Member>
        <Member Name="SignalProcessingController">
          <Annotation Term="OData.Description" String="A signal processing controller."/>
        </Member>
        <Member Name="ProcessingAccelerators">
          <Annotation Term="OData.Description" String="A processing accelerators."/>
        </Member>
        <Member Name="NonEssentialInstrumentation">
          <Annotation Term="OData.Description" String="A non-essential instrumentation."/>
        </Member>
        <Member Name="Coprocessor">
          <Annotation Term="OData.Description" String="A coprocessor."/>
        </Member>
        <Member Name="UnassignedClass">
          <Annotation Term="OData.Description" String="An unassigned class."/>
        </Member>
        <Member Name="Other">
          <Annotation Term="OData.Description"
                      String="A other class. The function Device Class Id needs to be verified"/>
        </Member>
      </EnumType>
      <EnumType Name="FunctionType">
        <Member Name="Physical">
          <Annotation Term="OData.Description" String="A physical PCie function."/>
        </Member>
        <Member Name="Virtual">
          <Annotation Term="OData.Description" String="A virtual PCIe function."/>
        </Member>
      </EnumType>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_P_CIE_FUNCTION_HPP */
