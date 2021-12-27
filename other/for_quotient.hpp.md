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
  bundledCode: "#line 1 \"other/for_quotient.hpp\"\n#define FOR_quotient(q, l, r,\
    \ n) \\\r\n  for (ll q = 1, l = n / (q + 1) + 1, r = n / q + 1;\\\r\n  q <= n;\
    \ q = (q == n ? n + 1 : n / (n / (q + 1))), l = n / (q + 1) + 1, r = n / q + 1)\r\
    \n"
  code: "#define FOR_quotient(q, l, r, n) \\\r\n  for (ll q = 1, l = n / (q + 1) +\
    \ 1, r = n / q + 1;\\\r\n  q <= n; q = (q == n ? n + 1 : n / (n / (q + 1))), l\
    \ = n / (q + 1) + 1, r = n / q + 1)\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/for_quotient.hpp
  requiredBy: []
  timestamp: '2021-12-27 17:06:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/for_quotient.hpp
layout: document
redirect_from:
- /library/other/for_quotient.hpp
- /library/other/for_quotient.hpp.html
title: other/for_quotient.hpp
---
