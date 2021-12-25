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
  bundledCode: "#line 1 \"flow/bipartite.hpp\"\nstruct BipartiteMatching {\r\n  int\
    \ n, m;\r\n  vector<vector<int>> graph;\r\n  vector<int> dist, match;\r\n  vector<bool>\
    \ used, vv;\r\n  bool calculated;\r\n\r\n  BipartiteMatching(int n, int m)\r\n\
    \      : n(n), m(m), graph(n), match(m, -1), used(n), calculated(false) {}\r\n\
    \r\n  void add(int u, int v) {\r\n    graph[u].push_back(v);\r\n    calculated\
    \ = false;\r\n  }\r\n\r\n  void bfs() {\r\n    dist.assign(graph.size(), -1);\r\
    \n    queue<int> que;\r\n    for (int i = 0; i < graph.size(); i++) {\r\n    \
    \  if (!used[i]) {\r\n        que.emplace(i);\r\n        dist[i] = 0;\r\n    \
    \  }\r\n    }\r\n\r\n    while (!que.empty()) {\r\n      int a = que.front();\r\
    \n      que.pop();\r\n      for (auto &b : graph[a]) {\r\n        int c = match[b];\r\
    \n        if (c >= 0 && dist[c] == -1) {\r\n          dist[c] = dist[a] + 1;\r\
    \n          que.emplace(c);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  bool\
    \ dfs(int a) {\r\n    vv[a] = true;\r\n    for (auto &b : graph[a]) {\r\n    \
    \  int c = match[b];\r\n      if (c < 0 || (!vv[c] && dist[c] == dist[a] + 1 &&\
    \ dfs(c))) {\r\n        match[b] = a;\r\n        used[a] = true;\r\n        return\
    \ (true);\r\n      }\r\n    }\r\n    return (false);\r\n  }\r\n\r\n  void calc()\
    \ {\r\n    if (calculated) return;\r\n    while (true) {\r\n      bfs();\r\n \
    \     vv.assign(graph.size(), false);\r\n      int flow = 0;\r\n      for (int\
    \ i = 0; i < graph.size(); i++) {\r\n        if (!used[i] && dfs(i)) ++flow;\r\
    \n      }\r\n      if (flow == 0) break;\r\n    }\r\n    calculated = true;\r\n\
    \  }\r\n\r\n  vector<pair<int, int>> max_matching() {\r\n    calc();\r\n    vector<pair<int,\
    \ int>> matching;\r\n    FOR(r, m) {\r\n      if (match[r] != -1) matching.eb(match[r],\
    \ r);\r\n    }\r\n    return matching;\r\n  }\r\n\r\n  pair<vector<int>, vector<int>>\
    \ min_vertex_cover() {\r\n    calc();\r\n    vector<bool> covered(m);\r\n    vector<int>\
    \ A, B;\r\n    FOR(l, n) if (dist[l] != -1) {\r\n      A.eb(l);\r\n      FORIN(r,\
    \ graph[l]) covered[r] = true;\r\n    }\r\n    FOR(r, m) if (!covered[r]) B.eb(r);\r\
    \n    return {A, B};\r\n  }\r\n\r\n  pair<vector<int>, vector<int>> max_independent_set()\
    \ {\r\n    calc();\r\n    vector<bool> covered(m);\r\n    vector<int> A, B;\r\n\
    \    FOR(l, n) if (dist[l] != -1) {\r\n      A.eb(l);\r\n      FORIN(r, graph[l])\
    \ covered[r] = true;\r\n    }\r\n    FOR(l, n) if (dist[l] == -1) A.eb(l);\r\n\
    \    FOR(r, m) if (covered[r]) B.eb(r);\r\n    return {A, B};\r\n  }\r\n\r\n \
    \ vector<pair<int, int>> min_edge_cover() {\r\n    auto E = max_matching();\r\n\
    \    vector<bool> done_l(n), done_r(m);\r\n    for (auto &&[l, r] : E) { done_l[l]\
    \ = done_r[r] = true; }\r\n    FOR(l, n) FORIN(r, graph[l]) {\r\n      if (!done_l[l])\
    \ E.eb(l, r);\r\n      if (!done_r[r]) E.eb(l, r);\r\n      done_l[l] = done_r[r]\
    \ = true;\r\n    }\r\n    FOR(l, n) if (!done_l[l]) return {};\r\n    FOR(r, m)\
    \ if (!done_r[r]) return {};\r\n    return E;\r\n  }\r\n};\r\n"
  code: "struct BipartiteMatching {\r\n  int n, m;\r\n  vector<vector<int>> graph;\r\
    \n  vector<int> dist, match;\r\n  vector<bool> used, vv;\r\n  bool calculated;\r\
    \n\r\n  BipartiteMatching(int n, int m)\r\n      : n(n), m(m), graph(n), match(m,\
    \ -1), used(n), calculated(false) {}\r\n\r\n  void add(int u, int v) {\r\n   \
    \ graph[u].push_back(v);\r\n    calculated = false;\r\n  }\r\n\r\n  void bfs()\
    \ {\r\n    dist.assign(graph.size(), -1);\r\n    queue<int> que;\r\n    for (int\
    \ i = 0; i < graph.size(); i++) {\r\n      if (!used[i]) {\r\n        que.emplace(i);\r\
    \n        dist[i] = 0;\r\n      }\r\n    }\r\n\r\n    while (!que.empty()) {\r\
    \n      int a = que.front();\r\n      que.pop();\r\n      for (auto &b : graph[a])\
    \ {\r\n        int c = match[b];\r\n        if (c >= 0 && dist[c] == -1) {\r\n\
    \          dist[c] = dist[a] + 1;\r\n          que.emplace(c);\r\n        }\r\n\
    \      }\r\n    }\r\n  }\r\n\r\n  bool dfs(int a) {\r\n    vv[a] = true;\r\n \
    \   for (auto &b : graph[a]) {\r\n      int c = match[b];\r\n      if (c < 0 ||\
    \ (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {\r\n        match[b] = a;\r\n\
    \        used[a] = true;\r\n        return (true);\r\n      }\r\n    }\r\n   \
    \ return (false);\r\n  }\r\n\r\n  void calc() {\r\n    if (calculated) return;\r\
    \n    while (true) {\r\n      bfs();\r\n      vv.assign(graph.size(), false);\r\
    \n      int flow = 0;\r\n      for (int i = 0; i < graph.size(); i++) {\r\n  \
    \      if (!used[i] && dfs(i)) ++flow;\r\n      }\r\n      if (flow == 0) break;\r\
    \n    }\r\n    calculated = true;\r\n  }\r\n\r\n  vector<pair<int, int>> max_matching()\
    \ {\r\n    calc();\r\n    vector<pair<int, int>> matching;\r\n    FOR(r, m) {\r\
    \n      if (match[r] != -1) matching.eb(match[r], r);\r\n    }\r\n    return matching;\r\
    \n  }\r\n\r\n  pair<vector<int>, vector<int>> min_vertex_cover() {\r\n    calc();\r\
    \n    vector<bool> covered(m);\r\n    vector<int> A, B;\r\n    FOR(l, n) if (dist[l]\
    \ != -1) {\r\n      A.eb(l);\r\n      FORIN(r, graph[l]) covered[r] = true;\r\n\
    \    }\r\n    FOR(r, m) if (!covered[r]) B.eb(r);\r\n    return {A, B};\r\n  }\r\
    \n\r\n  pair<vector<int>, vector<int>> max_independent_set() {\r\n    calc();\r\
    \n    vector<bool> covered(m);\r\n    vector<int> A, B;\r\n    FOR(l, n) if (dist[l]\
    \ != -1) {\r\n      A.eb(l);\r\n      FORIN(r, graph[l]) covered[r] = true;\r\n\
    \    }\r\n    FOR(l, n) if (dist[l] == -1) A.eb(l);\r\n    FOR(r, m) if (covered[r])\
    \ B.eb(r);\r\n    return {A, B};\r\n  }\r\n\r\n  vector<pair<int, int>> min_edge_cover()\
    \ {\r\n    auto E = max_matching();\r\n    vector<bool> done_l(n), done_r(m);\r\
    \n    for (auto &&[l, r] : E) { done_l[l] = done_r[r] = true; }\r\n    FOR(l,\
    \ n) FORIN(r, graph[l]) {\r\n      if (!done_l[l]) E.eb(l, r);\r\n      if (!done_r[r])\
    \ E.eb(l, r);\r\n      done_l[l] = done_r[r] = true;\r\n    }\r\n    FOR(l, n)\
    \ if (!done_l[l]) return {};\r\n    FOR(r, m) if (!done_r[r]) return {};\r\n \
    \   return E;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/bipartite.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/bipartite.hpp
layout: document
redirect_from:
- /library/flow/bipartite.hpp
- /library/flow/bipartite.hpp.html
title: flow/bipartite.hpp
---
