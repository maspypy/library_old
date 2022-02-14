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
  bundledCode: "#line 1 \"string/split.hpp\"\nvc<string> split(string S, char sep\
    \ = ',') {\r\n  vc<string> res = {\"\"};\r\n  for (auto&& s: S) {\r\n    if (s\
    \ == sep)\r\n      res.eb(\"\");\r\n    else\r\n      res.back() += s;\r\n  }\r\
    \n  return res;\r\n}\r\n"
  code: "vc<string> split(string S, char sep = ',') {\r\n  vc<string> res = {\"\"\
    };\r\n  for (auto&& s: S) {\r\n    if (s == sep)\r\n      res.eb(\"\");\r\n  \
    \  else\r\n      res.back() += s;\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/split.hpp
  requiredBy: []
  timestamp: '2022-02-14 23:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/split.hpp
layout: document
redirect_from:
- /library/string/split.hpp
- /library/string/split.hpp.html
title: string/split.hpp
---
