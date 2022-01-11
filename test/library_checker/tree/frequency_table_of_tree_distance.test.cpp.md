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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"graph/tree_all_distances.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N);\r\n  Graph<int> G(N);\r\n  FOR(_, N - 1) {\r\
    \n    LL(a, b);\r\n    G.add(a, b);\r\n  }\r\n  G.prepare();\r\n\r\n  vi ANS =\
    \ tree_all_distances(G);\r\n  ANS.erase(ANS.begin());\r\n  for (auto&& x : ANS)\
    \ x /= 2;\r\n  print(ANS);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
- /verify/test/library_checker/tree/frequency_table_of_tree_distance.test.cpp.html
title: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
---
