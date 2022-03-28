---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid_reverse.hpp
    title: alg/monoid_reverse.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/lazytreemonoid.hpp
    title: graph/lazytreemonoid.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\nstruct\
    \ Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) { return\
    \ Monoid::op(y, x); }\r\n  static constexpr X unit = Monoid::unit;\r\n  static\
    \ const bool commute = Monoid::commute;\r\n};\r\n#line 2 \"alg/lazy_reverse.hpp\"\
    \n\r\ntemplate <typename Lazy>\r\nstruct Lazy_Reverse {\r\n  using MX = Monoid_Reverse<typename\
    \ Lazy::X_structure>;\r\n  using MA = typename Lazy::A_structure;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return Lazy::act(x, a); }\r\n};\r\n"
  code: "#include \"alg/monoid_reverse.hpp\"\r\n\r\ntemplate <typename Lazy>\r\nstruct\
    \ Lazy_Reverse {\r\n  using MX = Monoid_Reverse<typename Lazy::X_structure>;\r\
    \n  using MA = typename Lazy::A_structure;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) { return\
    \ Lazy::act(x, a); }\r\n};\r\n"
  dependsOn:
  - alg/monoid_reverse.hpp
  isVerificationFile: false
  path: alg/lazy_reverse.hpp
  requiredBy:
  - graph/lazytreemonoid.hpp
  timestamp: '2022-01-11 13:47:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_reverse.hpp
layout: document
redirect_from:
- /library/alg/lazy_reverse.hpp
- /library/alg/lazy_reverse.hpp.html
title: alg/lazy_reverse.hpp
---
