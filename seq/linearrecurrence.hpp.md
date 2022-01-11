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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: sequence/find_linear_recurrence.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n\r\n#include \"sequence/find_linear_recurrence.hpp\"\r\n\
    #include \"sequence/coef_of_rational_fps.hpp\"\r\n\r\ntemplate <typename mint>\r\
    \nmint interpolate_linear_recurrence(vector<mint>& A, ll N) {\r\n  auto G = find_linear_recurrence(A);\r\
    \n  auto F = convolution(A, G);\r\n  F.resize(len(G) - 1);\r\n  return coef_of_rational(F,\
    \ G, N);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/linearrecurrence.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/linearrecurrence.hpp
layout: document
redirect_from:
- /library/seq/linearrecurrence.hpp
- /library/seq/linearrecurrence.hpp.html
title: seq/linearrecurrence.hpp
---
