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

__out == &stream && (__out != nullptr)
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

__out != 0 && ((value == CompressionAlgorithmType::e_UNKNOWN ==> __out == "UNKNOWN") && (value == CompressionAlgorithmType::e_NONE ==> __out == "NONE") && (value == CompressionAlgorithmType::e_ZLIB ==> __out == "ZLIB") && (value != CompressionAlgorithmType::e_UNKNOWN && value != CompressionAlgorithmType::e_NONE && value != CompressionAlgorithmType::e_ZLIB ==> __out == "(* UNKNOWN *)"))
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

(__out == true ==> (*out == CompressionAlgorithmType::e_NONE || *out == CompressionAlgorithmType::e_ZLIB)) && (__out == false ==> *out == old_out)
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

(__out == true) || (__out == false && stream.tellp() > old_stream.tellp())
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
