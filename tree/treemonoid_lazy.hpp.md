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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n\r\ntemplate <typename HLD, typename E,\
    \ typename OP, bool edge = false,\r\n          bool commute = true, bool OP_commute\
    \ = false>\r\nstruct TreeMonoidLazy {\r\n  using F = function<E(E, E)>;\r\n  using\
    \ G = function<E(E, OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  HLD &hld;\r\
    \n  int N;\r\n  F seg_f;\r\n  E E_unit;\r\n  LazySegTree<E, OP, OP_commute> seg,\
    \ seg_r;\r\n\r\n  TreeMonoidLazy(HLD &hld, F seg_f, G seg_g, H seg_h, E E_unit,\
    \ OP OP_unit)\r\n      : hld(hld)\r\n      , N(hld.N)\r\n      , seg_f(seg_f)\r\
    \n      , E_unit(E_unit)\r\n      , seg(seg_f, seg_g, seg_h, E_unit, OP_unit)\r\
    \n      , seg_r([&](E x, E y) -> E { return seg_f(y, x); }, seg_g, seg_h, E_unit,\r\
    \n              OP_unit) {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\
    \n  };\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\
    \n    vc<E> seg_raw(N, E_unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\
    \n        seg_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\
    \n    if (!commute) seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x)\
    \ {\r\n    if (edge) i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i,\
    \ x);\r\n    if (!commute) seg_r.set(i, x);\r\n  }\r\n\r\n  E fold_path_nc(int\
    \ u, int v) {\r\n    E vl = E_unit, vr = E_unit;\r\n    while (1) {\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\
    \n        vr = seg_f(seg.fold(hld.LID[hld.head[v]], hld.LID[v] + 1), vr);\r\n\
    \        v = hld.parent[hld.head[v]];\r\n      } else {\r\n        vl = seg_f(vl,\
    \ seg_r.fold(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\n        u = hld.parent[hld.head[u]];\r\
    \n      }\r\n    }\r\n    E vm =\r\n      (hld.LID[u] < hld.LID[v] ? seg.fold(hld.LID[u]\
    \ + edge, hld.LID[v] + 1)\r\n                               : seg_r.fold(hld.LID[v]\
    \ + edge, hld.LID[u] + 1));\r\n    return seg_f(vl, seg_f(vm, vr));\r\n  }\r\n\
    \r\n  E fold_path(int u, int v) {\r\n    if (!commute) return fold_path_nc(u,\
    \ v);\r\n    E val = E_unit;\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v])\
    \ swap(u, v);\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      val = seg_f(seg.fold(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return seg_f(seg.fold(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\
    \n  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\n    print(\"\
    seg\");\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\n\
    \  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\
    \");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\
    \u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\u9593\u3002\");\r\n    print(\"\
    \u30D1\u30B9\u9806\u3092\u6C17\u306B\u3059\u308B\u5834\u5408\u306F\u3001commute=false\u3068\
    \u3059\u308B\u3002\");\r\n    print(\"\u95A2\u9023\");\r\n    print(\"- \u7FA4\
    \u306A\u3089\u30D1\u30B9\u30AF\u30A8\u30EA\u306F TreeGrp \u3067 O(logN) \u6642\
    \u9593\");\r\n    print(\"- \u5909\u66F4\u306A\u3057\u306A\u3089\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u306F TreeMonoid_static \u3067 O(logN) \u6642\u9593\");\r\n  }\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/treemonoid_lazy.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/treemonoid_lazy.hpp
layout: document
redirect_from:
- /library/tree/treemonoid_lazy.hpp
- /library/tree/treemonoid_lazy.hpp.html
title: tree/treemonoid_lazy.hpp
---
