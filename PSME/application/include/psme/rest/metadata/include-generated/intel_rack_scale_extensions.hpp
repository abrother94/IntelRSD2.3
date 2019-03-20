#ifndef PSME_REST_METADATA_INTEL_RACK_SCALE_EXTENSIONS_HPP
#define PSME_REST_METADATA_INTEL_RACK_SCALE_EXTENSIONS_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string IntelRackScaleExtensions_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="UTF-8"?>
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">

  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Namespace="Org.OData.Core.V1" Alias="OData"/>
  </edmx:Reference>
  <edmx:Reference Uri="/redfish/v1/metadata/Settings.xml">
    <edmx:Include Namespace="Settings"/>
  </edmx:Reference>

  <edmx:DataServices>

    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="IntelRackScale.Extensions">
      <Term Name="Required" Type="Edm.Boolean" DefaultValue="true">
        <Annotation Term="OData.Description"
                    String="The term specifies that a property is required by Intel Rack Scale to be supported by services. Properties not annotated as required are optional."/>
      </Term>

      <Term Name="Nontrivial" Type="Edm.String" AppliesTo="Property">
        <Annotation Term="OData.Description"
                    String="The term shall be applied to a property in order to specify nontrivial preconditions, postconditions, side-effects or invariants that need to be satisfied."/>
      </Term>
    </Schema>


  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_INTEL_RACK_SCALE_EXTENSIONS_HPP */
