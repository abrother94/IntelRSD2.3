#ifndef PSME_REST_METADATA_COMPUTER_SYSTEM_COLLECTION_HPP
#define PSME_REST_METADATA_COMPUTER_SYSTEM_COLLECTION_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string ComputerSystemCollection_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?><!-- Copyright 2014-2015 Distributed Management Task Force, Inc. (DMTF). All rights reserved.-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystem.xml">
    <edmx:Include Namespace="ComputerSystem"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComputerSystemCollection">

      <EntityType Name="ComputerSystemCollection" BaseType="Resource.v1_0_0.ResourceCollection">
        <NavigationProperty Name="Members" Type="Collection(ComputerSystem.ComputerSystem)" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Collection of ComputerSystems"/>
          <Annotation Term="OData.LongDescription" String="Collection of ComputerSystems."/>
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


#endif /* PSME_REST_METADATA_COMPUTER_SYSTEM_COLLECTION_HPP */