---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid__old.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\
    \n  F f;\r\n  E unit;\r\n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\
    \n};\r\n\r\ntemplate <typename E, typename OP>\r\nstruct Monoid_OP {\r\n  using\
    \ F = function<E(E, E)>;\r\n  using G = function<E(E, OP)>;\r\n  using H = function<OP(OP,\
    \ OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n  E unit;\r\n  OP OP_unit;\r\n  bool\
    \ commute;\r\n  bool OP_commute;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_reverse(Monoid<E> Mono) {\r\n  auto rev_f = [=](E x, E y) -> E { return\
    \ Mono.f(y, x); };\r\n  return Monoid<E>(\r\n    {rev_f, Mono.unit, Mono.commute,\
    \ Mono.has_inverse, Mono.inverse});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E>\
    \ Monoid_add() {\r\n  auto f = [](E x, E y) -> E { return x + y; };\r\n  auto\
    \ g = [](E x) -> E { return -x; };\r\n  return Monoid<E>({f, 0, true, true, g});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f\
    \ = [](E x, E y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true,\
    \ false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF)\
    \ {\r\n  auto f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f,\
    \ MINUS_INF, true, false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E,\
    \ E>> Monoid_affine(bool has_inverse = false) {\r\n  auto f = [](pair<E, E> x,\
    \ pair<E, E> y) -> pair<E, E> {\r\n    return {x.fi * y.fi, x.se * y.fi + y.se};\r\
    \n  };\r\n  auto inv = [&](pair<E, E> x) -> pair<E, E> {\r\n    // y = ax + b\
    \ iff x = (1/a) y - (b/a)\r\n    auto [a, b] = x;\r\n    a = E(1) / a;\r\n   \
    \ return {a, a * (-b)};\r\n  };\r\n  return Monoid<pair<E, E>>({f, mp(E(1), E(0)),\
    \ false, has_inverse, inv});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid_OP<pair<E,\
    \ E>, pair<E, E>> Monoid_cnt_sum_affine() {\r\n  using P = pair<E, E>;\r\n  auto\
    \ f = [](P x, P y) -> P { return P({x.fi + y.fi, x.se + y.se}); };\r\n  auto g\
    \ = [](P x, P y) -> P { return P({x.fi, x.fi * y.se + x.se * y.fi}); };\r\n  auto\
    \ h = [](P x, P y) -> P { return P({x.fi * y.fi, x.se * y.fi + y.se}); };\r\n\
    \  return Monoid_OP<P, P>({f, g, h, P({0, 0}), P({1, 0}), true, false});\r\n}\r\
    \n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid {\r\n  using F\
    \ = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n  F f;\r\n  E unit;\r\
    \n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\n};\r\n\r\ntemplate\
    \ <typename E, typename OP>\r\nstruct Monoid_OP {\r\n  using F = function<E(E,\
    \ E)>;\r\n  using G = function<E(E, OP)>;\r\n  using H = function<OP(OP, OP)>;\r\
    \n  F f;\r\n  G g;\r\n  H h;\r\n  E unit;\r\n  OP OP_unit;\r\n  bool commute;\r\
    \n  bool OP_commute;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_reverse(Monoid<E>\
    \ Mono) {\r\n  auto rev_f = [=](E x, E y) -> E { return Mono.f(y, x); };\r\n \
    \ return Monoid<E>(\r\n    {rev_f, Mono.unit, Mono.commute, Mono.has_inverse,\
    \ Mono.inverse});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_add()\
    \ {\r\n  auto f = [](E x, E y) -> E { return x + y; };\r\n  auto g = [](E x) ->\
    \ E { return -x; };\r\n  return Monoid<E>({f, 0, true, true, g});\r\n}\r\n\r\n\
    template <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f = [](E x, E\
    \ y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true, false});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF) {\r\n  auto\
    \ f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f, MINUS_INF,\
    \ true, false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E, E>> Monoid_affine(bool\
    \ has_inverse = false) {\r\n  auto f = [](pair<E, E> x, pair<E, E> y) -> pair<E,\
    \ E> {\r\n    return {x.fi * y.fi, x.se * y.fi + y.se};\r\n  };\r\n  auto inv\
    \ = [&](pair<E, E> x) -> pair<E, E> {\r\n    // y = ax + b iff x = (1/a) y - (b/a)\r\
    \n    auto [a, b] = x;\r\n    a = E(1) / a;\r\n    return {a, a * (-b)};\r\n \
    \ };\r\n  return Monoid<pair<E, E>>({f, mp(E(1), E(0)), false, has_inverse, inv});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid_OP<pair<E, E>, pair<E, E>> Monoid_cnt_sum_affine()\
    \ {\r\n  using P = pair<E, E>;\r\n  auto f = [](P x, P y) -> P { return P({x.fi\
    \ + y.fi, x.se + y.se}); };\r\n  auto g = [](P x, P y) -> P { return P({x.fi,\
    \ x.fi * y.se + x.se * y.fi}); };\r\n  auto h = [](P x, P y) -> P { return P({x.fi\
    \ * y.fi, x.se * y.fi + y.se}); };\r\n  return Monoid_OP<P, P>({f, g, h, P({0,\
    \ 0}), P({1, 0}), true, false});\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid__old.hpp
  requiredBy: []
  timestamp: '2021-12-28 08:10:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid__old.hpp
layout: document
redirect_from:
- /library/algebra/monoid__old.hpp
- /library/algebra/monoid__old.hpp.html
title: algebra/monoid__old.hpp
---
