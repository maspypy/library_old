---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/nim_product.test.cpp
    title: test/library_checker/math/nim_product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/nim_product.hpp\"\null naive_nim_product(ull x, ull\
    \ y, int k = 6) {\r\n  if (x == 0 || y == 0) return 0;\r\n  if (x == 1) return\
    \ y;\r\n  if (y == 1) return x;\r\n  int B = 1 << (k - 1);\r\n  ull mask = (1ULL\
    \ << B) - 1;\r\n  ull a = x >> B, b = x & mask;\r\n  ull c = y >> B, d = y & mask;\r\
    \n  tie(a, b, c) = mt(naive_nim_product(a, c, k - 1),\r\n                    naive_nim_product(a\
    \ ^ b, c ^ d, k - 1),\r\n                    naive_nim_product(b, d, k - 1));\r\
    \n  b = a ^ b ^ c;\r\n  return (a << B) ^ naive_nim_product(1ULL << (B - 1), a,\
    \ k - 1) ^ (b << B) ^ c;\r\n}\r\n\r\null nim_product(ull x, ull y) {\r\n  static\
    \ bool prepared = false;\r\n  // x * y, 256\u4EE5\u4E0B\r\n  // 2^a * 2^b * x,\
    \ 8, 8, 256\r\n  static ull memo1[256][256];\r\n  static ull memo2[8][8][256];\r\
    \n  if (!prepared) {\r\n    prepared = true;\r\n    FOR(x, 256) FOR(y, 256) memo1[x][y]\
    \ = naive_nim_product(x, y, 4);\r\n    FOR(a, 8) FOR(b, 8) {\r\n      ull v =\
    \ naive_nim_product(1ULL << (8 * a), 1ULL << (8 * b));\r\n      FOR(x, 256) memo2[a][b][x]\
    \ = naive_nim_product(v, x);\r\n    }\r\n  } // end prepare\r\n\r\n  ull v = 0;\r\
    \n  FOR(a, 8) FOR(b, 8) {\r\n    v ^= memo2[a][b][memo1[(x >> (8 * a)) & 255][(y\
    \ >> (8 * b)) & 255]];\r\n  }\r\n  return v;\r\n}\n"
  code: "ull naive_nim_product(ull x, ull y, int k = 6) {\r\n  if (x == 0 || y ==\
    \ 0) return 0;\r\n  if (x == 1) return y;\r\n  if (y == 1) return x;\r\n  int\
    \ B = 1 << (k - 1);\r\n  ull mask = (1ULL << B) - 1;\r\n  ull a = x >> B, b =\
    \ x & mask;\r\n  ull c = y >> B, d = y & mask;\r\n  tie(a, b, c) = mt(naive_nim_product(a,\
    \ c, k - 1),\r\n                    naive_nim_product(a ^ b, c ^ d, k - 1),\r\n\
    \                    naive_nim_product(b, d, k - 1));\r\n  b = a ^ b ^ c;\r\n\
    \  return (a << B) ^ naive_nim_product(1ULL << (B - 1), a, k - 1) ^ (b << B) ^\
    \ c;\r\n}\r\n\r\null nim_product(ull x, ull y) {\r\n  static bool prepared = false;\r\
    \n  // x * y, 256\u4EE5\u4E0B\r\n  // 2^a * 2^b * x, 8, 8, 256\r\n  static ull\
    \ memo1[256][256];\r\n  static ull memo2[8][8][256];\r\n  if (!prepared) {\r\n\
    \    prepared = true;\r\n    FOR(x, 256) FOR(y, 256) memo1[x][y] = naive_nim_product(x,\
    \ y, 4);\r\n    FOR(a, 8) FOR(b, 8) {\r\n      ull v = naive_nim_product(1ULL\
    \ << (8 * a), 1ULL << (8 * b));\r\n      FOR(x, 256) memo2[a][b][x] = naive_nim_product(v,\
    \ x);\r\n    }\r\n  } // end prepare\r\n\r\n  ull v = 0;\r\n  FOR(a, 8) FOR(b,\
    \ 8) {\r\n    v ^= memo2[a][b][memo1[(x >> (8 * a)) & 255][(y >> (8 * b)) & 255]];\r\
    \n  }\r\n  return v;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/nim_product.hpp
  requiredBy: []
  timestamp: '2022-01-12 23:41:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/nim_product.test.cpp
documentation_of: other/nim_product.hpp
layout: document
redirect_from:
- /library/other/nim_product.hpp
- /library/other/nim_product.hpp.html
title: other/nim_product.hpp
---
