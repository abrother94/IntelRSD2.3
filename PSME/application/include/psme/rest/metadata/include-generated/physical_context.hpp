#ifndef PSME_REST_METADATA_PHYSICAL_CONTEXT_HPP
#define PSME_REST_METADATA_PHYSICAL_CONTEXT_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string PhysicalContext_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="PhysicalContext.v1_0_0">

      <!--Common PhysicalContext values for Power and Thermal Sensors-->
      <EnumType Name="PhysicalContext">
        <Member Name="Room">
          <Annotation Term="OData.Description" String="The room."/>
        </Member>
        <Member Name="Intake">
          <Annotation Term="OData.Description" String="The intake point of the chassis."/>
        </Member>
        <Member Name="Exhaust">
          <Annotation Term="OData.Description" String="The exhaust point of the chassis."/>
        </Member>
        <Member Name="Front">
          <Annotation Term="OData.Description" String="The front of the chassis."/>
        </Member>
        <Member Name="Back">
          <Annotation Term="OData.Description" String="The back of the chassis."/>
        </Member>
        <Member Name="Upper">
          <Annotation Term="OData.Description" String="The upper portion of the chassis."/>
        </Member>
        <Member Name="Lower">
          <Annotation Term="OData.Description" String="The lower portion of the chassis."/>
        </Member>
        <Member Name="CPU">
          <Annotation Term="OData.Description" String="A Processor (CPU)"/>
        </Member>
        <Member Name="GPU">
          <Annotation Term="OData.Description" String="A Graphics Processor (GPU)"/>
        </Member>
        <Member Name="Backplane">
          <Annotation Term="OData.Description" String="A backplane within the chassis."/>
        </Member>
        <Member Name="SystemBoard">
          <Annotation Term="OData.Description" String="The system board (PCB)"/>
        </Member>
        <Member Name="PowerSupply">
          <Annotation Term="OData.Description" String="A power supply."/>
        </Member>
        <Member Name="VoltageRegulator">
          <Annotation Term="OData.Description" String="A voltage regulator device."/>
        </Member>
        <Member Name="StorageDevice">
          <Annotation Term="OData.Description" String="A storage device."/>
        </Member>
        <Member Name="NetworkingDevice">
          <Annotation Term="OData.Description" String="A networking device."/>
        </Member>
        <Member Name="ComputeBay">
          <Annotation Term="OData.Description" String="Within a compute bay."/>
        </Member>
        <Member Name="StorageBay">
          <Annotation Term="OData.Description" String="Within a storage bay."/>
        </Member>
        <Member Name="NetworkBay">
          <Annotation Term="OData.Description" String="Within a networking bay."/>
        </Member>
        <Member Name="ExpansionBay">
          <Annotation Term="OData.Description" String="Within an expansion bay."/>
        </Member>
        <Member Name="PowerSupplyBay">
          <Annotation Term="OData.Description" String="Within a power supply bay."/>
        </Member>
      </EnumType>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_PHYSICAL_CONTEXT_HPP */
