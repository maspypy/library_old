---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_max_max.hpp
    title: alg/lazy_max_max.hpp
  - icon: ':warning:'
    path: alg/lazy_max_set.hpp
    title: alg/lazy_max_set.hpp
  - icon: ':warning:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_max.hpp\"\ntemplate <class X=long long, X INF=1LL<<60>\r\
    \nstruct Monoid_Max {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit\
    \ = -INF;\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X=long long, X INF=1LL<<60>\r\nstruct Monoid_Max {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return max(x, y); }\r\n  static constexpr X unit = -INF;\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_max.hpp
  requiredBy:
  - alg/lazy_max_max.hpp
  - alg/lazy_max_set.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-02-03 13:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_max.hpp
layout: document
redirect_from:
- /library/alg/monoid_max.hpp
- /library/alg/monoid_max.hpp.html
title: alg/monoid_max.hpp
---
