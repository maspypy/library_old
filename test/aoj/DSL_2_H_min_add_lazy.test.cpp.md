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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/lazy_min_add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"algebra/lazy_min_add.hpp\"\r\
    \n#include \"ds/lazysegtree.hpp\"\r\n\r\nvoid solve() {\r\n  using Lazy = Lazy_Min_Add<ll,\
    \ 1LL << 60>;\r\n  LL(N, Q);\r\n  vi A(N);\r\n  LazySegTree<Lazy> seg(A);\r\n\
    \  FOR(_, Q) {\r\n    LL(t, L, R);\r\n    ++R;\r\n    if (t == 0) {\r\n      LL(x);\r\
    \n      seg.apply(L, R, x);\r\n    } else {\r\n      print(seg.prod(L, R));\r\n\
    \    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  ll T = 1;\r\n  // LL(T);\r\n  FOR(_, T)\
    \ solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DSL_2_H_min_add_lazy.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_H_min_add_lazy.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_H_min_add_lazy.test.cpp
- /verify/test/aoj/DSL_2_H_min_add_lazy.test.cpp.html
title: test/aoj/DSL_2_H_min_add_lazy.test.cpp
---
