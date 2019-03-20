#ifndef PSME_REST_METADATA_LOG_SERVICE_HPP
#define PSME_REST_METADATA_LOG_SERVICE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string LogService_XML =
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
  <edmx:Reference Uri="/redfish/v1/metadata/LogEntryCollection.xml">
    <edmx:Include Namespace="LogEntryCollection"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogService">

      <EntityType Name="LogService" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This resource contains properties for monitoring and configuring an event log service for the resource or service to which it is associated."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a log service for a Redfish implementation."/>
      </EntityType>

      <Action Name="ClearLog" IsBound="true">
        <Parameter Name="LogService" Type="LogService.v1_0_0.Actions"/>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogService.v1_0_0">

      <EntityType Name="LogService" BaseType="LogService.LogService">
        <Annotation Term="OData.Description"
                    String="This resource represents the log service for the resource or service to which it is associated."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a log service for a Redfish implementation."/>
        <Property Name="ServiceEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="This indicates whether this service is enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be a boolean indicating whether this service is enabled."/>
        </Property>
        <Property Name="MaxNumberOfRecords" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The maximum number of log entries this service can have."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the maximum numbers of LogEntry resources in the Entries collection for this service."/>
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="OverWritePolicy" Type="LogService.v1_0_0.OverWritePolicy" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="The overwrite policy for this service that takes place when the log is full."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate the policy of the log service when the MaxNumberOfRecords has been reached. Unknown indicates the log overwrite policy is unknown. WrapsWhenFull indicates that the log overwrites its entries with new entries when the log has reached its maximum capacity. NeverOverwrites indicates that the log never overwrites its entries by the new entries and ceases logging when the limit has been reached."/>
        </Property>
        <Property Name="DateTime" Type="Edm.DateTimeOffset">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="The current DateTime (with offset) for the log service, used to set or read time."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall represent the current DateTime value that the log service is using, with offset from UTC, in Redfish Timestamp format."/>
        </Property>
        <Property Name="DateTimeLocalOffset" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="The time offset from UTC that the DateTime property is set to in format: +06:00 ."/>
          <Annotation Term="OData.LongDescription"
                      String="The value is property shall represent the offset from UTC time that the current value of DataTime property contains."/>
          <Annotation Term="Validation.Pattern" String="([-+][0-1][0-9]:[0-5][0-9])"/>
        </Property>
        <NavigationProperty Name="Entries" Type="LogEntryCollection.LogEntryCollection" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="References to the log entry collection."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall reference a collection of resources of type LogEntry."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Actions" Type="LogService.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Actions property shall contain the available actions for this resource."/>
        </Property>
        <Property Name="Status" Type="Resource.Status"/>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Oem" Type="LogService.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
      </ComplexType>

      <EnumType Name="OverWritePolicy">
        <Member Name="Unknown">
          <Annotation Term="OData.Description" String="The overwrite policy is not known or is undefined."/>
        </Member>
        <Member Name="WrapsWhenFull">
          <Annotation Term="OData.Description"
                      String="When full, new entries to the Log will overwrite previous entries"/>
        </Member>
        <Member Name="NeverOverWrites">
          <Annotation Term="OData.Description" String="When full, new entries to the Log will be discarded."/>
        </Member>
      </EnumType>

    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="LogService.v1_0_2">
      <EntityType Name="LogService" BaseType="LogService.v1_0_0.LogService"/>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_LOG_SERVICE_HPP */
