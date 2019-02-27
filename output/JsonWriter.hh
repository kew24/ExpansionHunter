//
// Expansion Hunter
// Copyright 2016-2019 Illumina, Inc.
// All rights reserved.
//
// Author: Egor Dolzhenko <edolzhenko@illumina.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//

#pragma once

#include "common/Parameters.hh"
#include "region_analysis/LocusFindings.hh"
#include "region_spec/LocusSpecification.hh"

#include "thirdparty/json/json.hpp"

namespace ehunter
{

class VariantJsonWriter : public VariantFindingsVisitor
{
public:
    VariantJsonWriter(
        const ReferenceContigInfo& contigInfo, const LocusSpecification& locusSpec,
        const VariantSpecification& variantSpec)
        : contigInfo_(contigInfo)
        , locusSpec_(locusSpec)
        , variantSpec_(variantSpec)
    {
    }

    ~VariantJsonWriter() = default;
    void visit(const RepeatFindings* repeatFindingsPtr);
    void visit(const SmallVariantFindings* smallVariantFindingsPtr);
    nlohmann::json record() const { return record_; }

private:
    const ReferenceContigInfo& contigInfo_;
    const LocusSpecification& locusSpec_;
    const VariantSpecification& variantSpec_;
    nlohmann::json record_;
};

class JsonWriter
{
public:
    JsonWriter(
        const ReferenceContigInfo& contigInfo, const RegionCatalog& regionCatalog,
        const SampleFindings& sampleFindings);

    void write(std::ostream& out);

private:
    const ReferenceContigInfo& contigInfo_;
    const RegionCatalog& regionCatalog_;
    const SampleFindings& sampleFindings_;
};

std::ostream& operator<<(std::ostream& out, JsonWriter& jsonWriter);

}
