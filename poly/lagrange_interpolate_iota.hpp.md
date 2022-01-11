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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/group_mul.hpp:\
    \ line -1: no such header\n"
  code: "#include \"algebra/group_mul.hpp\"\r\n#include \"ds/swag.hpp\"\r\n#include\
    \ \"polynomial/convolution.hpp\"\r\n\r\ntemplate <typename mint>\r\nvc<mint> lagrange_intepolate_iota(vc<mint>\
    \ &f, mint c, int m) {\r\n  /*\r\n  Input: f(0), ..., f(n-1) and c, m (1 default)\r\
    \n  Return: f(c), f(c+1), ..., f(c+m-1)\r\n  Complexity: M(n, m)\r\n  */\r\n \
    \ ll n = len(f);\r\n  auto a = f;\r\n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i)\
    \ * fact_inv<mint>(n - 1 - i);\r\n    if ((n - 1 - i) & 1) a[i] *= -1;\r\n  }\r\
    \n  // x = c, c+1, ... \u306B\u5BFE\u3057\u3066 a0/x + a1/(x-1) + ... \u3092\u6C42\
    \u3081\u3066\u304A\u304F\r\n  vc<mint> b(n + m - 1);\r\n  FOR(i, n + m - 1) b[i]\
    \ = mint(1) / (c + mint(i - n + 1));\r\n  a = convolution(a, b);\r\n\r\n  SWAG<Group_Mul<mint>>\
    \ swag;\r\n  vc<mint> ANS(m);\r\n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while\
    \ (L < i) { swag.pop(), ++L; }\r\n    while (R - L < n) { swag.push(c + mint((R++)\
    \ - n + 1)); }\r\n    auto coef = swag.prod();\r\n    if (coef == 0) {\r\n   \
    \   ANS[i] = f[(c + i).val];\r\n    } else {\r\n      ANS[i] = a[i + n - 1] *\
    \ coef;\r\n    }\r\n  }\r\n  return ANS;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nmint lagrange_intepolate_iota(vc<mint> &f, mint c) {\r\n  /*\r\n  Input: f(0),\
    \ ..., f(n-1) and c, m (1 default)\r\n  Return: f(c)\r\n  */\r\n  return lagrange_interpolate_iota(f,\
    \ c, 1)[0];\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/lagrange_interpolate_iota.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/lagrange_interpolate_iota.hpp
layout: document
redirect_from:
- /library/poly/lagrange_interpolate_iota.hpp
- /library/poly/lagrange_interpolate_iota.hpp.html
title: poly/lagrange_interpolate_iota.hpp
---
