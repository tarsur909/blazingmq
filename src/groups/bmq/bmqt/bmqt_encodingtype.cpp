// Copyright 2014-2023 Bloomberg Finance L.P.
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

// bmqt_encodingtype.cpp                                              -*-C++-*-
#include <bmqt_encodingtype.h>

#include <bmqscm_version.h>
// BDE
#include <bdlb_print.h>
#include <bdlb_string.h>
#include <bsl_ostream.h>

namespace BloombergLP {
namespace bmqt {

// -------------------
// struct EncodingType
// -------------------

bsl::ostream& EncodingType::print(bsl::ostream&      stream,
                                  EncodingType::Enum value,
                                  int                level,
                                  int                spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << EncodingType::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

// requires: true
// ensures: (value == EncodingType::e_UNDEFINED ==> __out == "UNDEFINED") && (value == EncodingType::e_RAW ==> __out == "RAW") && (value == EncodingType::e_BER ==> __out == "BER") && (value == EncodingType::e_BDEX ==> __out == "BDEX") && (value == EncodingType::e_XML ==> __out == "XML") && (value == EncodingType::e_JSON ==> __out == "JSON") && (value == EncodingType::e_TEXT ==> __out == "TEXT") && (value == EncodingType::e_MULTIPARTS ==> __out == "MULTIPARTS") && (value != EncodingType::e_UNDEFINED && value != EncodingType::e_RAW && value != EncodingType::e_BER && value != EncodingType::e_BDEX && value != EncodingType::e_XML && value != EncodingType::e_JSON && value != EncodingType::e_TEXT && value != EncodingType::e_MULTIPARTS ==> __out == "(* UNKNOWN *)")
const char* EncodingType::toAscii(EncodingType::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(UNDEFINED)
        BMQT_CASE(RAW)
        BMQT_CASE(BER)
        BMQT_CASE(BDEX)
        BMQT_CASE(XML)
        BMQT_CASE(JSON)
        BMQT_CASE(TEXT)
        BMQT_CASE(MULTIPARTS)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

bool EncodingType::fromAscii(EncodingType::Enum*      out,
                             const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(EncodingType::e_##M),          \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = EncodingType::e_##M;                                           \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(UNDEFINED)
    BMQT_CHECKVALUE(RAW)
    BMQT_CHECKVALUE(BER)
    BMQT_CHECKVALUE(BDEX)
    BMQT_CHECKVALUE(XML)
    BMQT_CHECKVALUE(JSON)
    BMQT_CHECKVALUE(TEXT)
    BMQT_CHECKVALUE(MULTIPARTS)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// requires: string != 0 && stream.good()
// ensures: (__out == true) || (__out == false && SEPFORALL(0, strlen("Error: encoding type must be one of [undefined, raw, ber, bdex, xml, json, text or multiparts]\n"), i, stream + stream.tellp() + i ↦ "Error: encoding type must be one of [undefined, raw, ber, bdex, xml, json, text or multiparts]\n"[i]))
bool EncodingType::isValid(const bsl::string* string, bsl::ostream& stream)
{
    EncodingType::Enum value;
    if (fromAscii(&value, *string)) {
        return true;  // RETURN
    }

    stream << "Error: encoding type must be one of "
           << "[undefined, raw, ber, bdex, xml, json, text or multiparts]\n";
    return false;
}

}  // close package namespace
}  // close enterprise namespace
