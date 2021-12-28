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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n\r\n#include \"algebra/convolution.hpp\"\r\n\r\ntemplate\
    \ <typename mint>\r\nmint coef_of_rational(vector<mint> A, vector<mint> B, ll\
    \ N) {\r\n  if(len(A)==0) return 0;\r\n  assert(B[0] == 1);\r\n  assert(len(B)\
    \ == len(A) + 1);\r\n  while (N) {\r\n    vc<mint> B1 = B;\r\n    FOR(i, len(B1))\
    \ if (i & 1) B1[i] = -B1[i];\r\n    A = convolve(A, B1);\r\n    B = convolve(B,\
    \ B1);\r\n    FOR(i, len(B1)) B[i] = B[2 * i];\r\n    if (N & 1) {\r\n      FOR(i,\
    \ len(B1) - 1) A[i] = A[2 * i | 1];\r\n    } else {\r\n      FOR(i, len(B1) -\
    \ 1) A[i] = A[2 * i];\r\n    }\r\n    A.resize(len(B1) - 1);\r\n    B.resize(len(B1));\r\
    \n    N /= 2;\r\n  }\r\n  return A[0];\r\n}\r\n\r\ntemplate <typename mint>\r\n\
    vector<mint> berlekamp_massey(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint>\
    \ B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\
    \n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n  \
    \  if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\
    \n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B)\
    \ + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l +\
    \ l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\
    \n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nmint interpolate_linear_recurrence(vector<mint>& A, ll N)\
    \ {\r\n  auto G = berlekamp_massey(A);\r\n  auto F = convolve(A, G);\r\n  F.resize(len(G)\
    \ - 1);\r\n  return coef_of_rational(F, G, N);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: sequence/linearrecurrence.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sequence/linearrecurrence.hpp
layout: document
redirect_from:
- /library/sequence/linearrecurrence.hpp
- /library/sequence/linearrecurrence.hpp.html
title: sequence/linearrecurrence.hpp
---
