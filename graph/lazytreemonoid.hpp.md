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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/reverselazy.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n#include \"graph/hld.hpp\"\r\n#include\
    \ \"algebra/reverselazy.hpp\"\r\n\r\ntemplate <typename HLD, typename Lazy, bool\
    \ edge = false>\r\nstruct LazyTreeMonoid {\r\n  using MonoX = typename Lazy::X_structure;\r\
    \n  using MonoA = typename Lazy::A_structure;\r\n  using X = typename MonoX::value_type;\r\
    \n  using A = typename MonoA::value_type;\r\n  using RevLazy = ReverseLazy<Lazy>;\r\
    \n  HLD &hld;\r\n  int N;\r\n  LazySegTree<Lazy> seg;\r\n  LazySegTree<RevLazy>\
    \ seg_r;\r\n\r\n  LazyTreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {\r\
    \n    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(hld.N);\r\n  }\r\n\r\n\
    \  LazyTreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {\r\n    vc<X> seg_raw(N,\
    \ MonoX::unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];\r\
    \n    } else {\r\n      FOR(e, N - 1) {\r\n        int v = hld.e_to_v(e);\r\n\
    \        seg_raw[hld.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = LazySegTree<Lazy>(seg_raw);\r\
    \n    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(seg_raw);\r\n  }\r\n\r\
    \n  void set(int i, X x) {\r\n    if (edge) i = hld.e_to_v(i);\r\n    i = hld.LID[i];\r\
    \n    seg.set(i, x);\r\n    if (!MonoX::commute) seg_r.set(i, x);\r\n  }\r\n\r\
    \n  X prod_path_nc(int u, int v) {\r\n    X xl = MonoX::unit, xr = MonoX::unit;\r\
    \n    while (1) {\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      if\
    \ (hld.LID[u] < hld.LID[v]) {\r\n        xr = MonoX::op(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), xr);\r\n        v = hld.parent[hld.head[v]];\r\n      } else\
    \ {\r\n        xl = MonoX::op(xl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u]\
    \ + 1));\r\n        u = hld.parent[hld.head[u]];\r\n      }\r\n    }\r\n    X\
    \ xm = (hld.LID[u] < hld.LID[v]\r\n                ? seg.prod(hld.LID[u] + edge,\
    \ hld.LID[v] + 1)\r\n                : seg_r.prod(hld.LID[v] + edge, hld.LID[u]\
    \ + 1));\r\n    return MonoX::op(xl, MonoX::op(xm, xr));\r\n  }\r\n\r\n  X prod_path(int\
    \ u, int v) {\r\n    if (!MonoX::commute) return prod_path_nc(u, v);\r\n    X\
    \ val = MonoX::unit;\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v])\
    \ swap(u, v);\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      val = MonoX::op(seg.prod(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return MonoX::op(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\
    \n\r\n  X prod_subtree(int u) {\r\n    int l = hld.LID[u], r = hld.RID[u];\r\n\
    \    return seg.prod(l + edge, r);\r\n  }\r\n\r\n  void apply_path(int u, int\
    \ v, A a) {\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v]) swap(u, v);\r\
    \n      if (hld.head[u] == hld.head[v]) break;\r\n      seg.apply(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1, a);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n    seg.apply(hld.LID[u]\
    \ + edge, hld.LID[v] + 1, a);\r\n  }\r\n\r\n  void apply_subtree(int u, A a) {\r\
    \n    int l = hld.LID[u], r = hld.RID[u];\r\n    return seg.apply(l + edge, r,\
    \ a);\r\n  }\r\n\r\n  void debug() {\r\n    print(\"tree_monoid\");\r\n    hld.debug();\r\
    \n    seg.debug();\r\n    seg_r.debug();\r\n  }\r\n\r\n  void doc() {\r\n    print(\"\
    HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\");\r\n    print(\"\u90E8\u5206\u6728\
    \u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N)\
    \ \u6642\u9593\u3002\");\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lazytreemonoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lazytreemonoid.hpp
layout: document
redirect_from:
- /library/graph/lazytreemonoid.hpp
- /library/graph/lazytreemonoid.hpp.html
title: graph/lazytreemonoid.hpp
---
