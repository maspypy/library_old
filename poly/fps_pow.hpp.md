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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/fps_exp.hpp:\
    \ line -1: no such header\n"
  code: "#include \"polynomial/fps_exp.hpp\"\r\n#include \"polynomial/fps_log.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_pow(vc<mint>& f, ll k) {\r\n\
    \  int n = len(f);\r\n  int d = n;\r\n  FOR_R(i, n) if (f[i] != 0) d = i;\r\n\
    \  ll off = d * k;\r\n  if (off >= n) return vc<mint>(n, 0);\r\n  mint c = f[d];\r\
    \n  mint c_inv = mint(1) / mint(c);\r\n  vc<mint> g(n - off);\r\n  FOR(i, n -\
    \ off) g[i] = f[d + i] * c_inv;\r\n  auto log_g = fps_log(g);\r\n  FOR(i, len(g))\
    \ log_g[i] *= mint(k);\r\n  g = fps_exp(log_g);\r\n  vc<mint> h(n);\r\n  c = c.pow(k);\r\
    \n  FOR(i, len(g)) h[off + i] = g[i] * c;\r\n  return h;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_pow.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_pow.hpp
layout: document
redirect_from:
- /library/poly/fps_pow.hpp
- /library/poly/fps_pow.hpp.html
title: poly/fps_pow.hpp
---
