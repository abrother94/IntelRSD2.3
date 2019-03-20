#ifndef PSME_REST_METADATA_DRIVE_COLLECTION_HPP
#define PSME_REST_METADATA_DRIVE_COLLECTION_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string DriveCollection_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource" />
    <edmx:Include Namespace="Resource.v1_0_0" />
    <edmx:Include Namespace="Resource.v1_1_0" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Drive.xml">
    <edmx:Include Namespace="Drive"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="DriveCollection">
      <EntityType Name="DriveCollection" BaseType="Resource.v1_0_0.ResourceCollection">
        <Annotation Term="OData.Description" String="A Collection of Drive resource instances."/>
        <Annotation Term="OData.LongDescription" String="An instance of this resource shall reference the set of Drive resources known in the scope of its use."/>
        <NavigationProperty Name="Members" Type="Collection(Drive.Drive)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains the members of this drive collection."/>
          <Annotation Term="OData.LongDescription" String="The value of each entry of this property shall reference a drive resource."/>
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


#endif /* PSME_REST_METADATA_DRIVE_COLLECTION_HPP */
