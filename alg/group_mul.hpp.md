---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy_add_mul.hpp
    title: alg/lazy_add_mul.hpp
  - icon: ':heavy_check_mark:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/group_mul.hpp\"\ntemplate <class X>\r\nstruct Group_Mul\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return X(1) / x; }\r\n  static constexpr X unit = X(1);\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "template <class X>\r\nstruct Group_Mul {\r\n  using value_type = X;\r\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return x * y; }\r\n\
    \  static constexpr X inverse(const X &x) noexcept { return X(1) / x; }\r\n  static\
    \ constexpr X unit = X(1);\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_mul.hpp
  requiredBy:
  - poly/lagrange_interpolate_iota.hpp
  - seq/interpolate_poly_exp_sum.hpp
  - alg/lazy_add_mul.hpp
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899_bfsnumbering.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
documentation_of: alg/group_mul.hpp
layout: document
redirect_from:
- /library/alg/group_mul.hpp
- /library/alg/group_mul.hpp.html
title: alg/group_mul.hpp
---
