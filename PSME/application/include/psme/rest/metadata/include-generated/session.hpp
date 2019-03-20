#ifndef PSME_REST_METADATA_SESSION_HPP
#define PSME_REST_METADATA_SESSION_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Session_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/LogEntry.xml">
    <edmx:Include Namespace="LogEntry"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Session">

      <EntityType Name="Session" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="The Session resource describes a single connection (session) between a client and a Redfish service instance."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent a session for a Redfish implementation."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Session.v1_0_0">

      <EntityType Name="Session" BaseType="Session.Session">
        <Property Name="UserName" Type="Edm.String">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Description" String="The UserName for the account for this session."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the UserName that matches a registered account identified by a ManagerAccount resource registered with the Account Service."/>
        </Property>
        <Property Name="Password" Type="Edm.String">
          <Annotation Term="Redfish.RequiredOnCreate"/>
          <Annotation Term="OData.Description"
                      String="This property is used in a POST to specify a password when creating a new session.  This property is null on a GET."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the password for this session.  The value shall be null for GET requests."/>
        </Property>
      </EntityType>

    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Session.v1_0_2">
      <EntityType Name="Session" BaseType="Session.v1_0_0.Session"/>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_SESSION_HPP */
