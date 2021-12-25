---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/swag.hpp\"\ntemplate <typename T>\nstruct SWAG {\n  using\
    \ F = function<T(T, T)>;\n  int L, R;\n  F f;\n  T e;\n  vc<T>& dat;\n  vc<T>\
    \ cum_l;\n  T cum_r;\n  SWAG(F f, T e, vc<T>& dat)\n      : L(0), R(0), f(f),\
    \ e(e), dat(dat), cum_l({e}), cum_r(e) {}\n\n  void push() { cum_r = f(cum_r,\
    \ dat[R++]); }\n  void pop() {\n    cum_l.pop_back();\n    ++L;\n    if (len(cum_l)\
    \ == 0) {\n      cum_l = {e};\n      FOR3_R(i, L, R) cum_l.eb(f(dat[i], cum_l.back()));\n\
    \      cum_r = e;\n    }\n  }\n  T fold(int l, int r) {\n    assert(L <= l);\n\
    \    assert(R <= r);\n    while (R < r) push();\n    while (L < l) pop();\n  \
    \  return f(cum_l.back(), cum_r);\n  }\n};\n"
  code: "template <typename T>\nstruct SWAG {\n  using F = function<T(T, T)>;\n  int\
    \ L, R;\n  F f;\n  T e;\n  vc<T>& dat;\n  vc<T> cum_l;\n  T cum_r;\n  SWAG(F f,\
    \ T e, vc<T>& dat)\n      : L(0), R(0), f(f), e(e), dat(dat), cum_l({e}), cum_r(e)\
    \ {}\n\n  void push() { cum_r = f(cum_r, dat[R++]); }\n  void pop() {\n    cum_l.pop_back();\n\
    \    ++L;\n    if (len(cum_l) == 0) {\n      cum_l = {e};\n      FOR3_R(i, L,\
    \ R) cum_l.eb(f(dat[i], cum_l.back()));\n      cum_r = e;\n    }\n  }\n  T fold(int\
    \ l, int r) {\n    assert(L <= l);\n    assert(R <= r);\n    while (R < r) push();\n\
    \    while (L < l) pop();\n    return f(cum_l.back(), cum_r);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/swag.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
documentation_of: ds/swag.hpp
layout: document
redirect_from:
- /library/ds/swag.hpp
- /library/ds/swag.hpp.html
title: ds/swag.hpp
---
