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
  bundledCode: "#line 1 \"graph/mis.hpp\"\ntemplate <typename T>\r\nvector<int> maximum_independent_set(const\
    \ vector<vector<T>> &g,\r\n                                    int trial = 1000000)\
    \ {\r\n\r\n  int N = (int)g.size();\r\n  vector<uint64_t> bit(N);\r\n\r\n  assert(N\
    \ <= 64);\r\n  for (int i = 0; i < N; i++) {\r\n    for (int j = 0; j < N; j++)\
    \ {\r\n      if (i != j) {\r\n        assert(g[i][j] == g[j][i]);\r\n        if\
    \ (g[i][j]) bit[i] |= uint64_t(1) << j;\r\n      }\r\n    }\r\n  }\r\n\r\n  vector<int>\
    \ ord(N);\r\n  iota(begin(ord), end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  int ret = 0;\r\n  uint64_t ver;\r\n  for (int i = 0; i < trial; i++) {\r\n\
    \    shuffle(begin(ord), end(ord), mt);\r\n    uint64_t used = 0;\r\n    int add\
    \ = 0;\r\n    for (int j : ord) {\r\n      if (used & bit[j]) continue;\r\n  \
    \    used |= uint64_t(1) << j;\r\n      ++add;\r\n    }\r\n    if (ret < add)\
    \ {\r\n      ret = add;\r\n      ver = used;\r\n    }\r\n  }\r\n  vector<int>\
    \ ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if ((ver >> i) & 1) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  code: "template <typename T>\r\nvector<int> maximum_independent_set(const vector<vector<T>>\
    \ &g,\r\n                                    int trial = 1000000) {\r\n\r\n  int\
    \ N = (int)g.size();\r\n  vector<uint64_t> bit(N);\r\n\r\n  assert(N <= 64);\r\
    \n  for (int i = 0; i < N; i++) {\r\n    for (int j = 0; j < N; j++) {\r\n   \
    \   if (i != j) {\r\n        assert(g[i][j] == g[j][i]);\r\n        if (g[i][j])\
    \ bit[i] |= uint64_t(1) << j;\r\n      }\r\n    }\r\n  }\r\n\r\n  vector<int>\
    \ ord(N);\r\n  iota(begin(ord), end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  int ret = 0;\r\n  uint64_t ver;\r\n  for (int i = 0; i < trial; i++) {\r\n\
    \    shuffle(begin(ord), end(ord), mt);\r\n    uint64_t used = 0;\r\n    int add\
    \ = 0;\r\n    for (int j : ord) {\r\n      if (used & bit[j]) continue;\r\n  \
    \    used |= uint64_t(1) << j;\r\n      ++add;\r\n    }\r\n    if (ret < add)\
    \ {\r\n      ret = add;\r\n      ver = used;\r\n    }\r\n  }\r\n  vector<int>\
    \ ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if ((ver >> i) & 1) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/mis.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/mis.hpp
layout: document
redirect_from:
- /library/graph/mis.hpp
- /library/graph/mis.hpp.html
title: graph/mis.hpp
---
