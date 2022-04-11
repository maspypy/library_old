---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_cntminmincnt_add.hpp
    title: alg/lazy_cntminmincnt_add.hpp
  - icon: ':warning:'
    path: ds/rectangleunion.hpp
    title: ds/rectangleunion.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_cntminmincnt.hpp\"\n// \u5168\u4F53\u306E\u500B\
    \u6570\u3001\u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate\
    \ <ll INF>\r\nstruct Monoid_CntMinMincnt {\r\n  using value_type = tuple<ll, ll,\
    \ ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xcnt,\
    \ xmin, xmincnt] = x;\r\n    auto [ycnt, ymin, ymincnt] = y;\r\n    if (xmin >\
    \ ymin) return {xcnt + ycnt, ymin, ymincnt};\r\n    if (xmin == ymin) return {xcnt\
    \ + ycnt, xmin, xmincnt + ymincnt};\r\n    return {xcnt + ycnt, xmin, xmincnt};\r\
    \n  }\r\n  static constexpr X unit = X(0, INF, 0);\r\n  static constexpr bool\
    \ commute = true;\r\n};\n"
  code: "// \u5168\u4F53\u306E\u500B\u6570\u3001\u6700\u5C0F\u5024\u3001\u6700\u5C0F\
    \u5024\u306E\u500B\u6570\r\ntemplate <ll INF>\r\nstruct Monoid_CntMinMincnt {\r\
    \n  using value_type = tuple<ll, ll, ll>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xcnt, xmin, xmincnt] = x;\r\n    auto [ycnt, ymin,\
    \ ymincnt] = y;\r\n    if (xmin > ymin) return {xcnt + ycnt, ymin, ymincnt};\r\
    \n    if (xmin == ymin) return {xcnt + ycnt, xmin, xmincnt + ymincnt};\r\n   \
    \ return {xcnt + ycnt, xmin, xmincnt};\r\n  }\r\n  static constexpr X unit = X(0,\
    \ INF, 0);\r\n  static constexpr bool commute = true;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_cntminmincnt.hpp
  requiredBy:
  - ds/rectangleunion.hpp
  - alg/lazy_cntminmincnt_add.hpp
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_cntminmincnt.hpp
layout: document
redirect_from:
- /library/alg/monoid_cntminmincnt.hpp
- /library/alg/monoid_cntminmincnt.hpp.html
title: alg/monoid_cntminmincnt.hpp
---
