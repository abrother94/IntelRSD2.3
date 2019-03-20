#ifndef PSME_REST_METADATA_PRIVILEGES_HPP
#define PSME_REST_METADATA_PRIVILEGES_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string Privileges_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Privileges.v1_0_0">

      <EnumType Name="PrivilegeType">
        <Member Name="Login">
          <Annotation Term="OData.Description" String="Able to log into the service and read resources."/>
        </Member>
        <Member Name="ConfigureManager">
          <Annotation Term="OData.Description" String="Able to configure Manager resources."/>
        </Member>
        <Member Name="ConfigureUsers">
          <Annotation Term="OData.Description" String="Able to configure Users and their Accounts."/>
        </Member>
        <Member Name="ConfigureSelf">
          <Annotation Term="OData.Description" String="Able to change the password for the current user Account."/>
        </Member>
        <Member Name="ConfigureComponents">
          <Annotation Term="OData.Description" String="Able to configure components managed by this service."/>
        </Member>
      </EnumType>

      <Term Name="OemGetPrivileges" Type="Collection(Edm.String)" Nullable="false">
        <Annotation Term="OData.Description"
                    String="OEM Get operations privileges may be defined on a Link element to provide read privileges for the referenced resources, or on individual elements to override the privileges for that element"/>
      </Term>
      <Term Name="OemPostPrivileges" Type="Collection(Edm.String)" Nullable="false">
        <Annotation Term="OData.Description"
                    String="OEM Post privileges may be defined on a Link element to provide create privileges for the referenced resources, or on individual elements to override the privileges for that element"/>
      </Term>
      <Term Name="OemPatchPutPrivileges" Type="Collection(Edm.String)" Nullable="false">
        <Annotation Term="OData.Description"
                    String="OEM PatchPut privileges may be defined on a Link element to provide update privileges for the referenced resources, or on individual elements to override the privileges for that element"/>
      </Term>
      <Term Name="OemDeletePrivileges" Type="Collection(Edm.String)" Nullable="false">
        <Annotation Term="OData.Description"
                    String="OEM Delete privileges may be defined on a Link element to provide update privileges for the referenced resources, or on individual elements to override the privileges for that element"/>
      </Term>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_PRIVILEGES_HPP */
