---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/cntsum_affine_lazy.hpp
    title: algebra/cntsum_affine_lazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/affinegroup.hpp\"\ntemplate <typename K>\nstruct\
    \ AffineGroup {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr\
    \ F op(const F &x, const F &y) noexcept {\n    return F({x.fi * y.fi, x.se * y.fi\
    \ + y.se});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a, b]\
    \ = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept { return f.fi * x + f.se; }\n  static constexpr\
    \ F unit = {K(1), K(0)};\n  static constexpr bool commute = false;\n};\n"
  code: "template <typename K>\nstruct AffineGroup {\n  using F = pair<K, K>;\n  using\
    \ value_type = F;\n  static constexpr F op(const F &x, const F &y) noexcept {\n\
    \    return F({x.fi * y.fi, x.se * y.fi + y.se});\n  }\n  static constexpr F inverse(const\
    \ F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n\
    \  }\n  static constexpr K eval(const F &f, K x) noexcept { return f.fi * x +\
    \ f.se; }\n  static constexpr F unit = {K(1), K(0)};\n  static constexpr bool\
    \ commute = false;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/affinegroup.hpp
  requiredBy:
  - algebra/cntsum_affine_lazy.hpp
  timestamp: '2021-12-30 04:14:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: algebra/affinegroup.hpp
layout: document
redirect_from:
- /library/algebra/affinegroup.hpp
- /library/algebra/affinegroup.hpp.html
title: algebra/affinegroup.hpp
---
