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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: densegraph/mis.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"densegraph/mis.hpp\"\r\n\r\n\
    void solve() {\r\n  LL(N, M);\r\n  Graph<int> G(N);\r\n  FOR(_, M) {\r\n    LL(a,\
    \ b);\r\n    G.add(a, b);\r\n  }\r\n  auto mis = maximum_independent_set(G);\r\
    \n  print(len(mis));\r\n  print(mis);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/graph/maximum_independent_set_dense.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/maximum_independent_set_dense.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/maximum_independent_set_dense.test.cpp
- /verify/test/library_checker/graph/maximum_independent_set_dense.test.cpp.html
title: test/library_checker/graph/maximum_independent_set_dense.test.cpp
---
