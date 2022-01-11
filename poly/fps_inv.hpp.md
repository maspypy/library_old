---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#include \"polynomial/convolution.hpp\"\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> fps_inv(vc<mint>& F) {\r\n  vc<mint> G = {mint(1) / F[0]};\r\n  G.reserve(len(F));\r\
    \n  ll N = len(F), n = 1;\r\n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 *\
    \ n);\r\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\
    \n    ntt(f, false);\r\n    ntt(g, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\
    \n    ntt(f, true);\r\n    FOR(i, n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i,\
    \ 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR3(i, n, 2 * n) G.eb(f[i]\
    \ * mint(-1));\r\n    n *= 2;\r\n  }\r\n  G.resize(N);\r\n  return G;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_inv.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_inv.hpp
layout: document
redirect_from:
- /library/poly/fps_inv.hpp
- /library/poly/fps_inv.hpp.html
title: poly/fps_inv.hpp
---
