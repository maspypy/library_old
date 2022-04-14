---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/4_modular_subset_sum.test.cpp
    title: test/yukicoder/4_modular_subset_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\nstruct modint61 {\r\n  static constexpr\
    \ bool is_modint = true;\r\n  static constexpr ll mod = (1LL << 61) - 1;\r\n \
    \ ll val;\r\n  constexpr modint61(const ll val = 0) : val(val) {}\r\n  bool operator<(const\
    \ modint61 &other) const {\r\n    return val < other.val;\r\n  } // To use std::map\r\
    \n  bool operator==(const modint61 &p) const { return val == p.val; }\r\n  bool\
    \ operator!=(const modint61 &p) const { return val != p.val; }\r\n  modint61 &operator+=(const\
    \ modint61 &p) {\r\n    if ((val += p.val) >= mod) val -= mod;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &p) {\r\n    if ((val += mod -\
    \ p.val) >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &p) {\r\n    ll a = val, b = p.val;\r\n    const ll MASK30 = (1LL <<\
    \ 30) - 1;\r\n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 =\
    \ (1LL << 61) - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >>\
    \ 31, bd = b & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30,\
    \ xd = x & MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n   \
    \ xu = x >> 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x\
    \ -= MASK61;\r\n    val = x;\r\n    return *this;\r\n  }\r\n  modint61 &operator/=(const\
    \ modint61 &p) {\r\n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n\
    \  modint61 operator+(const modint61 &p) const { return modint61(*this) += p;\
    \ }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n\r\n  modint61 inverse() const {\r\n    ll a = val, b = mod, u =\
    \ 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t\
    \ * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n\
    \  modint61 pow(int64_t n) const {\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\n      mul = mul * mul;\r\n\
    \      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n  static constexpr int get_mod()\
    \ { return mod; }\r\n};\r\n#line 3 \"alg/monoid_rollinghash.hpp\"\n\r\nstruct\
    \ Monoid_Rolling_Hash {\r\n  using value_type = pair<modint61, modint61>; // pow\
    \ of base, val\r\n  using X = value_type;\r\n  static X op(X x, X y) { return\
    \ {x.fi * y.fi, x.se * y.fi + y.se}; }\r\n  static constexpr X unit() { return\
    \ {1, 0}; }\r\n  static constexpr bool commute = false;\r\n};\n"
  code: "#pragma once\r\n#include \"mod/modint61.hpp\"\r\n\r\nstruct Monoid_Rolling_Hash\
    \ {\r\n  using value_type = pair<modint61, modint61>; // pow of base, val\r\n\
    \  using X = value_type;\r\n  static X op(X x, X y) { return {x.fi * y.fi, x.se\
    \ * y.fi + y.se}; }\r\n  static constexpr X unit() { return {1, 0}; }\r\n  static\
    \ constexpr bool commute = false;\r\n};"
  dependsOn:
  - mod/modint61.hpp
  isVerificationFile: false
  path: alg/monoid_rollinghash.hpp
  requiredBy:
  - mod/modular_subset_sum.hpp
  timestamp: '2022-04-11 18:07:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/4_modular_subset_sum.test.cpp
documentation_of: alg/monoid_rollinghash.hpp
layout: document
redirect_from:
- /library/alg/monoid_rollinghash.hpp
- /library/alg/monoid_rollinghash.hpp.html
title: alg/monoid_rollinghash.hpp
---
