---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_cntsum_affine.hpp
    title: algebra/lazy_cntsum_affine.hpp
  - icon: ':warning:'
    path: algebra/lazy_cntsum_set.hpp
    title: algebra/lazy_cntsum_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_cntsum.hpp\"\ntemplate <typename E = long\
    \ long>\r\nstruct Group_CntSum {\r\n  using value_type = pair<E,E>;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) { return\
    \ {x.fi + y.fi, x.se + y.se}; }\r\n  static constexpr X inverse(const X &x) {\
    \ return {-x.fi, -x.se}; }\r\n  static constexpr X unit = {0, 0};\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename E = long long>\r\nstruct Group_CntSum {\r\n  using value_type\
    \ = pair<E,E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X &x,\
    \ const X &y) { return {x.fi + y.fi, x.se + y.se}; }\r\n  static constexpr X inverse(const\
    \ X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit = {0, 0};\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_cntsum.hpp
  requiredBy:
  - algebra/lazy_cntsum_affine.hpp
  - algebra/lazy_cntsum_set.hpp
  timestamp: '2022-01-01 23:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
documentation_of: algebra/group_cntsum.hpp
layout: document
redirect_from:
- /library/algebra/group_cntsum.hpp
- /library/algebra/group_cntsum.hpp.html
title: algebra/group_cntsum.hpp
---
