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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid_reverse.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"graph/treemonoid.hpp\"\r\n\
    #include \"alg/group_add.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll,\
    \ A, N);\r\n  Graph<int, 1> G(N);\r\n  FOR3(v, 1, N) {\r\n    LL(p);\r\n    G.add(p,\
    \ v);\r\n  }\r\n  G.prepare();\r\n\r\n  HLD hld(G);\r\n  using Mono = Group_Add<ll>;\r\
    \n\r\n  TreeMonoid<decltype(hld), Mono, false> TM(hld, A);\r\n\r\n  FOR(_, Q)\
    \ {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(v, x);\r\n      A[v] += x;\r\
    \n      TM.set(v, A[v]);\r\n    } else {\r\n      LL(u);\r\n      print(TM.prod_subtree(u));\r\
    \n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp.html
title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
---
