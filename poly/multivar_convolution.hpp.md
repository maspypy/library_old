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
  code: "#include \"polynomial/convolution.hpp\"\r\ntemplate <typename mint>\r\nvc<mint>\
    \ multivar_convolution(vi ns, vc<mint>& f, vc<mint>& g) {\r\n  /*\r\n  (n0, n1,\
    \ n2, ...) \u9032\u6CD5\u3067\u306E\u7E70\u308A\u4E0A\u304C\u308A\u306E\u306A\u3044\
    \u8DB3\u3057\u7B97\u306B\u95A2\u3059\u308B\u7573\u307F\u8FBC\u307F\r\n\r\n  example\
    \ : ns = (2, 3) \u2192 1 \u306E\u4F4D\u304B\u3089\u9806\u306B 2, 3 \u9032\u6CD5\
    \r\n  [a0, a1, a2, a3, a4, a5] = [a(0,0), a(1,0), a(0,1), a(1,1), a(0,2), a(1,2)]\r\
    \n  [b0, b1, b2, b3, b4, b5] = [b(0,0), b(1,0), b(0,1), b(1,1), b(0,2), b(1,2)]\r\
    \n  c(0,2) = a(0,0)b(0,2) + a(0,1)b(0,1) + a(0,2)b(1,1)\r\n  c4 = a0b4 + a2b2\
    \ + a4b0\r\n\r\n  example : ns = (2, 2, ..., 2, 2)\r\n  \u2192 subset convolution\
    \ \u304C\u3053\u308C\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\r\n  */\r\n  int K =\
    \ len(ns);\r\n  int N = 1;\r\n  FOR(k, K) N *= ns[k];\r\n  assert(len(f) == N\
    \ && len(g) == N);\r\n  if (N == 1) return {f[0] * g[0]};\r\n\r\n  auto chi =\
    \ [&](ll i) -> ll {\r\n    int x = 0;\r\n    for (auto&& n : ns) {\r\n      i\
    \ /= n;\r\n      x += i;\r\n    }\r\n    return x % K;\r\n  };\r\n\r\n  int sz\
    \ = 1;\r\n  while (sz < N + N) sz *= 2;\r\n  vv(mint, ff, K, sz);\r\n  vv(mint,\
    \ gg, K, sz);\r\n\r\n  FOR(i, N) {\r\n    auto k = chi(i);\r\n    ff[k][i] = f[i];\r\
    \n    gg[k][i] = g[i];\r\n  }\r\n\r\n  FOR(k, K) {\r\n    ntt(ff[k], false);\r\
    \n    ntt(gg[k], false);\r\n  }\r\n\r\n  vv(mint, hh, K, sz);\r\n  FOR(a, K) FOR(b,\
    \ K) FOR(i, sz) { hh[(a + b) % K][i] += ff[a][i] * gg[b][i]; }\r\n  FOR(k, K)\
    \ ntt(hh[k], true);\r\n\r\n  vc<mint> h(N);\r\n  FOR(i, N) h[i] = hh[chi(i)][i];\r\
    \n  return h;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/multivar_convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/multivar_convolution.hpp
layout: document
redirect_from:
- /library/poly/multivar_convolution.hpp
- /library/poly/multivar_convolution.hpp.html
title: poly/multivar_convolution.hpp
---
