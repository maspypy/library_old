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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"my_template.hpp\"\n\n#include \"graph/base.hpp\"\n#include \"graph/hld.hpp\"\
    \n#include \"graph/treemonoid.hpp\"\n#include \"mod/modint.hpp\"\nusing mint =\
    \ modint998;\n\nvoid solve() {\n  LL(N, Q);\n  using E = pair<mint, mint>;\n \
    \ vc<E> A(N);\n  FOR(i, N) {\n    LL(a, b);\n    A[i] = {mint(a), mint(b)};\n\
    \  }\n  Graph<int> G(N);\n  FOR(_, N - 1) {\n    LL(a, b);\n    G.add(a, b);\n\
    \  }\n\n  HLD<Graph<int>> hld(G);\n  TreeMonoid<Graph<int>, E, false> TM(hld,\
    \ Monoid_affine<mint>());\n  TM.init(A);\n\n  FOR(_, Q) {\n    LL(t);\n    if\
    \ (t == 0) {\n      LL(p, c, d);\n      TM.set(p, E({mint(c), mint(d)}));\n\n\
    \    } else {\n      LL(u, v, x);\n      auto e = TM.prod_path(u, v);\n      print(e.fi\
    \ * mint(x) + e.se);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  solve();\n\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
- /verify/test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp.html
title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
---
