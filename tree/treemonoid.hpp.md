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
    \ \"graph/hld.hpp\"\r\n\r\ntemplate <typename Graph, typename E, bool edge = false>\r\
    \nstruct TreeMonoid {\r\n  using F = function<E(E, E)>;\r\n  HLD<Graph> &hld;\r\
    \n  int N;\r\n  F f;\r\n  E unit;\r\n  bool commute;\r\n  SegTree<E> seg, seg_r;\r\
    \n\r\n  TreeMonoid(HLD<Graph> &hld, Monoid<E> Mono)\r\n      : hld(hld)\r\n  \
    \    , N(hld.N)\r\n      , f(Mono.f)\r\n      , unit(Mono.unit)\r\n      , commute(Mono.commute)\r\
    \n      , seg(Mono)\r\n      , seg_r(Monoid_reverse<E>(Mono)) {\r\n    seg.init(N);\r\
    \n    if (!commute) seg_r.init(N);\r\n  };\r\n\r\n  void init(vc<E> &dat) {\r\n\
    \    // vertex index OR edge index\r\n    vc<E> seg_raw(N, unit);\r\n    if (!edge)\
    \ {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\n    } else {\r\n     \
    \ FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\n        seg_raw[hld.LID[v]]\
    \ = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\n    if (!commute)\
    \ seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x) {\r\n    if (edge)\
    \ i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i, x);\r\n    if (!commute)\
    \ seg_r.set(i, x);\r\n  }\r\n\r\n  E prod_path_nc(int u, int v) {\r\n    E vl\
    \ = unit, vr = unit;\r\n    while (1) {\r\n      if (hld.head[u] == hld.head[v])\
    \ break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\n        vr = f(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), vr);\r\n        v = hld.parent[hld.head[v]];\r\n      } else\
    \ {\r\n        vl = f(vl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\
    \n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    E vm =\r\n \
    \     (hld.LID[u] < hld.LID[v] ? seg.prod(hld.LID[u] + edge, hld.LID[v] + 1)\r\
    \n                               : seg_r.prod(hld.LID[v] + edge, hld.LID[u] +\
    \ 1));\r\n    return f(vl, f(vm, vr));\r\n  }\r\n\r\n  E prod_path(int u, int\
    \ v) {\r\n    if (!commute) return prod_path_nc(u, v);\r\n    E val = unit;\r\n\
    \    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      val = f(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return f(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\n\
    \  E prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n    return\
    \ seg.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"hld\");\r\
    \n    hld.debug();\r\n    print(\"seg\");\r\n    seg.debug();\r\n    print(\"\
    seg_r\");\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\
    \u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\
    \u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\
    \u9593\u3002\");\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/treemonoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/treemonoid.hpp
layout: document
redirect_from:
- /library/tree/treemonoid.hpp
- /library/tree/treemonoid.hpp.html
title: tree/treemonoid.hpp
---
