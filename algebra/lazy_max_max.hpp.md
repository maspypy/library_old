---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algebra/monoid_max.hpp
    title: algebra/monoid_max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_max.hpp\"\ntemplate <class X, X INF>\r\n\
    struct Monoid_Max {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit\
    \ = -INF;\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"algebra/lazy_max_max.hpp\"\
    \n\r\ntemplate <typename E, E INF>\r\nstruct Lazy_Max_Max {\r\n  using MX = Monoid_Max<E,\
    \ INF>;\r\n  using MA = Monoid_Max<E, INF>;\r\n  using X_structure = MX;\r\n \
    \ using A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A\
    \ = typename MA::value_type;\r\n  static constexpr X act(const X &x, const A &a)\
    \ { return max(x, a); }\r\n};\r\n"
  code: "#include \"algebra/monoid_max.hpp\"\r\n\r\ntemplate <typename E, E INF>\r\
    \nstruct Lazy_Max_Max {\r\n  using MX = Monoid_Max<E, INF>;\r\n  using MA = Monoid_Max<E,\
    \ INF>;\r\n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X\
    \ = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a) { return max(x, a); }\r\n};\r\n"
  dependsOn:
  - algebra/monoid_max.hpp
  isVerificationFile: false
  path: algebra/lazy_max_max.hpp
  requiredBy: []
  timestamp: '2022-01-01 23:37:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy_max_max.hpp
layout: document
redirect_from:
- /library/algebra/lazy_max_max.hpp
- /library/algebra/lazy_max_max.hpp.html
title: algebra/lazy_max_max.hpp
---
