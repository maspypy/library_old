---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: flow/bipartite.hpp
    title: flow/bipartite.hpp
  - icon: ':x:'
    path: graph/check_bipartite.hpp
    title: graph/check_bipartite.hpp
  - icon: ':warning:'
    path: graph/functional.hpp
    title: graph/functional.hpp
  - icon: ':warning:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/unionfind.test.cpp
    title: test/library_checker/datastructure/unionfind.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/bipartitematching.test.cpp
    title: test/library_checker/graph/bipartitematching.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int num;\n \
    \ int comp;\n  vc<int> size, par;\n  UnionFind(int n) : num(n), comp(n), size(n,\
    \ 1), par(n) {\n    iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n\
    \    while (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n \
    \   }\n    return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n \
    \ bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n    if (x == y)\
    \ { return false; }\n    comp--;\n    if (size[x] < size[y]) swap(x, y);\n   \
    \ size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n \
    \ }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i] = find(i);\n\
    \    return A;\n  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  int num;\n  int comp;\n  vc<int> size,\
    \ par;\n  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) {\n    iota(par.begin(),\
    \ par.end(), 0);\n  }\n  int find(int x) {\n    while (par[x] != x) {\n      par[x]\
    \ = par[par[x]];\n      x = par[x];\n    }\n    return x;\n  }\n\n  int operator[](int\
    \ x) { return find(x); }\n\n  bool merge(ll x, ll y) {\n    x = find(x);\n   \
    \ y = find(y);\n    if (x == y) { return false; }\n    comp--;\n    if (size[x]\
    \ < size[y]) swap(x, y);\n    size[x] += size[y];\n    size[y] = 0;\n    par[y]\
    \ = x;\n    return true;\n  }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n\
    \    FOR(i, num) A[i] = find(i);\n    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind.hpp
  requiredBy:
  - flow/bipartite.hpp
  - graph/functional.hpp
  - graph/check_bipartite.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-01-12 05:33:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/unionfind.test.cpp
  - test/library_checker/graph/bipartitematching.test.cpp
documentation_of: ds/unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind.hpp
- /library/ds/unionfind.hpp.html
title: ds/unionfind.hpp
---
