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
  bundledCode: "#line 1 \"string/zalgorithm.hpp\"\ntemplate <class T>\nstd::vector<int>\
    \ z_algorithm(const std::vector<T>& s) {\n  int n = int(s.size());\n  if (n ==\
    \ 0) return {};\n  std::vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j =\
    \ 0; i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : std::min(j\
    \ + z[j] - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n   \
    \ if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n\nstd::vector<int>\
    \ z_algorithm(const std::string& s) {\n  int n = int(s.size());\n  std::vector<int>\
    \ s2(n);\n  for (int i = 0; i < n; i++) {\n    s2[i] = s[i];\n  }\n  return z_algorithm(s2);\n\
    }\n"
  code: "template <class T>\nstd::vector<int> z_algorithm(const std::vector<T>& s)\
    \ {\n  int n = int(s.size());\n  if (n == 0) return {};\n  std::vector<int> z(n);\n\
    \  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n   \
    \ k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n    while (i +\
    \ k < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n\
    \  z[0] = n;\n  return z;\n}\n\nstd::vector<int> z_algorithm(const std::string&\
    \ s) {\n  int n = int(s.size());\n  std::vector<int> s2(n);\n  for (int i = 0;\
    \ i < n; i++) {\n    s2[i] = s[i];\n  }\n  return z_algorithm(s2);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/zalgorithm.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/zalgorithm.hpp
layout: document
redirect_from:
- /library/string/zalgorithm.hpp
- /library/string/zalgorithm.hpp.html
title: string/zalgorithm.hpp
---
