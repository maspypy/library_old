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
  bundledCode: "#line 2 \"graph/treedoubling.hpp\"\ntemplate <typename GT, typename\
    \ T>\nstruct TreeDoubling {\n  using F = function<T(T, T)>;\n  const int K = 20;\n\
    \  EulerTour<GT>& ET;\n  F f;\n  T T_unit;\n  bool edge;\n  vector<vector<T>>\
    \ dp;\n  bool done;\n\n  TreeDoubling(){}\n  TreeDoubling(EulerTour<GT>& ET, F\
    \ f, T T_unit, bool edge) : ET(ET), f(f), T_unit(T_unit), edge(edge), done(false)\
    \ {\n    auto N = ET.G.size();\n    FOR(k, K) { dp.eb(vector<T>(N, T_unit)); }\n\
    \  }\n\n  void set(int v, T t) { dp[0][v] = t; }\n\n  void build() {\n    done\
    \ = true;\n    auto& anc = ET.ancestors;\n    auto N = dp[0].size();\n    FOR3(k,\
    \ 1, K) {\n      FOR(v, N) {\n        int w = anc[k - 1][v];\n        dp[k][v]\
    \ = (w!=-1 ? f(dp[k - 1][v], dp[k - 1][w]) : dp[k-1][v]);\n      }\n    }\n  }\n\
    \n  int LA(int a, int n){\n    return ET.LA(a, n);\n  }\n\n  int LCA(int a, int\
    \ b) { return ET.LCA(a, b); }\n\n  T query(int a, int b) {\n    assert(done);\n\
    \    T res = T_unit;\n    auto& anc = ET.ancestors;\n    auto& dep = ET.depth;\n\
    \    if (dep[a] > dep[b]) swap(a, b);\n    auto n = dep[b] - dep[a];\n    FOR(k,\
    \ 20) {\n      if (n & 1 << k) {\n        res = f(res, dp[k][b]);\n        b =\
    \ anc[k][b];\n      }\n    }\n    if (a == b) {\n      return (edge ? res : f(res,\
    \ dp[0][a]));\n    }\n    FOR_R(k, 20) {\n      if (anc[k][a] != anc[k][b]) {\n\
    \        res = f(res, dp[k][a]);\n        res = f(res, dp[k][b]);\n        a =\
    \ anc[k][a];\n        b = anc[k][b];\n      }\n    }\n    res = f(res, dp[0][a]);\n\
    \    res = f(res, dp[0][b]);\n    int lca = anc[0][a];\n    return (edge ? res\
    \ : f(res, dp[0][lca]));\n  }\n\n  // lowest ancestor t of s, satisfying check(query(s,t))\n\
    \  template<typename C>\n  int max_ancestor(int s, C &check, bool edge=true){\n\
    \    assert(check(T_unit));\n    assert(edge);  // \u3068\u308A\u3042\u3048\u305A\
    \n    \n    auto& anc = ET.ancestors;\n    T x = T_unit;\n    FOR_R(k, K){\n \
    \     if(anc[k][s] == -1) continue;\n      T new_x = f(x, dp[k][s]);\n      if(check(new_x)){\n\
    \        s = anc[k][s];\n        x = new_x;\n      };\n    }\n    return s;\n\
    \  }\n};\n"
  code: "#pragma once\ntemplate <typename GT, typename T>\nstruct TreeDoubling {\n\
    \  using F = function<T(T, T)>;\n  const int K = 20;\n  EulerTour<GT>& ET;\n \
    \ F f;\n  T T_unit;\n  bool edge;\n  vector<vector<T>> dp;\n  bool done;\n\n \
    \ TreeDoubling(){}\n  TreeDoubling(EulerTour<GT>& ET, F f, T T_unit, bool edge)\
    \ : ET(ET), f(f), T_unit(T_unit), edge(edge), done(false) {\n    auto N = ET.G.size();\n\
    \    FOR(k, K) { dp.eb(vector<T>(N, T_unit)); }\n  }\n\n  void set(int v, T t)\
    \ { dp[0][v] = t; }\n\n  void build() {\n    done = true;\n    auto& anc = ET.ancestors;\n\
    \    auto N = dp[0].size();\n    FOR3(k, 1, K) {\n      FOR(v, N) {\n        int\
    \ w = anc[k - 1][v];\n        dp[k][v] = (w!=-1 ? f(dp[k - 1][v], dp[k - 1][w])\
    \ : dp[k-1][v]);\n      }\n    }\n  }\n\n  int LA(int a, int n){\n    return ET.LA(a,\
    \ n);\n  }\n\n  int LCA(int a, int b) { return ET.LCA(a, b); }\n\n  T query(int\
    \ a, int b) {\n    assert(done);\n    T res = T_unit;\n    auto& anc = ET.ancestors;\n\
    \    auto& dep = ET.depth;\n    if (dep[a] > dep[b]) swap(a, b);\n    auto n =\
    \ dep[b] - dep[a];\n    FOR(k, 20) {\n      if (n & 1 << k) {\n        res = f(res,\
    \ dp[k][b]);\n        b = anc[k][b];\n      }\n    }\n    if (a == b) {\n    \
    \  return (edge ? res : f(res, dp[0][a]));\n    }\n    FOR_R(k, 20) {\n      if\
    \ (anc[k][a] != anc[k][b]) {\n        res = f(res, dp[k][a]);\n        res = f(res,\
    \ dp[k][b]);\n        a = anc[k][a];\n        b = anc[k][b];\n      }\n    }\n\
    \    res = f(res, dp[0][a]);\n    res = f(res, dp[0][b]);\n    int lca = anc[0][a];\n\
    \    return (edge ? res : f(res, dp[0][lca]));\n  }\n\n  // lowest ancestor t\
    \ of s, satisfying check(query(s,t))\n  template<typename C>\n  int max_ancestor(int\
    \ s, C &check, bool edge=true){\n    assert(check(T_unit));\n    assert(edge);\
    \  // \u3068\u308A\u3042\u3048\u305A\n    \n    auto& anc = ET.ancestors;\n  \
    \  T x = T_unit;\n    FOR_R(k, K){\n      if(anc[k][s] == -1) continue;\n    \
    \  T new_x = f(x, dp[k][s]);\n      if(check(new_x)){\n        s = anc[k][s];\n\
    \        x = new_x;\n      };\n    }\n    return s;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/treedoubling.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treedoubling.hpp
layout: document
redirect_from:
- /library/graph/treedoubling.hpp
- /library/graph/treedoubling.hpp.html
title: graph/treedoubling.hpp
---
