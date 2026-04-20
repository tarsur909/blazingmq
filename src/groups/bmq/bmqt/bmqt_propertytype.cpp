// Copyright 2016-2023 Bloomberg Finance L.P.
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

// bmqt_propertytype.cpp                                              -*-C++-*-
#include <bmqt_propertytype.h>

#include <bmqscm_version.h>
// BDE
#include <bdlb_print.h>
#include <bdlb_string.h>
#include <bsl_ostream.h>

namespace BloombergLP {
namespace bmqt {

// -------------------
// struct PropertyType
// -------------------

bsl::ostream& PropertyType::print(bsl::ostream&      stream,
                                  PropertyType::Enum value,
                                  int                level,
                                  int                spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << PropertyType::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

// requires: true
// ensures: (value == PropertyType::e_UNDEFINED ==> __out == "UNDEFINED") && (value == PropertyType::e_BOOL ==> __out == "BOOL") && (value == PropertyType::e_CHAR ==> __out == "CHAR") && (value == PropertyType::e_SHORT ==> __out == "SHORT") && (value == PropertyType::e_INT32 ==> __out == "INT32") && (value == PropertyType::e_INT64 ==> __out == "INT64") && (value == PropertyType::e_STRING ==> __out == "STRING") && (value == PropertyType::e_BINARY ==> __out == "BINARY") && (value != PropertyType::e_UNDEFINED && value != PropertyType::e_BOOL && value != PropertyType::e_CHAR && value != PropertyType::e_SHORT && value != PropertyType::e_INT32 && value != PropertyType::e_INT64 && value != PropertyType::e_STRING && value != PropertyType::e_BINARY ==> __out == "(* UNKNOWN *)")
const char* PropertyType::toAscii(PropertyType::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(UNDEFINED)
        BMQT_CASE(BOOL)
        BMQT_CASE(CHAR)
        BMQT_CASE(SHORT)
        BMQT_CASE(INT32)
        BMQT_CASE(INT64)
        BMQT_CASE(STRING)
        BMQT_CASE(BINARY)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

// requires: true
// ensures: (__out == true ==> (*out == PropertyType::e_UNDEFINED || *out == PropertyType::e_BOOL || *out == PropertyType::e_CHAR || *out == PropertyType::e_SHORT || *out == PropertyType::e_INT32 || *out == PropertyType::e_INT64 || *out == PropertyType::e_STRING || *out == PropertyType::e_BINARY)) && (__out == false ==> (*out == old_out))
bool PropertyType::fromAscii(PropertyType::Enum*      out,
                             const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(PropertyType::e_##M),          \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = PropertyType::e_##M;                                           \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(UNDEFINED)
    BMQT_CHECKVALUE(BOOL)
    BMQT_CHECKVALUE(CHAR)
    BMQT_CHECKVALUE(SHORT)
    BMQT_CHECKVALUE(INT32)
    BMQT_CHECKVALUE(INT64)
    BMQT_CHECKVALUE(STRING)
    BMQT_CHECKVALUE(BINARY)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

}  // close package namespace
}  // close enterprise namespace
