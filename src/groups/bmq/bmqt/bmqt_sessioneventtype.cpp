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

// bmqt_sessioneventtype.cpp                                          -*-C++-*-
#include <bmqt_sessioneventtype.h>

#include <bmqscm_version.h>
// BDE
#include <bdlb_print.h>
#include <bdlb_string.h>
#include <bsl_ostream.h>

namespace BloombergLP {
namespace bmqt {

// -----------------------
// struct SessionEventType
// -----------------------

__out == stream
bsl::ostream& SessionEventType::print(bsl::ostream&          stream,
                                      SessionEventType::Enum value,
                                      int                    level,
                                      int                    spacesPerLevel)
{
    bdlb::Print::indent(stream, level, spacesPerLevel);
    stream << SessionEventType::toAscii(value);

    if (spacesPerLevel >= 0) {
        stream << '\n';
    }

    return stream;
}

__out != 0 && (__out == "UNDEFINED" || __out == "CONNECTED" || __out == "DISCONNECTED" || __out == "CONNECTION_LOST" || __out == "RECONNECTED" || __out == "STATE_RESTORED" || __out == "CONNECTION_TIMEOUT" || __out == "QUEUE_OPEN_RESULT" || __out == "QUEUE_REOPEN_RESULT" || __out == "QUEUE_CLOSE_RESULT" || __out == "SLOWCONSUMER_NORMAL" || __out == "SLOWCONSUMER_HIGHWATERMARK" || __out == "QUEUE_CONFIGURE_RESULT" || __out == "HOST_UNHEALTHY" || __out == "HOST_HEALTH_RESTORED" || __out == "QUEUE_SUSPENDED" || __out == "QUEUE_RESUMED" || __out == "ERROR" || __out == "TIMEOUT" || __out == "CANCELED" || __out == "(* UNKNOWN *)")
const char* SessionEventType::toAscii(SessionEventType::Enum value)
{
#define BMQT_CASE(X)                                                          \
    case e_##X: return #X;

    switch (value) {
        BMQT_CASE(UNDEFINED)
        BMQT_CASE(CONNECTED)
        BMQT_CASE(DISCONNECTED)
        BMQT_CASE(CONNECTION_LOST)
        BMQT_CASE(RECONNECTED)
        BMQT_CASE(STATE_RESTORED)
        BMQT_CASE(CONNECTION_TIMEOUT)
        BMQT_CASE(QUEUE_OPEN_RESULT)
        BMQT_CASE(QUEUE_REOPEN_RESULT)
        BMQT_CASE(QUEUE_CLOSE_RESULT)
        BMQT_CASE(SLOWCONSUMER_NORMAL)
        BMQT_CASE(SLOWCONSUMER_HIGHWATERMARK)
        BMQT_CASE(QUEUE_CONFIGURE_RESULT)
        BMQT_CASE(HOST_UNHEALTHY)
        BMQT_CASE(HOST_HEALTH_RESTORED)
        BMQT_CASE(QUEUE_SUSPENDED)
        BMQT_CASE(QUEUE_RESUMED)
        BMQT_CASE(ERROR)
        BMQT_CASE(TIMEOUT)
        BMQT_CASE(CANCELED)
    default: return "(* UNKNOWN *)";
    }

#undef BMQT_CASE
}

(__out == true ==> (*out == SessionEventType::e_UNDEFINED || *out == SessionEventType::e_CONNECTED || *out == SessionEventType::e_DISCONNECTED || *out == SessionEventType::e_CONNECTION_LOST || *out == SessionEventType::e_RECONNECTED || *out == SessionEventType::e_STATE_RESTORED || *out == SessionEventType::e_CONNECTION_TIMEOUT || *out == SessionEventType::e_QUEUE_OPEN_RESULT || *out == SessionEventType::e_QUEUE_REOPEN_RESULT || *out == SessionEventType::e_QUEUE_CLOSE_RESULT || *out == SessionEventType::e_SLOWCONSUMER_NORMAL || *out == SessionEventType::e_SLOWCONSUMER_HIGHWATERMARK || *out == SessionEventType::e_QUEUE_CONFIGURE_RESULT || *out == SessionEventType::e_HOST_UNHEALTHY || *out == SessionEventType::e_HOST_HEALTH_RESTORED || *out == SessionEventType::e_QUEUE_SUSPENDED || *out == SessionEventType::e_QUEUE_RESUMED || *out == SessionEventType::e_ERROR || *out == SessionEventType::e_TIMEOUT || *out == SessionEventType::e_CANCELED)) && (__out == false ==> *out == old_out)
bool SessionEventType::fromAscii(SessionEventType::Enum*  out,
                                 const bslstl::StringRef& str)
{
#define BMQT_CHECKVALUE(M)                                                    \
    if (bdlb::String::areEqualCaseless(toAscii(SessionEventType::e_##M),      \
                                       str)) {                                \
        *out = SessionEventType::e_##M;                                       \
        return true;                                                          \
    }

    BMQT_CHECKVALUE(UNDEFINED)
    BMQT_CHECKVALUE(CONNECTED)
    BMQT_CHECKVALUE(DISCONNECTED)
    BMQT_CHECKVALUE(CONNECTION_LOST)
    BMQT_CHECKVALUE(RECONNECTED)
    BMQT_CHECKVALUE(STATE_RESTORED)
    BMQT_CHECKVALUE(CONNECTION_TIMEOUT)
    BMQT_CHECKVALUE(QUEUE_OPEN_RESULT)
    BMQT_CHECKVALUE(QUEUE_REOPEN_RESULT)
    BMQT_CHECKVALUE(QUEUE_CLOSE_RESULT)
    BMQT_CHECKVALUE(SLOWCONSUMER_NORMAL)
    BMQT_CHECKVALUE(SLOWCONSUMER_HIGHWATERMARK)
    BMQT_CHECKVALUE(QUEUE_CONFIGURE_RESULT)
    BMQT_CHECKVALUE(HOST_UNHEALTHY)
    BMQT_CHECKVALUE(HOST_HEALTH_RESTORED)
    BMQT_CHECKVALUE(QUEUE_SUSPENDED)
    BMQT_CHECKVALUE(QUEUE_RESUMED)
    BMQT_CHECKVALUE(ERROR)
    BMQT_CHECKVALUE(TIMEOUT)
    BMQT_CHECKVALUE(CANCELED)

    // Invalid string
    return false;

#undef BMQT_CHECKVALUE
}

}  // close package namespace
}  // close enterprise namespace
