---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: polynomial/lagrange_interpolate_iota.hpp
    title: polynomial/lagrange_interpolate_iota.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/swag.hpp\"\ntemplate <class Monoid>\nstruct SWAG {\n\
    \  using X = typename Monoid::value_type;\n  using value_type = X;\n  vc<X> dat;\n\
    \  vc<X> cum_l;\n  X cum_r;\n\n  SWAG() : cum_l({Monoid::unit}), cum_r(Monoid::unit)\
    \ {}\n\n  void push(X x) {\n    cum_r = Monoid::op(cum_r, x);\n    dat.eb(x);\n\
    \  }\n\n  void pop() {\n    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n  \
    \    cum_l = {Monoid::unit};\n      cum_r = Monoid::unit;\n      while (len(dat)\
    \ > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n        dat.pop_back();\n\
    \      }\n      dat.pop_back();\n    }\n  }\n\n  X prod() { return Monoid::op(cum_l.back(),\
    \ cum_r); }\n\n  void debug() {\n    print(\"swag\");\n    print(\"dat\", dat);\n\
    \    print(\"cum_l\", cum_l);\n    print(\"cum_r\", cum_r);\n  }\n};\n"
  code: "template <class Monoid>\nstruct SWAG {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\n  SWAG()\
    \ : cum_l({Monoid::unit}), cum_r(Monoid::unit) {}\n\n  void push(X x) {\n    cum_r\
    \ = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void pop() {\n    cum_l.pop_back();\n\
    \    if (len(cum_l) == 0) {\n      cum_l = {Monoid::unit};\n      cum_r = Monoid::unit;\n\
    \      while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n\
    \        dat.pop_back();\n      }\n      dat.pop_back();\n    }\n  }\n\n  X prod()\
    \ { return Monoid::op(cum_l.back(), cum_r); }\n\n  void debug() {\n    print(\"\
    swag\");\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"\
    cum_r\", cum_r);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/swag.hpp
  requiredBy:
  - polynomial/lagrange_interpolate_iota.hpp
  timestamp: '2021-12-28 08:12:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
documentation_of: ds/swag.hpp
layout: document
redirect_from:
- /library/ds/swag.hpp
- /library/ds/swag.hpp.html
title: ds/swag.hpp
---
