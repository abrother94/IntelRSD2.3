#ifndef PSME_REST_METADATA_POWER_HPP
#define PSME_REST_METADATA_POWER_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Power_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
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
    <edmx:Include Namespace="Resource.v1_1_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PhysicalContext.xml">
    <edmx:Include Namespace="PhysicalContext.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Redundancy.xml">
    <edmx:Include Namespace="Redundancy"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power">

      <EntityType Name="Power" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This is the schema definition for the Power Metrics.  It represents the properties for Power Consumption and Power Limiting."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a power metrics resource for a Redfish implementation."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_0">

      <EntityType Name="Power" BaseType="Power.Power">
        <NavigationProperty Name="PowerControl" Type="Collection(Power.v1_0_0.PowerControl)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This is the definition for power control function (power reading/limiting)."/>
          <Annotation Term="OData.LongDescription"
                      String="These properties shall be the definition for power control (power reading and limiting) for a Redfish implementation."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="Voltages" Type="Collection(Power.v1_0_0.Voltage)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the definition for voltage sensors."/>
          <Annotation Term="OData.LongDescription"
                      String="These properties shall be the definition for voltage sensors for a Redfish implementation."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="PowerSupplies" Type="Collection(Power.v1_0_0.PowerSupply)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="Details of the power supplies associated with this system or device"/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain details of the power supplies associated with this system or device"/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Redundancy information for the power subsystem of this system or device"/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
      </EntityType>

      <EntityType Name="PowerControl" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Power Control Function name."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name of the Voltage sensor."/>
        </Property>
        <Property Name="PowerConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The actual power being consumed by the chassis."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the actual power being consumed (in Watts) by the chassis."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerRequestedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The potential power that the chassis resources are requesting which may be higher than the current level being consumed since requested power includes budget that the chassis resource wants for future use."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the amount of power (in Watts) that the chassis resource is currently requesting be budgeted to it for future use."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerAvailableWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The amount of power not already budgeted and therefore available for additional allocation. (powerCapacity - powerAllocated).  This indicates how much reserve power capacity is left."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the amount of power capacity (in Watts) not already allocated and shall equal PowerCapacityWatts - PowerAllocatedWatts."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerCapacityWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The total amount of power available to the chassis for allocation. This may the power supply capacity, or power budget assigned to the chassis from an up-stream chassis."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the total power capacity that is available for allocation to the chassis resources."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerAllocatedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The total amount of power that has been allocated (or budegeted)to  chassis resources."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the total power currently allocated to chassis resources."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
          <Annotation Term="Measures.Unit" String="W"/>
        </Property>
        <Property Name="PowerMetrics" Type="Power.v1_0_0.PowerMetric" Nullable="false">
          <Annotation Term="OData.Description" String="Power readings for this chassis."/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain power metrics for power readings (interval, min/max/ave power consumption) for the chassis."/>
        </Property>
        <Property Name="PowerLimit" Type="Power.v1_0_0.PowerLimit" Nullable="false">
          <Annotation Term="OData.Description"
                      String="Power limit status and configuration information for this chassis"/>
          <Annotation Term="OData.LongDescription"
                      String="This object shall contain power limit status and configuration information for this chassis"/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)" Nullable="false">
          <Annotation Term="OData.Description" String="The ID(s) of the resources associated with this Power Limit."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that is being limited."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <ComplexType Name="PowerMetric">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="IntervalInMin" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The time interval (or window) in which the PowerMetrics are measured over."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the time interval (or window), in minutes, in which the PowerMetrics properties are measured over."/>
          <Annotation Term="Measures.Unit" String="min"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="MinConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The lowest power consumption level over the measurement window (the last IntervalInMin minutes)."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the minimum power level in watts that occured within the last IntervalInMin minutes."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="MaxConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The highest power consumption level that has occured over the measurement window (the last IntervalInMin minutes)."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the maximum power level in watts that occured within the last IntervalInMin minutes."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="AverageConsumedWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The average power level over the measurement window (the last IntervalInMin minutes)."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the average power level that occured averaged over the last IntervalInMin minutes."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
      </ComplexType>

      <ComplexType Name="PowerLimit">
        <Annotation Term="OData.Description"
                    String="This object contains power limit status and configuration information for the chassis."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="LimitInWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Description"
                      String="The Power limit in watts. Set to null to disable power capping."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the power cap limit in watts for the resource.  If set to null, power capping shall be disabled."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="LimitException" Type="Power.v1_0_0.PowerLimitException">
          <Annotation Term="OData.Description"
                      String="The action that is taken if the power cannot be maintained below the LimitInWatts."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the action to be taken if the resource power consumption can not be limited below the specified limit after several correction time periods."/>
        </Property>
        <Property Name="CorrectionInMs" Type="Edm.Int64">
          <Annotation Term="OData.Description"
                      String="The time required for the limiting process to reduce power consumption to below the limit."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the time interval in ms required for the limiting process to react and reduce the power consumption below the limit."/>
          <Annotation Term="Measures.Unit" String="ms"/>
        </Property>
      </ComplexType>

      <EnumType Name="PowerLimitException">
        <Member Name="NoAction">
          <Annotation Term="OData.Description" String="Take no action when the limit is exceeded."/>
        </Member>
        <Member Name="HardPowerOff">
          <Annotation Term="OData.Description" String="Turn the power off immediately when the limit is exceeded."/>
        </Member>
        <Member Name="LogEventOnly">
          <Annotation Term="OData.Description"
                      String="Log an event when the limit is exceeded, but take no further action."/>
        </Member>
        <Member Name="Oem">
          <Annotation Term="OData.Description" String="Take an OEM-defined action."/>
        </Member>
      </EnumType>

      <EntityType Name="Voltage" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Voltage sensor name."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name of the Voltage sensor."/>
        </Property>
        <Property Name="SensorNumber" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A numerical identifier to represent the voltage sensor."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a numerical identifier for this voltage sensor that is unique within this resource. "/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
        <Property Name="ReadingVolts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The current value of the voltage sensor."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the current value of the voltage sensor's reading."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="UpperThresholdNonCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the CurrentReading is above the normal range but is not critical. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="UpperThresholdCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the CurrentReading is above the normal range but is not yet fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="UpperThresholdFatal" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range and is fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the CurrentReading is above the normal range and is fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="LowerThresholdNonCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the CurrentReading is below the normal range but is not critical. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="LowerThresholdCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the CurrentReading is below the normal range but is not yet fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="LowerThresholdFatal" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range and is fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the CurrentReading is below the normal range and is fatal. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MinReadingRange" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Minimum value for CurrentReading."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the lowest possible value for CurrentReading. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MaxReadingRange" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Maximum value for CurrentReading."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the highest possible value for CurrentReading. Units shall use the same units as the related ReadingVolts propoerty."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="PhysicalContext" Type="PhysicalContext.v1_0_0.PhysicalContext" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Describes the area or device to which this voltage measurement applies."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a description of the affected device or region within the chassis to which this voltage measurement applies."/>
        </Property>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Describes the areas or devices to which this voltage measurement applies."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the areas or devices to which this voltage measurement applies."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <EntityType Name="PowerSupply" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Annotation Term="OData.Description"
                    String="Details of a power supplies associated with this system or device"/>
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The name of the Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain a descriptive name for the associated power supply."/>
        </Property>
        <Property Name="PowerSupplyType" Type="Power.v1_0_0.PowerSupplyType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Power Supply type (AC or DC)"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the input power type (AC or DC) of the associated power supply."/>
        </Property>
        <Property Name="LineInputVoltageType" Type="Power.v1_0_0.LineInputVoltageType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The line voltage type supported as an input to this Power Supply"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the type of input line voltage supported by the associated power supply"/>
        </Property>
        <Property Name="LineInputVoltage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The line input voltage at which the Power Supply is operating."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the value in Volts of the line input voltage (measured or configured for) that the power supply has been configured to operate with or is currently receiving."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="PowerCapacityWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum capacity of this Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contiain the maximum amount of power, in Watts, that the associated power supply is rated to deliver."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="LastPowerOutputWatts" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The average power output of this Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the average power output, measured in Watts, of the associated power supply."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Model" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The model number for this Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the model information as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="FirmwareVersion" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The firmware version for this Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the firwmare version as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="SerialNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The serial number for this Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the serial number as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="PartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The part number for this Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the part number as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="SparePartNumber" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The spare part number for this Power Supply."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the spare or replacement part number as defined by the manufacturer for the associated power supply."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)" Nullable="false">
          <Annotation Term="OData.Description" String="The ID(s) of the resources associated with this Power Limit."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that is being limited."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This structure is used to show redundancy for power supplies.  The Component ids will reference the members of the redundancy groups."/>
          <Annotation Term="OData.LongDescription"
                      String="The values of the properties in this array shall be used to show redundancy for power supplies and other elements in this resource.  The use of IDs within these arrays shall reference the members of the redundancy groups."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
      </EntityType>

      <EnumType Name="PowerSupplyType">
        <Member Name="Unknown">
          <Annotation Term="OData.Description" String="The power supply type cannot be determined."/>
        </Member>
        <Member Name="AC">
          <Annotation Term="OData.Description" String="Alternating Current (AC) power supply."/>
        </Member>
        <Member Name="DC">
          <Annotation Term="OData.Description" String="Direct Current (DC) power supply."/>
        </Member>
        <Member Name="ACorDC">
          <Annotation Term="OData.Description" String="Power Supply supports both DC or AC."/>
        </Member>
      </EnumType>

      <EnumType Name="LineInputVoltageType">
        <Member Name="Unknown">
          <Annotation Term="OData.Description" String="The power supply line input voltage type cannot be determined."/>
        </Member>
        <Member Name="ACLowLine">
          <Annotation Term="OData.Description" String="100-127V AC input. Deprecated: Use AC120V."/>
        </Member>
        <Member Name="ACMidLine">
          <Annotation Term="OData.Description" String="200-240V AC input. Deprecated: Use AC240V."/>
        </Member>
        <Member Name="ACHighLine">
          <Annotation Term="OData.Description" String="277V AC input. Deprecated: Use AC277V."/>
        </Member>
        <Member Name="DCNeg48V">
          <Annotation Term="OData.Description" String="-48V DC input."/>
        </Member>
        <Member Name="DC380V">
          <Annotation Term="OData.Description" String="High Voltage DC input (380V)"/>
        </Member>
        <Member Name="AC120V">
          <Annotation Term="OData.Description" String="AC 120V nominal input."/>
        </Member>
        <Member Name="AC240V">
          <Annotation Term="OData.Description" String="AC 240V nominal input."/>
        </Member>
        <Member Name="AC277V">
          <Annotation Term="OData.Description" String="AC 277V nominal input."/>
        </Member>
        <Member Name="ACandDCWideRange">
          <Annotation Term="OData.Description" String="Wide range AC or DC input."/>
        </Member>
        <Member Name="ACWideRange">
          <Annotation Term="OData.Description" String="Wide range AC input."/>
        </Member>
        <Member Name="DC240V">
          <Annotation Term="OData.Description" String="DC 240V nominal input."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_1">

      <EntityType Name="Power" BaseType="Power.v1_0_0.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_0_2">
      <EntityType Name="Power" BaseType="Power.v1_0_1.Power"/>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_0">
      <EntityType Name="Power" BaseType="Power.v1_0_2.Power"/>
      <EntityType Name="PowerSupply" BaseType="Power.v1_0_0.PowerSupply">
        <Property Name="Manufacturer" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the manufacturer of this power supply."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name of the organization responsible for producing the power supply. This organization might be the entity from whom the power supply is purchased, but this is not necessarily true."/>
        </Property>
        <Property Name="InputRanges" Type="Collection(Power.v1_1_0.InputRange)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the input ranges that the power supply can use."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a collection of ranges usable by the power supply unit."/>
        </Property>
      </EntityType>
      <ComplexType Name="InputRange">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="InputType" Type="Power.v1_1_0.InputType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The Input type (AC or DC)"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the input type (AC or DC) of the associated range."/>
        </Property>
        <Property Name="MinimumVoltage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The minimum line input voltage at which this power supply input range is effective"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the value in Volts of the minimum line input voltage which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MaximumVoltage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The maximum line input voltage at which this power supply input range is effective"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the value in Volts of the maximum line input voltage which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="V"/>
        </Property>
        <Property Name="MinimumFrequencyHz" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The minimum line input frequency at which this power supply input range is effective"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the value in Hertz of the minimum line input frequency which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="Hz"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="MaximumFrequencyHz" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The maximum line input frequency at which this power supply input range is effective"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the value in Hertz of the maximum line input frequency which the power supply is capable of consuming for this range."/>
          <Annotation Term="Measures.Unit" String="Hz"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="OutputWattage" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The maximum capacity of this Power Supply when operating in this input range"/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contiain the maximum amount of power, in Watts, that the associated power supply is rated to deliver while operating in this input range."/>
          <Annotation Term="Measures.Unit" String="W"/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Oem" Type="Resource.Oem" Nullable="false"/>
      </ComplexType>
      <EnumType Name="InputType">
        <Member Name="AC">
          <Annotation Term="OData.Description" String="Alternating Current (AC) input range."/>
        </Member>
        <Member Name="DC">
          <Annotation Term="OData.Description" String="Direct Current (DC) input range."/>
        </Member>
      </EnumType>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_1_1">
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity." />
      <EntityType Name="Power" BaseType="Power.v1_1_0.Power" />
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_0">
      <EntityType Name="Power" BaseType="Power.v1_1_0.Power" />
      <EntityType Name="PowerSupply" BaseType="Power.v1_1_0.PowerSupply">
        <Property Name="IndicatorLED" Type="Resource.v1_1_0.IndicatorLED">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite" />
          <Annotation Term="OData.Description" String="The state of the indicator LED, used to identify the power supply." />
          <Annotation Term="OData.LongDescription" String="The value of this property shall contain the indicator light state for the indicator light associated with this power supply." />
        </Property>
      </EntityType>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Power.v1_2_1">
      <Annotation Term="OData.Description" String="This version was created to add explicit Permissions annotations to all properties for clarity." />
      <EntityType Name="Power" BaseType="Power.v1_2_0.Power" />
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>

)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_POWER_HPP */
