#ifndef PSME_REST_METADATA_RACK_LOCATION_HPP
#define PSME_REST_METADATA_RACK_LOCATION_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string RackLocation_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="RackLocation">
      <ComplexType Name="RackLocation">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="RackUnits" Type="RackLocation.RackLocationUnit"/>
        <Property Name="XLocation" Type="Edm.Int64"/>
        <Property Name="ULocation" Type="Edm.Int64"/>
        <Property Name="UHeight" Type="Edm.Int64"/>
      </ComplexType>

      <EnumType Name="RackLocationUnit">
        <Member Name="OU"/>
        <Member Name="AU"/>
      </EnumType>
    </Schema>

  </edmx:DataServices>
</edmx:Edmx>

)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_RACK_LOCATION_HPP */
