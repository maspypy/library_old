---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ v) { return G[v]; }\n};\n#line 3 \"graph/scc.hpp\"\n\ntemplate <class T> struct\
    \ SCC {\n  T &G;\n  ll N;\n  ll n_comp;\n  vc<int> comp_id;\n  vc<int> low;\n\
    \  vc<int> ord;\n  vc<int> visited;\n  ll now = 0;\n\n  SCC(T &G)\n      : G(G),\
    \ N(G.N), n_comp(0), comp_id(G.N, 0), low(G.N, 0), ord(G.N, -1) {\n    assert(G.directed);\n\
    \    build();\n  }\n\n  ll operator[](ll v) { return comp_id[v]; }\n\n  void dfs(int\
    \ v) {\n    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n\
    \    for (auto e : G[v]) {\n      if (ord[e.to] == -1) {\n        dfs(e.to);\n\
    \        chmin(low[v], low[e.to]);\n      } else {\n        chmin(low[v], ord[e.to]);\n\
    \      }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        ll u\
    \ = visited.back();\n        visited.pop_back();\n        ord[u] = N;\n      \
    \  comp_id[u] = n_comp;\n        if (u == v)\n          break;\n      }\n    \
    \  ++n_comp;\n    }\n  }\n\n  void build() {\n    FOR(v, N) {\n      if (ord[v]\
    \ == -1)\n        dfs(v);\n    }\n    FOR(v, N) comp_id[v] = n_comp - 1 - comp_id[v];\n\
    \  }\n\n  vc<vc<int>> comp() {\n    if (n_comp == 0)\n      build();\n    vc<vc<int>>\
    \ res;\n    res.resize(n_comp);\n    FOR(v, N) { res[comp_id[v]].eb(v); }\n  \
    \  return res;\n  };\n};\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <class T> struct SCC\
    \ {\n  T &G;\n  ll N;\n  ll n_comp;\n  vc<int> comp_id;\n  vc<int> low;\n  vc<int>\
    \ ord;\n  vc<int> visited;\n  ll now = 0;\n\n  SCC(T &G)\n      : G(G), N(G.N),\
    \ n_comp(0), comp_id(G.N, 0), low(G.N, 0), ord(G.N, -1) {\n    assert(G.directed);\n\
    \    build();\n  }\n\n  ll operator[](ll v) { return comp_id[v]; }\n\n  void dfs(int\
    \ v) {\n    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n\
    \    for (auto e : G[v]) {\n      if (ord[e.to] == -1) {\n        dfs(e.to);\n\
    \        chmin(low[v], low[e.to]);\n      } else {\n        chmin(low[v], ord[e.to]);\n\
    \      }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        ll u\
    \ = visited.back();\n        visited.pop_back();\n        ord[u] = N;\n      \
    \  comp_id[u] = n_comp;\n        if (u == v)\n          break;\n      }\n    \
    \  ++n_comp;\n    }\n  }\n\n  void build() {\n    FOR(v, N) {\n      if (ord[v]\
    \ == -1)\n        dfs(v);\n    }\n    FOR(v, N) comp_id[v] = n_comp - 1 - comp_id[v];\n\
    \  }\n\n  vc<vc<int>> comp() {\n    if (n_comp == 0)\n      build();\n    vc<vc<int>>\
    \ res;\n    res.resize(n_comp);\n    FOR(v, N) { res[comp_id[v]].eb(v); }\n  \
    \  return res;\n  };\n};\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
