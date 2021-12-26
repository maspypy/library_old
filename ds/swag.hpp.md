---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/monoid.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n\
    \  F f;\r\n  E unit;\r\n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\
    \n};\r\n\r\ntemplate <typename E, typename OP, bool commute, bool OP_commute>\r\
    \nstruct Monoid_OP {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E,\
    \ OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  F f;\r\n  G g;\r\n  H h;\r\n\
    \  E unit;\r\n  OP OP_unit;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_reverse(Monoid<E>\
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
    \n}\r\n#line 2 \"ds/swag.hpp\"\n\ntemplate <typename E>\nstruct SWAG {\n  using\
    \ F = function<E(E, E)>;\n  F f;\n  E e;\n  vc<E> dat;\n  vc<E> cum_l;\n  E cum_r;\n\
    \  SWAG(Monoid<E> M) : f(M.f), e(M.unit), cum_l({M.unit}), cum_r(M.unit) {}\n\n\
    \  void push(E x) {\n    cum_r = f(cum_r, x);\n    dat.eb(x);\n  }\n\n  void pop()\
    \ {\n    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n      cum_l = {e};\n \
    \     cum_r = e;\n      while (len(dat) > 1) {\n        cum_l.eb(f(dat.back(),\
    \ cum_l.back()));\n        dat.pop_back();\n      }\n      dat.pop_back();\n \
    \   }\n  }\n\n  E prod() { return f(cum_l.back(), cum_r); }\n\n  void debug()\
    \ {\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"cum_r\"\
    , cum_r);\n  }\n};\n"
  code: "#include \"algebra/monoid.hpp\"\n\ntemplate <typename E>\nstruct SWAG {\n\
    \  using F = function<E(E, E)>;\n  F f;\n  E e;\n  vc<E> dat;\n  vc<E> cum_l;\n\
    \  E cum_r;\n  SWAG(Monoid<E> M) : f(M.f), e(M.unit), cum_l({M.unit}), cum_r(M.unit)\
    \ {}\n\n  void push(E x) {\n    cum_r = f(cum_r, x);\n    dat.eb(x);\n  }\n\n\
    \  void pop() {\n    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n      cum_l\
    \ = {e};\n      cum_r = e;\n      while (len(dat) > 1) {\n        cum_l.eb(f(dat.back(),\
    \ cum_l.back()));\n        dat.pop_back();\n      }\n      dat.pop_back();\n \
    \   }\n  }\n\n  E prod() { return f(cum_l.back(), cum_r); }\n\n  void debug()\
    \ {\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"cum_r\"\
    , cum_r);\n  }\n};\n"
  dependsOn:
  - algebra/monoid.hpp
  isVerificationFile: false
  path: ds/swag.hpp
  requiredBy: []
  timestamp: '2021-12-27 03:31:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
documentation_of: ds/swag.hpp
layout: document
redirect_from:
- /library/ds/swag.hpp
- /library/ds/swag.hpp.html
title: ds/swag.hpp
---