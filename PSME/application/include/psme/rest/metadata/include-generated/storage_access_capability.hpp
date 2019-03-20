#ifndef PSME_REST_METADATA_STORAGE_ACCESS_CAPABILITY_HPP
#define PSME_REST_METADATA_STORAGE_ACCESS_CAPABILITY_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string StorageAccessCapability_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish"/>
  </edmx:Reference>
  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StorageAccessCapability.v1_0_0">
      <EnumType Name="StorageAccessCapability">
        <Annotation Term="OData.Description" String="Values of StorageAccessCapability describe abilities to read or write storage."/>
        <Annotation Term="OData.LongDescription" String="StorageAccessCapability enumeration literals may be used to describe abilities to read or write storage."/>
        <Member Name="Read">
          <Annotation Term="OData.Description" String="Read."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the storage may be read."/>
        </Member>
        <Member Name="Write">
          <Annotation Term="OData.Description" String="Write Many."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the storage may be written multiple times."/>
        </Member>
        <Member Name="WriteOnce">
          <Annotation Term="OData.Description" String="WriteOnce."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the storage may be written only once."/>
        </Member>
        <Member Name="Append">
          <Annotation Term="OData.Description" String="AppendOnly."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the storage may be written only to append."/>
        </Member>
        <Member Name="Streaming">
          <Annotation Term="OData.Description" String="Streaming."/>
          <Annotation Term="OData.LongDescription" String="This enumeration literal shall indicate that the storage may be read sequentially."/>
        </Member>
      </EnumType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_STORAGE_ACCESS_CAPABILITY_HPP */
