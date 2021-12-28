---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/affinegroup.hpp\"\ntemplate <typename K>\nstruct\
    \ AffineGroup {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr\
    \ F op(const F &x, const F &y) noexcept {\n    return F({x.fi * y.fi, x.se * y.fi\
    \ + y.se});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a, b]\
    \ = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept { return f.fi * x + f.se; }\n  static constexpr\
    \ F unit = {K(1), K(0)};\n};\n"
  code: "template <typename K>\nstruct AffineGroup {\n  using F = pair<K, K>;\n  using\
    \ value_type = F;\n  static constexpr F op(const F &x, const F &y) noexcept {\n\
    \    return F({x.fi * y.fi, x.se * y.fi + y.se});\n  }\n  static constexpr F inverse(const\
    \ F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n\
    \  }\n  static constexpr K eval(const F &f, K x) noexcept { return f.fi * x +\
    \ f.se; }\n  static constexpr F unit = {K(1), K(0)};\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/affinegroup.hpp
  requiredBy: []
  timestamp: '2021-12-28 08:11:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
documentation_of: algebra/affinegroup.hpp
layout: document
redirect_from:
- /library/algebra/affinegroup.hpp
- /library/algebra/affinegroup.hpp.html
title: algebra/affinegroup.hpp
---
