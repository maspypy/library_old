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
  bundledCode: "#line 1 \"graph/bfsnumbering.hpp\"\ntemplate <typename T>\r\nstruct\
    \ BFSNumbering {\r\n  T& G;\r\n  int root;\r\n  vector<int> V;\r\n  vector<int>\
    \ ID;\r\n  vector<int> depth;\r\n  vector<int> parent;\r\n  vector<int> LID, RID;\r\
    \n  vector<int> LID_seq;\r\n  vector<int> dep_ids;\r\n  int cnt;\r\n\r\n  BFSNumbering(T&\
    \ G, int root = 0) : G(G), root(root), cnt(0) { build(); }\r\n\r\n  void bfs()\
    \ {\r\n    deque<int> que = {root};\r\n    while (!que.empty()) {\r\n      int\
    \ v = que.front();\r\n      que.pop_front();\r\n      ID[v] = V.size();\r\n  \
    \    V.eb(v);\r\n      FORIN(e, G[v]) {\r\n        int to = e.to;\r\n        if\
    \ (to == parent[v]) continue;\r\n        que.emplace_back(to);\r\n        parent[to]\
    \ = v;\r\n        depth[to] = depth[v] + 1;\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  void dfs(int v) {\r\n    LID[v] = cnt++;\r\n    FORIN(e, G[v]) {\r\n      int\
    \ to = e.to;\r\n      if (to == parent[v]) continue;\r\n      dfs(to);\r\n   \
    \ }\r\n    RID[v] = cnt;\r\n  }\r\n\r\n  void build() {\r\n    int N = G.N;\r\n\
    \    V.reserve(N);\r\n    parent.assign(N, -1);\r\n    ID.assign(N, 0);\r\n  \
    \  LID.assign(N, 0);\r\n    RID.assign(N, 0);\r\n    depth.assign(N, 0);\r\n \
    \   bfs();\r\n    dfs(root);\r\n    int D = MAX(depth);\r\n    dep_ids.resize(D\
    \ + 2);\r\n    FOR(v, N) dep_ids[depth[v] + 1]++;\r\n    FOR(d, D + 1) dep_ids[d\
    \ + 1] += dep_ids[d];\r\n    LID_seq.reserve(N);\r\n    FOR(i, N) LID_seq.eb(LID[V[i]]);\r\
    \n  }\r\n\r\n  int bs(int L, int R, int x) {\r\n    while (L + 1 < R) {\r\n  \
    \    int M = (L + R) / 2;\r\n      if (LID_seq[M] >= x)\r\n        R = M;\r\n\
    \      else\r\n        L = M;\r\n    }\r\n    return R;\r\n  }\r\n\r\n  pair<int,\
    \ int> calc_range(int v, int dep) {\r\n    if (dep < depth[v]) return {0, 0};\r\
    \n    if (dep >= len(dep_ids) - 1) return {0, 0};\r\n    int l = LID[v], r = RID[v];\r\
    \n    int L = dep_ids[dep], R = dep_ids[dep + 1];\r\n    int a = bs(L - 1, R,\
    \ l);\r\n    int b = bs(L - 1, R, r);\r\n    return {a, b};\r\n  }\r\n};\r\n"
  code: "template <typename T>\r\nstruct BFSNumbering {\r\n  T& G;\r\n  int root;\r\
    \n  vector<int> V;\r\n  vector<int> ID;\r\n  vector<int> depth;\r\n  vector<int>\
    \ parent;\r\n  vector<int> LID, RID;\r\n  vector<int> LID_seq;\r\n  vector<int>\
    \ dep_ids;\r\n  int cnt;\r\n\r\n  BFSNumbering(T& G, int root = 0) : G(G), root(root),\
    \ cnt(0) { build(); }\r\n\r\n  void bfs() {\r\n    deque<int> que = {root};\r\n\
    \    while (!que.empty()) {\r\n      int v = que.front();\r\n      que.pop_front();\r\
    \n      ID[v] = V.size();\r\n      V.eb(v);\r\n      FORIN(e, G[v]) {\r\n    \
    \    int to = e.to;\r\n        if (to == parent[v]) continue;\r\n        que.emplace_back(to);\r\
    \n        parent[to] = v;\r\n        depth[to] = depth[v] + 1;\r\n      }\r\n\
    \    }\r\n  }\r\n\r\n  void dfs(int v) {\r\n    LID[v] = cnt++;\r\n    FORIN(e,\
    \ G[v]) {\r\n      int to = e.to;\r\n      if (to == parent[v]) continue;\r\n\
    \      dfs(to);\r\n    }\r\n    RID[v] = cnt;\r\n  }\r\n\r\n  void build() {\r\
    \n    int N = G.N;\r\n    V.reserve(N);\r\n    parent.assign(N, -1);\r\n    ID.assign(N,\
    \ 0);\r\n    LID.assign(N, 0);\r\n    RID.assign(N, 0);\r\n    depth.assign(N,\
    \ 0);\r\n    bfs();\r\n    dfs(root);\r\n    int D = MAX(depth);\r\n    dep_ids.resize(D\
    \ + 2);\r\n    FOR(v, N) dep_ids[depth[v] + 1]++;\r\n    FOR(d, D + 1) dep_ids[d\
    \ + 1] += dep_ids[d];\r\n    LID_seq.reserve(N);\r\n    FOR(i, N) LID_seq.eb(LID[V[i]]);\r\
    \n  }\r\n\r\n  int bs(int L, int R, int x) {\r\n    while (L + 1 < R) {\r\n  \
    \    int M = (L + R) / 2;\r\n      if (LID_seq[M] >= x)\r\n        R = M;\r\n\
    \      else\r\n        L = M;\r\n    }\r\n    return R;\r\n  }\r\n\r\n  pair<int,\
    \ int> calc_range(int v, int dep) {\r\n    if (dep < depth[v]) return {0, 0};\r\
    \n    if (dep >= len(dep_ids) - 1) return {0, 0};\r\n    int l = LID[v], r = RID[v];\r\
    \n    int L = dep_ids[dep], R = dep_ids[dep + 1];\r\n    int a = bs(L - 1, R,\
    \ l);\r\n    int b = bs(L - 1, R, r);\r\n    return {a, b};\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bfsnumbering.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bfsnumbering.hpp
layout: document
redirect_from:
- /library/graph/bfsnumbering.hpp
- /library/graph/bfsnumbering.hpp.html
title: graph/bfsnumbering.hpp
---
