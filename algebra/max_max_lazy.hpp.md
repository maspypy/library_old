---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algebra/maxmonoid.hpp
    title: algebra/maxmonoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/maxmonoid.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ MaxMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit = -INF;\r\
    \n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"algebra/max_max_lazy.hpp\"\
    \n\r\ntemplate <typename E, E INF = 1 << 30>\r\nstruct Max_Max_Lazy {\r\n  using\
    \ MX = MaxMonoid<E, INF>;\r\n  using MA = MaxMonoid<E, INF>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return max(x, a); }\r\n};\r\n"
  code: "#include \"algebra/maxmonoid.hpp\"\r\n\r\ntemplate <typename E, E INF = 1\
    \ << 30>\r\nstruct Max_Max_Lazy {\r\n  using MX = MaxMonoid<E, INF>;\r\n  using\
    \ MA = MaxMonoid<E, INF>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return max(x, a); }\r\n};\r\
    \n"
  dependsOn:
  - algebra/maxmonoid.hpp
  isVerificationFile: false
  path: algebra/max_max_lazy.hpp
  requiredBy: []
  timestamp: '2021-12-31 00:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/max_max_lazy.hpp
layout: document
redirect_from:
- /library/algebra/max_max_lazy.hpp
- /library/algebra/max_max_lazy.hpp.html
title: algebra/max_max_lazy.hpp
---
