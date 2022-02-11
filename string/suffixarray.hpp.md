---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_substrings.test.cpp
    title: test/library_checker/string/number_of_substrings.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/suffix_array.test.cpp
    title: test/library_checker/string/suffix_array.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/suffix_array_vec.test.cpp
    title: test/library_checker/string/suffix_array_vec.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/suffixarray.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#define int long long\nstruct SuffixArray {\n  vector<int>\
    \ SA;\n  vector<int> ISA;\n  vector<int> LCP;\n\n  SuffixArray(string& s, const\
    \ char first = 'a', const char last = 'z') {\n    SA = calc_suffix_array(s, first,\
    \ last);\n    calc_LCP(s);\n  }\n\n  SuffixArray(vector<int>& s) {\n    SA = calc_suffix_array(s);\n\
    \    calc_LCP(s);\n  }\n\n  void induced_sort(const std::vector<int>& vect, int\
    \ val_range, std::vector<int>& SA, const std::vector<bool>& sl,\n            \
    \        const std::vector<int>& lms_idx) {\n    std::vector<int> l(val_range,\
    \ 0), r(val_range, 0);\n    for (int c : vect) {\n      if (c + 1 < val_range)\
    \ ++l[c + 1];\n      ++r[c];\n    }\n    std::partial_sum(l.begin(), l.end(),\
    \ l.begin());\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    std::fill(SA.begin(),\
    \ SA.end(), -1);\n    for (int i = (int)lms_idx.size() - 1; i >= 0; --i) SA[--r[vect[lms_idx[i]]]]\
    \ = lms_idx[i];\n    for (int i : SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i\
    \ - 1]]++] = i - 1;\n    std::fill(r.begin(), r.end(), 0);\n    for (int c : vect)\
    \ ++r[c];\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    for (int\
    \ k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1\
    \ && !sl[i - 1]) {\n        SA[--r[vect[i - 1]]] = i - 1;\n      }\n  }\n\n  std::vector<int>\
    \ SA_IS(const std::vector<int>& vect, int val_range) {\n    const int n = vect.size();\n\
    \    std::vector<int> SA(n), lms_idx;\n    std::vector<bool> sl(n);\n    sl[n\
    \ - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    std::reverse(lms_idx.begin(),\
    \ lms_idx.end());\n    induced_sort(vect, val_range, SA, sl, lms_idx);\n    std::vector<int>\
    \ new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n    for (int i = 0, k\
    \ = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {\n \
    \       new_lms_idx[k++] = SA[i];\n      }\n    int cur = 0;\n    SA[n - 1] =\
    \ cur;\n    for (size_t k = 1; k < new_lms_idx.size(); ++k) {\n      int i = new_lms_idx[k\
    \ - 1], j = new_lms_idx[k];\n      if (vect[i] != vect[j]) {\n        SA[j] =\
    \ ++cur;\n        continue;\n      }\n      bool flag = false;\n      for (int\
    \ a = i + 1, b = j + 1;; ++a, ++b) {\n        if (vect[a] != vect[b]) {\n    \
    \      flag = true;\n          break;\n        }\n        if ((!sl[a] && sl[a\
    \ - 1]) || (!sl[b] && sl[b - 1])) {\n          flag = !((!sl[a] && sl[a - 1])\
    \ && (!sl[b] && sl[b - 1]));\n          break;\n        }\n      }\n      SA[j]\
    \ = (flag ? ++cur : cur);\n    }\n    for (size_t i = 0; i < lms_idx.size(); ++i)\
    \ lms_vec[i] = SA[lms_idx[i]];\n    if (cur + 1 < (int)lms_idx.size()) {\n   \
    \   auto lms_SA = SA_IS(lms_vec, cur + 1);\n      for (size_t i = 0; i < lms_idx.size();\
    \ ++i) {\n        new_lms_idx[i] = lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect,\
    \ val_range, SA, sl, new_lms_idx);\n    return SA;\n  }\n\n  std::vector<int>\
    \ calc_suffix_array(const std::string& s, const char first = 'a', const char last\
    \ = 'z') {\n    std::vector<int> vect(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vect));\n    for (auto& x : vect) x -= (int)first -\
    \ 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, (int)last - (int)first\
    \ + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  std::vector<int>\
    \ calc_suffix_array(const vector<int>& s) {\n    vector<int> ss = s;\n    sort(ss.begin(),\
    \ ss.end());\n    ss.erase(unique(ss.begin(), ss.end()), ss.end());\n\n    std::vector<int>\
    \ vect(s.size() + 1);\n    std::copy(std::begin(s), std::end(s), std::begin(vect));\n\
    \    for (auto& x : vect) x = lower_bound(ss.begin(), ss.end(), x) - ss.begin()\
    \ + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, *max_element(vect.begin(),\
    \ vect.end()) + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  void\
    \ calc_LCP(const std::string& s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n\
    \    LCP.resize(n);\n    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for\
    \ (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n     \
    \   k = 0;\n        continue;\n      }\n      int j = SA[ISA[i] + 1];\n      while\
    \ (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n\
    \    }\n    LCP.resize(n - 1);\n  }\n\n  void calc_LCP(const vector<int>& s) {\n\
    \    int n = s.size(), k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n    for\
    \ (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++, k ?\
    \ k-- : 0) {\n      if (ISA[i] == n - 1) {\n        k = 0;\n        continue;\n\
    \      }\n      int j = SA[ISA[i] + 1];\n      while (i + k < n && j + k < n &&\
    \ s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n    }\n    LCP.resize(n\
    \ - 1);\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define int long long\n\
    struct SuffixArray {\n  vector<int> SA;\n  vector<int> ISA;\n  vector<int> LCP;\n\
    \n  SuffixArray(string& s, const char first = 'a', const char last = 'z') {\n\
    \    SA = calc_suffix_array(s, first, last);\n    calc_LCP(s);\n  }\n\n  SuffixArray(vector<int>&\
    \ s) {\n    SA = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\n  void induced_sort(const\
    \ std::vector<int>& vect, int val_range, std::vector<int>& SA, const std::vector<bool>&\
    \ sl,\n                    const std::vector<int>& lms_idx) {\n    std::vector<int>\
    \ l(val_range, 0), r(val_range, 0);\n    for (int c : vect) {\n      if (c + 1\
    \ < val_range) ++l[c + 1];\n      ++r[c];\n    }\n    std::partial_sum(l.begin(),\
    \ l.end(), l.begin());\n    std::partial_sum(r.begin(), r.end(), r.begin());\n\
    \    std::fill(SA.begin(), SA.end(), -1);\n    for (int i = (int)lms_idx.size()\
    \ - 1; i >= 0; --i) SA[--r[vect[lms_idx[i]]]] = lms_idx[i];\n    for (int i :\
    \ SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i - 1;\n    std::fill(r.begin(),\
    \ r.end(), 0);\n    for (int c : vect) ++r[c];\n    std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1;\
    \ --k, i = SA[k])\n      if (i >= 1 && !sl[i - 1]) {\n        SA[--r[vect[i -\
    \ 1]]] = i - 1;\n      }\n  }\n\n  std::vector<int> SA_IS(const std::vector<int>&\
    \ vect, int val_range) {\n    const int n = vect.size();\n    std::vector<int>\
    \ SA(n), lms_idx;\n    std::vector<bool> sl(n);\n    sl[n - 1] = false;\n    for\
    \ (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i] > vect[i + 1] || (vect[i]\
    \ == vect[i + 1] && sl[i + 1]));\n      if (sl[i] && !sl[i + 1]) lms_idx.push_back(i\
    \ + 1);\n    }\n    std::reverse(lms_idx.begin(), lms_idx.end());\n    induced_sort(vect,\
    \ val_range, SA, sl, lms_idx);\n    std::vector<int> new_lms_idx(lms_idx.size()),\
    \ lms_vec(lms_idx.size());\n    for (int i = 0, k = 0; i < n; ++i)\n      if (!sl[SA[i]]\
    \ && SA[i] >= 1 && sl[SA[i] - 1]) {\n        new_lms_idx[k++] = SA[i];\n     \
    \ }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k < new_lms_idx.size();\
    \ ++k) {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n      if (vect[i]\
    \ != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n      }\n      bool\
    \ flag = false;\n      for (int a = i + 1, b = j + 1;; ++a, ++b) {\n        if\
    \ (vect[a] != vect[b]) {\n          flag = true;\n          break;\n        }\n\
    \        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n          flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n          break;\n   \
    \     }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n    for (size_t\
    \ i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if (cur +\
    \ 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec, cur + 1);\n \
    \     for (size_t i = 0; i < lms_idx.size(); ++i) {\n        new_lms_idx[i] =\
    \ lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect, val_range, SA, sl,\
    \ new_lms_idx);\n    return SA;\n  }\n\n  std::vector<int> calc_suffix_array(const\
    \ std::string& s, const char first = 'a', const char last = 'z') {\n    std::vector<int>\
    \ vect(s.size() + 1);\n    std::copy(std::begin(s), std::end(s), std::begin(vect));\n\
    \    for (auto& x : vect) x -= (int)first - 1;\n    vect.back() = 0;\n    auto\
    \ ret = SA_IS(vect, (int)last - (int)first + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  std::vector<int> calc_suffix_array(const vector<int>&\
    \ s) {\n    vector<int> ss = s;\n    sort(ss.begin(), ss.end());\n    ss.erase(unique(ss.begin(),\
    \ ss.end()), ss.end());\n\n    std::vector<int> vect(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vect));\n    for (auto& x : vect) x = lower_bound(ss.begin(),\
    \ ss.end(), x) - ss.begin() + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect,\
    \ *max_element(vect.begin(), vect.end()) + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  void calc_LCP(const std::string& s) {\n    int n =\
    \ s.size(), k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n    for (int i = 0;\
    \ i < n; i++) ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n\
    \      if (ISA[i] == n - 1) {\n        k = 0;\n        continue;\n      }\n  \
    \    int j = SA[ISA[i] + 1];\n      while (i + k < n && j + k < n && s[i + k]\
    \ == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n    }\n    LCP.resize(n - 1);\n \
    \ }\n\n  void calc_LCP(const vector<int>& s) {\n    int n = s.size(), k = 0;\n\
    \    ISA.resize(n);\n    LCP.resize(n);\n    for (int i = 0; i < n; i++) ISA[SA[i]]\
    \ = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i] == n\
    \ - 1) {\n        k = 0;\n        continue;\n      }\n      int j = SA[ISA[i]\
    \ + 1];\n      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n \
    \     LCP[ISA[i]] = k;\n    }\n    LCP.resize(n - 1);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/suffixarray.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/string/number_of_substrings.test.cpp
  - test/library_checker/string/suffix_array.test.cpp
  - test/library_checker/string/suffix_array_vec.test.cpp
documentation_of: string/suffixarray.hpp
layout: document
redirect_from:
- /library/string/suffixarray.hpp
- /library/string/suffixarray.hpp.html
title: string/suffixarray.hpp
---
