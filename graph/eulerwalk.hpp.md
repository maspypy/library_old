---
data:
  _extendedDependsOn:
  - icon: ':x:'
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
    \ v) { return G[v]; }\n};\n#line 2 \"graph/eulerwalk.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nvi euler_walk(Graph<T>& G) {\r\n  /*\r\n  \u9802\u70B9\u756A\u53F7\u306E\
    \u5217\u3092\u8FD4\u3059\u3002\u6709\u5411\u30FB\u7121\u5411\u4E21\u5BFE\u5FDC\
    \u3002\r\n  \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306B\u306F\u3001\u7A7A\
    \u3092\u8FD4\u3059\u3002\r\n  \u8FBA\u304C 0 \u500B\u306E\u5834\u5408\u306B\u306F\
    \ {0} \u3092\u8FD4\u3059\u3002\r\n  */\r\n  ll N = G.N, M = G.M;\r\n  if (M ==\
    \ 0) return {0};\r\n  vi deg(N);\r\n  FORIN(e, G.edges) {\r\n    if (G.directed)\
    \ {\r\n      deg[e.frm]++, deg[e.to]--;\r\n    } else {\r\n      deg[e.frm]++,\
    \ deg[e.to]++;\r\n    }\r\n  }\r\n\r\n  ll s = max_element(all(deg)) - deg.begin();\r\
    \n  if (deg[s] == 0) s = G.edges[0].frm;\r\n\r\n  vi D(N), its(N), eu(M), ret,\
    \ st = {s};\r\n  ++D[s];\r\n  while (!st.empty()) {\r\n    ll x = st.back(), y,\
    \ e, &it = its[x], end = len(G[x]);\r\n    if (it == end) {\r\n      ret.eb(x);\r\
    \n      st.pop_back();\r\n      continue;\r\n    }\r\n    auto ee = G[x][it++];\r\
    \n    y = ee.to, e = ee.id;\r\n    if (!eu[e]) {\r\n      D[x]--, D[y]++;\r\n\
    \      eu[e] = 1;\r\n      st.eb(y);\r\n    }\r\n  }\r\n  FORIN(x, D) if (x <\
    \ 0) return {};\r\n  if (len(ret) != M + 1) return {};\r\n  reverse(all(ret));\r\
    \n  return ret;\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\ntemplate <typename T>\r\nvi euler_walk(Graph<T>&\
    \ G) {\r\n  /*\r\n  \u9802\u70B9\u756A\u53F7\u306E\u5217\u3092\u8FD4\u3059\u3002\
    \u6709\u5411\u30FB\u7121\u5411\u4E21\u5BFE\u5FDC\u3002\r\n  \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306B\u306F\u3001\u7A7A\u3092\u8FD4\u3059\u3002\r\n \
    \ \u8FBA\u304C 0 \u500B\u306E\u5834\u5408\u306B\u306F {0} \u3092\u8FD4\u3059\u3002\
    \r\n  */\r\n  ll N = G.N, M = G.M;\r\n  if (M == 0) return {0};\r\n  vi deg(N);\r\
    \n  FORIN(e, G.edges) {\r\n    if (G.directed) {\r\n      deg[e.frm]++, deg[e.to]--;\r\
    \n    } else {\r\n      deg[e.frm]++, deg[e.to]++;\r\n    }\r\n  }\r\n\r\n  ll\
    \ s = max_element(all(deg)) - deg.begin();\r\n  if (deg[s] == 0) s = G.edges[0].frm;\r\
    \n\r\n  vi D(N), its(N), eu(M), ret, st = {s};\r\n  ++D[s];\r\n  while (!st.empty())\
    \ {\r\n    ll x = st.back(), y, e, &it = its[x], end = len(G[x]);\r\n    if (it\
    \ == end) {\r\n      ret.eb(x);\r\n      st.pop_back();\r\n      continue;\r\n\
    \    }\r\n    auto ee = G[x][it++];\r\n    y = ee.to, e = ee.id;\r\n    if (!eu[e])\
    \ {\r\n      D[x]--, D[y]++;\r\n      eu[e] = 1;\r\n      st.eb(y);\r\n    }\r\
    \n  }\r\n  FORIN(x, D) if (x < 0) return {};\r\n  if (len(ret) != M + 1) return\
    \ {};\r\n  reverse(all(ret));\r\n  return ret;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/eulerwalk.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/eulerwalk.hpp
layout: document
redirect_from:
- /library/graph/eulerwalk.hpp
- /library/graph/eulerwalk.hpp.html
title: graph/eulerwalk.hpp
---
