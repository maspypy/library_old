---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/addgroup.hpp
    title: algebra/addgroup.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/mulgroup.hpp
    title: algebra/mulgroup.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/addgroup.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"algebra/mulgroup.hpp\"\ntemplate\
    \ <class X, X ONE = X(1)>\r\nstruct MulGroup {\r\n  using value_type = X;\r\n\
    \  static constexpr X op(const X &x, const X &y) noexcept { return x * y; }\r\n\
    \  static constexpr X inverse(const X &x) noexcept { return X(1) / x; }\r\n  static\
    \ constexpr X unit = ONE;\r\n  static constexpr bool commute = true;\r\n};\r\n\
    #line 3 \"algebra/add_mul_lazy.hpp\"\n\r\ntemplate <typename E>\r\nstruct Add_Mul_Lazy\
    \ {\r\n  using MX = AddGroup<E>;\r\n  using MA = MulGroup<E>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return x * a; }\r\n};\r\n"
  code: "#include \"algebra/addgroup.hpp\"\r\n#include \"algebra/mulgroup.hpp\"\r\n\
    \r\ntemplate <typename E>\r\nstruct Add_Mul_Lazy {\r\n  using MX = AddGroup<E>;\r\
    \n  using MA = MulGroup<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return x * a; }\r\n};\r\n"
  dependsOn:
  - algebra/addgroup.hpp
  - algebra/mulgroup.hpp
  isVerificationFile: false
  path: algebra/add_mul_lazy.hpp
  requiredBy: []
  timestamp: '2021-12-31 00:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: algebra/add_mul_lazy.hpp
layout: document
redirect_from:
- /library/algebra/add_mul_lazy.hpp
- /library/algebra/add_mul_lazy.hpp.html
title: algebra/add_mul_lazy.hpp
---
