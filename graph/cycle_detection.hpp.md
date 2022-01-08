---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/cycle_detection.test.cpp
    title: test/library_checker/graph/cycle_detection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle_detection.hpp\"\ntemplate <typename Graph>\r\
    \nvc<int> cycle_detection(Graph& G, bool is_edge) {\r\n  assert(G.is_directed());\r\
    \n  assert(G.is_prepared());\r\n  if (!is_edge) {\r\n    auto C = cycle_detection(G,\
    \ true);\r\n    if (len(C) == 0) return C;\r\n    vc<int> ANS(len(C) + 1);\r\n\
    \    FOR(i, len(C)) {\r\n      auto e = G.edges[C[i]];\r\n      ANS[i + 0] = e.frm;\r\
    \n      ANS[i + 1] = e.to;\r\n    }\r\n    return ANS;\r\n  }\r\n\r\n  int N =\
    \ G.N;\r\n  vc<int> used(N);\r\n  vc<int> path; // edge\r\n  vc<pair<int, int>>\
    \ par(N);\r\n  vector<int> ANS;\r\n\r\n  auto dfs = [&](auto self, int v) -> void\
    \ {\r\n    used[v] = 1;\r\n    for (auto&& e: G[v]) {\r\n      if (len(ANS)) return;\r\
    \n      if (!used[e.to]) {\r\n        par[e.to] = {v, e.id};\r\n        self(self,\
    \ e.to);\r\n      }\r\n      elif (used[e.to] == 1) {\r\n        ANS = {e.id};\r\
    \n        int cur = v;\r\n        while (cur != e.to) {\r\n          ANS.eb(par[cur].se);\r\
    \n          cur = par[cur].fi;\r\n        }\r\n        reverse(all(ANS));\r\n\
    \        return;\r\n      }\r\n    }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N)\
    \ if (!used[v]) dfs(dfs, v);\r\n  return ANS;\r\n}\n"
  code: "template <typename Graph>\r\nvc<int> cycle_detection(Graph& G, bool is_edge)\
    \ {\r\n  assert(G.is_directed());\r\n  assert(G.is_prepared());\r\n  if (!is_edge)\
    \ {\r\n    auto C = cycle_detection(G, true);\r\n    if (len(C) == 0) return C;\r\
    \n    vc<int> ANS(len(C) + 1);\r\n    FOR(i, len(C)) {\r\n      auto e = G.edges[C[i]];\r\
    \n      ANS[i + 0] = e.frm;\r\n      ANS[i + 1] = e.to;\r\n    }\r\n    return\
    \ ANS;\r\n  }\r\n\r\n  int N = G.N;\r\n  vc<int> used(N);\r\n  vc<int> path; //\
    \ edge\r\n  vc<pair<int, int>> par(N);\r\n  vector<int> ANS;\r\n\r\n  auto dfs\
    \ = [&](auto self, int v) -> void {\r\n    used[v] = 1;\r\n    for (auto&& e:\
    \ G[v]) {\r\n      if (len(ANS)) return;\r\n      if (!used[e.to]) {\r\n     \
    \   par[e.to] = {v, e.id};\r\n        self(self, e.to);\r\n      }\r\n      elif\
    \ (used[e.to] == 1) {\r\n        ANS = {e.id};\r\n        int cur = v;\r\n   \
    \     while (cur != e.to) {\r\n          ANS.eb(par[cur].se);\r\n          cur\
    \ = par[cur].fi;\r\n        }\r\n        reverse(all(ANS));\r\n        return;\r\
    \n      }\r\n    }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N) if (!used[v]) dfs(dfs,\
    \ v);\r\n  return ANS;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2021-12-31 12:29:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/cycle_detection.test.cpp
documentation_of: graph/cycle_detection.hpp
layout: document
redirect_from:
- /library/graph/cycle_detection.hpp
- /library/graph/cycle_detection.hpp.html
title: graph/cycle_detection.hpp
---
