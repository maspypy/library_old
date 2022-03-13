---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/predecessor_problem.test.cpp
    title: test/library_checker/datastructure/predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\
    \n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet\
    \ {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\n\r\n \
    \ int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x) { return\
    \ __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int n, lg;\r\
    \n  vc<vc<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do {\r\n      seg.push_back(vc<ull>((_n\
    \ + B - 1) / B));\r\n      _n = (_n + B - 1) / B;\r\n    } while (_n > 1);\r\n\
    \    lg = int(seg.size());\r\n  }\r\n  bool operator[](int i) const { return (seg[0][i\
    \ / B] >> (i % B) & 1) != 0; }\r\n  void insert(int i) {\r\n    for (int h = 0;\
    \ h < lg; h++) {\r\n      seg[h][i / B] |= 1ULL << (i % B);\r\n      i /= B;\r\
    \n    }\r\n  }\r\n  void erase(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\
    \n      seg[h][i / B] &= ~(1ULL << (i % B));\r\n      if (seg[h][i / B])\r\n \
    \       break;\r\n      i /= B;\r\n    }\r\n  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\
    \u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\
    \u308C\u3070 n\u3002\r\n  int next(int i) {\r\n    for (int h = 0; h < lg; h++)\
    \ {\r\n      if (i / B == seg[h].size())\r\n        break;\r\n      ull d = seg[h][i\
    \ / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsf(d);\r\n      for (int g = h - 1;\
    \ g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i / B]);\r\n  \
    \    }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // x\u4EE5\
    \u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if(i < 0) return\
    \ -1;\r\n    chmin(i, n - 1);\r\n    for (int h = 0; h < lg; h++) {\r\n      if\
    \ (i == -1)\r\n        break;\r\n      ull d = seg[h][i / B] << (63 - i % 64);\r\
    \n      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n\
    \      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g = h - 1; g\
    \ >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\n    \
    \  }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  void debug(){\r\
    \n    string s;\r\n    FOR(i, n) s += ((*this)[i] ? '1' : '0');\r\n    print(s);\r\
    \n  }\r\n};\n"
  code: "/* 64\u5206\u6728\u3002\r\ninsert, erase\r\n[]\u3067\u306E\u5B58\u5728\u5224\
    \u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet {\r\n  using uint = unsigned;\r\n\
    \  using ull = unsigned long long;\r\n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x);\
    \ }\r\n  int bsf(ull x) { return __builtin_ctzll(x); }\r\n\r\n  static constexpr\
    \ uint B = 64;\r\n  int n, lg;\r\n  vc<vc<ull>> seg;\r\n  FastSet(int _n) : n(_n)\
    \ {\r\n    do {\r\n      seg.push_back(vc<ull>((_n + B - 1) / B));\r\n      _n\
    \ = (_n + B - 1) / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n\
    \  }\r\n  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1)\
    \ != 0; }\r\n  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      seg[h][i / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n\
    \  void erase(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] &= ~(1ULL << (i % B));\r\n      if (seg[h][i / B])\r\n        break;\r\n\
    \      i /= B;\r\n    }\r\n  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\
    \u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\
    \r\n  int next(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      if (i /\
    \ B == seg[h].size())\r\n        break;\r\n      ull d = seg[h][i / B] >> (i %\
    \ B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\n  \
    \    }\r\n      // find\r\n      i += bsf(d);\r\n      for (int g = h - 1; g >=\
    \ 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i / B]);\r\n      }\r\
    \n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // x\u4EE5\u4E0B\u6700\
    \u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\
    \u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if(i < 0) return -1;\r\n \
    \   chmin(i, n - 1);\r\n    for (int h = 0; h < lg; h++) {\r\n      if (i == -1)\r\
    \n        break;\r\n      ull d = seg[h][i / B] << (63 - i % 64);\r\n      if\
    \ (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n      //\
    \ find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g = h - 1; g >= 0; g--)\
    \ {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\n      }\r\n    \
    \  return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  void debug(){\r\n    string\
    \ s;\r\n    FOR(i, n) s += ((*this)[i] ? '1' : '0');\r\n    print(s);\r\n  }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/fastset.hpp
  requiredBy: []
  timestamp: '2022-03-14 00:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/predecessor_problem.test.cpp
documentation_of: ds/fastset.hpp
layout: document
redirect_from:
- /library/ds/fastset.hpp
- /library/ds/fastset.hpp.html
title: ds/fastset.hpp
---
