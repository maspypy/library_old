---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/cntsum_affine_lazy.hpp
    title: algebra/cntsum_affine_lazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/cntsum.hpp\"\ntemplate <typename E = long long>\r\
    \nstruct CntSum {\r\n  using value_type = pair<E,E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) { return {x.fi + y.fi, x.se\
    \ + y.se}; }\r\n  static constexpr X inverse(const X &x) { return {-x.fi, -x.se};\
    \ }\r\n  static constexpr X unit = {0, 0};\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  code: "template <typename E = long long>\r\nstruct CntSum {\r\n  using value_type\
    \ = pair<E,E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X &x,\
    \ const X &y) { return {x.fi + y.fi, x.se + y.se}; }\r\n  static constexpr X inverse(const\
    \ X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit = {0, 0};\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/cntsum.hpp
  requiredBy:
  - algebra/cntsum_affine_lazy.hpp
  timestamp: '2021-12-30 04:54:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
documentation_of: algebra/cntsum.hpp
layout: document
redirect_from:
- /library/algebra/cntsum.hpp
- /library/algebra/cntsum.hpp.html
title: algebra/cntsum.hpp
---
