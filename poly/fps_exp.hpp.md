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
    \ fps_exp(vc<mint>& f) {\r\n  const int n = len(f);\r\n  assert(n > 0 && f[0]\
    \ == mint(0));\r\n  vc<mint> b = {1, (1 < n ? f[1] : 0)};\r\n  vc<mint> c = {1},\
    \ z1, z2 = {1, 1};\r\n  while (len(b) < n) {\r\n    int m = len(b);\r\n    auto\
    \ y = b;\r\n    y.resize(2 * m);\r\n    ntt(y, 0);\r\n    z1 = z2;\r\n    vc<mint>\
    \ z(m);\r\n    FOR(i, m) z[i] = y[i] * z1[i];\r\n    ntt(z, 1);\r\n    FOR(i,\
    \ m / 2) z[i] = 0;\r\n    ntt(z, 0);\r\n    FOR(i, m) z[i] *= -z1[i];\r\n    ntt(z,\
    \ 1);\r\n    c.insert(c.end(), z.begin() + m / 2, z.end());\r\n    z2 = c;\r\n\
    \    z2.resize(2 * m);\r\n    ntt(z2, 0);\r\n\r\n    vc<mint> x(f.begin(), f.begin()\
    \ + m);\r\n    FOR(i, len(x) - 1) x[i] = x[i + 1] * mint(i + 1);\r\n    x.back()\
    \ = 0;\r\n    ntt(x, 0);\r\n    FOR(i, m) x[i] *= y[i];\r\n    ntt(x, 1);\r\n\r\
    \n    FOR(i, m - 1) x[i] -= b[i + 1] * mint(i + 1);\r\n\r\n    x.resize(m + m);\r\
    \n    FOR(i, m - 1) x[m + i] = x[i], x[i] = 0;\r\n    ntt(x, 0);\r\n    FOR(i,\
    \ m + m) x[i] *= z2[i];\r\n    ntt(x, 1);\r\n    FOR_R(i, len(x) - 1) x[i + 1]\
    \ = x[i] * inv<mint>(i + 1);\r\n    x[0] = 0;\r\n\r\n    FOR3(i, m, min(n, m +\
    \ m)) x[i] += f[i];\r\n    FOR(i, m) x[i] = 0;\r\n    ntt(x, 0);\r\n    FOR(i,\
    \ m + m) x[i] *= y[i];\r\n    ntt(x, 1);\r\n    b.insert(b.end(), x.begin() +\
    \ m, x.end());\r\n  }\r\n  b.resize(n);\r\n  return b;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_exp.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_exp.hpp
layout: document
redirect_from:
- /library/poly/fps_exp.hpp
- /library/poly/fps_exp.hpp.html
title: poly/fps_exp.hpp
---
