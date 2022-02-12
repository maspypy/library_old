---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  void\
    \ read_tree(bool wt=false, int off=1){\n    read_graph(N - 1, wt, off);\n  }\n\
    \n  void read_graph(int M, bool wt=false, int off=1){\n    FOR_(M){\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if(!wt){\n        add(a, b);\n      }\
    \ else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n   \
    \ }\n    prepare();\n  }\n\n  void prepare() {\n    assert(!prepared);\n    prepared\
    \ = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v\
    \ + 1] += indptr[v];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 2 \"graph/bfsnumbering.hpp\"\n\r\ntemplate <typename Graph>\r\
    \nstruct BFSNumbering {\r\n  Graph& G;\r\n  int root;\r\n  vector<int> V;\r\n\
    \  vector<int> ID;\r\n  vector<int> depth;\r\n  vector<int> parent;\r\n  vector<int>\
    \ LID, RID;\r\n  vector<int> LID_seq;\r\n  vector<int> dep_ids;\r\n  int cnt;\r\
    \n\r\n  BFSNumbering(Graph& G, int root = 0) : G(G), root(root), cnt(0) { build();\
    \ }\r\n\r\n  void bfs() {\r\n    deque<int> que = {root};\r\n    while (!que.empty())\
    \ {\r\n      int v = que.front();\r\n      que.pop_front();\r\n      ID[v] = V.size();\r\
    \n      V.eb(v);\r\n      for(auto&& [frm,to,cost,id] : G[v]) {\r\n        if\
    \ (to == parent[v]) continue;\r\n        que.emplace_back(to);\r\n        parent[to]\
    \ = v;\r\n        depth[to] = depth[v] + 1;\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  void dfs(int v) {\r\n    LID[v] = cnt++;\r\n    for(auto&& [frm,to,cost,id]\
    \ : G[v]) {\r\n      if (to == parent[v]) continue;\r\n      dfs(to);\r\n    }\r\
    \n    RID[v] = cnt;\r\n  }\r\n\r\n  void build() {\r\n    int N = G.N;\r\n   \
    \ V.reserve(N);\r\n    parent.assign(N, -1);\r\n    ID.assign(N, 0);\r\n    LID.assign(N,\
    \ 0);\r\n    RID.assign(N, 0);\r\n    depth.assign(N, 0);\r\n    bfs();\r\n  \
    \  dfs(root);\r\n    int D = MAX(depth);\r\n    dep_ids.resize(D + 2);\r\n   \
    \ FOR(v, N) dep_ids[depth[v] + 1]++;\r\n    FOR(d, D + 1) dep_ids[d + 1] += dep_ids[d];\r\
    \n    LID_seq.reserve(N);\r\n    FOR(i, N) LID_seq.eb(LID[V[i]]);\r\n  }\r\n\r\
    \n  int bs(int L, int R, int x) {\r\n    while (L + 1 < R) {\r\n      int M =\
    \ (L + R) / 2;\r\n      if (LID_seq[M] >= x)\r\n        R = M;\r\n      else\r\
    \n        L = M;\r\n    }\r\n    return R;\r\n  }\r\n\r\n  pair<int, int> calc_range(int\
    \ v, int dep) {\r\n    assert(dep >= depth[v]);\r\n    if (dep >= len(dep_ids)\
    \ - 1) return {0, 0};\r\n    int l = LID[v], r = RID[v];\r\n    int L = dep_ids[dep],\
    \ R = dep_ids[dep + 1];\r\n    int a = bs(L - 1, R, l);\r\n    int b = bs(L -\
    \ 1, R, r);\r\n    return {a, b};\r\n  }\r\n};\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\ntemplate <typename Graph>\r\nstruct BFSNumbering\
    \ {\r\n  Graph& G;\r\n  int root;\r\n  vector<int> V;\r\n  vector<int> ID;\r\n\
    \  vector<int> depth;\r\n  vector<int> parent;\r\n  vector<int> LID, RID;\r\n\
    \  vector<int> LID_seq;\r\n  vector<int> dep_ids;\r\n  int cnt;\r\n\r\n  BFSNumbering(Graph&\
    \ G, int root = 0) : G(G), root(root), cnt(0) { build(); }\r\n\r\n  void bfs()\
    \ {\r\n    deque<int> que = {root};\r\n    while (!que.empty()) {\r\n      int\
    \ v = que.front();\r\n      que.pop_front();\r\n      ID[v] = V.size();\r\n  \
    \    V.eb(v);\r\n      for(auto&& [frm,to,cost,id] : G[v]) {\r\n        if (to\
    \ == parent[v]) continue;\r\n        que.emplace_back(to);\r\n        parent[to]\
    \ = v;\r\n        depth[to] = depth[v] + 1;\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  void dfs(int v) {\r\n    LID[v] = cnt++;\r\n    for(auto&& [frm,to,cost,id]\
    \ : G[v]) {\r\n      if (to == parent[v]) continue;\r\n      dfs(to);\r\n    }\r\
    \n    RID[v] = cnt;\r\n  }\r\n\r\n  void build() {\r\n    int N = G.N;\r\n   \
    \ V.reserve(N);\r\n    parent.assign(N, -1);\r\n    ID.assign(N, 0);\r\n    LID.assign(N,\
    \ 0);\r\n    RID.assign(N, 0);\r\n    depth.assign(N, 0);\r\n    bfs();\r\n  \
    \  dfs(root);\r\n    int D = MAX(depth);\r\n    dep_ids.resize(D + 2);\r\n   \
    \ FOR(v, N) dep_ids[depth[v] + 1]++;\r\n    FOR(d, D + 1) dep_ids[d + 1] += dep_ids[d];\r\
    \n    LID_seq.reserve(N);\r\n    FOR(i, N) LID_seq.eb(LID[V[i]]);\r\n  }\r\n\r\
    \n  int bs(int L, int R, int x) {\r\n    while (L + 1 < R) {\r\n      int M =\
    \ (L + R) / 2;\r\n      if (LID_seq[M] >= x)\r\n        R = M;\r\n      else\r\
    \n        L = M;\r\n    }\r\n    return R;\r\n  }\r\n\r\n  pair<int, int> calc_range(int\
    \ v, int dep) {\r\n    assert(dep >= depth[v]);\r\n    if (dep >= len(dep_ids)\
    \ - 1) return {0, 0};\r\n    int l = LID[v], r = RID[v];\r\n    int L = dep_ids[dep],\
    \ R = dep_ids[dep + 1];\r\n    int a = bs(L - 1, R, l);\r\n    int b = bs(L -\
    \ 1, R, r);\r\n    return {a, b};\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/bfsnumbering.hpp
  requiredBy: []
  timestamp: '2022-02-11 06:57:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: graph/bfsnumbering.hpp
layout: document
redirect_from:
- /library/graph/bfsnumbering.hpp
- /library/graph/bfsnumbering.hpp.html
title: graph/bfsnumbering.hpp
---
