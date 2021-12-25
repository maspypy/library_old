---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a),\
    \ to(b), cost(c), id(d) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n  int\
    \ N, M;\n  using edge_t = Edge<T>;\n  vector<edge_t> edges;\n  vector<vector<edge_t>>\
    \ G;\n  bool directed;\n  Graph() {}\n  Graph(int N, bool bl = false) : N(N),\
    \ M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    if (i == -1) i = M;\n    auto e = edge_t(frm, to, cost, i);\n \
    \   edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n      auto e_rev =\
    \ edge_t(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n    ++M;\n  }\n\n\
    \  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout << v << \" :\"\
    ;\n      for (auto e : G[v]) {\n        if (detail)\n          cout << \" (\"\
    \ << e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id\n            \
    \   << \")\";\n        else\n          cout << \" \" << e.to;\n      }\n     \
    \ cout << \"\\n\";\n    }\n  }\n\n  vector<int> degrees() {\n    vector<int> deg(N);\n\
    \    FORIN(e, edges) {\n      deg[e.frm]++;\n      deg[e.to]++;\n    }\n    return\
    \ deg;\n  }\n\n  int size() { return N; }\n\n  vector<edge_t>& operator[](int\
    \ v) { return G[v]; }\n};\n#line 3 \"graph/dijkstra.hpp\"\n\ntemplate <typename\
    \ T>\npair<vi, vi> dijkstra(Graph<T>& G, ll v) {\n  const ll INF = 1LL << 60;\n\
    \  auto N = G.N;\n  vi dist(N, INF);\n  vi par(N, -1);\n  using P = pair<T, ll>;\n\
    \n  priority_queue<P, vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n  que.push(mp(T(0),\
    \ v));\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n\
    \    if(dv > dist[v]) continue;\n    for (auto&& e : G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        par[e.to] = e.frm;\n        que.push(mp(dist[e.to],\
    \ e.to));\n      }\n    }\n  }\n  return mp(dist, par);\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename T>\npair<vi,\
    \ vi> dijkstra(Graph<T>& G, ll v) {\n  const ll INF = 1LL << 60;\n  auto N = G.N;\n\
    \  vi dist(N, INF);\n  vi par(N, -1);\n  using P = pair<T, ll>;\n\n  priority_queue<P,\
    \ vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n  que.push(mp(T(0), v));\n  while\
    \ (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n    if(dv >\
    \ dist[v]) continue;\n    for (auto&& e : G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        par[e.to] = e.frm;\n        que.push(mp(dist[e.to],\
    \ e.to));\n      }\n    }\n  }\n  return mp(dist, par);\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
