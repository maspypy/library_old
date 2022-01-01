---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_max_set.hpp
    title: algebra/lazy_max_set.hpp
  - icon: ':warning:'
    path: algebra/lazy_min_add.hpp
    title: algebra/lazy_min_add.hpp
  - icon: ':warning:'
    path: algebra/lazy_min_set.hpp
    title: algebra/lazy_min_set.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_min.hpp\"\ntemplate <class X, X INF>\r\n\
    struct MinMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit\
    \ = INF;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct MinMonoid {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit = INF;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_min.hpp
  requiredBy:
  - algebra/lazy_min_add.hpp
  - algebra/lazy_max_set.hpp
  - algebra/lazy_min_set.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_min.hpp
layout: document
redirect_from:
- /library/algebra/monoid_min.hpp
- /library/algebra/monoid_min.hpp.html
title: algebra/monoid_min.hpp
---
