---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_cntsum_affine.hpp
    title: algebra/lazy_cntsum_affine.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_affine.hpp\"\ntemplate <typename K>\nstruct\
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
  path: algebra/group_affine.hpp
  requiredBy:
  - algebra/lazy_cntsum_affine.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/group_affine.hpp
layout: document
redirect_from:
- /library/algebra/group_affine.hpp
- /library/algebra/group_affine.hpp.html
title: algebra/group_affine.hpp
---
