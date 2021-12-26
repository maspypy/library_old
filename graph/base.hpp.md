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
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':warning:'
    path: graph/eulerwalk.hpp
    title: graph/eulerwalk.hpp
  - icon: ':warning:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/lca.test.cpp
    title: test/library_checker/tree/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ v) { return G[v]; }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T\
    \ cost;\n  int id;\n  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c),\
    \ id(d) {}\n};\n\ntemplate <typename T>\nstruct Graph {\n  int N, M;\n  using\
    \ edge_t = Edge<T>;\n  vector<edge_t> edges;\n  vector<vector<edge_t>> G;\n  bool\
    \ directed;\n  Graph() {}\n  Graph(int N, bool bl = false) : N(N), M(0), G(N),\
    \ directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n \
    \   if (i == -1) i = M;\n    auto e = edge_t(frm, to, cost, i);\n    edges.eb(e);\n\
    \    G[frm].eb(e);\n    if (!directed) {\n      auto e_rev = edge_t(to, frm, cost,\
    \ i);\n      G[to].eb(e_rev);\n    }\n    ++M;\n  }\n\n  void debug(bool detail\
    \ = false) {\n    FOR(v, N) {\n      cout << v << \" :\";\n      for (auto e :\
    \ G[v]) {\n        if (detail)\n          cout << \" (\" << e.frm << \",\" <<\
    \ e.to << \",\" << e.cost << \",\" << e.id\n               << \")\";\n       \
    \ else\n          cout << \" \" << e.to;\n      }\n      cout << \"\\n\";\n  \
    \  }\n  }\n\n  vector<int> degrees() {\n    vector<int> deg(N);\n    FORIN(e,\
    \ edges) {\n      deg[e.frm]++;\n      deg[e.to]++;\n    }\n    return deg;\n\
    \  }\n\n  int size() { return N; }\n\n  vector<edge_t>& operator[](int v) { return\
    \ G[v]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/base.hpp
  requiredBy:
  - graph/dijkstra.hpp
  - graph/bfs01.hpp
  - graph/scc.hpp
  - graph/bipartite_coloring.hpp
  - graph/eulerwalk.hpp
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/tree/lca.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_nc.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
documentation_of: graph/base.hpp
layout: document
redirect_from:
- /library/graph/base.hpp
- /library/graph/base.hpp.html
title: graph/base.hpp
---
