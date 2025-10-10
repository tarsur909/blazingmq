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

// bmqt_resultcode.cpp                                                -*-C++-*-
#include <bmqt_resultcode.h>

#include <bmqscm_version.h>
// BDE
#include <bdlb_print.h>
#include <bdlb_string.h>
#include <bsl_ostream.h>

namespace BloombergLP {
namespace bmqt {

// --------------------
// struct GenericResult
// --------------------

__out == stream
bsl::ostream& GenericResult::print(bsl::ostream&       stream,
                                   GenericResult::Enum value,
                                   int                 level,
                                   int                 spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << GenericResult::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

const char* GenericResult::toAscii(GenericResult::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(SUCCESS)
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(TIMEOUT)
        BMQT_CASE(NOT_CONNECTED)
        BMQT_CASE(CANCELED)
        BMQT_CASE(NOT_SUPPORTED)
        BMQT_CASE(REFUSED)
        BMQT_CASE(INVALID_ARGUMENT)
        BMQT_CASE(NOT_READY)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (*out == GenericResult::e_SUCCESS || *out == GenericResult::e_UNKNOWN || *out == GenericResult::e_TIMEOUT || *out == GenericResult::e_NOT_CONNECTED || *out == GenericResult::e_CANCELED || *out == GenericResult::e_NOT_SUPPORTED || *out == GenericResult::e_REFUSED || *out == GenericResult::e_INVALID_ARGUMENT || *out == GenericResult::e_NOT_READY)) && (__out == false ==> *out == old_out)
bool GenericResult::fromAscii(GenericResult::Enum*     out,
                              const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(GenericResult::e_##M),         \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = GenericResult::e_##M;                                          \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(SUCCESS)
    BMQT_CHECKVALUE(UNKNOWN)
    BMQT_CHECKVALUE(TIMEOUT)
    BMQT_CHECKVALUE(NOT_CONNECTED)
    BMQT_CHECKVALUE(CANCELED)
    BMQT_CHECKVALUE(NOT_SUPPORTED)
    BMQT_CHECKVALUE(REFUSED)
    BMQT_CHECKVALUE(INVALID_ARGUMENT)
    BMQT_CHECKVALUE(NOT_READY)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// ----------------------
// struct OpenQueueResult
// ----------------------

__out == stream
bsl::ostream& OpenQueueResult::print(bsl::ostream&         stream,
                                     OpenQueueResult::Enum value,
                                     int                   level,
                                     int                   spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << OpenQueueResult::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

__out != 0 && (__out == "SUCCESS" || __out == "UNKNOWN" || __out == "TIMEOUT" || __out == "NOT_CONNECTED" || __out == "CANCELED" || __out == "NOT_SUPPORTED" || __out == "REFUSED" || __out == "INVALID_ARGUMENT" || __out == "NOT_READY" || __out == "ALREADY_OPENED" || __out == "ALREADY_IN_PROGRESS" || __out == "INVALID_URI" || __out == "INVALID_FLAGS" || __out == "CORRELATIONID_NOT_UNIQUE" || __out == "(* UNKNOWN *)")
const char* OpenQueueResult::toAscii(OpenQueueResult::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(SUCCESS)
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(TIMEOUT)
        BMQT_CASE(NOT_CONNECTED)
        BMQT_CASE(CANCELED)
        BMQT_CASE(NOT_SUPPORTED)
        BMQT_CASE(REFUSED)
        BMQT_CASE(INVALID_ARGUMENT)
        BMQT_CASE(NOT_READY)
        BMQT_CASE(ALREADY_OPENED)
        BMQT_CASE(ALREADY_IN_PROGRESS)
        BMQT_CASE(INVALID_URI)
        BMQT_CASE(INVALID_FLAGS)
        BMQT_CASE(CORRELATIONID_NOT_UNIQUE)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (out != 0 && (*out == OpenQueueResult::e_SUCCESS || *out == OpenQueueResult::e_UNKNOWN || *out == OpenQueueResult::e_TIMEOUT || *out == OpenQueueResult::e_NOT_CONNECTED || *out == OpenQueueResult::e_CANCELED || *out == OpenQueueResult::e_NOT_SUPPORTED || *out == OpenQueueResult::e_REFUSED || *out == OpenQueueResult::e_INVALID_ARGUMENT || *out == OpenQueueResult::e_NOT_READY || *out == OpenQueueResult::e_ALREADY_OPENED || *out == OpenQueueResult::e_ALREADY_IN_PROGRESS || *out == OpenQueueResult::e_INVALID_URI || *out == OpenQueueResult::e_INVALID_FLAGS || *out == OpenQueueResult::e_CORRELATIONID_NOT_UNIQUE))) && (__out == false ==> *out == old_out)
bool OpenQueueResult::fromAscii(OpenQueueResult::Enum*   out,
                                const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(OpenQueueResult::e_##M),       \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = OpenQueueResult::e_##M;                                        \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(SUCCESS)
    BMQT_CHECKVALUE(UNKNOWN)
    BMQT_CHECKVALUE(TIMEOUT)
    BMQT_CHECKVALUE(NOT_CONNECTED)
    BMQT_CHECKVALUE(CANCELED)
    BMQT_CHECKVALUE(NOT_SUPPORTED)
    BMQT_CHECKVALUE(REFUSED)
    BMQT_CHECKVALUE(INVALID_ARGUMENT)
    BMQT_CHECKVALUE(NOT_READY)
    BMQT_CHECKVALUE(ALREADY_OPENED)
    BMQT_CHECKVALUE(ALREADY_IN_PROGRESS)
    BMQT_CHECKVALUE(INVALID_URI)
    BMQT_CHECKVALUE(INVALID_FLAGS)
    BMQT_CHECKVALUE(CORRELATIONID_NOT_UNIQUE)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// ---------------------------
// struct ConfigureQueueResult
// ---------------------------

__out == stream && (spacesPerLevel >= 0 ==> (__out ↦ _ ⋆ SFORALL(0, __out.tellp(), i, (__out + i |-> _))))
bsl::ostream& ConfigureQueueResult::print(bsl::ostream&              stream,
                                          ConfigureQueueResult::Enum value,
                                          int                        level,
                                          int spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << ConfigureQueueResult::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

__out != 0 && (value == ConfigureQueueResult::Enum::e_SUCCESS ==> __out == "SUCCESS") && (value == ConfigureQueueResult::Enum::e_UNKNOWN ==> __out == "UNKNOWN") && (value == ConfigureQueueResult::Enum::e_TIMEOUT ==> __out == "TIMEOUT") && (value == ConfigureQueueResult::Enum::e_NOT_CONNECTED ==> __out == "NOT_CONNECTED") && (value == ConfigureQueueResult::Enum::e_CANCELED ==> __out == "CANCELED") && (value == ConfigureQueueResult::Enum::e_NOT_SUPPORTED ==> __out == "NOT_SUPPORTED") && (value == ConfigureQueueResult::Enum::e_REFUSED ==> __out == "REFUSED") && (value == ConfigureQueueResult::Enum::e_INVALID_ARGUMENT ==> __out == "INVALID_ARGUMENT") && (value == ConfigureQueueResult::Enum::e_NOT_READY ==> __out == "NOT_READY") && (value == ConfigureQueueResult::Enum::e_ALREADY_IN_PROGRESS ==> __out == "ALREADY_IN_PROGRESS") && (value == ConfigureQueueResult::Enum::e_INVALID_QUEUE ==> __out == "INVALID_QUEUE") && (value != ConfigureQueueResult::Enum::e_SUCCESS && value != ConfigureQueueResult::Enum::e_UNKNOWN && value != ConfigureQueueResult::Enum::e_TIMEOUT && value != ConfigureQueueResult::Enum::e_NOT_CONNECTED && value != ConfigureQueueResult::Enum::e_CANCELED && value != ConfigureQueueResult::Enum::e_NOT_SUPPORTED && value != ConfigureQueueResult::Enum::e_REFUSED && value != ConfigureQueueResult::Enum::e_INVALID_ARGUMENT && value != ConfigureQueueResult::Enum::e_NOT_READY && value != ConfigureQueueResult::Enum::e_ALREADY_IN_PROGRESS && value != ConfigureQueueResult::Enum::e_INVALID_QUEUE ==> __out == "(* UNKNOWN *)")
const char* ConfigureQueueResult::toAscii(ConfigureQueueResult::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(SUCCESS)
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(TIMEOUT)
        BMQT_CASE(NOT_CONNECTED)
        BMQT_CASE(CANCELED)
        BMQT_CASE(NOT_SUPPORTED)
        BMQT_CASE(REFUSED)
        BMQT_CASE(INVALID_ARGUMENT)
        BMQT_CASE(NOT_READY)
        BMQT_CASE(ALREADY_IN_PROGRESS)
        BMQT_CASE(INVALID_QUEUE)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (*out == ConfigureQueueResult::e_SUCCESS || *out == ConfigureQueueResult::e_UNKNOWN || *out == ConfigureQueueResult::e_TIMEOUT || *out == ConfigureQueueResult::e_NOT_CONNECTED || *out == ConfigureQueueResult::e_CANCELED || *out == ConfigureQueueResult::e_NOT_SUPPORTED || *out == ConfigureQueueResult::e_REFUSED || *out == ConfigureQueueResult::e_INVALID_ARGUMENT || *out == ConfigureQueueResult::e_NOT_READY || *out == ConfigureQueueResult::e_ALREADY_IN_PROGRESS || *out == ConfigureQueueResult::e_INVALID_QUEUE)) && (__out == false ==> *out == old_out)
bool ConfigureQueueResult::fromAscii(ConfigureQueueResult::Enum* out,
                                     const bslstl::StringRef&    str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(ConfigureQueueResult::e_##M),  \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = ConfigureQueueResult::e_##M;                                   \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(SUCCESS)
    BMQT_CHECKVALUE(UNKNOWN)
    BMQT_CHECKVALUE(TIMEOUT)
    BMQT_CHECKVALUE(NOT_CONNECTED)
    BMQT_CHECKVALUE(CANCELED)
    BMQT_CHECKVALUE(NOT_SUPPORTED)
    BMQT_CHECKVALUE(REFUSED)
    BMQT_CHECKVALUE(INVALID_ARGUMENT)
    BMQT_CHECKVALUE(NOT_READY)
    BMQT_CHECKVALUE(ALREADY_IN_PROGRESS)
    BMQT_CHECKVALUE(INVALID_QUEUE)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// -----------------------
// struct CloseQueueResult
// -----------------------

__out == stream
bsl::ostream& CloseQueueResult::print(bsl::ostream&          stream,
                                      CloseQueueResult::Enum value,
                                      int                    level,
                                      int                    spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << CloseQueueResult::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

const char* CloseQueueResult::toAscii(CloseQueueResult::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(SUCCESS)
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(TIMEOUT)
        BMQT_CASE(NOT_CONNECTED)
        BMQT_CASE(CANCELED)
        BMQT_CASE(NOT_SUPPORTED)
        BMQT_CASE(REFUSED)
        BMQT_CASE(INVALID_ARGUMENT)
        BMQT_CASE(NOT_READY)
        BMQT_CASE(ALREADY_CLOSED)
        BMQT_CASE(ALREADY_IN_PROGRESS)
        BMQT_CASE(UNKNOWN_QUEUE)
        BMQT_CASE(INVALID_QUEUE)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (*out == CloseQueueResult::e_SUCCESS || *out == CloseQueueResult::e_UNKNOWN || *out == CloseQueueResult::e_TIMEOUT || *out == CloseQueueResult::e_NOT_CONNECTED || *out == CloseQueueResult::e_CANCELED || *out == CloseQueueResult::e_NOT_SUPPORTED || *out == CloseQueueResult::e_REFUSED || *out == CloseQueueResult::e_INVALID_ARGUMENT || *out == CloseQueueResult::e_NOT_READY || *out == CloseQueueResult::e_ALREADY_CLOSED || *out == CloseQueueResult::e_ALREADY_IN_PROGRESS || *out == CloseQueueResult::e_UNKNOWN_QUEUE || *out == CloseQueueResult::e_INVALID_QUEUE)) && (__out == false ==> *out == old_out)
bool CloseQueueResult::fromAscii(CloseQueueResult::Enum*  out,
                                 const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(CloseQueueResult::e_##M),      \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = CloseQueueResult::e_##M;                                       \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(SUCCESS)
    BMQT_CHECKVALUE(UNKNOWN)
    BMQT_CHECKVALUE(TIMEOUT)
    BMQT_CHECKVALUE(NOT_CONNECTED)
    BMQT_CHECKVALUE(CANCELED)
    BMQT_CHECKVALUE(NOT_SUPPORTED)
    BMQT_CHECKVALUE(REFUSED)
    BMQT_CHECKVALUE(INVALID_ARGUMENT)
    BMQT_CHECKVALUE(NOT_READY)
    BMQT_CHECKVALUE(ALREADY_CLOSED)
    BMQT_CHECKVALUE(ALREADY_IN_PROGRESS)
    BMQT_CHECKVALUE(UNKNOWN_QUEUE)
    BMQT_CHECKVALUE(INVALID_QUEUE)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// -------------------------
// struct EventBuilderResult
// -------------------------

__out == stream
bsl::ostream& EventBuilderResult::print(bsl::ostream&            stream,
                                        EventBuilderResult::Enum value,
                                        int                      level,
                                        int spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << EventBuilderResult::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

const char* EventBuilderResult::toAscii(EventBuilderResult::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(SUCCESS)
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(QUEUE_INVALID)
        BMQT_CASE(QUEUE_READONLY)
        BMQT_CASE(MISSING_CORRELATION_ID)
        BMQT_CASE(EVENT_TOO_BIG)
        BMQT_CASE(PAYLOAD_TOO_BIG)
        BMQT_CASE(PAYLOAD_EMPTY)
        BMQT_CASE(OPTION_TOO_BIG)
#ifdef BMQ_ENABLE_MSG_GROUPID
        BMQT_CASE(INVALID_MSG_GROUP_ID)
#endif
        BMQT_CASE(QUEUE_SUSPENDED)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (*out == EventBuilderResult::e_SUCCESS || *out == EventBuilderResult::e_UNKNOWN || *out == EventBuilderResult::e_QUEUE_INVALID || *out == EventBuilderResult::e_QUEUE_READONLY || *out == EventBuilderResult::e_MISSING_CORRELATION_ID || *out == EventBuilderResult::e_EVENT_TOO_BIG || *out == EventBuilderResult::e_PAYLOAD_TOO_BIG || *out == EventBuilderResult::e_PAYLOAD_EMPTY || *out == EventBuilderResult::e_OPTION_TOO_BIG || *out == EventBuilderResult::e_QUEUE_SUSPENDED)) && (__out == false ==> *out == old_out)
bool EventBuilderResult::fromAscii(EventBuilderResult::Enum* out,
                                   const bslstl::StringRef&  str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(EventBuilderResult::e_##M),    \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = EventBuilderResult::e_##M;                                     \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(SUCCESS)
    BMQT_CHECKVALUE(UNKNOWN)
    BMQT_CHECKVALUE(QUEUE_INVALID)
    BMQT_CHECKVALUE(QUEUE_READONLY)
    BMQT_CHECKVALUE(MISSING_CORRELATION_ID)
    BMQT_CHECKVALUE(EVENT_TOO_BIG)
    BMQT_CHECKVALUE(PAYLOAD_TOO_BIG)
    BMQT_CHECKVALUE(PAYLOAD_EMPTY)
    BMQT_CHECKVALUE(OPTION_TOO_BIG)
#ifdef BMQ_ENABLE_MSG_GROUPID
    BMQT_CHECKVALUE(INVALID_MSG_GROUP_ID)
#endif
    BMQT_CHECKVALUE(QUEUE_SUSPENDED)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// ----------------
// struct AckResult
// ----------------

__out == stream
bsl::ostream& AckResult::print(bsl::ostream&   stream,
                               AckResult::Enum value,
                               int             level,
                               int             spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << AckResult::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

(value == AckResult::e_SUCCESS && __out == "SUCCESS"
const char* AckResult::toAscii(AckResult::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(SUCCESS)
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(TIMEOUT)
        BMQT_CASE(NOT_CONNECTED)
        BMQT_CASE(CANCELED)
        BMQT_CASE(NOT_SUPPORTED)
        BMQT_CASE(REFUSED)
        BMQT_CASE(INVALID_ARGUMENT)
        BMQT_CASE(NOT_READY)
        BMQT_CASE(LIMIT_MESSAGES)
        BMQT_CASE(LIMIT_BYTES)
        BMQT_CASE(LIMIT_QUEUE_MESSAGES)
        BMQT_CASE(LIMIT_QUEUE_BYTES)
        BMQT_CASE(STORAGE_FAILURE)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (*out == AckResult::e_SUCCESS || *out == AckResult::e_UNKNOWN || *out == AckResult::e_TIMEOUT || *out == AckResult::e_NOT_CONNECTED || *out == AckResult::e_CANCELED || *out == AckResult::e_NOT_SUPPORTED || *out == AckResult::e_REFUSED || *out == AckResult::e_INVALID_ARGUMENT || *out == AckResult::e_NOT_READY || *out == AckResult::e_LIMIT_MESSAGES || *out == AckResult::e_LIMIT_BYTES || *out == AckResult::e_LIMIT_DOMAIN_MESSAGES || *out == AckResult::e_LIMIT_DOMAIN_BYTES || *out == AckResult::e_LIMIT_QUEUE_MESSAGES || *out == AckResult::e_LIMIT_QUEUE_BYTES || *out == AckResult::e_STORAGE_FAILURE)) && (__out == false ==> true)
bool AckResult::fromAscii(AckResult::Enum* out, const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(AckResult::e_##M),             \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = AckResult::e_##M;                                              \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(SUCCESS)
    BMQT_CHECKVALUE(UNKNOWN)
    BMQT_CHECKVALUE(TIMEOUT)
    BMQT_CHECKVALUE(NOT_CONNECTED)
    BMQT_CHECKVALUE(CANCELED)
    BMQT_CHECKVALUE(NOT_SUPPORTED)
    BMQT_CHECKVALUE(REFUSED)
    BMQT_CHECKVALUE(INVALID_ARGUMENT)
    BMQT_CHECKVALUE(NOT_READY)
    BMQT_CHECKVALUE(LIMIT_MESSAGES)
    BMQT_CHECKVALUE(LIMIT_BYTES)
    BMQT_CHECKVALUE(LIMIT_DOMAIN_MESSAGES)
    BMQT_CHECKVALUE(LIMIT_DOMAIN_BYTES)
    BMQT_CHECKVALUE(LIMIT_QUEUE_MESSAGES)
    BMQT_CHECKVALUE(LIMIT_QUEUE_BYTES)
    BMQT_CHECKVALUE(STORAGE_FAILURE)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

// -----------------
// struct PostResult
// -----------------

bsl::ostream& PostResult::print(bsl::ostream&    stream,
                                PostResult::Enum value,
                                int              level,
                                int              spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << PostResult::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

const char* PostResult::toAscii(PostResult::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(SUCCESS)
        BMQT_CASE(UNKNOWN)
        BMQT_CASE(TIMEOUT)
        BMQT_CASE(NOT_CONNECTED)
        BMQT_CASE(CANCELED)
        BMQT_CASE(NOT_SUPPORTED)
        BMQT_CASE(REFUSED)
        BMQT_CASE(INVALID_ARGUMENT)
        BMQT_CASE(NOT_READY)
        BMQT_CASE(BW_LIMIT)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (*out == PostResult::e_SUCCESS || *out == PostResult::e_UNKNOWN || *out == PostResult::e_TIMEOUT || *out == PostResult::e_NOT_CONNECTED || *out == PostResult::e_CANCELED || *out == PostResult::e_NOT_SUPPORTED || *out == PostResult::e_REFUSED || *out == PostResult::e_INVALID_ARGUMENT || *out == PostResult::e_NOT_READY || *out == PostResult::e_BW_LIMIT)) && (__out == false ==> true)
bool PostResult::fromAscii(PostResult::Enum* out, const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(PostResult::e_##M),            \
                                       str.data(),                            \
                                       static_cast<int>(str.length()))) {     \
        *out = PostResult::e_##M;                                             \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(SUCCESS)
    BMQT_CHECKVALUE(UNKNOWN)
    BMQT_CHECKVALUE(TIMEOUT)
    BMQT_CHECKVALUE(NOT_CONNECTED)
    BMQT_CHECKVALUE(CANCELED)
    BMQT_CHECKVALUE(NOT_SUPPORTED)
    BMQT_CHECKVALUE(REFUSED)
    BMQT_CHECKVALUE(INVALID_ARGUMENT)
    BMQT_CHECKVALUE(NOT_READY)
    BMQT_CHECKVALUE(BW_LIMIT)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

}  // close package namespace
}  // close enterprise namespace
