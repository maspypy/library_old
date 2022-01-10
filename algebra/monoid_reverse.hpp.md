---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_reverse.hpp
    title: algebra/lazy_reverse.hpp
  - icon: ':warning:'
    path: graph/lazytreemonoid.hpp
    title: graph/lazytreemonoid.hpp
  - icon: ':question:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\n\
    struct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit = Monoid::unit;\r\n\
    \  static const bool commute = Monoid::commute;\r\n};\r\n"
  code: "template <class Monoid>\r\nstruct Monoid_Reverse {\r\n  using value_type\
    \ = typename Monoid::value_type;\r\n  using X = value_type;\r\n  static constexpr\
    \ X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\n  static constexpr\
    \ X unit = Monoid::unit;\r\n  static const bool commute = Monoid::commute;\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_reverse.hpp
  requiredBy:
  - graph/treemonoid.hpp
  - graph/lazytreemonoid.hpp
  - algebra/lazy_reverse.hpp
  timestamp: '2022-01-01 23:37:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: algebra/monoid_reverse.hpp
layout: document
redirect_from:
- /library/algebra/monoid_reverse.hpp
- /library/algebra/monoid_reverse.hpp.html
title: algebra/monoid_reverse.hpp
---
