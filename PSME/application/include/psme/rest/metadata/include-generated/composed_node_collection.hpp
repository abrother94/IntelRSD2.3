#ifndef PSME_REST_METADATA_COMPOSED_NODE_COLLECTION_HPP
#define PSME_REST_METADATA_COMPOSED_NODE_COLLECTION_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string ComposedNodeCollection_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Resource.xml">
    <edmx:Include Namespace="Resource"/>
    <edmx:Include Namespace="Resource.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComposedNode.xml">
    <edmx:Include Namespace="ComposedNode.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Processor.xml">
    <edmx:Include Namespace="Processor.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Memory.xml">
    <edmx:Include Namespace="Memory.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/EthernetInterface.xml">
    <edmx:Include Namespace="EthernetInterface.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Chassis.xml">
    <edmx:Include Namespace="Chassis.v1_0_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/ComputerSystem.xml">
    <edmx:Include Namespace="ComputerSystem.v1_1_0"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Storage.xml">
    <edmx:Include Namespace="Storage.v1_0_0"/>
  </edmx:Reference>

  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="ComposedNodeCollection">
      <EntityType Name="ComposedNodeCollection" BaseType="Resource.v1_0_0.ResourceCollection">
        <NavigationProperty Name="Members" Type="Collection(ComposedNode.v1_0_0.ComposedNode)">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/Read"/>
          <Annotation Term="OData.Description" String="Contains the members of this collection."/>
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <Property Name="Actions" Type="ComposedNodeCollection.Actions" Nullable="false"/>
      </EntityType>

      <ComplexType Name="Actions">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
      </ComplexType>

      <Action Name="Allocate" IsBound="true">
        <Annotation Term="OData.Description" String="This action is used to allocate composed node."/>

        <Parameter Name="ComposedNodeCollection" Type="ComposedNodeCollection.Actions"/>
        <Parameter Name="Name" Type="Edm.String"/>
        <Parameter Name="Description" Type="Edm.String"/>
        <Parameter Name="Processors" Type="Collection(AllocationComposedNodeRequest.Processor)"/>
        <Parameter Name="Memory" Type="Collection(AllocationComposedNodeRequest.Memory)"/>
        <Parameter Name="RemoteDrives" Type="Collection(AllocationComposedNodeRequest.RemoteDrive)"/>
        <Parameter Name="LocalDrives" Type="Collection(AllocationComposedNodeRequest.LocalDrive)"/>
        <Parameter Name="NetworkInterfaces" Type="Collection(AllocationComposedNodeRequest.EthernetInterface)"/>
        <Parameter Name="TotalMemoryCapacityMiB" Type="Edm.Int64"/>
        <Parameter Name="TotalProcessorCoreCount" Type="Edm.Int64"/>
        <Parameter Name="Security" Type="AllocationComposedNodeRequest.Security"/>
      </Action>
    </Schema>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="AllocationComposedNodeRequest">
      <ComplexType Name="Processor">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Model" Type="Edm.String"/>
        <Property Name="TotalCores" Type="Edm.Int32"/>
        <Property Name="AchievableSpeedMHz" Type="Edm.Int32"/>
        <Property Name="InstructionSet" Type="Edm.String"/>
        <NavigationProperty Name="Resource" Type="Processor.v1_0_0.Processor">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Chassis" Type="Chassis.v1_0_0.Chassis">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Memory">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="CapacityMiB" Type="Edm.Int32"/>
        <Property Name="MemoryDeviceType" Type="Memory.v1_0_0.MemoryDeviceType"/>
        <Property Name="SpeedMHz" Type="Edm.Int64"/>
        <Property Name="Manufacturer" Type="Edm.String"/>
        <Property Name="DataWidthBits" Type="Edm.Int32"/>
        <NavigationProperty Name="Resource" Type="Memory.v1_0_0.Memory">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Chassis" Type="Chassis.v1_0_0.Chassis">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="EthernetInterface">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="SpeedMbps" Type="Edm.Int32"/>
        <Property Name="PrimaryVLAN" Type="Edm.Int32"/>
        <Property Name="VLANs" Type="Collection(AllocationComposedNodeRequest.VLAN)"/>

        <NavigationProperty Name="Resource" Type="EthernetInterface.v1_0_0.EthernetInterface">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Chassis" Type="Chassis.v1_0_0.Chassis">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="VLAN">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="VLANId" Type="Edm.Int32"/>
        <Property Name="Tagged" Type="Edm.Boolean"/>
      </ComplexType>

      <ComplexType Name="LocalDrive">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="CapacityGiB" Type="Edm.Decimal"/>
        <Property Name="FabricSwitch" Type="Edm.Boolean"/>
        <Property Name="Type" Type="Edm.String"/>
        <Property Name="MinRPM" Type="Edm.Int32"/>
        <Property Name="SerialNumber" Type="Edm.String"/>
        <Property Name="Interface" Type="Edm.String"/>

        <NavigationProperty Name="Resource" Type="Resource.Item">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
        <NavigationProperty Name="Chassis" Type="Chassis.v1_0_0.Chassis">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <ComplexType Name="Master">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="Type" Type="AllocationComposedNodeRequest.MasterType"/>
      </ComplexType>

      <ComplexType Name="RemoteDrive">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Property Name="CapacityGiB" Type="Edm.Decimal"/>
        <Property Name="Protocol" Type="Storage.v1_0_0.Protocol"/>
        <Property Name="Master" Type="AllocationComposedNodeRequest.Master"/>
        <NavigationProperty Name="Resource" Type="Resource.Resource">
          <Annotation Term="OData.AutoExpandReferences"/>
        </NavigationProperty>
      </ComplexType>

      <EnumType Name="AuthType">
        <Member Name="OneWay">
          <Annotation Term="OData.Description" String="Only initiator is authenticated."/>
        </Member>
        <Member Name="Mutual">
          <Annotation Term="OData.Description" String="Both initiator and target needs to be authenticated."/>
        </Member>
      </EnumType>

      <EnumType Name="MasterType">
        <Member Name="Clone">
          <Annotation Term="OData.Description" String="Volume should be cloned."/>
        </Member>
        <Member Name="Snapshot">
          <Annotation Term="OData.Description" String="Copy on Write should be created from indicated volume."/>
        </Member>
      </EnumType>
      <ComplexType Name="Security">
        <Annotation Term="OData.AdditionalProperties" Bool="false"/>
        <Annotation Term="OData.Description" String="Those are security requirements for composed node."/>
        <Annotation Term="OData.LongDescription" String="Those are security requirements for composed node."/>
        <Property Name="TpmPresent" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This is used to specify if composed node should have TPM module present."/>
          <Annotation Term="OData.LongDescription"
                      String="This is used to specify if composed node should have TPM module present."/>
        </Property>
        <Property Name="TpmInterfaceType" Type="ComputerSystem.v1_1_0.InterfaceType">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This is the used to specify requested TPM interface type. It overrides TpmPresent attribute."/>
          <Annotation Term="OData.LongDescription"
                      String="This is the used to specify requested TPM interface type. It overrides TpmPresent attribute."/>
        </Property>
        <Property Name="TxtEnabled" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This is used to specify if composed node should have TXT mode enabled."/>
          <Annotation Term="OData.LongDescription"
                      String="This is used to specify if composed node should have TXT mode enabled."/>
        </Property>
        <Property Name="ClearTPMOnDelete" Type="Edm.Boolean">
          <Annotation Term="OData.Permissions" EnumMember="OData.Permission/ReadWrite"/>
          <Annotation Term="OData.Description"
                      String="This is used to specify if TPM module should be cleared on composed node DELETE request."/>
          <Annotation Term="OData.LongDescription"
                      String="This is used to specify if TPM module should be cleared on composed node DELETE request."/>
        </Property>
      </ComplexType>
    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_COMPOSED_NODE_COLLECTION_HPP */
