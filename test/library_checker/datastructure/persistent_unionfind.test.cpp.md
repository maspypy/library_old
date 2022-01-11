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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: persistent_ds/array.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n#include \"my_template.hpp\"\r\n\r\n#include \"pds/unionfind.hpp\"\r\n\r\nvoid\
    \ solve() {\r\n  LL(N, Q);\r\n\r\n  PersistentUnionFind uf(N);\r\n  using np =\
    \ PersistentUnionFind::np;\r\n  vc<np> UFS;\r\n\r\n  UFS.reserve(Q + 1);\r\n \
    \ UFS.eb(uf.init());\r\n\r\n  FOR3(q, 1, Q + 1) {\r\n    LL(t, k, u, v);\r\n \
    \   ++k;\r\n    if (t == 0) {\r\n      UFS.eb(uf.merge(u, v, UFS[k]).se);\r\n\
    \    } else {\r\n      print(uf.same(u, v, UFS[k]));\r\n      UFS.eb(UFS[q - 1]);\r\
    \n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/persistent_unionfind.test.cpp
- /verify/test/library_checker/datastructure/persistent_unionfind.test.cpp.html
title: test/library_checker/datastructure/persistent_unionfind.test.cpp
---
