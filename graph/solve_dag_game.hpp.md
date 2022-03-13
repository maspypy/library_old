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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/reverse_graph.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/reverse_graph.hpp\"\r\ntemplate <typename Graph, typename\
    \ INT>\r\nvoid solve_dag_game(Graph& G, vc<INT>& DP) {\r\n  /*\r\n  -1: unknown\r\
    \n  0 : lose\r\n  1 : win\r\n\r\n  \u4E88\u3081\u9077\u79FB\u5148\u306E\u306A\u3044\
    \u9802\u70B9\u306B\u306F\u30010 \u307E\u305F\u306F 1 \u3092\u5165\u308C\u3066\u304A\
    \u304F\r\n  */\r\n  int N = G.N;\r\n  vc<int> outdeg(N);\r\n  for (auto&& e: G.edges)\
    \ outdeg[e.frm]++;\r\n\r\n  G = reverse_graph(G);\r\n  vc<int> que;\r\n  FOR(v,\
    \ N) {\r\n    assert((outdeg[v] == 0) == (DP[v] != -1));\r\n    if (outdeg[v]\
    \ == 0) que.eb(v);\r\n  }\r\n  while (!que.empty()) {\r\n    int v = que.back();\r\
    \n    que.pop_back();\r\n    for (auto&& e: G[v]) {\r\n      if (DP[e.to] != -1)\
    \ continue;\r\n      if (DP[v] == 0) {\r\n        DP[e.to] = 1;\r\n        que.eb(e.to);\r\
    \n      }\r\n      elif (DP[v] == 1) {\r\n        outdeg[e.to]--;\r\n        if\
    \ (outdeg[e.to] == 0) {\r\n          DP[e.to] = 0;\r\n          que.eb(e.to);\r\
    \n        }\r\n      }\r\n    }\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/solve_dag_game.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/solve_dag_game.hpp
layout: document
redirect_from:
- /library/graph/solve_dag_game.hpp
- /library/graph/solve_dag_game.hpp.html
title: graph/solve_dag_game.hpp
---
