---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/bfs01.hpp
    title: graph/bfs01.hpp
  - icon: ':question:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1320_mincostcycle.test.cpp
    title: test/yukicoder/1320_mincostcycle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared && 0 <= frm && 0 <= to);\n   \
    \ chmax(N, frm + 1);\n    chmax(N, to + 1);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  FOR_(M) {\n      INT(a, b);\n      a -= off, b -= off;\n      if (!wt) {\n\
    \        add(a, b);\n      } else {\n        T c;\n        read(c);\n        add(a,\
    \ b, c);\n      }\n    }\n    prepare();\n  }\n\n  void read_parent(int off =\
    \ 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n      p -= off;\n      add(p, v);\n\
    \    }\n    prepare();\n  }\n\n  void prepare() {\n    assert(!prepared);\n  \
    \  prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n\
    \      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n\
    \    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 3 \"graph/dijkstra.hpp\"\n\ntemplate <typename Graph>\n\
    pair<vector<typename Graph::cost_type>, vector<int>> dijkstra(Graph& G, int v)\
    \ {\n  auto N = G.N;\n  using T = typename Graph::cost_type;\n  vector<T> dist(N,\
    \ -1);\n  vector<int> par(N, -1);\n  using P = pair<T, int>;\n\n  priority_queue<P,\
    \ vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n  que.push(mp(T(0), v));\n  while\
    \ (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n    if (dv\
    \ > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (dist[e.to] == -1\
    \ || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm] +\
    \ e.cost;\n        par[e.to] = e.frm;\n        que.push(mp(dist[e.to], e.to));\n\
    \      }\n    }\n  }\n  return mp(dist, par);\n}\n#line 3 \"graph/bfs01.hpp\"\n\
    \ntemplate <typename Graph>\npair<vc<ll>, vc<int>> bfs01(Graph& G, ll v) {\n \
    \ assert(G.is_prepared());\n  int N = G.N;\n  vc<ll> dist(N, -1);\n  vc<int> par(N,\
    \ -1);\n  deque<int> que;\n\n  dist[v] = 0;\n  que.push_front(v);\n  while (!que.empty())\
    \ {\n    auto v = que.front();\n    que.pop_front();\n    for (auto&& e: G[v])\
    \ {\n      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost) {\n    \
    \    dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n        if\
    \ (e.cost == 0)\n          que.push_front(e.to);\n        else\n          que.push_back(e.to);\n\
    \      }\n    }\n  }\n  return {dist, par};\n}\n\ntemplate <typename Graph>\n\
    pair<vc<ll>, vc<int>> bfs01(Graph& G, vc<int> vs) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<ll> dist(N, -1);\n  vc<int> par(N, -1);\n  deque<int> que;\n\
    \n  for (auto&& v: vs) {\n    dist[v] = 0;\n    que.push_front(v);\n  }\n\n  while\
    \ (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n    for (auto&&\
    \ e: G[v]) {\n      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost)\
    \ {\n        dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n\
    \        if (e.cost == 0)\n          que.push_front(e.to);\n        else\n   \
    \       que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par};\n}\n\
    #line 3 \"graph/mincostcycle.hpp\"\n\r\ntemplate <typename Graph>\r\ntypename\
    \ Graph::cost_type MinCostCycle(Graph& G) {\r\n  using T = typename Graph::cost_type;\r\
    \n  int M = G.M;\r\n  int N = G.N;\r\n  T mx = 0;\r\n  T INF = 1;\r\n  for (auto&&\
    \ e: G.edges) chmax(mx, e.cost), INF += e.cost;\r\n  T res = INF;\r\n\r\n  FOR(i,\
    \ M) {\r\n    auto& e = G.edges[i];\r\n    T cost = e.cost;\r\n    int frm = e.to,\
    \ to = e.frm;\r\n    Graph Gi(N);\r\n    FOR(j, M) if (i != j) {\r\n      auto&\
    \ e = G.edges[j];\r\n      Gi.add(e.frm, e.to, e.cost);\r\n    }\r\n    Gi.prepare();\r\
    \n    T x = (mx <= 1 ? bfs01(Gi, frm).fi[to] : dijkstra(Gi, frm).fi[to]);\r\n\
    \    if (x == -1) x = INF;\r\n    chmin(res, cost + x);\r\n  }\r\n  if (res ==\
    \ INF) res = -1;\r\n  return res;\r\n}\n"
  code: "#include \"graph/dijkstra.hpp\"\r\n#include \"graph/bfs01.hpp\"\r\n\r\ntemplate\
    \ <typename Graph>\r\ntypename Graph::cost_type MinCostCycle(Graph& G) {\r\n \
    \ using T = typename Graph::cost_type;\r\n  int M = G.M;\r\n  int N = G.N;\r\n\
    \  T mx = 0;\r\n  T INF = 1;\r\n  for (auto&& e: G.edges) chmax(mx, e.cost), INF\
    \ += e.cost;\r\n  T res = INF;\r\n\r\n  FOR(i, M) {\r\n    auto& e = G.edges[i];\r\
    \n    T cost = e.cost;\r\n    int frm = e.to, to = e.frm;\r\n    Graph Gi(N);\r\
    \n    FOR(j, M) if (i != j) {\r\n      auto& e = G.edges[j];\r\n      Gi.add(e.frm,\
    \ e.to, e.cost);\r\n    }\r\n    Gi.prepare();\r\n    T x = (mx <= 1 ? bfs01(Gi,\
    \ frm).fi[to] : dijkstra(Gi, frm).fi[to]);\r\n    if (x == -1) x = INF;\r\n  \
    \  chmin(res, cost + x);\r\n  }\r\n  if (res == INF) res = -1;\r\n  return res;\r\
    \n}"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/base.hpp
  - graph/bfs01.hpp
  isVerificationFile: false
  path: graph/mincostcycle.hpp
  requiredBy: []
  timestamp: '2022-03-14 00:26:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1320_mincostcycle.test.cpp
documentation_of: graph/mincostcycle.hpp
layout: document
redirect_from:
- /library/graph/mincostcycle.hpp
- /library/graph/mincostcycle.hpp.html
title: graph/mincostcycle.hpp
---
