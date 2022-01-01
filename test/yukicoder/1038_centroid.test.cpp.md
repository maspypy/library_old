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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/addgroup.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1038\"\r\n#include \"\
    my_template.hpp\"\r\n\r\n#include \"algebra/addgroup.hpp\"\r\n#include \"ds/fenwick.hpp\"\
    \r\n#include \"graph/centroid.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n \
    \ Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\n    LL(a, b);\r\n    G.add(--a, --b);\r\
    \n  }\r\n  G.prepare();\r\n\r\n  using T = tuple<ll, ll, ll>;\r\n  VEC(T, query,\
    \ Q);\r\n  for (auto&& [a, b, c]: query) --a;\r\n\r\n  // \u9802\u70B9 -> \u30AF\
    \u30A8\u30EA\r\n  vc<vi> query_at(N);\r\n  FOR(q, Q) query_at[get<0>(query[q])].eb(q);\r\
    \n\r\n  CentroidDecomposition CD(G);\r\n  vi ANS(Q);\r\n  FenwickTree<AddGroup<ll>>\
    \ bit(N + 10);\r\n\r\n  FOR(root, N) {\r\n    auto dats = CD.collect(root, 0);\r\
    \n    FOR(i, len(dats)) {\r\n      auto dat = dats[i];\r\n      // qid, v, dv\r\
    \n      vc<T> event;\r\n      for (auto&& [v, dv]: dat) {\r\n        for (auto&&\
    \ q: query_at[v]) { event.eb(q, v, dv); }\r\n      }\r\n      sort(all(event));\r\
    \n      for (auto&& [qid, v, dv]: event) {\r\n        auto [_, y, z] = query[qid];\r\
    \n        ll add = bit.sum(0, dv + 1);\r\n        ANS[qid] += (i == 0 ? add :\
    \ -add);\r\n        if (dv <= y) {\r\n          bit.add(0, z);\r\n          bit.add(y\
    \ - dv + 1, -z);\r\n        }\r\n      }\r\n      for (auto&& [qid, v, dv]: event)\
    \ {\r\n        auto [_, y, z] = query[qid];\r\n        if (dv <= y) {\r\n    \
    \      bit.add(0, -z);\r\n          bit.add(y - dv + 1, +z);\r\n        }\r\n\
    \      }\r\n    }\r\n  }\r\n  for (auto&& x: ANS) print(x);\r\n}\r\n\r\nsigned\
    \ main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout\
    \ << setprecision(15);\r\n\r\n  ll T = 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yukicoder/1038_centroid.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1038_centroid.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1038_centroid.test.cpp
- /verify/test/yukicoder/1038_centroid.test.cpp.html
title: test/yukicoder/1038_centroid.test.cpp
---
