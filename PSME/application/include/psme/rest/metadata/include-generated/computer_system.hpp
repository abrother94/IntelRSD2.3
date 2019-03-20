#ifndef PSME_REST_METADATA_COMPUTER_SYSTEM_HPP
#define PSME_REST_METADATA_COMPUTER_SYSTEM_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string ComputerSystem_XML =
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
    <edmx:Include Namespace="Resource.v1_1_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Chassis.xml">
    <edmx:Include Namespace="Chassis"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/LogServiceCollection.xml">
    <edmx:Include Namespace="LogServiceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterfaceCollection.xml">
    <edmx:Include Namespace="EthernetInterfaceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/SimpleStorageCollection.xml">
    <edmx:Include Namespace="SimpleStorageCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ProcessorCollection.xml">
    <edmx:Include Namespace="ProcessorCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/MemoryCollection.xml">
    <edmx:Include Namespace="MemoryCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Manager.xml">
    <edmx:Include Namespace="Manager"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageCollection.xml">
    <edmx:Include Namespace="StorageCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeFunction.xml">
    <edmx:Include Namespace="PCIeFunction"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint.xml">
    <edmx:Include Namespace="Endpoint"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/HostedStorageServices.xml">
    <edmx:Include Namespace="HostedStorageServices"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/NetworkInterfaceCollection.xml">
    <edmx:Include Namespace="NetworkInterfaceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/IntelRackScaleExtensions.xml">
    <edmx:Include Namespace="IntelRackScale.Extensions"/>
  </edmx:Reference>

  <edmx:DataServices>

    <!-- This schema defines a computer system and its respective properties.-->
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem">

      <EntityType Name="ComputerSystem" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="A Computer System represents a general purpose machine or system (as opposed to an appliance) instance and the software-visible resources (items within the data plane) such as memory, CPU and other devices that can be accessed from that machine.  Details of those resources or subsystems are also linked through this resource."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent resources that represent a computing system (as opposed to an appliance) in the Redfish specification."/>
      </EntityType>

      <Action Name="Reset" IsBound="true">
        <Parameter Name="ComputerSystem" Type="ComputerSystem.v1_0_0.Actions"/>
        <Parameter Name="ResetType" Type="Resource.ResetType">
          <Annotation Term="OData.Description" String="The type of reset to be performed."/>
          <Annotation Term="OData.LongDescription" String="This defines the property name for the action."/>
        </Parameter>
        <Annotation Term="OData.Description" String="This action is used to reset the system."/>
        <Annotation Term="OData.LongDescription"
                    String="This action shall perform a reset of the ComputerSystem.  For systems which implement APCI Power Button functionality, the PushPowerButton value shall perform or emulate an ACPI Power Button push.  The ForceOff value shall remove power from the system or perform an ACPI Power Button Override (commonly known as a 4-second hold of the Power Button).  The ForceRestart value shall perform a ForceOff action followed by a On action."/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_0_0">

      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.ComputerSystem">
        <Annotation Term="OData.Description"
                    String="This schema defines a computer system and its respective properties.  A computer system represents a machine (physical or virtual) and the local resources such as memory, cpu and other devices that can be accessed from that machine."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent resources that represent a computing system in the Redfish specification."/>
        <Property Name="SystemType" Type="ComputerSystem.v1_0_0.SystemType" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The type of computer system represented by the resource."/>
          <Annotation Term="OData.LongDescription"
                      String="An enumeration that indicates the kind of system the resource represents."/>
        </Property>
        <Property Name="Links" Type="ComputerSystem.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Contains references to other resources that are related to the resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Links property, as described by the Redfish Specification, contains references to resources related to, but not contained by (subordinate to), the resource."/>
        </Property>
        <Property Name="AssetTag" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="The user definable tag that can be used to track the computer system for inventory or other client purposes"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property contains the value of the asset tag of the system."/>
        </Property>
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The manufacturer or OEM of the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property contains a value that represents the manufacturer of the system."/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The model number for the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property contains the information about how the manufacturer references the system."/>
        </Property>
        <Property Name="SKU" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The manufacturer SKU for the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property contains the Stock Keeping Unit (SKU) for the system."/>
        </Property>
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number for the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property contains the serial number for the system."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The part number for the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property contains the part number for the system as defined by the manufacturer."/>
        </Property>
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The universal unique identifier (UUID) for this system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property is used to contain a universal unique identifier number for the system. RFC4122 describes methods that can be used to create the value. The value should be considered to be opaque. Client software should only treat the overall value as a universally unique identifier and should not interpret any subfields in the UUID. If the system supports SMBIOS, the value of the property should be formed by following the SMBIOS 2.6+ recommendation for converting the SMBIOS 16-byte UUID structure into the Redfish canonical xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx string format so the property value matches the byte order presented by current OS APIs, such as WMI and dmidecode."/>
        </Property>
        <Property Name="HostName" Type="Edm.String">
          <Annotation Term="OData.Description" String="The DNS Host Name, without any domain information."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be the host name for the system, as reported by the operating system or hypervisor. The value is typically provided to the Manager by a service running in the host operating system."/>
        </Property>
        <Property Name="IndicatorLED" Type="Resource.v1_1_0.IndicatorLED">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The state of the indicator LED, used to identify the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the indicator light state for the indicator light associated with the system."/>
        </Property>
        <Property Name="PowerState" Type="ComputerSystem.v1_0_0.PowerState">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the current power state of the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the power state of the system."/>
        </Property>
        <Property Name="Boot" Type="ComputerSystem.v1_0_0.Boot" Nullable="false">
          <Annotation Term="IntelRackScale.Extensions.Nontrivial"/>
          <Annotation Term="OData.Description" String="Information about the boot settings for the system."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain properties which describe boot information for the current resource. Changes to this object do not alter the BIOS-persistent boot order configuration."/>
        </Property>
        <Property Name="BiosVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The version of the system BIOS or primary system firmware."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be the version string of the currently installed and running BIOS (for x86 systems). For other systems, the value may contain a version string representing the primary system firmware."/>
        </Property>
        <Property Name="ProcessorSummary" Type="ComputerSystem.v1_0_0.ProcessorSummary" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This object describes the central processors of the system in general detail."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain properties that describe the central processors for the current resource."/>
        </Property>
        <Property Name="MemorySummary" Type="ComputerSystem.v1_0_0.MemorySummary" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This object describes the central memory of the system in general detail."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain properties that describe the central memory for the current resource."/>
        </Property>
        <Property Name="Actions" Type="ComputerSystem.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The available actions for the resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Actions property shall contain the available actions for the resource."/>
        </Property>
        <NavigationProperty Name="Processors" Type="ProcessorCollection.ProcessorCollection" ContainsTarget="true"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the collection of Processors associated with the system"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type ProcessorCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="EthernetInterfaces" Type="EthernetInterfaceCollection.EthernetInterfaceCollection"
                            ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the collection of Ethernet interfaces associated with the system"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type EthernetInterfaceCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="SimpleStorage" Type="SimpleStorageCollection.SimpleStorageCollection"
                            ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the collection of storage devices associated with the system"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type SimpleStorageCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="LogServices" Type="LogServiceCollection.LogServiceCollection" ContainsTarget="true"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the collection of Log Services associated with this system"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type LogServiceCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Status" Type="Resource.Status" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Resource status."/>
          <Annotation Term="OData.LongDescription"
                      String="Resource status."/>
        </Property>
      </EntityType>

      <ComplexType Name="Links" BaseType="Resource.Links">
        <Annotation Term="OData.Description" String="Contains references to other resources that are related to this resource."/>
        <Annotation Term="OData.LongDescription" String="This type, as described by the Redfish Specification, shall contain references to resources that are related to, but not contained by (subordinate to), this resource."/>
        <NavigationProperty Name="Chassis" Type="Collection(Chassis.Chassis)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the chassis in which this system is contained"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall reference a resource of type Chassis that represents the physical container associated with this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ManagedBy" Type="Collection(Manager.Manager)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the Managers responsible for this system"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall reference a resource of type manager that represents the resource with management responsibility for this resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PoweredBy" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of ID[s] of resources that power this computer system. Normally the ID will be a chassis or a specific set of powerSupplies"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that powers this computer system."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="CooledBy" Type="Collection(Resource.Item)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of ID[s] of resources that cool this computer system. Normally the ID will be a chassis or a specific set of fans."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that powers this computer system."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="The available actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain the available actions for this resource."/>
        <Property Name="Oem" Type="ComputerSystem.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="OData.Description" String="The available OEM specific actions for this resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain any additional OEM actions for this resource."/>
      </ComplexType>

      <EnumType Name="SystemType">
        <Member Name="Physical">
          <Annotation Term="OData.Description" String="A computer system."/>
        </Member>
        <Member Name="Virtual">
          <Annotation Term="OData.Description" String="A virtual machine instance running on this system."/>
        </Member>
        <Member Name="OS">
          <Annotation Term="OData.Description" String="An operating system instance."/>
        </Member>
        <Member Name="PhysicallyPartitioned">
          <Annotation Term="OData.Description" String="A hardware-based partition of a computer system."/>
        </Member>
        <Member Name="VirtuallyPartitioned">
          <Annotation Term="OData.Description" String="A virtual or software-based partition of a computer system."/>
        </Member>
      </EnumType>

      <EnumType Name="PowerState">
        <Member Name="On">
          <Annotation Term="OData.Description" String="The system is powered on."/>
        </Member>
        <Member Name="Off">
          <Annotation Term="OData.Description"
                      String="The system is powered off, although some components may continue to have AUX power such as management controller."/>
        </Member>
        <Member Name="PoweringOn">
          <Annotation Term="OData.Description"
                      String="A temporary state between Off and On. This temporary state can be very short."/>
        </Member>
        <Member Name="PoweringOff">
          <Annotation Term="OData.Description"
                      String="A temporary state between On and Off. The power off action can take time while the OS is in the shutdown process."/>
        </Member>
      </EnumType>

      <ComplexType Name="Boot">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object contains the boot information for the current resource."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain properties which describe boot information for a system."/>
        <Property Name="BootSourceOverrideTarget" Type="ComputerSystem.v1_0_0.BootSource">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="The current boot source to be used at next boot instead of the normal boot device, if BootSourceOverrideEnabled is true."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall contain the source to boot the system from, overriding the normal boot order. The valid values for this property are specified through the Redfish.AllowableValues annotation. Pxe indicates to PXE boot from the primary NIC; Floppy, Cd, Usb, Hdd indicates to boot from their devices respectively. BiosSetup indicates to boot into the native BIOS screen setup. Utilities and Diags indicate to boot from the local utilities or diags partitions and UefiTarget indicates to boot from the UEFI device path found in UefiTargetBootSourceOverride."/>
        </Property>
        <Property Name="BootSourceOverrideEnabled" Type="ComputerSystem.v1_0_0.BootSourceOverrideEnabled">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Describes the state of the Boot Source Override feature."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Once if this is a one time boot override and Continuous if this selection should remain active until cancelled. If the property value is set to Once, the value will be reset back to Disabled after the BootSourceOverrideTarget actions have been completed."/>
        </Property>
        <Property Name="UefiTargetBootSourceOverride" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This property is the UEFI Device Path of the device to boot from when BootSourceOverrideSupported is UefiTarget."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the UEFI device path of the override boot target. The valid values for this property are specified through the Redfish.AllowableValues annotation. BootSourceOverrideEnabled = Continuous is not supported for UEFI Boot Source Override as this setting is defined in UEFI as a one time boot only."/>
        </Property>
      </ComplexType>

      <EnumType Name="BootSource">
        <Member Name="None">
          <Annotation Term="OData.Description" String="Boot from the normal boot device."/>
        </Member>
        <Member Name="Pxe">
          <Annotation Term="OData.Description" String="Boot from the Pre-Boot EXecution (PXE) environment."/>
        </Member>
        <Member Name="Floppy">
          <Annotation Term="OData.Description" String="Boot from the floppy disk drive."/>
        </Member>
        <Member Name="Cd">
          <Annotation Term="OData.Description" String="Boot from the CD/DVD disc."/>
        </Member>
        <Member Name="Usb">
          <Annotation Term="OData.Description" String="Boot from a USB device as specified by the system BIOS."/>
        </Member>
        <Member Name="Hdd">
          <Annotation Term="OData.Description" String="Boot from a hard drive."/>
        </Member>
        <Member Name="BiosSetup">
          <Annotation Term="OData.Description" String="Boot to the BIOS Setup Utility."/>
        </Member>
        <Member Name="Utilities">
          <Annotation Term="OData.Description" String="Boot the manufacturer's Utilities program(s)"/>
        </Member>
        <Member Name="Diags">
          <Annotation Term="OData.Description" String="Boot the manufacturer's Diagnostics program."/>
        </Member>
        <Member Name="UefiShell">
          <Annotation Term="OData.Description" String="Boot to the UEFI Shell."/>
        </Member>
        <Member Name="UefiTarget">
          <Annotation Term="OData.Description"
                      String="Boot to the UEFI Device specified in the UefiTargetBootSourceOverride property"/>
        </Member>
        <Member Name="SDCard">
          <Annotation Term="OData.Description" String="Boot from an SD Card."/>
        </Member>
        <Member Name="UefiHttp">
          <Annotation Term="OData.Description" String="Boot from a UEFI HTTP network location."/>
        </Member>
        <Member Name="RemoteDrive">
          <Annotation Term="OData.Description" String="Boot from a remote drive (e.g. iSCSI)"/>
        </Member>
      </EnumType>

      <EnumType Name="BootSourceOverrideEnabled">
        <Member Name="Disabled">
          <Annotation Term="OData.Description" String="The system will boot normally."/>
        </Member>
        <Member Name="Once">
          <Annotation Term="OData.Description"
                      String="On its next boot cycle, the system will boot (one time) to the Boot Source Override Target. The value of BootSourceOverrideEnabled is then reset back to Disabled."/>
        </Member>
        <Member Name="Continuous">
          <Annotation Term="OData.Description"
                      String="The system will boot to the target specified in the BootSourceOverrideTarget until this property is set to Disabled."/>
        </Member>
      </EnumType>

      <ComplexType Name="ProcessorSummary">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object describes the central processors of the system in general detail."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain properties which describe the central processors for a system."/>
        <Property Name="Count" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The number of processors in the system."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the number of central processors in the system."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The processor model for the primary or majority of processors in this system."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the processor model for the central processors in the system, per the description in Table 22 of the SMBIOS Specification DSP0134 2.8 or later."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="MemorySummary">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object describes the memory of the system in general detail."/>
        <Annotation Term="OData.LongDescription" String="This type shall contain properties which describe the central memory for a system."/>
        <Property Name="TotalSystemMemoryGiB" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The total installed, operating system-accessible memory (RAM), measured in GiB."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the amount of system general purpose volatile (RAM) memory as measured in gibibytes."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
      </ComplexType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_0_1">
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_0_0.ComputerSystem"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_0_2">
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_0_1.ComputerSystem"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_0_3">
      <Annotation Term="OData.Description" String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_0_2.ComputerSystem"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_1_0">

      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_0_2.ComputerSystem">
        <Property Name="TrustedModules" Type="Collection(ComputerSystem.v1_1_0.TrustedModules)" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This object describes the array of Trusted Modules in the system."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain an array of objects with properties that describe the trusted modules for the current resource."/>
        </Property>
        <NavigationProperty Name="Memory" Type="MemoryCollection.MemoryCollection" ContainsTarget="true"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the collection of Memory associated with the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type MemoryCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Storage" Type="StorageCollection.StorageCollection" ContainsTarget="true"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the collection of storage devices associated with the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type StorageCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="Boot" BaseType="ComputerSystem.v1_0_0.Boot">
        <Property Name="BootSourceOverrideMode" Type="ComputerSystem.v1_1_0.BootSourceOverrideMode">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="The BIOS Boot Mode (either Legacy or UEFI) to be used when BootSourceOverrideTarget boot source is booted from."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Legacy for non-UEFI BIOS boot or UEFI for UEFI boot from boot source specified in BootSourceOverrideTarget property."/>
        </Property>
      </ComplexType>

      <EnumType Name="BootSourceOverrideMode">
        <Member Name="Legacy">
          <Annotation Term="OData.Description"
                      String="The system will boot in non-UEFI boot mode to the Boot Source Override Target."/>
        </Member>
        <Member Name="UEFI">
          <Annotation Term="OData.Description"
                      String="The system will boot in UEFI boot mode to the Boot Source Override Target."/>
        </Member>
      </EnumType>

      <ComplexType Name="TrustedModules">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object describes the inventory of a Trusted Modules installed in the system."/>
        <Annotation Term="OData.LongDescription" String="This type shall describe a trusted module for a system."/>
        <Property Name="FirmwareVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The firmware version of this Trusted Module."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the firwmare version as defined by the manufacturer for the Trusted Module."/>
        </Property>
        <Property Name="InterfaceType" Type="ComputerSystem.v1_1_0.InterfaceType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property indicates the interface type of the Trusted Module."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the interface type of the installed Trusted Module."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false"/>
      </ComplexType>

      <EnumType Name="InterfaceType">
        <Member Name="TPM1_2">
          <Annotation Term="OData.Description" String="Trusted Platform Module (TPM) 1.2."/>
        </Member>
        <Member Name="TPM2_0">
          <Annotation Term="OData.Description" String="Trusted Platform Module (TPM) 2.0."/>
        </Member>
        <Member Name="TCM1_0">
          <Annotation Term="OData.Description" String="Trusted Cryptography Module (TCM) 1.0."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_1_1">
      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_1_0.ComputerSystem"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_2_0">
      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_1_1.ComputerSystem">
        <Property Name="HostingRoles" Type="Collection(ComputerSystem.v1_2_0.HostingRole)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The hosing roles that the computer system supports."/>
          <Annotation Term="OData.LongDescription"
                      String="The values of the collection shall be the hosting roles supported by the computer system."/>
        </Property>
        <NavigationProperty Name="PCIeDevices" Type="Collection(PCIeDevice.PCIeDevice)" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to a collection of PCIe Devices used by the computer system"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be an array of references of type PCIeDevice."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="PCIeFunctions" Type="Collection(PCIeFunction.PCIeFunction)" ContainsTarget="true"
                            Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to a collection of PCIe Functions used by the computer system."/>
          <Annotation Term="OData.LongDescription" String="The value of the property shall be an array of references of type PCIeFunction."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="HostedServices" Type="ComputerSystem.v1_2_0.HostedServices" Nullable="false">
          <Annotation Term="OData.Description" String="The services that the computer system supports."/>
          <Annotation Term="OData.LongDescription" String="The values of the collection shall describe services supported by the computer system."/>
        </Property>
      </EntityType>
      <ComplexType Name="HostedServices">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="This object describes services that may be running or installed on the system."/>
        <Annotation Term="OData.LongDescription" String="The values of the collection shall describe services supported by the computer system."/>
        <NavigationProperty Name="StorageServices" Type="HostedStorageServices.HostedStorageServices" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A reference to a collection of storage services supported by this computer system."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be a link to a collection of type HostedStorageServices."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false"/>
      </ComplexType>
      <EnumType Name="HostingRole">
        <Annotation Term="OData.Description"
                    String="The enumerations of HostingRoles specify different features that the hosting ComputerSystem supports."/>
        <Member Name="ApplicationServer">
          <Annotation Term="OData.Description"
                      String="The system hosts functionality that supports general purpose applications."/>
        </Member>
        <Member Name="StorageServer">
          <Annotation Term="OData.Description"
                      String="The system hosts functionality that supports the system acting as a storage server."/>
        </Member>
        <Member Name="Switch">
          <Annotation Term="OData.Description"
                      String="The system hosts functionality that supports the system acting as a switch."/>
        </Member>
      </EnumType>

      <ComplexType Name="Links" BaseType="ComputerSystem.v1_0_0.Links">
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the endpoints that connect to this system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this system is associated with and shall reference a resource of type Endpoint."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_2_1">
      <Annotation Term="OData.Description"
                  String="This version was created to show annotations in previous namespaces were updated."/>
      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_2_0.ComputerSystem"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystem.v1_3_0">
      <EntityType Name="ComputerSystem" BaseType="ComputerSystem.v1_2_0.ComputerSystem">
        <NavigationProperty Name="NetworkInterfaces" Type="NetworkInterfaceCollection.NetworkInterfaceCollection" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the collection of Network Interfaces associated with the system."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a link to a collection of type NetworkInterfaceCollection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="TrustedModules" BaseType="ComputerSystem.v1_1_0.TrustedModules">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="FirmwareVersion2" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The 2nd firmware version of this Trusted Module, if applicable."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the 2nd firmware version, if applicable, as defined by the manufacturer for the Trusted Module."/>
        </Property>
        <Property Name="InterfaceTypeSelection" Type="ComputerSystem.v1_3_0.InterfaceTypeSelection">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Interface Type selection supported by this Trusted Module."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the Interface Type Selection method (for example to switch between TPM1_2 and TPM2_0) that is supported by this TrustedModule."/>
        </Property>
      </ComplexType>
      <EnumType Name="InterfaceTypeSelection">
        <Annotation Term="OData.Description"
                    String="The enumerations of InterfaceTypeSelection specify the method for switching the TrustedModule InterfaceType, for instance between TPM1_2 and TPM2_0, if supported."/>
        <Member Name="None">
          <Annotation Term="OData.Description"
                      String="The TrustedModule does not support switching the InterfaceType."/>
        </Member>
        <Member Name="FirmwareUpdate">
          <Annotation Term="OData.Description"
                      String="The TrustedModule supports switching InterfaceType via a firmware update."/>
        </Member>
        <Member Name="BiosSetting">
          <Annotation Term="OData.Description"
                      String="The TrustedModule supports switching InterfaceType via platform software, such as a BIOS configuration Attribute."/>
        </Member>
        <Member Name="OemMethod">
          <Annotation Term="OData.Description"
                      String="The TrustedModule supports switching InterfaceType via an OEM proprietary mechanism."/>
        </Member>
      </EnumType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_COMPUTER_SYSTEM_HPP */
