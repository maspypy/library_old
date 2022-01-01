---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_cntsum_affine.hpp
    title: algebra/lazy_cntsum_affine.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_cntsum.hpp\"\ntemplate <typename E = long\
    \ long>\r\nstruct CntSum {\r\n  using value_type = pair<E,E>;\r\n  using X = value_type;\r\
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
  path: algebra/monoid_cntsum.hpp
  requiredBy:
  - algebra/lazy_cntsum_affine.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_cntsum.hpp
layout: document
redirect_from:
- /library/algebra/monoid_cntsum.hpp
- /library/algebra/monoid_cntsum.hpp.html
title: algebra/monoid_cntsum.hpp
---
