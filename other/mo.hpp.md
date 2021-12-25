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
  bundledCode: "#line 1 \"other/mo.hpp\"\nstruct Mo {\r\n  using ADD = function<void(int)>;\r\
    \n  using RM = function<void(int)>;\r\n  using CALC = function<void(int)>;\r\n\
    \r\n  int width;\r\n  vector<int> left, right, order;\r\n  vector<bool> v;\r\n\
    \r\n  Mo(int N, int Q) : width((int)sqrt(N)), order(Q), v(N) {\r\n    iota(begin(order),\
    \ end(order), 0);\r\n  }\r\n\r\n  void add(int l, int r) { /* [l, r) */\r\n  \
    \  left.emplace_back(l);\r\n    right.emplace_back(r);\r\n  }\r\n\r\n  void run(const\
    \ ADD& add, const RM& rm, const CALC& calc) {\r\n    assert(left.size() == order.size());\r\
    \n    sort(begin(order), end(order), [&](int a, int b) {\r\n      int ablock =\
    \ left[a] / width, bblock = left[b] / width;\r\n      if (ablock != bblock) return\
    \ ablock < bblock;\r\n      if (ablock & 1) return right[a] < right[b];\r\n  \
    \    return right[a] > right[b];\r\n    });\r\n    int nl = 0, nr = 0;\r\n   \
    \ auto push = [&](int idx) {\r\n      v[idx].flip();\r\n      if (v[idx])\r\n\
    \        add(idx);\r\n      else\r\n        rm(idx);\r\n    };\r\n    for (auto\
    \ idx : order) {\r\n      while (nl > left[idx]) push(--nl);\r\n      while (nr\
    \ < right[idx]) push(nr++);\r\n      while (nl < left[idx]) push(nl++);\r\n  \
    \    while (nr > right[idx]) push(--nr);\r\n      calc(idx);\r\n    }\r\n  }\r\
    \n};\r\n"
  code: "struct Mo {\r\n  using ADD = function<void(int)>;\r\n  using RM = function<void(int)>;\r\
    \n  using CALC = function<void(int)>;\r\n\r\n  int width;\r\n  vector<int> left,\
    \ right, order;\r\n  vector<bool> v;\r\n\r\n  Mo(int N, int Q) : width((int)sqrt(N)),\
    \ order(Q), v(N) {\r\n    iota(begin(order), end(order), 0);\r\n  }\r\n\r\n  void\
    \ add(int l, int r) { /* [l, r) */\r\n    left.emplace_back(l);\r\n    right.emplace_back(r);\r\
    \n  }\r\n\r\n  void run(const ADD& add, const RM& rm, const CALC& calc) {\r\n\
    \    assert(left.size() == order.size());\r\n    sort(begin(order), end(order),\
    \ [&](int a, int b) {\r\n      int ablock = left[a] / width, bblock = left[b]\
    \ / width;\r\n      if (ablock != bblock) return ablock < bblock;\r\n      if\
    \ (ablock & 1) return right[a] < right[b];\r\n      return right[a] > right[b];\r\
    \n    });\r\n    int nl = 0, nr = 0;\r\n    auto push = [&](int idx) {\r\n   \
    \   v[idx].flip();\r\n      if (v[idx])\r\n        add(idx);\r\n      else\r\n\
    \        rm(idx);\r\n    };\r\n    for (auto idx : order) {\r\n      while (nl\
    \ > left[idx]) push(--nl);\r\n      while (nr < right[idx]) push(nr++);\r\n  \
    \    while (nl < left[idx]) push(nl++);\r\n      while (nr > right[idx]) push(--nr);\r\
    \n      calc(idx);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/mo.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/mo.hpp
layout: document
redirect_from:
- /library/other/mo.hpp
- /library/other/mo.hpp.html
title: other/mo.hpp
---
