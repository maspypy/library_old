---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
  - icon: ':heavy_check_mark:'
    path: mod/binomial.hpp
    title: mod/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  - icon: ':heavy_check_mark:'
    path: nt/divisors.hpp
    title: nt/divisors.hpp
  - icon: ':heavy_check_mark:'
    path: nt/euler_phi.hpp
    title: nt/euler_phi.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C_primetest.test.cpp
    title: test/aoj/ALDS1_1_C_primetest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_D_D_divisors.test.cpp
    title: test/aoj/ITP1_D_D_divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient.test.cpp
    title: test/library_checker/math/binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/factorize.test.cpp
    title: test/library_checker/math/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n    using i64 = int64_t;\r\
    \n    using u64 = uint64_t;\r\n    using u128 = __uint128_t;\r\n\r\n    inline\
    \ static u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n    static\
    \ void set_mod(u64 m) {\r\n        assert(m < (1ull << 62));\r\n        assert((m\
    \ & 1) == 1);\r\n        m64::m = m;\r\n        n2 = -u128(m) % m;\r\n       \
    \ r = m;\r\n        FOR (_, 5) r *= 2 - m*r;\r\n        r = -r;\r\n        assert(r\
    \ * m == -1ull);\r\n    }\r\n    static u64 reduce(u128 b) { return (b + u128(u64(b)\
    \ * r) * m) >> 64; }\r\n\r\n    u64 x;\r\n    m64() : x(0) {}\r\n    m64(u64 x)\
    \ : x(reduce(u128(x) * n2)){};\r\n    u64 val() const { u64 y = reduce(x); return\
    \ y >= m ? y-m : y; }\r\n    m64 &operator+=(m64 y) {\r\n        x += y.x - (m\
    \ << 1);\r\n        x = (i64(x) < 0 ? x + (m << 1) : x);\r\n        return *this;\r\
    \n    }\r\n    m64 &operator-=(m64 y) {\r\n        x -= y.x;\r\n        x = (i64(x)\
    \ < 0 ? x + (m << 1) : x);\r\n        return *this;\r\n    }\r\n    m64 &operator*=(m64\
    \ y) { x = reduce(u128(x) * y.x); return *this; }\r\n    m64 operator+(m64 y)\
    \ const { return m64(*this) += y; }\r\n    m64 operator-(m64 y) const { return\
    \ m64(*this) -= y; }\r\n    m64 operator*(m64 y) const { return m64(*this) *=\
    \ y; }\r\n    bool operator==(m64 y) const { return (x >= m ? x-m : x) == (y.x\
    \ >= m ? y.x-m : y.x); }\r\n    bool operator!=(m64 y) const { return not operator==(y);\
    \ }\r\n    m64 pow(u64 n) const {\r\n        m64 y = 1, z = *this;\r\n       \
    \ for ( ; n; n >>= 1, z *= z) if (n & 1) y *= z;\r\n        return y;\r\n    }\r\
    \n};\r\n\r\nbool primetest(const uint64_t x) {\r\n    using u64 = uint64_t;\r\n\
    \    if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\n    if (x % 2 ==\
    \ 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n    if (x < 121)\
    \ return x > 1;\r\n    const u64 d = (x-1) >> __builtin_ctzll(x-1);\r\n    m64::set_mod(x);\r\
    \n    const m64 one(1), minus_one(x-1);\r\n    auto ok = [&](u64 a) {\r\n    \
    \    auto y = m64(a).pow(d);\r\n        u64 t = d;\r\n        while (y != one\
    \ and y != minus_one and t != x-1) y *= y, t <<= 1;\r\n        if (y != minus_one\
    \ and t % 2 == 0) return false;\r\n        return true;\r\n    };\r\n    if (x\
    \ < (1ull << 32)) {\r\n        for (u64 a : { 2, 7, 61 }) if (not ok(a)) return\
    \ false;\r\n    } else {\r\n        for (u64 a : { 2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022 }) {\r\n            if (x <= a) return true;\r\n       \
    \     if (not ok(a)) return false;\r\n        }\r\n    }\r\n    return true;\r\
    \n}\n"
  code: "#pragma once\r\nstruct m64 {\r\n    using i64 = int64_t;\r\n    using u64\
    \ = uint64_t;\r\n    using u128 = __uint128_t;\r\n\r\n    inline static u64 m,\
    \ r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n    static void set_mod(u64\
    \ m) {\r\n        assert(m < (1ull << 62));\r\n        assert((m & 1) == 1);\r\
    \n        m64::m = m;\r\n        n2 = -u128(m) % m;\r\n        r = m;\r\n    \
    \    FOR (_, 5) r *= 2 - m*r;\r\n        r = -r;\r\n        assert(r * m == -1ull);\r\
    \n    }\r\n    static u64 reduce(u128 b) { return (b + u128(u64(b) * r) * m) >>\
    \ 64; }\r\n\r\n    u64 x;\r\n    m64() : x(0) {}\r\n    m64(u64 x) : x(reduce(u128(x)\
    \ * n2)){};\r\n    u64 val() const { u64 y = reduce(x); return y >= m ? y-m :\
    \ y; }\r\n    m64 &operator+=(m64 y) {\r\n        x += y.x - (m << 1);\r\n   \
    \     x = (i64(x) < 0 ? x + (m << 1) : x);\r\n        return *this;\r\n    }\r\
    \n    m64 &operator-=(m64 y) {\r\n        x -= y.x;\r\n        x = (i64(x) < 0\
    \ ? x + (m << 1) : x);\r\n        return *this;\r\n    }\r\n    m64 &operator*=(m64\
    \ y) { x = reduce(u128(x) * y.x); return *this; }\r\n    m64 operator+(m64 y)\
    \ const { return m64(*this) += y; }\r\n    m64 operator-(m64 y) const { return\
    \ m64(*this) -= y; }\r\n    m64 operator*(m64 y) const { return m64(*this) *=\
    \ y; }\r\n    bool operator==(m64 y) const { return (x >= m ? x-m : x) == (y.x\
    \ >= m ? y.x-m : y.x); }\r\n    bool operator!=(m64 y) const { return not operator==(y);\
    \ }\r\n    m64 pow(u64 n) const {\r\n        m64 y = 1, z = *this;\r\n       \
    \ for ( ; n; n >>= 1, z *= z) if (n & 1) y *= z;\r\n        return y;\r\n    }\r\
    \n};\r\n\r\nbool primetest(const uint64_t x) {\r\n    using u64 = uint64_t;\r\n\
    \    if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\n    if (x % 2 ==\
    \ 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n    if (x < 121)\
    \ return x > 1;\r\n    const u64 d = (x-1) >> __builtin_ctzll(x-1);\r\n    m64::set_mod(x);\r\
    \n    const m64 one(1), minus_one(x-1);\r\n    auto ok = [&](u64 a) {\r\n    \
    \    auto y = m64(a).pow(d);\r\n        u64 t = d;\r\n        while (y != one\
    \ and y != minus_one and t != x-1) y *= y, t <<= 1;\r\n        if (y != minus_one\
    \ and t % 2 == 0) return false;\r\n        return true;\r\n    };\r\n    if (x\
    \ < (1ull << 32)) {\r\n        for (u64 a : { 2, 7, 61 }) if (not ok(a)) return\
    \ false;\r\n    } else {\r\n        for (u64 a : { 2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022 }) {\r\n            if (x <= a) return true;\r\n       \
    \     if (not ok(a)) return false;\r\n        }\r\n    }\r\n    return true;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/primetest.hpp
  requiredBy:
  - graph/chromatic.hpp
  - mod/mod_kth_root.hpp
  - mod/tetration.hpp
  - mod/binomial.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - nt/divisors.hpp
  - nt/euler_phi.hpp
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C_primetest.test.cpp
  - test/aoj/ITP1_D_D_divisors.test.cpp
  - test/library_checker/math/binomial_coefficient.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/factorize.test.cpp
  - test/library_checker/math/tetration.test.cpp
  - test/library_checker/graph/chromatic_number.test.cpp
documentation_of: nt/primetest.hpp
layout: document
redirect_from:
- /library/nt/primetest.hpp
- /library/nt/primetest.hpp.html
title: nt/primetest.hpp
---
