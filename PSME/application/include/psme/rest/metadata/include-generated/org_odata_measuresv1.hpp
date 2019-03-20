#ifndef PSME_REST_METADATA_ORG_ODATA_MEASURESV1_HPP
#define PSME_REST_METADATA_ORG_ODATA_MEASURESV1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string OrgODataMeasuresV1_XML =
R"Xy+Z*aF--(<?xml version="1.0" encoding="utf-8"?>
<!--
  Copyright (c) 2017 Intel Corporation

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

-->
<!--

  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements. See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership. The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License. You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied. See the License for the
  specific language governing permissions and limitations
  under the License.

-->
<!--

     OData Version 4.0 Plus Errata 02
     OASIS Standard incorporating Approved Errata 02
     30 October 2014
     Copyright (c) OASIS Open 2014. All Rights Reserved.
     Source: http://docs.oasis-open.org/odata/odata/v4.0/errata02/os/complete/vocabularies/
 
-->
<!--

Technical Committee:
  OASIS Open Data Protocol (OData) TC
  https://www.oasis-open.org/committees/odata

Chairs:
  - Barbara Hartel (barbara.hartel@sap.com), SAP AG
  - Ram Jeyaraman (Ram.Jeyaraman@microsoft.com), Microsoft

Editors:
  - Ralf Handl (ralf.handl@sap.com), SAP AG
  - Michael Pizzo (mikep@microsoft.com), Microsoft
  - Martin Zurmuehl (martin.zurmuehl@sap.com), SAP AG

Additional artifacts: 
  This CSDL document is one component of a Work Product which consists of:
  - OData Version 4.0 Part 1: Protocol
  - OData Version 4.0 Part 2: URL Conventions
  - OData Version 4.0 Part 3: Common Schema Definition Language (CSDL)
  - OData ABNF Construction Rules Version 4.0 
  - OData ABNF Test Cases
  - OData Core Vocabulary
  - OData Capabilities Vocabulary
  - OData Measures Vocabulary (this document)
  - OData Metadata Service Entity Model
  - OData EDMX XML Schema
  - OData EDM XML Schema

Related work:
  This work product is related to the following two Work Products, each of 
  which define alternate formats for OData payloads
  - OData Atom Format Version 4.0
  - OData JSON Format Version 4.0
  This specification replaces or supersedes:
  - None

Declared XML namespaces:
  - http://docs.oasis-open.org/odata/ns/edmx
  - http://docs.oasis-open.org/odata/ns/edm

Abstract:
  The Open Data Protocol (OData) enables the creation of REST-based data
  services, which allow resources, identified using Uniform Resource
  Identifiers (URLs) and defined in a data model, to be published and 
  edited by Web clients using simple HTTP messages. This document defines
  the URL syntax for requests and the serialization format for primitive 
  literals in request and response payloads.

Overview:
  This document contains terms describing monetary amounts and measured quantities.  

-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:Reference Uri="/redfish/v1/metadata/Org.OData.Core.V1.xml">
    <edmx:Include Alias="Core" Namespace="Org.OData.Core.V1"/>
  </edmx:Reference>
  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Org.OData.Measures.V1" Alias="Measures">
      <Annotation Term="Core.Description">
        <String>Terms describing monetary amounts and measured quantities</String>
      </Annotation>

      <Term Name="ISOCurrency" Type="Edm.String" AppliesTo="Property">
        <Annotation Term="Core.Description"
                    String="The currency for this monetary amount as an ISO 4217 currency code"/>
      </Term>

      <Term Name="Scale" Type="Edm.Byte" AppliesTo="Property">
        <Annotation Term="Core.Description"
                    String="The number of significant decimal places in the scale part (less than or equal to the number declared in the Scale facet)"/>
        <Annotation Term="Core.RequiresType" String="Edm.Decimal"/>
      </Term>

      <Term Name="Unit" Type="Edm.String" AppliesTo="Property">
        <Annotation Term="Core.Description"
                    String="The unit of measure for this measured quantity, e.g. cm for centimeters or % for percentages"/>
      </Term>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ORG_ODATA_MEASURESV1_HPP */