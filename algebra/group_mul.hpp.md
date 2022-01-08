---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_add_mul.hpp
    title: algebra/lazy_add_mul.hpp
  - icon: ':x:'
    path: polynomial/lagrange_interpolate_iota.hpp
    title: polynomial/lagrange_interpolate_iota.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_mul.hpp\"\ntemplate <class X>\r\nstruct Group_Mul\
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
  path: algebra/group_mul.hpp
  requiredBy:
  - algebra/lazy_add_mul.hpp
  - polynomial/lagrange_interpolate_iota.hpp
  timestamp: '2022-01-08 10:07:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: algebra/group_mul.hpp
layout: document
redirect_from:
- /library/algebra/group_mul.hpp
- /library/algebra/group_mul.hpp.html
title: algebra/group_mul.hpp
---
