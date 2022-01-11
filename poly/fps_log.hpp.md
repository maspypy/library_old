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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/fps_inv.hpp:\
    \ line -1: no such header\n"
  code: "#include \"polynomial/fps_inv.hpp\"\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ fps_log(vc<mint>& f) {\r\n  ll N = len(f);\r\n  vc<mint> df = f;\r\n  FOR(i,\
    \ N) df[i] *= mint(i);\r\n  df.erase(df.begin());\r\n  auto f_inv = fps_inv(f);\r\
    \n  f = convolution(df, f_inv);\r\n  f.resize(N - 1);\r\n  f.insert(f.begin(),\
    \ 0);\r\n  FOR(i, N) f[i] *= inv<mint>(i);\r\n  return f;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_log.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_log.hpp
layout: document
redirect_from:
- /library/poly/fps_log.hpp
- /library/poly/fps_log.hpp.html
title: poly/fps_log.hpp
---
