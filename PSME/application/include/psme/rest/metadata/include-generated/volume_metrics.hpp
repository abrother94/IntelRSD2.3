#ifndef PSME_REST_METADATA_VOLUME_METRICS_HPP
#define PSME_REST_METADATA_VOLUME_METRICS_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string VolumeMetrics_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VolumeMetrics">

      <EntityType Name="VolumeMetrics" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description"
                    String="VolumeMetrics contains usage and health statistics for a single Volume resource."/>
        <Annotation Term="OData.LongDescription"
                    String="This resource shall be used to represent the Volume Metrics for a single Volume resource in a Redfish implementation."/>
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
      </EntityType>

    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="VolumeMetrics.v1_0_0">

      <EntityType Name="VolumeMetrics" BaseType="VolumeMetrics.VolumeMetrics">
        <Property Name="CapacityUsedBytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="The size in bytes of this Volume's Capacity used for storing files."/>
          <Annotation Term="OData.LongDescription"
                      String="This property shall contain the size in bytes of the volume's capacity used for storing files."/>
          <Annotation Term="Measures.Unit" String="By"/>
        </Property>
      </EntityType>

    </Schema>

  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_VOLUME_METRICS_HPP */
