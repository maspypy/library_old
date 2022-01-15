---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: string/run_enumerate.hpp
    title: string/run_enumerate.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/run_enumerate.test.cpp
    title: test/library_checker/string/run_enumerate.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/run_enumerate_vec.test.cpp
    title: test/library_checker/string/run_enumerate_vec.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/zalgorithm.test.cpp
    title: test/library_checker/string/zalgorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/zalgorithm.hpp\"\ntemplate <typename STRING>  //\
    \ string, vector \u3069\u3061\u3089\u3067\u3082\nvector<int> zalgorithm(const\
    \ STRING& s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int>\
    \ z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n\
    \    k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k\
    \ < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n"
  code: "template <typename STRING>  // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> zalgorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/zalgorithm.hpp
  requiredBy:
  - string/run_enumerate.hpp
  timestamp: '2022-01-11 11:40:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/string/run_enumerate.test.cpp
  - test/library_checker/string/zalgorithm.test.cpp
  - test/library_checker/string/run_enumerate_vec.test.cpp
documentation_of: string/zalgorithm.hpp
layout: document
redirect_from:
- /library/string/zalgorithm.hpp
- /library/string/zalgorithm.hpp.html
title: string/zalgorithm.hpp
---
