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

// bmqsys_mocktime.cpp                                                -*-C++-*-
#include <bmqsys_mocktime.h>

#include <bmqscm_version.h>

#include <bmqsys_time.h>

// BDE
#include <bdlf_memfn.h>

namespace BloombergLP {
namespace bmqsys {

// --------------
// class MockTime
// --------------

MockTime::MockTime()
: d_realtimeClock(0, 0)
, d_monotonicClock(0, 0)
, d_highResTimer(0)
{
    bmqsys::Time::initialize(
        bdlf::MemFnUtil::memFn(&MockTime::realtimeClock, this),
        bdlf::MemFnUtil::memFn(&MockTime::monotonicClock, this),
        bdlf::MemFnUtil::memFn(&MockTime::highResTimer, this));
}

MockTime::~MockTime()
{
    bmqsys::Time::shutdown();
}

// requires: true
// ensures: __out.d_realtimeClock == value
MockTime& MockTime::setRealTimeClock(const bsls::TimeInterval& value)
{
    d_realtimeClock = value;
    return *this;
}

// requires: true
// ensures: __out.d_monotonicClock ↦ value
MockTime& MockTime::setMonotonicClock(const bsls::TimeInterval& value)
{
    d_monotonicClock = value;
    return *this;
}

// requires: true
// ensures: __out.d_highResTimer == value
MockTime& MockTime::setHighResTimer(bsls::Types::Int64 value)
{
    d_highResTimer = value;
    return *this;
}

// requires: true
// ensures: (__out == *this) && (d_realtimeClock == old_d_realtimeClock + offset)
MockTime& MockTime::advanceRealTimeClock(const bsls::TimeInterval& offset)
{
    d_realtimeClock += offset;
    return *this;
}

// requires: true
// ensures: (__out == *this) && (d_monotonicClock == old_d_monotonicClock + offset)
MockTime& MockTime::advanceMonotonicClock(const bsls::TimeInterval& offset)
{
    d_monotonicClock += offset;
    return *this;
}

// requires: true
// ensures: (__out == *this) && (d_highResTimer == old_d_highResTimer + offset)
MockTime& MockTime::advanceHighResTimer(bsls::Types::Int64 offset)
{
    d_highResTimer += offset;
    return *this;
}
// requires: true
// ensures: (__out.d_realtimeClock ↦ bsls::TimeInterval(0, 0)) ⋆ (__out.d_monotonicClock ↦ bsls::TimeInterval(0, 0)) ⋆ (__out.d_highResTimer ↦ 0)
MockTime& MockTime::reset()
{
    d_realtimeClock  = bsls::TimeInterval(0, 0);
    d_monotonicClock = bsls::TimeInterval(0, 0);
    d_highResTimer   = 0;

    return *this;
}

// requires: true
// ensures: __out == d_realtimeClock
bsls::TimeInterval MockTime::realtimeClock() const
{
    return d_realtimeClock;
}

// requires: true
// ensures: __out == d_monotonicClock
bsls::TimeInterval MockTime::monotonicClock() const
{
    return d_monotonicClock;
}

// requires: true
// ensures: __out == d_highResTimer
bsls::Types::Int64 MockTime::highResTimer() const
{
    return d_highResTimer;
}

}  // close package namespace
}  // close enterprise namespace
