#ifndef PSME_REST_METADATA_EVENT_SERVICE_HPP
#define PSME_REST_METADATA_EVENT_SERVICE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string EventService_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Event.xml">
    <edmx:Include Namespace="Event.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EventDestinationCollection.xml">
    <edmx:Include Namespace="EventDestinationCollection"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EventService">

      <EntityType Name="EventService" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="The Event Service resource contains properties for managing event subcriptions and generates the events sent to subscribers.  The resource has links to the actual collection of subscriptions (called Event Destinations)."/>
      </EntityType>

      <Action Name="SubmitTestEvent" IsBound="true">
        <Annotation Term="OData.Description" String="This action is used to generate a test event."/>
        <Annotation Term="OData.LongDescription"
                    String="This action shall add a test event to the event service with the event data specified in the action parameters. This message should then be sent to any appropriate ListenerDestination targets."/>
        <Parameter Name="EventService" Type="EventService.v1_0_0.Actions"/>
        <Parameter Name="EventType" Type="Event.v1_0_0.EventType" Nullable="false">
          <Annotation Term="OData.Description" String="This is the type of event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This defines the property name for which the following allowable values apply."/>
        </Parameter>
        <Parameter Name="EventId" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description" String="This is the ID of event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This property has the same semantics as the EventId property in the Event schema for Redfish."/>
        </Parameter>
        <Parameter Name="EventTimestamp" Type="Edm.DateTimeOffset" Nullable="false">
          <Annotation Term="OData.Description" String="This is the time stamp of event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This property has the same semantics as the EventId property in the Event schema for Redfish."/>
        </Parameter>
        <Parameter Name="Severity" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description" String="This is the Severity of event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This property has the same semantics as the Severity property in the Event schema for Redfish."/>
        </Parameter>
        <Parameter Name="Message" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description" String="This is the human readable message of event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This property has the same semantics as the Message property in the Event schema for Redfish."/>
        </Parameter>
        <Parameter Name="MessageId" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description" String="This is the message ID of event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This property has the same semantics as the MessageId property in the Event schema for Redfish."/>
        </Parameter>
        <Parameter Name="MessageArgs" Type="Collection(Edm.String)" Nullable="false">
          <Annotation Term="OData.Description"
                      String="This is the array of message arguments of the event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This property has the same semantics as the MessageArgs property in the Event schema for Redfish."/>
        </Parameter>
        <Parameter Name="OriginOfCondition" Type="Edm.String" Nullable="false">
          <Annotation Term="OData.Description" String="This is the OriginOfCondition property of event to be added."/>
          <Annotation Term="OData.LongDescription"
                      String="This property has the same semantics as the OriginOfCondition property in the Event schema for Redfish."/>
        </Parameter>
      </Action>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EventService.v1_0_0">

      <!-- This schema defines an event service and its respective properties.-->
      <EntityType Name="EventService" BaseType="EventService.EventService">
        <Property Name="ServiceEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Description" String="This indicates whether this service is enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be a Boolean indicating whether the service is enabled."/>
        </Property>
        <Property Name="DeliveryRetryAttempts" Type="Edm.Int64" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is the number of attempts an event posting is retried before the subscription is terminated."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be the number of retries attempted for any given event to the subscription destination before the subscription is terminated."/>
        </Property>
        <Property Name="DeliveryRetryIntervalSeconds" Type="Edm.Int64" Nullable="false">
          <Annotation Term="Measures.Unit" String="s"/>
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This represents the number of seconds between retry attempts for sending any given Event"/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the interval in seconds between the retry attempts for any given event to the subscription destination."/>
        </Property>
        <Property Name="EventTypesForSubscription" Type="Collection(Event.v1_0_0.EventType)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="This is the types of Events that can be subscribed to."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall be the types of events that subscriptions can subscribe to. The semantics associated with the enumerations values are defined in the Redfish specification."/>
        </Property>
        <Property Name="Actions" Type="EventService.v1_0_0.Actions" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The available actions for this resource."/>
          <Annotation Term="OData.LongDescription"
                      String="The Actions property shall contain the available actions for the resource."/>
        </Property>
        <NavigationProperty Name="Subscriptions" Type="EventDestinationCollection.EventDestinationCollection"
                            ContainsTarget="true" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This is a reference to a collection of Event Destination resources."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of the property shall contain the link to a collection of type EventDestinationCollection."/>
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

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Oem" Type="EventService.v1_0_0.OemActions" Nullable="false"/>
      </ComplexType>

      <ComplexType Name="OemActions">
        <Annotation Term="OData.AdditionalProperties" Bool="true"/>
      </ComplexType>

    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="EventService.v1_0_2">
      <EntityType Name="EventService" BaseType="EventService.v1_0_0.EventService"/>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_EVENT_SERVICE_HPP */
