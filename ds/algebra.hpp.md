---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/disjointsparse.hpp
    title: ds/disjointsparse.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/algebra.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid\
    \ {\r\n  using F = function<E(E, E)>;\r\n  F f;\r\n  E E_unit;\r\n  bool commute;\r\
    \n};\r\n\r\ntemplate <typename E, typename OP, bool commute, bool OP_commute>\r\
    \nstruct Monoid_OP {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E,\
    \ OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n\
    \  E E_unit;\r\n  OP OP_unit;\r\n};\r\n\r\ntemplate <typename E>\r\nstruct Group\
    \ {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n  F f;\r\
    \n  E E_unit;\r\n  G inv;\r\n  bool commute;\r\n};\r\n\r\ntemplate <typename E>\r\
    \nMonoid<E> Monoid_min(E INF) {\r\n  auto f = [](E x, E y) -> E { return min(x,\
    \ y); };\r\n  return Monoid<E>({f, INF, true});\r\n}\r\n\r\ntemplate <typename\
    \ E>\r\nMonoid<E> Monoid_max(E MINUS_INF) {\r\n  auto f = [](E x, E y) -> E {\
    \ return max(x, y); };\r\n  return Monoid<E>({f, MINUS_INF, true});\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid {\r\n  using F\
    \ = function<E(E, E)>;\r\n  F f;\r\n  E E_unit;\r\n  bool commute;\r\n};\r\n\r\
    \ntemplate <typename E, typename OP, bool commute, bool OP_commute>\r\nstruct\
    \ Monoid_OP {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E, OP)>;\r\
    \n  using H = function<OP(OP, OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n  E E_unit;\r\
    \n  OP OP_unit;\r\n};\r\n\r\ntemplate <typename E>\r\nstruct Group {\r\n  using\
    \ F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n  F f;\r\n  E E_unit;\r\
    \n  G inv;\r\n  bool commute;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_min(E INF) {\r\n  auto f = [](E x, E y) -> E { return min(x, y); };\r\
    \n  return Monoid<E>({f, INF, true});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_max(E MINUS_INF) {\r\n  auto f = [](E x, E y) -> E { return max(x, y);\
    \ };\r\n  return Monoid<E>({f, MINUS_INF, true});\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/algebra.hpp
  requiredBy:
  - ds/disjointsparse.hpp
  timestamp: '2021-12-26 18:49:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
documentation_of: ds/algebra.hpp
layout: document
redirect_from:
- /library/ds/algebra.hpp
- /library/ds/algebra.hpp.html
title: ds/algebra.hpp
---
