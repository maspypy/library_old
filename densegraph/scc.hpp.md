---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: densegraph/base.hpp
    title: densegraph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"densegraph/base.hpp\"\n\ntemplate <typename T> struct Graph\
    \ {\n  // only simple graph.\n  int N, M;\n  vector<vector<T>> G;\n  T none_val;\n\
    \  bool directed;\n  Graph() {}\n  Graph(int N, bool bl = false, T none_val =\
    \ -1)\n      : N(N), M(0), G(N, vector<int>(N, none_val)), none_val(none_val),\n\
    \        directed(bl) {}\n\n  void add(int frm, int to, T cost = 1, bool check_mult\
    \ = true) {\n    if(check_mult) assert(G[frm][to] == none_val);\n    G[frm][to]\
    \ = cost;\n    if (!directed) {\n      G[to][frm] = cost;\n    }\n    ++M;\n \
    \ }\n\n  void debug(bool detail = false) {\n    FOR(v, N) {\n      cout << v <<\
    \ \" :\";\n      for (auto e : G[v]) {\n        if (detail)\n          cout <<\
    \ \" (\" << e.frm << \",\" << e.to << \",\" << e.cost << \",\" << e.id\n     \
    \          << \")\";\n        else\n          cout << \" \" << e.to;\n      }\n\
    \      cout << \"\\n\";\n    }\n  }\n\n  int size() { return N; }\n  vector<T>\
    \ &operator[](int v) { return G[v]; }\n};\n#line 3 \"densegraph/scc.hpp\"\n\n\
    template <class T> struct SCC {\n  T &G;\n  ll N;\n  ll n_comp;\n  vc<int> comp_id;\n\
    \  vc<int> low;\n  vc<int> ord;\n  vc<int> visited;\n  ll now = 0;\n\n  SCC(T\
    \ &G)\n      : G(G), N(G.N), n_comp(0), comp_id(G.N, 0), low(G.N, 0), ord(G.N,\
    \ -1) {\n    assert(G.directed);\n    build();\n  }\n\n  ll operator[](ll v) {\
    \ return comp_id[v]; }\n\n  void dfs(int v) {\n    low[v] = now;\n    ord[v] =\
    \ now;\n    ++now;\n    visited.eb(v);\n    FOR(to, N) if(G[v][to]!=G.none_val){\n\
    \      if (ord[to] == -1) {\n        dfs(to);\n        chmin(low[v], low[to]);\n\
    \      } else {\n        chmin(low[v], ord[to]);\n      }\n    }\n    if (low[v]\
    \ == ord[v]) {\n      while (1) {\n        ll u = visited.back();\n        visited.pop_back();\n\
    \        ord[u] = N;\n        comp_id[u] = n_comp;\n        if (u == v)\n    \
    \      break;\n      }\n      ++n_comp;\n    }\n  }\n\n  void build() {\n    FOR(v,\
    \ N) {\n      if (ord[v] == -1)\n        dfs(v);\n    }\n    FOR(v, N) comp_id[v]\
    \ = n_comp - 1 - comp_id[v];\n  }\n\n  vc<vc<int>> comp() {\n    if (n_comp ==\
    \ 0)\n      build();\n    vc<vc<int>> res;\n    res.resize(n_comp);\n    FOR(v,\
    \ N) { res[comp_id[v]].eb(v); }\n    return res;\n  };\n};\n"
  code: "#pragma once\n#include \"densegraph/base.hpp\"\n\ntemplate <class T> struct\
    \ SCC {\n  T &G;\n  ll N;\n  ll n_comp;\n  vc<int> comp_id;\n  vc<int> low;\n\
    \  vc<int> ord;\n  vc<int> visited;\n  ll now = 0;\n\n  SCC(T &G)\n      : G(G),\
    \ N(G.N), n_comp(0), comp_id(G.N, 0), low(G.N, 0), ord(G.N, -1) {\n    assert(G.directed);\n\
    \    build();\n  }\n\n  ll operator[](ll v) { return comp_id[v]; }\n\n  void dfs(int\
    \ v) {\n    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n\
    \    FOR(to, N) if(G[v][to]!=G.none_val){\n      if (ord[to] == -1) {\n      \
    \  dfs(to);\n        chmin(low[v], low[to]);\n      } else {\n        chmin(low[v],\
    \ ord[to]);\n      }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n\
    \        ll u = visited.back();\n        visited.pop_back();\n        ord[u] =\
    \ N;\n        comp_id[u] = n_comp;\n        if (u == v)\n          break;\n  \
    \    }\n      ++n_comp;\n    }\n  }\n\n  void build() {\n    FOR(v, N) {\n   \
    \   if (ord[v] == -1)\n        dfs(v);\n    }\n    FOR(v, N) comp_id[v] = n_comp\
    \ - 1 - comp_id[v];\n  }\n\n  vc<vc<int>> comp() {\n    if (n_comp == 0)\n   \
    \   build();\n    vc<vc<int>> res;\n    res.resize(n_comp);\n    FOR(v, N) { res[comp_id[v]].eb(v);\
    \ }\n    return res;\n  };\n};\n"
  dependsOn:
  - densegraph/base.hpp
  isVerificationFile: false
  path: densegraph/scc.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: densegraph/scc.hpp
layout: document
redirect_from:
- /library/densegraph/scc.hpp
- /library/densegraph/scc.hpp.html
title: densegraph/scc.hpp
---
