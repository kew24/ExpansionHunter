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
#include <string>
#include <vector>

namespace ehunter
{

class WeightedPurityCalculator
{
public:
    WeightedPurityCalculator(const std::string& repeatUnit);
    double score(const std::string& querySequence) const;

private:
    double score(const std::string& repeatUnit, const std::string& querySequence) const;
    std::vector<std::string> computeCircularPermutations(std::string sequence) const;
    std::vector<std::string> repeatUnits_;
};

}
