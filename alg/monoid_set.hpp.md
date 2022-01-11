---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_set.hpp\"\ntemplate <typename E, E none_val>\r\
    \nstruct Monoid_Set {\r\n  using value_type = E;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static constexpr\
    \ X unit = none_val;\r\n  static constexpr bool commute = false;\r\n};\n"
  code: "template <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit = none_val;\r\n  static constexpr bool\
    \ commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_set.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_set.hpp
layout: document
redirect_from:
- /library/alg/monoid_set.hpp
- /library/alg/monoid_set.hpp.html
title: alg/monoid_set.hpp
---
