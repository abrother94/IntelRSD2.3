#ifndef PSME_REST_METADATA_ORG_ODATA_COREV1_HPP
#define PSME_REST_METADATA_ORG_ODATA_COREV1_HPP

#include <string>

namespace psme {
namespace rest {
namespace metadata {

static const std::string OrgODataCoreV1_XML =
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
  - OData Core Vocabulary (this document)
  - OData Capabilities Vocabulary
  - OData Measures Vocabulary
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
  This document contains Core terms needed to write vocabularies.

-->
<edmx:Edmx xmlns:edmx="http://docs.oasis-open.org/odata/ns/edmx" Version="4.0">
  <edmx:DataServices>
    <Schema xmlns="http://docs.oasis-open.org/odata/ns/edm" Namespace="Org.OData.Core.V1" Alias="Core">
      <Annotation Term="Core.Description">
        <String>Core terms needed to write vocabularies</String>
      </Annotation>

      <!--Documentation -->

      <Term Name="Description" Type="Edm.String">
        <Annotation Term="Core.Description" String="A brief description of a model element" />
        <Annotation Term="Core.IsLanguageDependent" />
      </Term>

      <Term Name="LongDescription" Type="Edm.String">
        <Annotation Term="Core.Description" String="A lengthy description of a model element" />
        <Annotation Term="Core.IsLanguageDependent" />
      </Term>

      <!-- Localization -->

      <Term Name="IsLanguageDependent" Type="Core.Tag" DefaultValue="true" AppliesTo="Term Property">
        <Annotation Term="Core.Description" String="Properties and terms annotated with this term are language-dependent" />
        <Annotation Term="Core.RequiresType" String="Edm.String" />
      </Term>

      <!-- Term Restrictions -->

      <TypeDefinition Name="Tag" UnderlyingType="Edm.Boolean">
        <Annotation Term="Core.Description" String="This is the type to use for all tagging terms" />
      </TypeDefinition>

      <Term Name="RequiresType" Type="Edm.String" AppliesTo="Term">
        <Annotation Term="Core.Description"
          String="Terms annotated with this term can only be applied to elements that have a type that is identical to or derived from the given type name" />
      </Term>

      <!--Resource Paths -->

      <Term Name="ResourcePath" Type="Edm.String" AppliesTo="EntitySet Singleton ActionImport FunctionImport">
        <Annotation Term="Core.Description"
          String="Resource path for entity container child, can be relative to xml:base and the request URL" />
        <Annotation Term="Core.IsURL" />
      </Term>

      <Term Name="DereferenceableIDs" Type="Core.Tag" DefaultValue="true" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="Entity-ids are URLs that locate the identified entity" />
      </Term>

      <Term Name="ConventionalIDs" Type="Core.Tag" DefaultValue="true" AppliesTo="EntityContainer">
        <Annotation Term="Core.Description" String="Entity-ids follow OData URL conventions" />
      </Term>

      <!-- Permissions -->

      <Term Name="Permissions" Type="Core.Permission"
        AppliesTo="Property ComplexType TypeDefinition EntityType EntitySet NavigationProperty Action Function"
      >
        <Annotation Term="Core.Description" String="Permissions for accessing a resource" />
      </Term>
      <EnumType Name="Permission" IsFlags="true">
        <Member Name="None" Value="0" />
        <Member Name="Read" Value="1" />
        <Member Name="Write" Value="2" />
        <Member Name="ReadWrite" Value="3" />
        <Member Name="Invoke" Value="4" />
      </EnumType>

      <!-- Metadata Extensions -->

      <Term Name="Immutable" Type="Core.Tag" DefaultValue="true" AppliesTo="Property">
        <Annotation Term="Core.Description"
          String="A value for this non-key property can be provided on insert and remains unchanged on update" />
      </Term>

      <Term Name="Computed" Type="Core.Tag" DefaultValue="true" AppliesTo="Property">
        <Annotation Term="Core.Description" String="A value for this property is generated on both insert and update" />
      </Term>

      <Term Name="IsURL" Type="Core.Tag" DefaultValue="true" AppliesTo="Property Term">
        <Annotation Term="Core.Description" String="Properties and terms annotated with this term MUST contain a valid URL" />
        <Annotation Term="Core.RequiresType" String="Edm.String" />
      </Term>

      <Term Name="AcceptableMediaTypes" Type="Collection(Edm.String)" Nullable="false" AppliesTo="EntityType Property">
        <Annotation Term="Core.Description"
          String="Lists the MIME types acceptable for the annotated entity type marked with HasStream=&quot;true&quot; or the annotated stream property" />
        <Annotation Term="Core.IsMediaType" />
      </Term>

      <Term Name="MediaType" Type="Edm.String" AppliesTo="Property">
        <Annotation Term="Core.Description" String="The media type of a binary resource" />
        <Annotation Term="Core.IsMediaType" />
        <Annotation Term="Core.RequiresType" String="Edm.Binary" />
      </Term>

      <Term Name="IsMediaType" Type="Core.Tag" DefaultValue="true" AppliesTo="Property Term">
        <Annotation Term="Core.Description" String="Properties and terms annotated with this term MUST contain a valid MIME type" />
        <Annotation Term="Core.RequiresType" String="Edm.String" />
      </Term>

      <Term Name="OptimisticConcurrency" Type="Collection(Edm.PropertyPath)" Nullable="false" AppliesTo="EntitySet">
        <Annotation Term="Core.Description"
          String="Data modification requires the use of ETags. A non-empty collection contains the set of properties that are used to compute the ETag." />
      </Term>

      <Term Name="AdditionalProperties" Type="Core.Tag" DefaultValue="true" AppliesTo="EntityType ComplexType">
        <Annotation Term="Core.Description"
          String="Instances of this type may contain properties in addition to those declared in $metadata" />
        <Annotation Term="Core.LongDescription"
          String="If specified as false clients can assume that instances will not contain dynamic properties, irrespective of the value of the OpenType attribute." />
      </Term>

      <Term Name="AutoExpand" Type="Core.Tag" DefaultValue="true" AppliesTo="NavigationProperty">
        <Annotation Term="Core.Description"
          String="The service will automatically expand this navigation property even if not requested with $expand" />
      </Term>

      <Term Name="AutoExpandReferences" Type="Core.Tag" DefaultValue="true" AppliesTo="NavigationProperty">
        <Annotation Term="Core.Description"
          String="The service will automatically expand this navigation property as entity references even if not requested with $expand=.../$ref" />
      </Term>

    </Schema>
  </edmx:DataServices>
</edmx:Edmx>
)Xy+Z*aF--";

} /* metadata */
} /* rest */
} /* psme */


#endif /* PSME_REST_METADATA_ORG_ODATA_COREV1_HPP */
