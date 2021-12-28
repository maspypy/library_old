---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/hld.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"my_template.hpp\"\n\n#include \"ds/segtree.hpp\"\n#include \"graph/base.hpp\"\
    \n#include \"graph/hld.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\
    \ntemplate <typename Graph, typename E, bool edge = false>\nstruct TreeGroup {\n\
    \  using F = function<E(E, E)>;\n  using G = function<E(E)>;\n\n  HLD<Graph> &hld;\n\
    \  int N;\n  F f;\n  G inverse;\n  E unit;\n  const bool commute;\n  const bool\
    \ path_query;\n  const bool subtree_query;\n  SegTree<E> seg, seg_r, seg_subtree;\n\
    \n  TreeGroup(HLD<Graph> &hld, Monoid<E> Mono, bool path_query,\n            bool\
    \ subtree_query)\n      : hld(hld)\n      , N(hld.N)\n      , f(Mono.f)\n    \
    \  , inverse(Mono.inverse)\n      , unit(Mono.unit)\n      , commute(Mono.commute)\n\
    \      , path_query(path_query)\n      , subtree_query(subtree_query)\n      ,\
    \ seg(Mono)\n      , seg_r(Monoid_reverse<E>(Mono))\n      , seg_subtree(Mono)\
    \ {\n    assert(Mono.has_inverse);\n    if (path_query) {\n      seg.init(N +\
    \ N);\n      if (!commute) seg_r.init(N + N);\n    }\n    if (subtree_query) {\n\
    \      assert(Mono.commute);\n      seg_subtree.init(N);\n    }\n  };\n\n  void\
    \ init_path(vc<E> &dat) {\n    vc<E> seg_raw(N + N, unit);\n    if (!edge) {\n\
    \      FOR(v, N) {\n        seg_raw[hld.ELID[v]] = dat[v];\n        seg_raw[hld.ERID[v]]\
    \ = inverse(dat[v]);\n      }\n    } else {\n      FOR(i, N - 1) {\n        int\
    \ v = hld.e_to_v[i];\n        seg_raw[hld.ELID[v]] = dat[i];\n        seg_raw[hld.ERID[v]]\
    \ = inverse(dat[i]);\n      }\n    }\n    seg.build(seg_raw);\n    if (!commute)\
    \ seg_r.build(seg_raw);\n  }\n\n  void init_subtree(vc<E> &dat) {\n    vc<E> seg_raw(N,\
    \ unit);\n    if (!edge) {\n      FOR(v, N) { seg_raw[hld.LID[v]] = dat[v]; }\n\
    \    } else {\n      FOR(i, N - 1) {\n        int v = hld.e_to_v[i];\n       \
    \ seg_raw[hld.LID[v]] = dat[i];\n      }\n    }\n    seg_subtree.build(seg_raw);\n\
    \  }\n\n  void init(vc<E> &dat) {\n    // vertex index OR edge index\n    if (path_query)\
    \ init_path(dat);\n    if (subtree_query) init_subtree(dat);\n  }\n\n  void set_path(int\
    \ v, E x) {\n    seg.set(hld.ELID[v], x);\n    seg.set(hld.ERID[v], inverse(x));\n\
    \    if (!commute) {\n      seg_r.set(hld.ELID[v], x);\n      seg_r.set(hld.ERID[v],\
    \ inverse(x));\n    }\n  }\n\n  void set_subtree(int v, E x) { seg_subtree.set(hld.LID[v],\
    \ x); }\n\n  void set(int i, E x) {\n    int v = (edge ? hld.e_to_v[i] : i);\n\
    \    if (path_query) set_path(v, x);\n    if (subtree_query) set_subtree(v, x);\n\
    \  }\n\n  E prod_path(int frm, int to) {\n    int lca = hld.LCA(frm, to);\n  \
    \  // [frm, lca)\n    E x1 = (commute ? seg.prod(hld.ELID[lca] + 1, hld.ELID[frm]\
    \ + 1)\n                    : seg_r.prod(hld.ELID[lca] + 1, hld.ELID[frm] + 1));\n\
    \    // edge \u306A\u3089 (lca, to]\u3001vertex \u306A\u3089 [lca, to]\n    E\
    \ x2 = seg.prod(hld.ELID[lca] + edge, hld.ELID[to] + 1);\n    return f(x1, x2);\n\
    \  }\n\n  E prod_subtree(int u) {\n    assert(subtree_query);\n    int l = hld.LID[u],\
    \ r = hld.RID[u];\n    return seg_subtree.prod(l + edge, r);\n  }\n\n  void debug()\
    \ {\n    print(\"hld\");\n    hld.debug();\n    print(\"seg\");\n    seg.debug();\n\
    \    print(\"seg_r\");\n    seg_r.debug();\n    print(\"seg_subtree\");\n    seg_subtree.debug();\n\
    \  }\n\n  void doc() {\n    print(\"EulerTour + \u30BB\u30B0\u6728\u3002\");\n\
    \    print(\"\u9006\u5143\u3092\u5229\u7528\u3057\u3066\u3001\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3092 O(logN) \u6642\u9593\u3067\u884C\u3046\u3002\");\n    print(\"\
    \u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\u30D1\u30B9\u30AF\
    \u30A8\u30EA O(logN) \u6642\u9593\u3002\");\n  }\n};\n\nvoid solve() {\n  LL(N,\
    \ Q);\n  using E = pair<mint, mint>;\n  vc<E> A(N);\n  FOR(i, N) {\n    LL(a,\
    \ b);\n    A[i] = mp(mint(a), mint(b));\n  }\n\n  Graph<int> G(N);\n  FOR(_, N\
    \ - 1) {\n    LL(a, b);\n    G.add(a, b);\n  }\n\n  HLD<Graph<int>> hld(G);\n\
    \  TreeGroup<Graph<int>, E, false> TG(hld, Monoid_affine<mint>(true), true,\n\
    \                                     false);\n  TG.init(A);\n\n  FOR(_, Q) {\n\
    \    LL(t);\n    if (t == 0) {\n      LL(v, c, d);\n      TG.set(v, E({mint(c),\
    \ mint(d)}));\n    } else {\n      LL(u, v, x);\n      auto e = TG.prod_path(u,\
    \ v);\n      print(e.fi * mint(x) + e.se);\n    }\n  }\n}\n\nsigned main() {\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
- /verify/test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp.html
title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
---
