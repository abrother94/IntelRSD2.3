#ifndef PSME_REST_METADATA_STORAGE_POOL_HPP
#define PSME_REST_METADATA_STORAGE_POOL_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string StoragePool_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Measures.V1.xml">
    <edmx:Include Namespace="Org.OData.Measures.V1" Alias="Measures" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource" />
    <edmx:Include Namespace="Resource.v1_0_0" />
    <edmx:Include Namespace="Resource.v1_1_0" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/RedfishExtensions.xml">
    <edmx:Include Namespace="RedfishExtensions.v1_0_0" Alias="Redfish" />
    <edmx:Include Namespace="Validation.v1_0_0" Alias="Validation" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/VolumeCollection.xml">
    <edmx:Include Namespace="VolumeCollection" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/StoragePoolCollection.xml">
    <edmx:Include Namespace="StoragePoolCollection" />
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Capacity.xml">
    <edmx:Include Namespace="Capacity.v1_0_0" />
  </edmx:Reference>
  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool">
      <EntityType Name="StoragePool" BaseType="Resource.v1_0_0.Resource" Abstract="true">
        <Annotation Term="OData.Description" String="A container of data storage." />
        <Annotation Term="OData.LongDescription"
        String="A container of data storage capable of providing capacity conforming to one of its supported classes of service. The storage pool does not support IO to its data storage." />
      </EntityType>
    </Schema>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="StoragePool.v1_0_0">
      <EntityType Name="StoragePool" BaseType="StoragePool.StoragePool">
        <Property Name="Identifier" Type="Resource.v1_1_0.Identifier">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite" />
          <Annotation Term="OData.Description" String="The value identifies this resource." />
          <Annotation Term="OData.LongDescription" String="The value identifies this resource. The value shall be unique in the managed ecosystem." />
        </Property>
        <Property Name="BlockSizeBytes" Type="Edm.Int64">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="Maximum Block size in bytes." />
          <Annotation Term="OData.LongDescription"
          String="Maximum size in bytes of the blocks that form the volume. If the block size is variable, the maximum block size in bytes should be specified. If the block size is unknown or if a block concept is not valid (for example, with Memory), enter 1." />
          <Annotation Term="Measures.Unit" String="By" />
          <Annotation Term="Validation.Minimum" Int="0"/>
        </Property>
        <Property Name="Capacity" Type="Capacity.v1_0_0.Capacity">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="Capacity utilization." />
          <Annotation Term="OData.LongDescription" String="The value of this property shall provide information about the actual utilization of the capacity within this storage pool." />
        </Property>
        <Property Name="CapacitySources" Type="Collection(Capacity.v1_0_0.CapacitySource)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="An array of space allocations to this store." />
          <Annotation Term="OData.LongDescription"
          String="Fully or partially consumed storage from a source resource. Each entry shall provide capacity allocation data from a named source resource." />
        </Property>
        <NavigationProperty Name="AllocatedVolumes" Type="VolumeCollection.VolumeCollection" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="A reference to the collection of volumes allocated from this storage pool." />
          <Annotation Term="OData.LongDescription" String="The value of the property shall contain a reference to the collection of volumes allocated from the storage pool." />
          <Annotation Term="OData.AutoExpandReferences" />
        </NavigationProperty>
        <NavigationProperty Name="AllocatedPools" Type="StoragePoolCollection.StoragePoolCollection" ContainsTarget="true">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="A reference to the collection of storage pools allocated from this storage pool." />
          <Annotation Term="OData.LongDescription"
          String="The value of the property shall contain a reference to the collection of storage pools allocated from the storage pool." />
          <Annotation Term="OData.AutoExpandReferences" />
        </NavigationProperty>
        <Property Name="Links" Type="StoragePool.v1_0_0.Links" Nullable="false">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="Contains links to other resources that are related to this resource." />
          <Annotation Term="OData.LongDescription" String="This structure shall contain references to resources that are not contained in the resource." />
        </Property>
        <Property Name="Status" Type="Resource.Status">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read" />
          <Annotation Term="OData.Description" String="Resource status." />
          <Annotation Term="OData.LongDescription" String="Resource status." />
        </Property>
      </EntityType>
      <ComplexType Name="Links" BaseType="Resource.Links">
      </ComplexType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_STORAGE_POOL_HPP */
