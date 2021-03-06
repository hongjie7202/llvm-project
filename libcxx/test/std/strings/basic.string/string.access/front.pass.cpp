//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// const charT& front() const;
//       charT& front();

#ifdef _LIBCPP_DEBUG
#define _LIBCPP_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))
#endif

#include <string>
#include <cassert>

#include "min_allocator.h"

template <class S>
void
test(S s)
{
    const S& cs = s;
    assert(&cs.front() == &cs[0]);
    assert(&s.front() == &s[0]);
    s.front() = typename S::value_type('z');
    assert(s.front() == typename S::value_type('z'));
}

int main(int, char**)
{
    {
    typedef std::string S;
    test(S("1"));
    test(S("1234567890123456789012345678901234567890"));
    }
#if TEST_STD_VER >= 11
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    test(S("1"));
    test(S("1234567890123456789012345678901234567890"));
    }
#endif
#ifdef _LIBCPP_DEBUG
    {
        std::string s;
        char c = s.front();
        assert(false);
    }
#endif

  return 0;
}
