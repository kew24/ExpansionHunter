//
// Expansion Hunter
// Copyright 2016-2019 Illumina, Inc.
// All rights reserved.
//
// Author: Xiao Chen <xchen2@illumina.com>,
//         Egor Dolzhenko <edolzhenko@illumina.com>
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

#include <memory>
#include <string>
#include <vector>

#include "workflow/LocusAnalyzer.hh"
#include "region_spec/VariantSpecification.hh"

namespace ehunter
{

class CNVVariantAnalyzer;
class ReadCountAnalyzer;

class CNVLocusAnalyzer : public LocusAnalyzer
{
public:
    CNVLocusAnalyzer(double minLocusCoverage, std::string locusId, CNVLocusSubtype locusSubtype);
    ~CNVLocusAnalyzer() override = default;

    const std::string& locusId() const override { return locusId_; }
    const CNVLocusSubtype& locusSubtype() const { return locusSubtype_; }
    void setStats(std::shared_ptr<ReadCountAnalyzer> statsAnalyzer);
    void addAnalyzer(std::shared_ptr<CNVVariantAnalyzer> variantAnalyzer);
    LocusFindings analyze(Sex sampleSex) const override;
    std::vector<std::shared_ptr<FeatureAnalyzer>> featureAnalyzers() override;

private:
    double minLocusCoverage_;
    std::string locusId_;
    CNVLocusSubtype locusSubtype_;
    std::shared_ptr<ReadCountAnalyzer> readCountAnalyzer_;
    std::vector<std::shared_ptr<CNVVariantAnalyzer>> variantAnalyzers_;    
};

}
