---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_reverse.hpp
    title: alg/lazy_reverse.hpp
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
    \ const bool commute = Monoid::commute;\r\n};\r\n"
  code: "template <class Monoid>\r\nstruct Monoid_Reverse {\r\n  using value_type\
    \ = typename Monoid::value_type;\r\n  using X = value_type;\r\n  static constexpr\
    \ X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\n  static constexpr\
    \ X unit = Monoid::unit;\r\n  static const bool commute = Monoid::commute;\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_reverse.hpp
  requiredBy:
  - alg/lazy_reverse.hpp
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid_reverse.hpp
- /library/alg/monoid_reverse.hpp.html
title: alg/monoid_reverse.hpp
---
