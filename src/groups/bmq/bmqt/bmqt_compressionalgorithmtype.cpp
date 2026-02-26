// Copyright 2019-2023 Bloomberg Finance L.P.
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// bmqt_compressionalgorithmtype.cpp                                  -*-C++-*-
#include <bmqt_compressionalgorithmtype.h>

#include <bmqscm_version.h>
// BDE
#include <bdlb_print.h>
#include <bdlb_string.h>

namespace BloombergLP {
namespace bmqt {

// ===============================
// struct CompressionAlgorithmType
// ===============================

bsl::ostream&
CompressionAlgorithmType::print(bsl::ostream&                  stream,
                                CompressionAlgorithmType::Enum value,
                                int                            level,
                                int                            spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << CompressionAlgorithmType::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

// requires: true
// ensures: (value == CompressionAlgorithmType::e_UNKNOWN ==> strcmp(__out, "UNKNOWN") == 0) && (value == CompressionAlgorithmType::e_NONE ==> strcmp(__out, "NONE") == 0) && (value == CompressionAlgorithmType::e_ZLIB ==> strcmp(__out, "ZLIB") == 0) && (value != CompressionAlgorithmType::e_UNKNOWN && value != CompressionAlgorithmType::e_NONE && value != CompressionAlgorithmType::e_ZLIB ==> strcmp(__out, "(* UNKNOWN *)") == 0)
const char*
CompressionAlgorithmType::toAscii(CompressionAlgorithmType::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(NONE)
        BMQT_CASE(ZLIB)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

// requires: out != 0 && str.size() >= 0
// ensures: (__out == true ==> ((*out == CompressionAlgorithmType::e_NONE && bdlb::String::areEqualCaseless(toAscii(CompressionAlgorithmType::e_NONE), str)) || (*out == CompressionAlgorithmType::e_ZLIB && bdlb::String::areEqualCaseless(toAscii(CompressionAlgorithmType::e_ZLIB), str)))) && (__out == false ==> !bdlb::String::areEqualCaseless(toAscii(CompressionAlgorithmType::e_NONE), str) && !bdlb::String::areEqualCaseless(toAscii(CompressionAlgorithmType::e_ZLIB), str))
bool CompressionAlgorithmType::fromAscii(CompressionAlgorithmType::Enum* out,
                                         const bsl::string&              str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(                                       \
            toAscii(CompressionAlgorithmType::e_##M),                         \
            str)) {                                                           \
        *out = CompressionAlgorithmType::e_##M;                               \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(NONE);
    BMQT_CHECKVALUE(ZLIB);

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// requires: str != nullptr
// ensures: (__out == true) || (__out == false && SEPFORALL(0, strlen("Error: compressionAlgorithmType must be one of [NONE, ZLIB]\n"), i, stream + i ↦ "Error: compressionAlgorithmType must be one of [NONE, ZLIB]\n"[i]))
bool CompressionAlgorithmType::isValid(const bsl::string* str,
                                       bsl::ostream&      stream)
{
    CompressionAlgorithmType::Enum value;
    if (fromAscii(&value, *str) == true) {
        return true;  // RETURN
    }

    stream << "Error: compressionAlgorithmType must be one of [NONE, ZLIB]\n";
    return false;
}

}  // close package namespace
}  // close enterprise namespace
