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
  bundledCode: "#line 1 \"ds/slope.hpp\"\ntemplate< typename T >\r\nstruct SlopeTrick\
    \ {\r\n \r\n  const T INF = numeric_limits< T >::max() / 3;\r\n \r\n  T min_f;\r\
    \n  priority_queue< T, vector< T >, less<> > L;\r\n  priority_queue< T, vector<\
    \ T >, greater<> > R;\r\n  T add_l, add_r;\r\n \r\nprivate:\r\n  void push_R(const\
    \ T &a) {\r\n    R.push(a - add_r);\r\n  }\r\n \r\n  T top_R() const {\r\n   \
    \ if(R.empty()) return INF;\r\n    else return R.top() + add_r;\r\n  }\r\n \r\n\
    \  T pop_R() {\r\n    T val = top_R();\r\n    if(not R.empty()) R.pop();\r\n \
    \   return val;\r\n  }\r\n \r\n  void push_L(const T &a) {\r\n    L.push(a - add_l);\r\
    \n  }\r\n \r\n  T top_L() const {\r\n    if(L.empty()) return -INF;\r\n    else\
    \ return L.top() + add_l;\r\n  }\r\n \r\n  T pop_L() {\r\n    T val = top_L();\r\
    \n    if(not L.empty()) L.pop();\r\n    return val;\r\n  }\r\n \r\n  size_t size()\
    \ {\r\n    return L.size() + R.size();\r\n  }\r\n \r\npublic:\r\n  SlopeTrick()\
    \ : min_f(0), add_l(0), add_r(0) {}\r\n \r\n  struct Query {\r\n    T lx, rx,\
    \ min_f;\r\n  };\r\n \r\n  // return min f(x)\r\n  Query query() const {\r\n \
    \   return Query({top_L(), top_R(), min_f});\r\n  }\r\n \r\n  // f(x) += a\r\n\
    \  void add_all(const T &a) {\r\n    min_f += a;\r\n  }\r\n \r\n  // add \\_\r\
    \n  // f(x) += max(a - x, 0)\r\n  void add_a_minus_x(const T &a) {\r\n    min_f\
    \ += max(T(0), a - top_R());\r\n    push_R(a);\r\n    push_L(pop_R());\r\n  }\r\
    \n \r\n  // add _/\r\n  // f(x) += max(x - a, 0)\r\n  void add_x_minus_a(const\
    \ T &a) {\r\n    min_f += max(T(0), top_L() - a);\r\n    push_L(a);\r\n    push_R(pop_L());\r\
    \n  }\r\n \r\n  // add \\/\r\n  // f(x) += abs(x - a)\r\n  void add_abs(const\
    \ T &a) {\r\n    add_a_minus_x(a);\r\n    add_x_minus_a(a);\r\n  }\r\n \r\n  //\
    \ \\/ -> \\_\r\n  // f_{new} (x) = min f(y) (y <= x)\r\n  void clear_right() {\r\
    \n    while(not R.empty()) R.pop();\r\n  }\r\n \r\n  // \\/ -> _/\r\n  // f_{new}\
    \ (x) = min f(y) (y >= x)\r\n  void clear_left() {\r\n    while(not L.empty())\
    \ L.pop();\r\n  }\r\n \r\n  // \\/ -> \\_/\r\n  // f_{new} (x) = min f(y) (x-b\
    \ <= y <= x-a)\r\n  void shift(const T &a, const T &b) {\r\n    assert(a <= b);\r\
    \n    add_l += a;\r\n    add_r += b;\r\n  }\r\n \r\n  // \\/. -> .\\/\r\n  //\
    \ f_{new} (x) = f(x - a)\r\n  void shift(const T &a) {\r\n    shift(a, a);\r\n\
    \  }\r\n \r\n  // L, R \u3092\u7834\u58CA\u3059\u308B\r\n  T get(const T &x) {\r\
    \n    T ret = min_f;\r\n    while(not L.empty()) {\r\n      ret += max(T(0), pop_L()\
    \ - x);\r\n    }\r\n    while(not R.empty()) {\r\n      ret += max(T(0), x - pop_R());\r\
    \n    }\r\n    return ret;\r\n  }\r\n \r\n  void merge(SlopeTrick &st) {\r\n \
    \   if(st.size() > size()) {\r\n      swap(st.L, L);\r\n      swap(st.R, R);\r\
    \n      swap(st.add_l, add_l);\r\n      swap(st.add_r, add_r);\r\n      swap(st.min_f,\
    \ min_f);\r\n    }\r\n    while(not st.R.empty()) {\r\n      add_x_minus_a(st.pop_R());\r\
    \n    }\r\n    while(not st.L.empty()) {\r\n      add_a_minus_x(st.pop_L());\r\
    \n    }\r\n    min_f += st.min_f;\r\n  }\r\n};\n"
  code: "template< typename T >\r\nstruct SlopeTrick {\r\n \r\n  const T INF = numeric_limits<\
    \ T >::max() / 3;\r\n \r\n  T min_f;\r\n  priority_queue< T, vector< T >, less<>\
    \ > L;\r\n  priority_queue< T, vector< T >, greater<> > R;\r\n  T add_l, add_r;\r\
    \n \r\nprivate:\r\n  void push_R(const T &a) {\r\n    R.push(a - add_r);\r\n \
    \ }\r\n \r\n  T top_R() const {\r\n    if(R.empty()) return INF;\r\n    else return\
    \ R.top() + add_r;\r\n  }\r\n \r\n  T pop_R() {\r\n    T val = top_R();\r\n  \
    \  if(not R.empty()) R.pop();\r\n    return val;\r\n  }\r\n \r\n  void push_L(const\
    \ T &a) {\r\n    L.push(a - add_l);\r\n  }\r\n \r\n  T top_L() const {\r\n   \
    \ if(L.empty()) return -INF;\r\n    else return L.top() + add_l;\r\n  }\r\n \r\
    \n  T pop_L() {\r\n    T val = top_L();\r\n    if(not L.empty()) L.pop();\r\n\
    \    return val;\r\n  }\r\n \r\n  size_t size() {\r\n    return L.size() + R.size();\r\
    \n  }\r\n \r\npublic:\r\n  SlopeTrick() : min_f(0), add_l(0), add_r(0) {}\r\n\
    \ \r\n  struct Query {\r\n    T lx, rx, min_f;\r\n  };\r\n \r\n  // return min\
    \ f(x)\r\n  Query query() const {\r\n    return Query({top_L(), top_R(), min_f});\r\
    \n  }\r\n \r\n  // f(x) += a\r\n  void add_all(const T &a) {\r\n    min_f += a;\r\
    \n  }\r\n \r\n  // add \\_\r\n  // f(x) += max(a - x, 0)\r\n  void add_a_minus_x(const\
    \ T &a) {\r\n    min_f += max(T(0), a - top_R());\r\n    push_R(a);\r\n    push_L(pop_R());\r\
    \n  }\r\n \r\n  // add _/\r\n  // f(x) += max(x - a, 0)\r\n  void add_x_minus_a(const\
    \ T &a) {\r\n    min_f += max(T(0), top_L() - a);\r\n    push_L(a);\r\n    push_R(pop_L());\r\
    \n  }\r\n \r\n  // add \\/\r\n  // f(x) += abs(x - a)\r\n  void add_abs(const\
    \ T &a) {\r\n    add_a_minus_x(a);\r\n    add_x_minus_a(a);\r\n  }\r\n \r\n  //\
    \ \\/ -> \\_\r\n  // f_{new} (x) = min f(y) (y <= x)\r\n  void clear_right() {\r\
    \n    while(not R.empty()) R.pop();\r\n  }\r\n \r\n  // \\/ -> _/\r\n  // f_{new}\
    \ (x) = min f(y) (y >= x)\r\n  void clear_left() {\r\n    while(not L.empty())\
    \ L.pop();\r\n  }\r\n \r\n  // \\/ -> \\_/\r\n  // f_{new} (x) = min f(y) (x-b\
    \ <= y <= x-a)\r\n  void shift(const T &a, const T &b) {\r\n    assert(a <= b);\r\
    \n    add_l += a;\r\n    add_r += b;\r\n  }\r\n \r\n  // \\/. -> .\\/\r\n  //\
    \ f_{new} (x) = f(x - a)\r\n  void shift(const T &a) {\r\n    shift(a, a);\r\n\
    \  }\r\n \r\n  // L, R \u3092\u7834\u58CA\u3059\u308B\r\n  T get(const T &x) {\r\
    \n    T ret = min_f;\r\n    while(not L.empty()) {\r\n      ret += max(T(0), pop_L()\
    \ - x);\r\n    }\r\n    while(not R.empty()) {\r\n      ret += max(T(0), x - pop_R());\r\
    \n    }\r\n    return ret;\r\n  }\r\n \r\n  void merge(SlopeTrick &st) {\r\n \
    \   if(st.size() > size()) {\r\n      swap(st.L, L);\r\n      swap(st.R, R);\r\
    \n      swap(st.add_l, add_l);\r\n      swap(st.add_r, add_r);\r\n      swap(st.min_f,\
    \ min_f);\r\n    }\r\n    while(not st.R.empty()) {\r\n      add_x_minus_a(st.pop_R());\r\
    \n    }\r\n    while(not st.L.empty()) {\r\n      add_a_minus_x(st.pop_L());\r\
    \n    }\r\n    min_f += st.min_f;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/slope.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/slope.hpp
layout: document
redirect_from:
- /library/ds/slope.hpp
- /library/ds/slope.hpp.html
title: ds/slope.hpp
---
