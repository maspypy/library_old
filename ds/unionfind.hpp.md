---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/functional.hpp
    title: graph/functional.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/unionfind.test.cpp
    title: test/library_checker/datastructure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int num;\n \
    \ int comp;\n  vi size, par;\n  UnionFind(int n) : num(n), comp(n), size(n, 1),\
    \ par(n) { iota(par.begin(), par.end(), 0); }\n  int find(int x) {\n    while\
    \ (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n    }\n   \
    \ return x;\n  }\n\n  int operator[](int x) {\n    return find(x);\n  }\n\n\n\
    \  bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n    if (x ==\
    \ y) {\n      return false;\n    }\n    comp--;\n    if (size[x] < size[y]) swap(x,\
    \ y);\n    size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return\
    \ true;\n  }\n\n  vi find_all() {\n    vi A(num);\n    FOR(i, num) A[i] = find(i);\n\
    \    return A;\n  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  int num;\n  int comp;\n  vi size, par;\n\
    \  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) { iota(par.begin(),\
    \ par.end(), 0); }\n  int find(int x) {\n    while (par[x] != x) {\n      par[x]\
    \ = par[par[x]];\n      x = par[x];\n    }\n    return x;\n  }\n\n  int operator[](int\
    \ x) {\n    return find(x);\n  }\n\n\n  bool merge(ll x, ll y) {\n    x = find(x);\n\
    \    y = find(y);\n    if (x == y) {\n      return false;\n    }\n    comp--;\n\
    \    if (size[x] < size[y]) swap(x, y);\n    size[x] += size[y];\n    size[y]\
    \ = 0;\n    par[y] = x;\n    return true;\n  }\n\n  vi find_all() {\n    vi A(num);\n\
    \    FOR(i, num) A[i] = find(i);\n    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind.hpp
  requiredBy:
  - graph/functional.hpp
  timestamp: '2022-01-08 22:12:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/unionfind.test.cpp
documentation_of: ds/unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind.hpp
- /library/ds/unionfind.hpp.html
title: ds/unionfind.hpp
---
