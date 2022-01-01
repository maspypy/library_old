---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_reverse.hpp
    title: algebra/lazy_reverse.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\n\
    struct ReverseMonoid {\r\n  using value_type = typename Monoid::value_type;\r\n\
    \  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit = Monoid::unit;\r\n\
    \  static const bool commute = Monoid::commute;\r\n};\r\n"
  code: "template <class Monoid>\r\nstruct ReverseMonoid {\r\n  using value_type =\
    \ typename Monoid::value_type;\r\n  using X = value_type;\r\n  static constexpr\
    \ X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\n  static constexpr\
    \ X unit = Monoid::unit;\r\n  static const bool commute = Monoid::commute;\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_reverse.hpp
  requiredBy:
  - algebra/lazy_reverse.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_reverse.hpp
layout: document
redirect_from:
- /library/algebra/monoid_reverse.hpp
- /library/algebra/monoid_reverse.hpp.html
title: algebra/monoid_reverse.hpp
---
