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

// bmqa_abstractsession.cpp                                           -*-C++-*-
#include <bmqa_abstractsession.h>

#include <bmqscm_version.h>
// BDE
#include <bsla_annotations.h>
#include <bslma_allocator.h>
#include <bsls_assert.h>

namespace BloombergLP {
namespace bmqa {

// ---------------------
// class AbstractSession
// ---------------------

AbstractSession::~AbstractSession()
{
    // NOTHING
}

// MANIPULATORS

/// Session management
///------------------
__out == -1
int AbstractSession::start(BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out == -1
int AbstractSession::startAsync(BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

void AbstractSession::stop()
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

void AbstractSession::stopAsync()
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

void AbstractSession::finalizeStop()
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

void AbstractSession::loadMessageEventBuilder(
    BSLA_UNUSED MessageEventBuilder* builder)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

void AbstractSession::loadConfirmEventBuilder(
    BSLA_UNUSED ConfirmEventBuilder* builder)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

void AbstractSession::loadMessageProperties(
    BSLA_UNUSED MessageProperties* buffer)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

/// Queue management
///----------------
__out == -1
int AbstractSession::getQueueId(BSLA_UNUSED QueueId* queueId,
                                BSLA_UNUSED const bmqt::Uri& uri)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out == -1
int AbstractSession::getQueueId(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bmqt::CorrelationId& correlationId)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out == -1
int AbstractSession::openQueue(BSLA_UNUSED QueueId* queueId,
                               BSLA_UNUSED const bmqt::Uri& uri,
                               BSLA_UNUSED bsls::Types::Uint64 flags,
                               BSLA_UNUSED const bmqt::QueueOptions& options,
                               BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out.queueId() == bmqa::QueueId(
OpenQueueStatus
AbstractSession::openQueueSync(BSLA_UNUSED QueueId* queueId,
                               BSLA_UNUSED const bmqt::Uri& uri,
                               BSLA_UNUSED bsls::Types::Uint64 flags,
                               BSLA_UNUSED const bmqt::QueueOptions& options,
                               BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return bmqa::OpenQueueStatus(bmqa::QueueId(),
                                 bmqt::OpenQueueResult::e_NOT_SUPPORTED,
                                 "Method is undefined in base protocol");
}

__out == -1
int AbstractSession::openQueueAsync(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bmqt::Uri& uri,
    BSLA_UNUSED bsls::Types::Uint64 flags,
    BSLA_UNUSED const bmqt::QueueOptions& options,
    BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

void AbstractSession::openQueueAsync(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bmqt::Uri& uri,
    BSLA_UNUSED bsls::Types::Uint64      flags,
    BSLA_UNUSED const OpenQueueCallback& callback,
    BSLA_UNUSED const bmqt::QueueOptions& options,
    BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

__out == -1
int AbstractSession::configureQueue(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bmqt::QueueOptions& options,
    BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out.result() == bmqt::ConfigureQueueResult::e_NOT_SUPPORTED
ConfigureQueueStatus AbstractSession::configureQueueSync(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bmqt::QueueOptions& options,
    BSLA_UNUSED const bsls::TimeInterval& timeout)

{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return bmqa::ConfigureQueueStatus(
        bmqa::QueueId(),
        bmqt::ConfigureQueueResult::e_NOT_SUPPORTED,
        "Method is undefined in base protocol");
}

__out == -1
int AbstractSession::configureQueueAsync(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bmqt::QueueOptions& options,
    BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

void AbstractSession::configureQueueAsync(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bmqt::QueueOptions&     options,
    BSLA_UNUSED const ConfigureQueueCallback& callback,
    BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

__out == -1
int AbstractSession::closeQueue(BSLA_UNUSED QueueId* queueId,
                                BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out.queueId() == BloombergLP::bmqa::QueueId() && __out.result() == BloombergLP::bmqt::CloseQueueResult::e_NOT_SUPPORTED
CloseQueueStatus
AbstractSession::closeQueueSync(BSLA_UNUSED QueueId* queueId,
                                BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return bmqa::CloseQueueStatus(bmqa::QueueId(),
                                  bmqt::CloseQueueResult::e_NOT_SUPPORTED,
                                  "Method is undefined in base protocol");
}

__out == -1
int AbstractSession::closeQueueAsync(
    BSLA_UNUSED QueueId* queueId,
    BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

void AbstractSession::closeQueueAsync(
    BSLA_UNUSED QueueId*                  queueId,
    BSLA_UNUSED const CloseQueueCallback& callback,
    BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");
}

/// Queue manipulation
///------------------
Event AbstractSession::nextEvent(BSLA_UNUSED const bsls::TimeInterval& timeout)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return Event();
}

__out == -1
int AbstractSession::post(BSLA_UNUSED const MessageEvent& event)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out == -1
int AbstractSession::confirmMessage(BSLA_UNUSED const Message& message)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out == -1
int AbstractSession::confirmMessage(
    BSLA_UNUSED const MessageConfirmationCookie& cookie)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

__out == -1
int AbstractSession::confirmMessages(BSLA_UNUSED ConfirmEventBuilder* builder)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

/// Debugging related
///-----------------
__out == -1
int AbstractSession::configureMessageDumping(
    BSLA_UNUSED const bslstl::StringRef& command)
{
    // PRECONDITIONS
    BSLS_ASSERT_OPT(false && "Method is undefined in base protocol");

    return -1;
}

}  // close package namespace
}  // close enterprise namespace
