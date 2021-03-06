#ifndef PSME_REST_METADATA_THERMAL_HPP
#define PSME_REST_METADATA_THERMAL_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Thermal_XML =
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
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/PhysicalContext.xml">
    <edmx:Include Namespace="PhysicalContext.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Redundancy.xml">
    <edmx:Include Namespace="Redundancy"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Thermal">

      <EntityType Name="Thermal" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This is the schema definition for the Thermal properties.  It represents the properties for Temperature and Cooling."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a thermal metrics resource for a Redfish implementation."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Thermal.v1_0_0">

      <EntityType Name="Thermal" BaseType="Thermal.Thermal">
        <NavigationProperty Name="Temperatures" Type="Collection(Thermal.v1_0_0.Temperature)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the definition for temperature sensors."/>
          <Annotation Term="OData.LongDescription"
                      String="These properties shall be the definition for temperature sensors for a Redfish implementation."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="Fans" Type="Collection(Thermal.v1_0_0.Fan)" Nullable="false" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="This is the definition for fans."/>
          <Annotation Term="OData.LongDescription"
                      String="These properties shall be the definition for fans for a Redfish implementation."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This structure is used to show redundancy for fans.  The Component ids will reference the members of the redundancy groups."/>
          <Annotation Term="OData.LongDescription"
                      String="The values of the properties in this array shall be used to show redundancy for fans and other elements in this resource.  The use of IDs within these arrays shall reference the members of the redundancy groups."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
      </EntityType>

      <EntityType Name="Temperature" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Temperature sensor name."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the name of the temperature sensor."/>
        </Property>
        <Property Name="SensorNumber" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="A numerical identifier to represent the temperature sensor."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a numerical identifier for this temperature sensor that is unique within this resource. "/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
        <Property Name="ReadingCelsius" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Temperature."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the current value of the temperature sensor's reading."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="UpperThresholdNonCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the ReadingCelsius is above the normal range but is not critical. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="UpperThresholdCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the ReadingCelsius is above the normal range but is not yet fatal. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="UpperThresholdFatal" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range and is fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the ReadingCelsius is above the normal range and is fatal. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="LowerThresholdNonCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the ReadingCelsius is below the normal range but is not critical. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="LowerThresholdCritical" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the ReadingCelsius is below the normal range but is not yet fatal. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="LowerThresholdFatal" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range and is fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the ReadingCelsius is below the normal range and is fatal. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="MinReadingRangeTemp" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Minimum value for ReadingCelsius."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the lowest possible value for ReadingCelsius. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="MaxReadingRangeTemp" Type="Edm.Decimal">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Maximum value for ReadingCelsius."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the highest possible value for ReadingCelsius. The units shall be the same units as the related ReadingCelsius property."/>
          <Annotation Term="Measures.Unit" String="Cel"/>
        </Property>
        <Property Name="PhysicalContext" Type="PhysicalContext.v1_0_0.PhysicalContext" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Describes the area or device to which this temperature measurement applies."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a description of the affected device or region within the chassis to which this temperature measurement applies."/>
        </Property>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="Describes the areas or devices to which this temperature measurement applies."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall the array of IDs of areas or devices to which this temperature measurement applies."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

      <EntityType Name="Fan" BaseType="Resource.v1_0_0.ReferenceableMember">
        <Property Name="FanName" Type="Edm.String">
          <Annotation Term="Redfish.Deprecated"
                      String="This property has been Deprecated in favor of Thermal.v1_1_0.Thermal.Fan.Name"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Name of the fan."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the fan."/>
        </Property>
        <Property Name="PhysicalContext" Type="PhysicalContext.v1_0_0.PhysicalContext" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Describes the area or device associated with this fan."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a description of the affected device or region within the chassis to which this fan is associated."/>
        </Property>
        <Property Name="Status" Type="Resource.Status" Nullable="false"/>
        <Property Name="Reading" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Current fan speed."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the current value of the fan sensor's reading."/>
        </Property>
        <Property Name="UpperThresholdNonCritical" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the Reading is above the normal range but is not critical. The units shall be the same units as the related Reading property."/>
        </Property>
        <Property Name="UpperThresholdCritical" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the Reading is above the normal range but is not yet fatal. The units shall be the same units as the related Reading property."/>
        </Property>
        <Property Name="UpperThresholdFatal" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Above normal range and is fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the Reading is above the normal range and is fatal. The units shall be the same units as the related Reading property."/>
        </Property>
        <Property Name="LowerThresholdNonCritical" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the Reading is below the normal range but is not critical. The units shall be the same units as the related Reading property."/>
        </Property>
        <Property Name="LowerThresholdCritical" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range but not yet fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the Reading is below the normal range but is not yet fatal. The units shall be the same units as the related Reading property."/>
        </Property>
        <Property Name="LowerThresholdFatal" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Below normal range and is fatal."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the Reading is below the normal range and is fatal. The units shall be the same units as the related Reading property."/>
        </Property>
        <Property Name="MinReadingRange" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Minimum value for Reading."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the lowest possible value for Reading. The units shall be the same units as the related Reading property."/>
        </Property>
        <Property Name="MaxReadingRange" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Maximum value for Reading."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the highest possible value for Reading. The units shall be the same units as the related Reading property."/>
        </Property>
        <NavigationProperty Name="RelatedItem" Type="Collection(Resource.Item)" Nullable="false">
          <Annotation Term="OData.Description" String="The ID(s) of the resources serviced with this fan."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be an array of IDs containing pointers consistent with JSON pointer syntax to the resource that are being serviced by this fan."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Redundancy" Type="Collection(Redundancy.Redundancy)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This structure is used to show redundancy for fans.  The Component ids will reference the members of the redundancy groups."/>
          <Annotation Term="OData.LongDescription"
                      String="The values of the properties in this array shall be used to show redundancy for fans and other elements in this resource.  The use of IDs within these arrays shall reference the members of the redundancy groups."/>
          <Annotation Term="OData.AutoExpand"/>
        </NavigationProperty>
      </EntityType>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Thermal.v1_0_1">
      <EntityType Name="Thermal" BaseType="Thermal.v1_0_0.Thermal"/>
      <EntityType Name="Fan" BaseType="Thermal.v1_0_0.Fan">
        <Property Name="ReadingUnits" Type="Thermal.v1_0_1.ReadingUnits">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Units in which the reading and thresholds are measured."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the units in which the fan's reading and thresholds are measured."/>
        </Property>
      </EntityType>

      <EnumType Name="ReadingUnits">
        <Member Name="RPM">
          <Annotation Term="OData.Description"
                      String="Indicates that the fan reading and thresholds are measured in rotations per minute."/>
        </Member>
        <Member Name="Percent">
          <Annotation Term="OData.Description"
                      String="Indicates that the fan reading and thresholds are measured in percentage."/>
        </Member>
      </EnumType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Thermal.v1_0_2">
      <EntityType Name="Thermal" BaseType="Thermal.v1_0_1.Thermal"/>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Thermal.v1_1_0">
      <EntityType Name="Thermal" BaseType="Thermal.v1_0_2.Thermal"/>
      <EntityType Name="Fan" BaseType="Thermal.v1_0_1.Fan">
        <Property Name="Name" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Name of the fan."/>
          <Annotation Term="OData.LongDescription" String="The value of this property shall be the name of the fan."/>
        </Property>
      </EntityType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_THERMAL_HPP */
