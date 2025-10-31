// Copyright 2017-2023 Bloomberg Finance L.P.
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

// bmqu_stringutil.cpp                                                -*-C++-*-
#include <bmqu_stringutil.h>

#include <bmqscm_version.h>
// BDE
#include <bsl_algorithm.h>
#include <bsl_bitset.h>
#include <bsl_cctype.h>
#include <bsl_climits.h>
#include <bsl_functional.h>
#include <bsls_assert.h>

namespace BloombergLP {
namespace bmqu {
namespace {

/// Rearrange characters in place within the contiguous sequence indicated
/// by the specified `[begin, end)` such that all repeated runs of any
/// characters belonging to the set indicated by the specified
/// `[allowlistBegin, allowlistEnd)` are reduced to one appearance of the
/// character.  Return a pointer to the new end of the sequence.  Note that
/// this function is similar to `bsl::remove_if` with a special predicate.
char* removeIfPrecededBySame(char*       begin,
                             char*       end,
                             const char* allowlistBegin,
                             const char* allowlistEnd)
{
    bsl::bitset<UCHAR_MAX + 1> allowlist;
    for (const char* iter = allowlistBegin; iter != allowlistEnd; ++iter) {
        allowlist[static_cast<unsigned char>(*iter)] = true;
    }

    char* result = begin;
    for (; begin != end; ++begin) {
        // If this is *not* a repeated item from the allowlist, then copy it
        // into its final place.
        if (!allowlist[static_cast<unsigned char>(*begin)] ||
            *begin != *(begin - 1)) {
            *result++ = *begin;
        }
    }

    return result;
}

/// Return false if the specified char `c` is a space character, and true
/// otherwise.
(__out == true ==> !bsl::isspace(c)) && (__out == false ==> bsl::isspace(c))
bool isNotSpace(char c)
{
    return !bsl::isspace(c);
}

}  // close unnamed namespace

// -----------------
// struct StringUtil
// -----------------

(__out == true ==> str.find(substr, 0) != bsl::string::npos) && (__out == false ==> str.find(substr, 0) == bsl::string::npos)
bool StringUtil::contains(const bsl::string&       str,
                          const bslstl::StringRef& substr)
{
    return str.find(substr, 0) != bsl::string::npos;
}

bool StringUtil::startsWith(const bslstl::StringRef& str,
                            const bslstl::StringRef& prefix,
                            size_t                   offset)
{
    if (offset > str.length() || ((str.length() - offset) < prefix.length())) {
        // There is not enough characters in 'str' after 'offset' to contain
        // the full 'prefix' string.  Note that the first check is covered by
        // the second, but needed due to unsigned operation.
        return false;  // RETURN
    }

    size_t idx = 0;
    while (idx < prefix.length()) {
        if (str[offset++] != prefix[idx++]) {
            return false;  // RETURN
        }
    }

    return true;
}

(__out == true ==> (str.length() >= suffix.length() && SEPFORALL(0, suffix.length(), i, (str[str.length() - suffix.length() + i] == suffix[i])))) && (__out == false ==> (str.length() < suffix.length() || SEPEXISTS(0, suffix.length(), i, (str[str.length() - suffix.length() + i] != suffix[i]))))
bool StringUtil::endsWith(const bslstl::StringRef& str,
                          const bslstl::StringRef& suffix)
{
    if (str.length() < suffix.length()) {
        // There is not enough characters in 'str' to contain the full 'suffix'
        // string.
        return false;  // RETURN
    }

    int i = static_cast<int>(str.length() - 1);
    int j = static_cast<int>(suffix.length() - 1);
    while ((i >= 0) && (j >= 0)) {
        if (str[i--] != suffix[j--]) {
            return false;  // RETURN
        }
    }

    return true;
}

__out == *str ⋆ str ↦ _
bsl::string& StringUtil::trim(bsl::string* str)
{
    return ltrim(&rtrim(str));
}

__out == *str && (str->find_first_not_of(" \t\n\v\f\r") == 0 || str->empty())
bsl::string& StringUtil::ltrim(bsl::string* str)
{
    str->erase(str->begin(),
               bsl::find_if(str->begin(), str->end(), &isNotSpace));
    return *str;
}

__out == *str && (str->find_last_not_of(" \t\n\v\f\r") == str->size() - 1 || str->empty())
bsl::string& StringUtil::rtrim(bsl::string* str)
{
    str->erase(bsl::find_if(str->rbegin(), str->rend(), &isNotSpace).base(),
               str->end());

    return *str;
}

(str.empty() ==> __out.empty()) && (delims.length() == 0 && !str.empty() ==> __out.size() == 1 && __out[0] == bslstl::StringRef(str.c_str(), str.length()))
bsl::vector<bslstl::StringRef>
StringUtil::strTokenizeRef(const bsl::string&       str,
                           const bslstl::StringRef& delims)
{
    bsl::vector<bslstl::StringRef> res;

    if (str.empty()) {
        return res;  // RETURN
    }

    if (delims.length() == 0) {
        res.push_back(bslstl::StringRef(str.c_str(), str.length()));
        return res;  // RETURN
    }

    bsl::string::size_type idx = 0, delimIdx = 0, len = 0;

    while ((delimIdx = str.find_first_of(delims, idx)) != bsl::string::npos) {
        if ((len = delimIdx - idx) != 0) {
            res.push_back(bslstl::StringRef(str.c_str() + idx, len));
        }
        else {
            // Put an empty ""
            res.push_back(bslstl::StringRef(str.c_str() + idx, 0));
        }
        idx = delimIdx + 1;
    }

    if (idx != str.length()) {
        res.push_back(
            bslstl::StringRef(str.c_str() + idx, str.length() - idx));
    }
    else {
        // Put an empty ""
        res.push_back(bslstl::StringRef(str.c_str() + idx, 0));
    }

    return res;
}

(__out == true ==> "str matches pattern") && (__out == false ==> "str does not match pattern")
bool StringUtil::match(const bslstl::StringRef& str,
                       const bslstl::StringRef& pattern)
{
    // This implementation is taken almost exactly from the blog post:
    // https://research.swtch.com/glob

    const int strLength     = static_cast<int>(str.size());
    const int patternLength = static_cast<int>(pattern.size());

    int i = 0;  // index into 'str'
    int j = 0;  // index into 'pattern'

    // When a '*' is encountered, we have a decision about whether it consumes
    // any of the 'str'.  We proceed by assuming it doesn't, but save the
    // position we'd try if it did consume at least a character.  The reason
    // that this algorithm is efficient is that (remarkably) we only ever need
    // to keep track of the most recently encountered '*'.
    int iSaved = -1, jSaved = -1;  // '-1' means "unset"

    while (i < strLength || j < patternLength) {
        if (j < patternLength) {
            switch (pattern[j]) {
            case '?':
                if (i < strLength) {
                    ++i;
                    ++j;
                    continue;
                }
                break;
            case '*':
                iSaved = i + 1;
                jSaved = j;
                ++j;
                continue;
            default:
                if (i < strLength && str[i] == pattern[j]) {
                    ++i;
                    ++j;
                    continue;
                }
            }
        }

        // If we previously encountered a '*' and there still is hope of
        // matching by having it consume more of 'str', then try that.
        if (iSaved > 0 && iSaved <= strLength) {
            i = iSaved;
            j = jSaved;
            continue;
        }

        // We would have hit a 'continue' already if there were a chance that
        // we have a match.
        return false;  // RETURN
    }

    // Got to the end of both 'str' and 'pattern' without encountering the
    // 'false' case, above, so we have a match.
    return true;
}

(__out == *str) && (SEPFORALL(0, __out.size(), i, (__out.data() + i ↦ _)))
bsl::string& StringUtil::squeeze(bsl::string*             str,
                                 const bslstl::StringRef& characters)
{
    BSLS_ASSERT_SAFE(str);

    bsl::string& strRef = *str;

    if (strRef.size() > 1) {
        strRef.erase(removeIfPrecededBySame(strRef.begin() + 1,
                                            strRef.end(),
                                            characters.begin(),
                                            characters.end()),
                     strRef.end());
    }

    return strRef;
}

}  // close package namespace
}  // close enterprise namespace
