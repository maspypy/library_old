---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group_cntsum.hpp
    title: algebra/group_cntsum.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_set.hpp
    title: algebra/monoid_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_cntsum.hpp\"\ntemplate <typename E = long\
    \ long>\r\nstruct Group_CntSum {\r\n  using value_type = pair<E,E>;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) { return\
    \ {x.fi + y.fi, x.se + y.se}; }\r\n  static constexpr X inverse(const X &x) {\
    \ return {-x.fi, -x.se}; }\r\n  static constexpr X unit = {0, 0};\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"algebra/monoid_set.hpp\"\n\
    template <typename E, E none_val = E(-1)>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit = none_val;\r\n  static constexpr bool\
    \ commute = false;\r\n};\n#line 3 \"algebra/lazy_cntsum_set.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Lazy_CntSum_Affine {\r\n  using X_structure = Group_CntSum<E>;\r\
    \n  using A_structure = Monoid_Set<E>;\r\n  using X = typename X_structure::value_type;\r\
    \n  using A = typename A_structure::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a) {\r\n    if(a == A_structure::unit) return x;\r\n    return\
    \ {x.fi, x.fi * a};\r\n  }\r\n};\n"
  code: "#include \"algebra/group_cntsum.hpp\"\r\n#include \"algebra/monoid_set.hpp\"\
    \r\n\r\ntemplate <typename E>\r\nstruct Lazy_CntSum_Affine {\r\n  using X_structure\
    \ = Group_CntSum<E>;\r\n  using A_structure = Monoid_Set<E>;\r\n  using X = typename\
    \ X_structure::value_type;\r\n  using A = typename A_structure::value_type;\r\n\
    \  static constexpr X act(const X &x, const A &a) {\r\n    if(a == A_structure::unit)\
    \ return x;\r\n    return {x.fi, x.fi * a};\r\n  }\r\n};"
  dependsOn:
  - algebra/group_cntsum.hpp
  - algebra/monoid_set.hpp
  isVerificationFile: false
  path: algebra/lazy_cntsum_set.hpp
  requiredBy: []
  timestamp: '2022-01-01 23:37:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/lazy_cntsum_set.hpp
layout: document
redirect_from:
- /library/algebra/lazy_cntsum_set.hpp
- /library/algebra/lazy_cntsum_set.hpp.html
title: algebra/lazy_cntsum_set.hpp
---
