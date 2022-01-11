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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/group_reverse.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"my_template.hpp\"\n\n#include \"mod/modint.hpp\"\n#include \"graph/treegroup.hpp\"\
    \n#include \"algebra/group_affine.hpp\"\n\nusing mint = modint998;\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  using Mono = Group_Affine<mint>;\n  using E = Mono::value_type;\n\
    \  vc<E> A(N);\n  FOR(i, N) {\n    LL(a, b);\n    A[i] = mp(mint(a), mint(b));\n\
    \  }\n\n  Graph<int> G(N);\n  FOR(_, N - 1) {\n    LL(a, b);\n    G.add(a, b);\n\
    \  }\n  G.prepare();\n\n  HLD hld(G);\n  TreeGroup<decltype(hld), Mono, false,\
    \ true, false> TG(hld, A);\n\n  FOR(_, Q) {\n    LL(t);\n    if (t == 0) {\n \
    \     LL(v, c, d);\n      TG.set(v, E({mint(c), mint(d)}));\n    } else {\n  \
    \    LL(u, v, x);\n      auto e = TG.prod_path(u, v);\n      print(e.fi * mint(x)\
    \ + e.se);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
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
