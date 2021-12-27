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
  bundledCode: "#line 1 \"other/for_nck.hpp\"\n#define FOR_nCk(s, n, k) \\\r\n  for\
    \ (ll s = (1LL << k) - 1, tmp_var = 0; s < (1LL << n); \\\r\n       tmp_var =\
    \ s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctzll(s)\
    \ + 1)))\r\n"
  code: "#define FOR_nCk(s, n, k) \\\r\n  for (ll s = (1LL << k) - 1, tmp_var = 0;\
    \ s < (1LL << n); \\\r\n       tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var\
    \ & -~tmp_var) - 1) >> (__builtin_ctzll(s) + 1)))\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/for_nck.hpp
  requiredBy: []
  timestamp: '2021-12-27 17:06:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/for_nck.hpp
layout: document
redirect_from:
- /library/other/for_nck.hpp
- /library/other/for_nck.hpp.html
title: other/for_nck.hpp
---
