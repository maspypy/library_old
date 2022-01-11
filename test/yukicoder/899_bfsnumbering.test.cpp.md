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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/lazy_add_mul.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/899\"\r\n#include \"my_template.hpp\"\
    \r\n#include \"graph/bfsnumbering.hpp\"\r\n#include \"ds/lazysegtree.hpp\"\r\n\
    #include \"algebra/lazy_add_mul.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N);\r\n  Graph<int>\
    \ G(N);\r\n  FOR(_, N - 1) {\r\n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n \
    \ G.prepare();\r\n\r\n  BFSNumbering BFS(G);\r\n  auto &ID = BFS.ID;\r\n  vi seg_raw(N);\r\
    \n\r\n  FOR(v, N) {\r\n    LL(a);\r\n    seg_raw[ID[v]] = a;\r\n  }\r\n\r\n  using\
    \ Lazy = Lazy_Add_Mul<ll>;\r\n  LazySegTree<Lazy> seg(seg_raw);\r\n\r\n  LL(Q);\r\
    \n  FOR(_, Q) {\r\n    LL(v);\r\n    ll p = BFS.parent[v];\r\n    ll pp = (p ==\
    \ -1 ? -1 : BFS.parent[p]);\r\n    ll x = 0;\r\n    if (pp >= 0) x += seg.get(ID[pp]),\
    \ seg.set(ID[pp], 0);\r\n    if (p >= 0) {\r\n      x += seg.get(ID[p]), seg.set(ID[p],\
    \ 0);\r\n      auto [l, r] = BFS.calc_range(p, BFS.depth[p] + 1);\r\n      x +=\
    \ seg.prod(l, r), seg.apply(l, r, 0);\r\n    }\r\n    FOR(d, 3) {\r\n      auto\
    \ [l, r] = BFS.calc_range(v, BFS.depth[v] + d);\r\n      x += seg.prod(l, r),\
    \ seg.apply(l, r, 0);\r\n    }\r\n    print(x);\r\n    seg.set(ID[v], x);\r\n\
    \  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  ll T = 1;\r\n  // LL(T);\r\n  FOR(_, T)\
    \ solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yukicoder/899_bfsnumbering.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/899_bfsnumbering.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/899_bfsnumbering.test.cpp
- /verify/test/yukicoder/899_bfsnumbering.test.cpp.html
title: test/yukicoder/899_bfsnumbering.test.cpp
---
