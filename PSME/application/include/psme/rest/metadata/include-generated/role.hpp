#ifndef PSME_REST_METADATA_ROLE_HPP
#define PSME_REST_METADATA_ROLE_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Role_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Privileges.xml">
    <edmx:Include Namespace="Privileges.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Role">

      <EntityType Name="Role" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="This schema defines a user role to be used in conjunction with a manager account."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent resources that represent the user role for the user account."/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Role.v1_0_0">

      <EntityType Name="Role" BaseType="Role.Role">
        <Annotation Term="OData.Description"
                    String="This resource defines a user role to be used in conjunction with a Manager Account."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent resources that represent the user role for the user account."/>
        <Property Name="IsPredefined" Type="Edm.Boolean" Nullable="false" DefaultValue="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description"
                      String="This property is used to indicate if the Role is one of the Redfish Predefined Roles vs a Custom role."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall indicate if the role is a predefined role. ."/>
        </Property>
        <Property Name="AssignedPrivileges" Type="Collection(Privileges.v1_0_0.PrivilegeType)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The redfish privileges that this role includes."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the redfish privileges that the role includes. For pre-defined roles, this property shall be readOnly. For custom roles some implementations may not allow writing this property."/>
        </Property>
        <Property Name="OemPrivileges" Type="Collection(Edm.String)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The OEM privileges that this role includes."/>
          <Annotation Term="OData.LongDescription"
                      String="The value of this property shall be the OEM privileges that this role includes. For pre-defined roles, this property shall be readOnly. For custom roles some implementations may not allow writing this property."/>
        </Property>
      </EntityType>

    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Role.v1_0_2">
      <EntityType Name="Role" BaseType="Role.v1_0_0.Role"/>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ROLE_HPP */
