---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_affine.hpp
    title: alg/group_affine.hpp
  - icon: ':x:'
    path: alg/group_cntsum.hpp
    title: alg/group_cntsum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/group_cntsum.hpp\"\ntemplate <typename E = long long>\r\
    \nstruct Group_CntSum {\r\n  using value_type = pair<E,E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) { return {x.fi + y.fi, x.se\
    \ + y.se}; }\r\n  static constexpr X inverse(const X &x) { return {-x.fi, -x.se};\
    \ }\r\n  static constexpr X unit = {0, 0};\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 1 \"alg/group_affine.hpp\"\ntemplate <typename K>\nstruct\
    \ Group_Affine {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr\
    \ F op(const F &x, const F &y) noexcept {\n    return F({x.fi * y.fi, x.se * y.fi\
    \ + y.se});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a, b]\
    \ = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept { return f.fi * x + f.se; }\n  static constexpr\
    \ F unit() { return {K(1), K(0)}; }\n  static constexpr bool commute = false;\n\
    };\n#line 3 \"alg/lazy_cntsum_affine.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Lazy_CntSum_Affine {\r\n  using X_structure = Group_CntSum<E>;\r\n  using A_structure\
    \ = Group_Affine<E>;\r\n  using X = typename X_structure::value_type;\r\n  using\
    \ A = typename A_structure::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) {\r\n    return {x.fi, x.fi * a.se + x.se * a.fi};\r\n  }\r\n};\n"
  code: "#include \"alg/group_cntsum.hpp\"\r\n#include \"alg/group_affine.hpp\"\r\n\
    \r\ntemplate <typename E>\r\nstruct Lazy_CntSum_Affine {\r\n  using X_structure\
    \ = Group_CntSum<E>;\r\n  using A_structure = Group_Affine<E>;\r\n  using X =\
    \ typename X_structure::value_type;\r\n  using A = typename A_structure::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    return {x.fi, x.fi\
    \ * a.se + x.se * a.fi};\r\n  }\r\n};"
  dependsOn:
  - alg/group_cntsum.hpp
  - alg/group_affine.hpp
  isVerificationFile: false
  path: alg/lazy_cntsum_affine.hpp
  requiredBy: []
  timestamp: '2022-04-11 17:48:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
documentation_of: alg/lazy_cntsum_affine.hpp
layout: document
redirect_from:
- /library/alg/lazy_cntsum_affine.hpp
- /library/alg/lazy_cntsum_affine.hpp.html
title: alg/lazy_cntsum_affine.hpp
---
