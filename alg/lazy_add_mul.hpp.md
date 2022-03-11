---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/group_mul.hpp
    title: alg/group_mul.hpp
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
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/group_mul.hpp\"\ntemplate\
    \ <class X>\r\nstruct Group_Mul {\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return X(1) / x; }\r\n  static constexpr X\
    \ unit = X(1);\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"\
    alg/lazy_add_mul.hpp\"\n\r\ntemplate <typename E>\r\nstruct Lazy_Add_Mul {\r\n\
    \  using MX = Group_Add<E>;\r\n  using MA = Group_Mul<E>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return x * a; }\r\n};\r\n"
  code: "#include \"alg/group_add.hpp\"\r\n#include \"alg/group_mul.hpp\"\r\n\r\n\
    template <typename E>\r\nstruct Lazy_Add_Mul {\r\n  using MX = Group_Add<E>;\r\
    \n  using MA = Group_Mul<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return x * a; }\r\n};\r\n"
  dependsOn:
  - alg/group_add.hpp
  - alg/group_mul.hpp
  isVerificationFile: false
  path: alg/lazy_add_mul.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:47:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: alg/lazy_add_mul.hpp
layout: document
redirect_from:
- /library/alg/lazy_add_mul.hpp
- /library/alg/lazy_add_mul.hpp.html
title: alg/lazy_add_mul.hpp
---
