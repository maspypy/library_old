---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/treemonoid.hpp
    title: tree/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/reversemonoid.hpp\"\ntemplate <class Monoid>\r\n\
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
  path: algebra/reversemonoid.hpp
  requiredBy:
  - tree/treemonoid.hpp
  timestamp: '2021-12-30 04:14:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: algebra/reversemonoid.hpp
layout: document
redirect_from:
- /library/algebra/reversemonoid.hpp
- /library/algebra/reversemonoid.hpp.html
title: algebra/reversemonoid.hpp
---
