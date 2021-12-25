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
  bundledCode: "#line 1 \"string/manacher.hpp\"\nvector<ll> manacher(string s) {\r\
    \n  vector<ll> radius;\r\n  radius.resize(s.size());\r\n  int i = 0, j = 0;\r\n\
    \  while (i < s.size()) {\r\n    while (i - j >= 0 && i + j < s.size() && s[i\
    \ - j] == s[i + j]) {\r\n      ++j;\r\n    }\r\n    radius[i] = j;\r\n    int\
    \ k = 1;\r\n    while (i - k >= 0 && i + k < s.size() && k + radius[i - k] < j)\
    \ {\r\n      radius[i + k] = radius[i - k];\r\n      ++k;\r\n    }\r\n    i +=\
    \ k;\r\n    j -= k;\r\n  }\r\n}\r\n"
  code: "vector<ll> manacher(string s) {\r\n  vector<ll> radius;\r\n  radius.resize(s.size());\r\
    \n  int i = 0, j = 0;\r\n  while (i < s.size()) {\r\n    while (i - j >= 0 &&\
    \ i + j < s.size() && s[i - j] == s[i + j]) {\r\n      ++j;\r\n    }\r\n    radius[i]\
    \ = j;\r\n    int k = 1;\r\n    while (i - k >= 0 && i + k < s.size() && k + radius[i\
    \ - k] < j) {\r\n      radius[i + k] = radius[i - k];\r\n      ++k;\r\n    }\r\
    \n    i += k;\r\n    j -= k;\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
