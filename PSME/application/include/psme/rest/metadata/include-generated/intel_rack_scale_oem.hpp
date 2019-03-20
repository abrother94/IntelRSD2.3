#ifndef PSME_REST_METADATA_INTEL_RACK_SCALE_OEM_HPP
#define PSME_REST_METADATA_INTEL_RACK_SCALE_OEM_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string IntelRackScaleOem_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageService.xml">
    <edmx:Include Namespace="StorageService.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystem.xml">
    <edmx:Include Namespace="ComputerSystem"/>
    <edmx:Include Namespace="ComputerSystem.v1_0_0"/>
    <edmx:Include Namespace="ComputerSystem.v1_1_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchPort.xml">
    <edmx:Include Namespace="EthernetSwitchPort"/>
    <edmx:Include Namespace="EthernetSwitchPort.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface.xml">
    <edmx:Include Namespace="EthernetInterface"/>
    <edmx:Include Namespace="EthernetInterface.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitch.xml">
    <edmx:Include Namespace="EthernetSwitch.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Switch.xml">
    <edmx:Include Namespace="Switch"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeDevice.xml">
    <edmx:Include Namespace="PCIeDevice"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PCIeFunction.xml">
    <edmx:Include Namespace="PCIeFunction"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Zone.xml">
    <edmx:Include Namespace="Zone"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Port.xml">
    <edmx:Include Namespace="Port"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Storage.xml">
    <edmx:Include Namespace="Storage"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystemMetrics.xml">
    <edmx:Include Namespace="ComputerSystemMetrics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ProcessorMetrics.xml">
    <edmx:Include Namespace="ProcessorMetrics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Thermal.xml">
    <edmx:Include Namespace="Thermal"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Power.xml">
    <edmx:Include Namespace="Power"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PortMetrics.xml">
    <edmx:Include Namespace="PortMetrics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Manager.xml">
    <edmx:Include Namespace="Manager"/>
    <edmx:Include Namespace="Manager.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageServiceCollection.xml">
    <edmx:Include Namespace="StorageServiceCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetSwitchCollection.xml">
    <edmx:Include Namespace="EthernetSwitchCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComposedNodeCollection.xml">
    <edmx:Include Namespace="ComposedNodeCollection"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StoragePool.xml">
    <edmx:Include Namespace="StoragePool"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Endpoint.xml">
    <edmx:Include Namespace="Endpoint"/>
    <edmx:Include Namespace="Endpoint.v1_1_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/IntelRackScaleExtensions.xml">
    <edmx:Include Namespace="IntelRackScale.Extensions"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/DriveMetrics.xml">
    <edmx:Include Namespace="DriveMetrics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/MetricDefinition.xml">
    <edmx:Include Namespace="MetricDefinition"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VolumeMetrics.xml">
    <edmx:Include Namespace="VolumeMetrics"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Protocol.xml">
    <edmx:Include Namespace="Protocol"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Intel.Oem">

      <ComplexType Name="Chassis" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Location" Type="Intel.Oem.Location">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Chassis location in relation to it’s parent."/>
          <Annotation Term="OData.LongDescription"
                      String="Chassis location in relation to it’s parent."/>
        </Property>
      </ComplexType>

      <ComplexType Name="RackChassis" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Location" Type="Intel.Oem.Location">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
        </Property>
        <Property Name="RMMPresent" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This indicate if Rack Management Module is present in Rack chassis."/>
          <Annotation Term="OData.LongDescription"
                      String="This indicate if Rack Management Module is present in Rack chassis."/>
        </Property>
        <Property Name="RackSupportsDisaggregatedPowerCooling" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This indicate if Rack chassis support disaggregated power and cooling feature."/>
          <Annotation Term="OData.LongDescription"
                      String="This indicate if Rack chassis support disaggregated power and cooling feature."/>
        </Property>
        <Property Name="UUID" Type="Resource.UUID">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Universal Unique Identifier for this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="Universal Unique Identifier for this resource."/>
        </Property>
        <Property Name="GeoTag" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="String containing geographical identification metadata."/>
          <Annotation Term="OData.LongDescription"
                      String="String containing geographical identification metadata. Usually consist of latitude and longitude."/>
        </Property>
      </ComplexType>

      <ComplexType Name="Location">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Id" Type="Edm.String">
          <Annotation Term="IntelRackScale.Extensions.Nontrivial"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="String containing physical location ID of this chassis."/>
          <Annotation Term="OData.LongDescription" String="String containing physical location ID of this chassis."/>
          <Annotation Term="Validation.Pattern" String="^(?!\s*$).+"/>
        </Property>
        <Property Name="ParentId" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="String containing  physical location ID of parent chassis."/>
          <Annotation Term="OData.LongDescription" String="String containing  physical location ID of parent chassis."/>
          <Annotation Term="Validation.Pattern" String="^(?!\s*$).+"/>
        </Property>
      </ComplexType>

      <ComplexType Name="ManagerLinks" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <NavigationProperty Name="ManagerForServices" Type="Collection(StorageService.v1_0_0.StorageService)">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="ManagerForSwitches" Type="Collection(EthernetSwitch.v1_0_0.EthernetSwitch)">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="ComputerSystem" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="PCIeConnectionId" Type="Collection(Edm.String)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property is an array of IDs of cable or cables connected to this port."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain an array of string identifying cable(s) connected to this port. This is crucial for topology discovery."/>
        </Property>
        <Property Name="PciDevices" Type="Collection(Intel.Oem.PciDevice)" Nullable="false">
          <Annotation Term="OData.Description" String="This indicates array of PCI devices present in computer system."/>
          <Annotation Term="OData.LongDescription"
                      String="This indicates array of PCI devices present in computer system"/>
        </Property>
        <Property Name="DiscoveryState" Type="Intel.Oem.DiscoveryState">
          <Annotation Term="OData.Description" String="This indicates computer system discovery state."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent discovery state of this interface"/>
        </Property>
        <Property Name="ProcessorSockets" Type="Edm.Int64">
          <Annotation Term="OData.Description" String="This indicates number of processor sockets available in system."/>
          <Annotation Term="OData.LongDescription"
                      String="This indicates number of memory sockets available in system"/>
        </Property>
        <Property Name="MemorySockets" Type="Edm.Int64">
          <Annotation Term="OData.Description" String="This indicates number of memory sockets available in system."/>
          <Annotation Term="OData.LongDescription"
                      String="This indicates number of memory sockets available in system"/>
        </Property>
        <Property Name="UserModeEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="This indicates if platform user mode is enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent current platform mode. When enabled update of FW components should be blocked on in-band interfaces."/>
        </Property>
        <Property Name="TrustedExecutionTechnologyEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="This indicates if TXT mode is enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent current Trusted Execution Technology state."/>
        </Property>
        <NavigationProperty Name="Metrics" Type="ComputerSystemMetrics.ComputerSystemMetrics" ContainsTarget="true"
                            Nullable="false">
          <Annotation Term="OData.Description" String="A reference to the Metrics associated with this ComputerSystem."/>
          <Annotation Term="OData.LongDescription"
                      String="A reference to the Metrics associated with this ComputerSystem."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Memory" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="VoltageVolt" Type="Edm.Decimal">
          <Annotation Term="OData.Description" String="This indicates current voltage of memory module."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent current voltage of memory module"/>
        </Property>
      </ComplexType>
      <ComplexType Name="MemoryMetrics" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="TemperatureCelsius" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Temperature of the Memory resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be temperature of the Memory resource in Celsius."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="BandwidthPercent" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Memory Bandwidth in Percent."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Memory Utilization on specific Memory module in Percent."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="100"/>
        </Property>
        <Property Name="ThrottledCyclesPercent" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The percentage of memory cycles that were throttled due to power limiting."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the percentage of memory cycles that were throttled due to power limiting."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="100"/>
        </Property>
        <Property Name="ConsumedPowerWatt" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Power consumed by Memory domain resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be global power for specific Memory module (e.g. DIMM) in Watts."/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="ThermalMarginCelsius" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Memory Thermal Margin in degree Celsius."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a difference between current memory module temperature and optimal temperature for the module in degree Celsius."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="ECCErrorsCount" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Number of ECC Errors found on this Memory module."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a number of ECC Errors found on this Memory module. It's up to implementer if only UnCorrectable or both Correctable and Uncorrectable errors are shown per Module resource."/>
        </Property>
        <Property Name="Health" Type="Collection(Edm.String)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Memory module Health as a discrete sensor reading"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Memory module Health as a discrete sensor reading."/>
        </Property>
      </ComplexType>

      <ComplexType Name="PciDevice">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="VendorId" Type="Edm.String"/>
        <Property Name="DeviceId" Type="Edm.String"/>
      </ComplexType>

      <EnumType Name="DiscoveryState">
        <Member Name="None"/>
        <Member Name="Basic"/>
        <Member Name="DeepInProgress"/>
        <Member Name="Deep"/>
        <Member Name="DeepFailed"/>
      </EnumType>

      <Action Name="StartDeepDiscovery" IsBound="true">
        <Parameter Name="ComputerSystem" Type="ComputerSystem.v1_0_0.OemActions"/>
        <Annotation Term="OData.Description" String="This action is used to trigger Deep Discovery." />
        <Annotation Term="OData.LongDescription" String="This action is used to trigger Pod Manager Deep Discovery mechanism." />
      </Action>

      <Action Name="ChangeTPMState" IsBound="true">
        <Parameter Name="ComputerSystem" Type="ComputerSystem.v1_0_0.OemActions"/>
        <Parameter Name="DeviceEnabled" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Description" String="Required device state after action is finished." />
          <Annotation Term="OData.LongDescription" String="This defines the TPM device state as a result of triggering this action." />
        </Parameter>
        <Parameter Name="InterfaceType" Type="ComputerSystem.v1_1_0.InterfaceType">
          <Annotation Term="OData.Description" String="Required  interface type of the Trusted Module." />
          <Annotation Term="OData.LongDescription" String="This defines the interface type of the installed Trusted Module device as a result of triggering this action." />
        </Parameter>
        <Parameter Name="ClearOwnership" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="This indicates if TPM ownership should be cleared." />
          <Annotation Term="OData.LongDescription" String="This defines if Trusted Module ownership should be cleared as a result of triggering this action." />
        </Parameter>
        <Annotation Term="OData.Description" String="This action is used to change TPM state and version." />
        <Annotation Term="OData.LongDescription" String="This action is used to change TPM state and version." />
      </Action>

      <Action Name="StartDiscoveryOnDemand" IsBound="true">
        <Parameter Name="Manager" Type="Manager.v1_0_0.OemActions"/>
      </Action>

      <ComplexType Name="EthernetInterfaceLinks" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <NavigationProperty Name="NeighborPort" Type="EthernetSwitchPort.EthernetSwitchPort">
          <Annotation Term="OData.Description"
                      String="This indicates ethernet port which is connected to this interface"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent the URI of ethernet port connected to this interface"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="EthernetInterface" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="SupportedProtocols" Type="Collection(Protocol.Protocol)">
          <Annotation Term="OData.Description"
                      String="This indicates all supported protocol types."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent an array of supported protocol types by the Ethernet interface."/>
       </Property>
      </ComplexType>

      <ComplexType Name="Processor" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Brand" Type="Intel.Oem.ProcessorBrand">
          <Annotation Term="OData.Description" String="This indicates processor brand."/>
          <Annotation Term="OData.LongDescription" String="This property shall represent the brand of processor."/>
        </Property>
        <Property Name="Capabilities" Type="Collection(Edm.String)">
          <Annotation Term="OData.Description" String="This indicates array of processor capabilities."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent array of processor capabilities (like reported in /proc/cpuinfo flags)"/>
        </Property>
        <Property Name="OnPackageMemory" Type="Collection(Intel.Oem.ProcessorMemory)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the endpoints that connect to this processor."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this processor is associated with and shall reference a resource of type Endpoint."/>
        </Property>
        <Property Name="ThermalDesignPowerWatt" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Thermal Design Power (TDP) of this processor."/>
          <Annotation Term="OData.LongDescription" String="Thermal Design Power (TDP) of this processor."/>
        </Property>
        <Property Name="FPGA" Type="Intel.Oem.FPGA">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="FPGA specific properties for FPGA ProcessorType."/>
          <Annotation Term="OData.LongDescription"
                      String="For FPGA ProcessorType this property will expose specific data."/>
        </Property>
        <NavigationProperty Name="Metrics" Type="ProcessorMetrics.ProcessorMetrics" ContainsTarget="true"
                            Nullable="false">
          <Annotation Term="OData.Description" String="A reference to the Metrics associated with this Processor."/>
          <Annotation Term="OData.LongDescription" String="A reference to the Metrics associated with this Processor."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="ExtendedIdentificationRegisters" Type="Intel.Oem.ExtendedIdentificationRegister">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="Extended contents of the Identification Registers (CPUID) for this processor." />
          <Annotation Term="OData.LongDescription" String="This property shall include the extended raw CPUID instruction output for  (that is for all possible combinations of input registers) as provided by the manufacturer of this processor." />
        </Property>


      </ComplexType>

      <EnumType Name="ProcessorBrand">
        <Member Name="E3">
          <Annotation Term="OData.Description" String="Xeon E3 CPU family."/>
        </Member>
        <Member Name="E5">
          <Annotation Term="OData.Description" String="Xeon E5 CPU family."/>
        </Member>
        <Member Name="E7">
          <Annotation Term="OData.Description" String="Xeon E7 CPU family."/>
        </Member>
        <Member Name="X3">
          <Annotation Term="OData.Description" String="uServer X3 CPU family."/>
        </Member>
        <Member Name="X5">
          <Annotation Term="OData.Description" String="uServer X5 CPU family."/>
        </Member>
        <Member Name="X7">
          <Annotation Term="OData.Description" String="uServer X7 CPU family."/>
        </Member>
        <Member Name="I3">
          <Annotation Term="OData.Description" String="Core i3 CPU family."/>
        </Member>
        <Member Name="I5">
          <Annotation Term="OData.Description" String="Core i5 CPU family."/>
        </Member>
        <Member Name="I7">
          <Annotation Term="OData.Description" String="Core i7 CPU family."/>
        </Member>
        <Member Name="Silver">
          <Annotation Term="OData.Description" String="Xeon Silver CPU family."/>
        </Member>
        <Member Name="Gold">
          <Annotation Term="OData.Description" String="Xeon Gold CPU family."/>
        </Member>
        <Member Name="Platinum">
          <Annotation Term="OData.Description" String="Xeon Platinum CPU family."/>
        </Member>
      </EnumType>

      <ComplexType Name="ProcessorMemory">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Type" Type="Intel.Oem.ProcessorMemoryType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Type of memory."/>
          <Annotation Term="OData.LongDescription" String="Type of memory."/>
        </Property>
        <Property Name="CapacityMB" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Memory capacity."/>
          <Annotation Term="OData.LongDescription" String="Memory capacity."/>
          <Annotation Term="Measures.Unit" String="MBy"/>
        </Property>
        <Property Name="SpeedMHz" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Memory speed."/>
          <Annotation Term="OData.LongDescription" String="Memory speed."/>
          <Annotation Term="Measures.Unit" String="MHz"/>
        </Property>
        <Annotation Term="OData.Description" String="On die processor memory."/>
      </ComplexType>

      <EnumType Name="ProcessorMemoryType">
        <Member Name="L1Cache"/>
        <Member Name="L2Cache"/>
        <Member Name="L3Cache"/>
        <Member Name="HBM"/>
        <Member Name="HBM2"/>
        <Member Name="Flash"/>
        <Member Name="DDR"/>
        <Member Name="DDR3"/>
        <Member Name="DDR4"/>
        <Member Name="GDDR5"/>
        <Member Name="EDRAM"/>
      </EnumType>

      <ComplexType Name="FPGA">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Type" Type="Intel.Oem.FPGAType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="FPGA type."/>
          <Annotation Term="OData.LongDescription" String="FPGA type."/>
        </Property>
        <Property Name="BitStreamVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Version of BitStream loaded on FPGA."/>
          <Annotation Term="OData.LongDescription" String="Version of BitStream loaded on FPGA."/>
        </Property>
        <Property Name="HSSIConfiguration" Type="Intel.Oem.HSSIConfig">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="High Speed Serial Interface configuration."/>
          <Annotation Term="OData.LongDescription" String="High Speed Serial Interface configuration."/>
        </Property>
        <Property Name="HSSISideband" Type="Intel.Oem.HSSISideband">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="High Speed Serial Interface sideband interface type."/>
          <Annotation Term="OData.LongDescription"
                      String="High Speed Serial Interface sideband interface type."/>
        </Property>
        <Property Name="ReconfigurationSlots" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Number of supported reconfiguration slots."/>
          <Annotation Term="OData.LongDescription" String="Number of supported reconfiguration slots."/>
        </Property>
        <Annotation Term="OData.Description" String="FPGA properties."/>
      </ComplexType>

      <EnumType Name="FPGAType">
        <Member Name="Integrated"/>
        <Member Name="Discrete"/>
      </EnumType>

      <TypeDefinition Name="HSSIConfig" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="4x10G"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="2x40G"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="10x10G"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="PCIe"/>
            </Record>
          </Collection>
        </Annotation>
      </TypeDefinition>

      <TypeDefinition Name="HSSISideband" UnderlyingType="Edm.String">
        <Annotation Term="Redfish.Enumeration">
          <Collection>
            <Record>
              <PropertyValue Property="Member" String="SPI"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="I2C-0"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="I2C-1"/>
            </Record>
            <Record>
              <PropertyValue Property="Member" String="I2C"/>
            </Record>
          </Collection>
        </Annotation>
      </TypeDefinition>

      <ComplexType Name="ExtendedIdentificationRegister">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
        <Annotation Term="Redfish.DynamicPropertyPatterns">
          <Collection>
            <Record>
              <PropertyValue Property="Pattern" String="[A-Za-z0-9_.:]+"/>
              <PropertyValue Property="Type" String="Edm.String"/>
            </Record>
          </Collection>
        </Annotation>
        <Annotation Term="OData.Description" String="The contents of the Identification Registers (CPUID) for this processor for specific combination of input registers." />
        <Annotation Term="OData.LongDescription" String="This property shall include the raw CPUID instruction output as provided by the manufacturer of this processor for specific combination of input registers." />
      </ComplexType>

      <ComplexType Name="ServiceRoot" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="ApiVersion" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Version of Rack Scale Design API exposed by this service."/>
          <Annotation Term="OData.LongDescription"
                      String="Version of Intel® RSD API exposed by this service."/>
        </Property>
        <NavigationProperty Name="EthernetSwitches" Type="EthernetSwitchCollection.EthernetSwitchCollection">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection Ethernet Switches."/>
          <Annotation Term="OData.LongDescription"
                      String="The classes' structure shall only contain a reference to a resource that complies to the EthernetSwitch schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Nodes" Type="ComposedNodeCollection.ComposedNodeCollection">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is a link to a collection of Nodes."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall only contain a reference to a collection of resources that comply to the Nodes schema."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="VLanNetworkInterface" BaseType="Resource.OemObject">
        <Property Name="Status" Type="Resource.Status"/>
        <Property Name="Tagged" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This indicates if VLAN is tagged (as defined in IEEE 802.1Q)."/>
          <Annotation Term="OData.LongDescription"
                      String="This indicates if VLAN is tagged (as defined in IEEE 802.1Q)."/>
        </Property>
      </ComplexType>

      <ComplexType Name="PortLinks" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="CableId" Type="Collection(Edm.String)"/>
        <NavigationProperty Name="NeighborPort" Type="Collection(Port.Port)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates neighbor port which is connected to this port."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent the URI of port connected to this port"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Drive" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="EraseOnDetach" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite" Qualifier="PODM"/>
          <Annotation Term="OData.Description"
                      String="This indicates if drive should be erased when detached from PCI switch."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent the state of policy for protecting data stored on drive connected to PCI switch. If set to null it is interpreted as it would be set to true."/>
        </Property>
        <Property Name="DriveErased" Type="Edm.Boolean" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" Qualifier="PODM"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite" Qualifier="PSME"/>
          <Annotation Term="OData.Description"
                      String="This indicates whether drive was cleared after assignment to composed node."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent the erase state of drive."/>
        </Property>
        <Property Name="FirmwareVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This indicates drive firmware version."/>
          <Annotation Term="OData.LongDescription" String="This indicates drive firmware version."/>
        </Property>
        <NavigationProperty Name="Storage" Type="Storage.Storage">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the storage controller where this drive is connected."/>
          <Annotation Term="OData.LongDescription"
                      String="A reference to the storage controller where this drive is connected."/>
        </NavigationProperty>
        <NavigationProperty Name="PCIeFunction" Type="PCIeFunction.PCIeFunction">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="A reference to the PCIe function that provides this drive functionality."/>
          <Annotation Term="OData.LongDescription"
                      String="A reference to the PCIe function that provides this drive functionality."/>
        </NavigationProperty>
        <NavigationProperty Name="UsedBy" Type="Collection(StoragePool.StoragePool)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the storage pools using the drive."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this drive is associated with and shall reference a resource of type storage pool."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Metrics" Type="DriveMetrics.DriveMetrics" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Description" String="A reference to the Metrics associated with this Drive."/>
          <Annotation Term="OData.LongDescription" String="A reference to the Metrics associated with this Drive."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="ChassisLinks" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <NavigationProperty Name="Switches" Type="Collection(EthernetSwitch.v1_0_0.EthernetSwitch)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the ethernet switches located in this Chassis."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall reference one or more resources of type EthernetSwitch that are in this Chassis."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Port" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="PCIeConnectionId" Type="Collection(Edm.String)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the PCIe connection identifiers (e.g. cable ID)."/>
          <Annotation Term="OData.LongDescription"
                      String="An array of references to the PCIe connection identifiers (e.g. cable ID)."/>
        </Property>
        <NavigationProperty Name="Metrics" Type="PortMetrics.PortMetrics" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Description" String="A reference to the Metrics associated with this Port."/>
          <Annotation Term="OData.LongDescription" String="A reference to the Metrics associated with this Port."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Power" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="Extended Power resource."/>
        <Annotation Term="OData.LongDescription" String="Extended Power resource."/>
        <Property Name="Actions" Type="Intel.Oem.Actions">
          <Annotation Term="OData.Description" String="Additional actions for Power resource."/>
          <Annotation Term="OData.LongDescription" String="Additional actions for Power resource."/>
        </Property>
        <Property Name="InputACPowerWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The global power level on AC side in Watts."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the global power level on AC side in Watts, requires platform instrumentation to get reports of AC power."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
      </ComplexType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
      </ComplexType>

      <Action Name="RequestPowerSupplyStateChange" IsBound="true">
        <Parameter Name="Power" Type="Intel.Oem.Actions"/>
        <Parameter Name="State" Type="Intel.Oem.PowerSupplyState">
          <Annotation Term="OData.Description" String="This is the requested state of PSU."/>
          <Annotation Term="OData.LongDescription" String="This property defines requested state of Power Supply to be changed to."/>
        </Parameter>
        <Parameter Name="MemberId" Type="Edm.String">
          <Annotation Term="OData.Description" String="This is the identifier for the Power Supply within the PowerSupplies collection."/>
          <Annotation Term="OData.LongDescription" String="This is the identifier for the Power Supply within the PowerSupplies collection."/>
        </Parameter>
        <Annotation Term="OData.Description"
                    String="This action is used to change state of Power Supply."/>
        <Annotation Term="OData.LongDescription"
                    String="This action is used to change state of Power Supply."/>
      </Action>

      <EnumType Name="PowerSupplyState">
        <Member Name="Enabled"/>
        <Member Name="Disabled"/>
      </EnumType>

      <ComplexType Name="Thermal" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="Extended Thermal resource."/>
        <Annotation Term="OData.LongDescription" String="Extended Thermal resource."/>
        <Property Name="VolumetricAirflowCfm" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Volumetric Air Flow measured in Cubic Feet per Minute."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be Volumetric Air Flow measured in Cubic Feet per Minute. This metric requires Inlet and Outlet temperature sensor readings"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="DesiredSpeedPwm" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This property represent desired speed of all FANs in current chassis as percentage of max speed."/>
          <Annotation Term="OData.LongDescription"
                      String="This property represents desired speed of all FANs in current chassis as percentage of maximum fan speed."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Validation.Maximum" Int="100"/>
        </Property>
      </ComplexType>

      <ComplexType Name="MetricDefinition" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="CalculationPrecision" Type="Edm.Double">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property specifies the precision of a calculated metric (calculated metric shall be aligned to a value specified by This property ."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall specify the precision of a calculated metric (calculated metric shall be aligned to a value specified by this property)"/>
        </Property>
        <Property Name="DiscreteMetricType" Type="Intel.Oem.MetricValueType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This array property specifies possible values of a discrete metric."/>
          <Annotation Term="OData.LongDescription"
                      String="The values of the property shall specify type of the discrete metric. It specifies whether single or multiple values defined in DiscreteValues array are valid for specific metric, metric property shall be defined accordingly.  This property shall be defined only when the MetricType property has the value 'Discrete'."/>
        </Property>
      </ComplexType>
      <EnumType Name="MetricValueType">
        <Annotation Term="OData.Description" String="The type of Discrete Metric reading."/>
        <Annotation Term="OData.LongDescription"
                    String="The value shall indicate the type of Discrete Metric reading."/>
        <Member Name="Single">
          <Annotation Term="OData.Description" String="Single entry from DiscreteValues array is allowed as Discrete Metric Reading."/>
        </Member>
        <Member Name="Multiple">
          <Annotation Term="OData.Description" String="Multiple entries from DiscreteValues array is allowed as Discrete Metric Reading."/>
        </Member>
      </EnumType>

      <Action Name="LoadFactoryDefaults" IsBound="true">
        <Parameter Name="Manager" Type="Manager.v1_0_0.OemActions"/>
      </Action>

      <ComplexType Name="VolumeLinks" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <NavigationProperty Name="Endpoints" Type="Collection(Endpoint.Endpoint)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the endpoints that connect to this volume."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a reference to the resources that this volume is associated with and shall reference a resource of type Endpoint."/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="StorageServiceLinks" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <NavigationProperty Name="ManagedBy" Type="Collection(Manager.Manager)">
          <Annotation Term="OData.Description"
                      String="Collection of managers managing the service."/>
          <Annotation Term="OData.LongDescription"
                      String="Collection of managers managing the service."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Endpoint" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Authentication" Type="Intel.Oem.EndpointAuthentication">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="Endpoint authentication."/>
          <Annotation Term="OData.LongDescription"
                      String="This property provides information about endpoint authentication required credentials."/>
        </Property>
      </ComplexType>

      <ComplexType Name="EndpointAuthentication">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="Endpoint authentication credentials."/>
        <Property Name="Username" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="Endpoint username."/>
          <Annotation Term="OData.LongDescription"
                      String="This property provides an endpoint username that is used to authenticate it on other side of communication channel." />
        </Property>
        <Property Name="Password" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Write"/>
          <Annotation Term="OData.Description" String="Endpoint password."/>
          <Annotation Term="OData.LongDescription"
                      String="This property is used to provide an endpoint password. It provides write only access. On read, it shall return null value." />
        </Property>
      </ComplexType>

      <ComplexType Name="Volume" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Bootable" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="Determines if volume is bootable."/>
          <Annotation Term="OData.LongDescription"
                      String="This property provides information about the bootable capability of the volume."/>
        </Property>
        <Property Name="EraseOnDetach" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite" Qualifier="PODM"/>
          <Annotation Term="OData.Description"
                      String="This indicates if volume should be erased when detached from initiator host."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall represent the state of policy for protecting data stored on a drive connected to an initiator host. If set to null, it is interpreted as true."/>
        </Property>
        <Property Name="Erased" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" Qualifier="PODM"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite" Qualifier="PSME"/>
          <Annotation Term="OData.Description"
                      String="This indicates whether volume was cleared after assignment to composed node."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall be set to true if the volume was erased."/>
        </Property>
        <NavigationProperty Name="Metrics" Type="VolumeMetrics.VolumeMetrics" ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Description" String="A reference to the Metrics associated with this Volume"/>
          <Annotation Term="OData.LongDescription" String="A reference to the metrics associated with this volume."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="EndpointLinks" BaseType="Resource.OemObject">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <NavigationProperty Name="Zones" Type="Collection(Zone.Zone)">
          <Annotation Term="OData.AutoExpandReferences"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="An array of references to the Zone resources containing this endpoint."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property is a reference to the resources that the endpoint is associated with and references a resource of type Zone."/>
        </NavigationProperty>
        <NavigationProperty Name="Interfaces" Type="Collection(Resource.Resource)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Specifies the interfaces on which this transport is available."/>
          <Annotation Term="OData.LongDescription"
                      String="This property is an array of references to resources representing interface where this endpoint is available."/>
        </NavigationProperty>
      </ComplexType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_INTEL_RACK_SCALE_OEM_HPP */
