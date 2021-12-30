---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fenwickraq.hpp\"\ntemplate <typename AbelGroup>\r\nstruct\
    \ FenwickRAQ {\r\n  using E = typename AbelGroup::value_type;\r\n  int n;\r\n\
    \  FenwickTree<AbelGroup> bit0;\r\n  FenwickTree<AbelGroup> bit1;\r\n\r\n  FenwickRAQ()\
    \ : FenwickRAQ(0) {}\r\n  FenwickRAQ(int n) : n(n), bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E>\
    \ v) : n(len(v)), bit0(v), bit1(len(v)) {}\r\n\r\n  void add(ll i, E val) { bit0.add(i,\
    \ val); }\r\n\r\n  void add(ll L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val,\
    \ -L));\r\n    bit0.add(R, AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\
    \n    bit1.add(R, AbelGroup::inverse(val));\r\n  }\r\n\r\n  E sum(ll L, ll R)\
    \ {\r\n    E sum_R = AbelGroup::op(AbelGroup::power(bit1.sum(R), R), bit0.sum(R));\r\
    \n    E sum_L = AbelGroup::op(AbelGroup::power(bit1.sum(L), L), bit0.sum(L));\r\
    \n    return AbelGroup::op(AbelGroup::inverse(sum_L), sum_R);\r\n  }\r\n};\r\n"
  code: "template <typename AbelGroup>\r\nstruct FenwickRAQ {\r\n  using E = typename\
    \ AbelGroup::value_type;\r\n  int n;\r\n  FenwickTree<AbelGroup> bit0;\r\n  FenwickTree<AbelGroup>\
    \ bit1;\r\n\r\n  FenwickRAQ() : FenwickRAQ(0) {}\r\n  FenwickRAQ(int n) : n(n),\
    \ bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E> v) : n(len(v)), bit0(v), bit1(len(v))\
    \ {}\r\n\r\n  void add(ll i, E val) { bit0.add(i, val); }\r\n\r\n  void add(ll\
    \ L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val, -L));\r\n    bit0.add(R,\
    \ AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\n    bit1.add(R, AbelGroup::inverse(val));\r\
    \n  }\r\n\r\n  E sum(ll L, ll R) {\r\n    E sum_R = AbelGroup::op(AbelGroup::power(bit1.sum(R),\
    \ R), bit0.sum(R));\r\n    E sum_L = AbelGroup::op(AbelGroup::power(bit1.sum(L),\
    \ L), bit0.sum(L));\r\n    return AbelGroup::op(AbelGroup::inverse(sum_L), sum_R);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickraq.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwickraq.hpp
layout: document
redirect_from:
- /library/ds/fenwickraq.hpp
- /library/ds/fenwickraq.hpp.html
title: ds/fenwickraq.hpp
---