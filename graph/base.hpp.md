---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bfs01.hpp
    title: graph/bfs01.hpp
  - icon: ':warning:'
    path: graph/bipartite_coloring.hpp
    title: graph/bipartite_coloring.hpp
  - icon: ':warning:'
    path: graph/degree.hpp
    title: graph/degree.hpp
  - icon: ':warning:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':warning:'
    path: graph/eulerwalk.hpp
    title: graph/eulerwalk.hpp
  - icon: ':x:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  - icon: ':x:'
    path: graph/mis.hpp
    title: graph/mis.hpp
  - icon: ':warning:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/lca.test.cpp
    title: test/library_checker/graph/lca.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/maximum_independent_set.test.cpp
    title: test/library_checker/graph/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a),\
    \ to(b), cost(c), id(d) {}\n};\n\ntemplate <typename T, bool directed = false>\n\
    struct Graph {\n  int N, M;\n  using value_type = T;\n  using edge_type = Edge<T>;\n\
    \  vector<edge_type> edges;\n  vector<vector<edge_type>> G;\n  Graph() {}\n  Graph(int\
    \ N) : N(N), M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    if (i == -1) i = M;\n    auto e = edge_type(frm, to,\
    \ cost, i);\n    edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n     \
    \ auto e_rev = edge_type(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n \
    \   ++M;\n  }\n\n  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout\
    \ << v << \" :\";\n      for (auto e: G[v]) {\n        if (detail)\n         \
    \ cout << \" (\" << e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id\n\
    \               << \")\";\n        else\n          cout << \" \" << e.to;\n  \
    \    }\n      cout << \"\\n\";\n    }\n  }\n  int size() { return N; }\n\n  vector<edge_type>&\
    \ operator[](int v) { return G[v]; }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T\
    \ cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c),\
    \ id(d) {}\n};\n\ntemplate <typename T, bool directed = false>\nstruct Graph {\n\
    \  int N, M;\n  using value_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<vector<edge_type>> G;\n  Graph() {}\n  Graph(int N) : N(N),\
    \ M(0), G(N), directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    if (i == -1) i = M;\n    auto e = edge_type(frm, to, cost, i);\n\
    \    edges.eb(e);\n    G[frm].eb(e);\n    if (!directed) {\n      auto e_rev =\
    \ edge_type(to, frm, cost, i);\n      G[to].eb(e_rev);\n    }\n    ++M;\n  }\n\
    \n  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout << v << \"\
    \ :\";\n      for (auto e: G[v]) {\n        if (detail)\n          cout << \"\
    \ (\" << e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id\n        \
    \       << \")\";\n        else\n          cout << \" \" << e.to;\n      }\n \
    \     cout << \"\\n\";\n    }\n  }\n  int size() { return N; }\n\n  vector<edge_type>&\
    \ operator[](int v) { return G[v]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/base.hpp
  requiredBy:
  - graph/hld.hpp
  - graph/degree.hpp
  - graph/dijkstra.hpp
  - graph/mis.hpp
  - graph/bfs01.hpp
  - graph/scc.hpp
  - graph/bipartite_coloring.hpp
  - graph/eulerwalk.hpp
  timestamp: '2021-12-29 00:40:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/maximum_independent_set.test.cpp
  - test/library_checker/graph/lca.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
documentation_of: graph/base.hpp
layout: document
redirect_from:
- /library/graph/base.hpp
- /library/graph/base.hpp.html
title: graph/base.hpp
---
