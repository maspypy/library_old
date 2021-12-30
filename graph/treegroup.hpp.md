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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#include \"algebra/monoid.hpp\"\r\n#include \"ds/segtree.hpp\"\r\n#include\
    \ \"graph/hld.hpp\"\r\n\r\n// \u4F5C\u3063\u3066\u307F\u305F\u3082\u306E\u306E\
    \u3001HLD(log^2N)\u3088\u308A\u9045\u3044\u304C\u3061\uFF1F\r\ntemplate <typename\
    \ Graph, typename E, bool edge = false>\r\nstruct TreeGroup {\r\n  using F = function<E(E,\
    \ E)>;\r\n  using G = function<E(E)>;\r\n\r\n  HLD<Graph> &hld;\r\n  int N;\r\n\
    \  F f;\r\n  G inverse;\r\n  E unit;\r\n  const bool commute;\r\n  const bool\
    \ path_query;\r\n  const bool subtree_query;\r\n  SegTree<E> seg, seg_r, seg_subtree;\r\
    \n\r\n  TreeGroup(HLD<Graph> &hld, Monoid<E> Mono, bool path_query,\r\n      \
    \      bool subtree_query)\r\n      : hld(hld)\r\n      , N(hld.N)\r\n      ,\
    \ f(Mono.f)\r\n      , inverse(Mono.inverse)\r\n      , unit(Mono.unit)\r\n  \
    \    , commute(Mono.commute)\r\n      , path_query(path_query)\r\n      , subtree_query(subtree_query)\r\
    \n      , seg(Mono)\r\n      , seg_r(Monoid_reverse<E>(Mono))\r\n      , seg_subtree(Mono)\
    \ {\r\n    assert(Mono.has_inverse);\r\n    if (path_query) {\r\n      seg.init(N\
    \ + N);\r\n      if (!commute) seg_r.init(N + N);\r\n    }\r\n    if (subtree_query)\
    \ {\r\n      assert(Mono.commute);\r\n      seg_subtree.init(N);\r\n    }\r\n\
    \  };\r\n\r\n  void init_path(vc<E> &dat) {\r\n    vc<E> seg_raw(N + N, unit);\r\
    \n    if (!edge) {\r\n      FOR(v, N) {\r\n        seg_raw[hld.ELID[v]] = dat[v];\r\
    \n        seg_raw[hld.ERID[v]] = inverse(dat[v]);\r\n      }\r\n    } else {\r\
    \n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n        seg_raw[hld.ELID[v]]\
    \ = dat[i];\r\n        seg_raw[hld.ERID[v]] = inverse(dat[i]);\r\n      }\r\n\
    \    }\r\n    seg.build(seg_raw);\r\n    if (!commute) seg_r.build(seg_raw);\r\
    \n  }\r\n\r\n  void init_subtree(vc<E> &dat) {\r\n    vc<E> seg_raw(N, unit);\r\
    \n    if (!edge) {\r\n      FOR(v, N) { seg_raw[hld.LID[v]] = dat[v]; }\r\n  \
    \  } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n   \
    \     seg_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    seg_subtree.build(seg_raw);\r\
    \n  }\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\n\
    \    if (path_query) init_path(dat);\r\n    if (subtree_query) init_subtree(dat);\r\
    \n  }\r\n\r\n  void set_path(int v, E x) {\r\n    seg.set(hld.ELID[v], x);\r\n\
    \    seg.set(hld.ERID[v], inverse(x));\r\n    if (!commute) {\r\n      seg_r.set(hld.ELID[v],\
    \ x);\r\n      seg_r.set(hld.ERID[v], inverse(x));\r\n    }\r\n  }\r\n\r\n  void\
    \ set_subtree(int v, E x) { seg_subtree.set(hld.LID[v], x); }\r\n\r\n  void set(int\
    \ i, E x) {\r\n    int v = (edge ? hld.e_to_v[i] : i);\r\n    if (path_query)\
    \ set_path(v, x);\r\n    if (subtree_query) set_subtree(v, x);\r\n  }\r\n\r\n\
    \  E prod_path(int frm, int to) {\r\n    int lca = hld.LCA(frm, to);\r\n    //\
    \ [frm, lca)\r\n    E x1 = (commute ? seg.prod(hld.ELID[lca] + 1, hld.ELID[frm]\
    \ + 1)\r\n                    : seg_r.prod(hld.ELID[lca] + 1, hld.ELID[frm] +\
    \ 1));\r\n    // edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\r\
    \n    E x2 = seg.prod(hld.ELID[lca] + edge, hld.ELID[to] + 1);\r\n    return f(x1,\
    \ x2);\r\n  }\r\n\r\n  E prod_subtree(int u) {\r\n    assert(subtree_query);\r\
    \n    int l = hld.LID[u], r = hld.RID[u];\r\n    return seg_subtree.prod(l + edge,\
    \ r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\
    \n    print(\"seg\");\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\
    \n    print(\"seg_subtree\");\r\n    seg_subtree.debug();\r\n  }\r\n\r\n  void\
    \ doc() {\r\n    print(\"EulerTour + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\
    \u9006\u5143\u3092\u5229\u7528\u3057\u3066\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \u3092 O(logN) \u6642\u9593\u3067\u884C\u3046\u3002\");\r\n    print(\"\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA\
    \ O(logN) \u6642\u9593\u3002\");\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/treegroup.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treegroup.hpp
layout: document
redirect_from:
- /library/graph/treegroup.hpp
- /library/graph/treegroup.hpp.html
title: graph/treegroup.hpp
---
