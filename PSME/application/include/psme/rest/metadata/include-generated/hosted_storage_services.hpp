#ifndef PSME_REST_METADATA_HOSTED_STORAGE_SERVICES_HPP
#define PSME_REST_METADATA_HOSTED_STORAGE_SERVICES_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string HostedStorageServices_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StorageService.xml">
    <edmx:Include Namespace="StorageService.v1_0_0" Alias="StorageService"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="HostedStorageServices">

      <EntityType Name="HostedStorageServices" BaseType="Resource.v1_0_0.ResourceCollection">
        <Annotation Term="OData.Description" String="A Collection of Hosted Storage Service resource instances."/>
        <NavigationProperty Name="Members" Type="Collection(StorageService.StorageService)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description" String="The value of each member references a StorageService resource."/>
          <Annotation Term="OData.LongDescription" String="The value of each member entry shall reference a StorageService resource."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </EntityType>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_HOSTED_STORAGE_SERVICES_HPP */
