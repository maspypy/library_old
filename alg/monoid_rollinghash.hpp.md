---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_rollinghash.hpp\"\nstruct Monoid_Rolling_Hash\
    \ {\r\n  using value_type = pi; // pow of base, val\r\n  using X = value_type;\r\
    \n  static constexpr ll M61 = (1LL << 61) - 1;\r\n  static ll add(ll a, ll b)\
    \ {\r\n    if ((a += b) >= M61) a -= M61;\r\n    return a;\r\n  }\r\n  static\
    \ ll mul(ll a, ll b) {\r\n    const ll MASK30 = (1LL << 30) - 1;\r\n    const\
    \ ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 = (1LL << 61) - 1;\r\n \
    \   ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >> 31, bd = b & MASK31;\r\
    \n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30, xd = x & MASK30;\r\n \
    \   x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n    xu = x >> 61, xd = x &\
    \ MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x -= MASK61;\r\n    return\
    \ x;\r\n  }\r\n  static X op(X x, X y) {\r\n    return {mul(x.fi, y.fi), add(mul(x.se,\
    \ y.fi), y.se)};\r\n  }\r\n  static constexpr X unit = X(1, 0);\r\n  static constexpr\
    \ bool commute = false;\r\n};\n"
  code: "struct Monoid_Rolling_Hash {\r\n  using value_type = pi; // pow of base,\
    \ val\r\n  using X = value_type;\r\n  static constexpr ll M61 = (1LL << 61) -\
    \ 1;\r\n  static ll add(ll a, ll b) {\r\n    if ((a += b) >= M61) a -= M61;\r\n\
    \    return a;\r\n  }\r\n  static ll mul(ll a, ll b) {\r\n    const ll MASK30\
    \ = (1LL << 30) - 1;\r\n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll\
    \ MASK61 = (1LL << 61) - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll\
    \ bu = b >> 31, bd = b & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu\
    \ = x >> 30, xd = x & MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad *\
    \ bd;\r\n    xu = x >> 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >=\
    \ MASK61) x -= MASK61;\r\n    return x;\r\n  }\r\n  static X op(X x, X y) {\r\n\
    \    return {mul(x.fi, y.fi), add(mul(x.se, y.fi), y.se)};\r\n  }\r\n  static\
    \ constexpr X unit = X(1, 0);\r\n  static constexpr bool commute = false;\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_rollinghash.hpp
  requiredBy:
  - mod/modular_subset_sum.hpp
  timestamp: '2022-03-11 22:59:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_rollinghash.hpp
layout: document
redirect_from:
- /library/alg/monoid_rollinghash.hpp
- /library/alg/monoid_rollinghash.hpp.html
title: alg/monoid_rollinghash.hpp
---
