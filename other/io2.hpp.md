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
  bundledCode: "#line 1 \"other/io2.hpp\"\n#define INT(...) \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...) \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define STR(...) \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ CHR(...) \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...)\
    \ \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  scan(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  scan(name)\r\n\r\nvoid scan(int &a) { cin >> a; }\r\
    \nvoid scan(long long &a) { cin >> a; }\r\nvoid scan(char &a) { cin >> a; }\r\n\
    void scan(double &a) { cin >> a; }\r\nvoid scan(long double &a) { cin >> a; }\r\
    \nvoid scan(string &a) { cin >> a; }\r\ntemplate <class T, class S> void scan(pair<T,\
    \ S> &p) { scan(p.first), scan(p.second); }\r\ntemplate <class T> void scan(vector<T>\
    \ &a) {for(auto &i : a) scan(i);}\r\ntemplate <class T> void scan(T &a) { cin\
    \ >> a; }\r\nvoid IN() {}\r\ntemplate <class Head, class... Tail> void IN(Head\
    \ &head, Tail &...tail) {\r\n  scan(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate\
    \ <typename T, typename U>\r\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ A) {\r\n  os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nostream& operator<<(ostream& os, const vector<T>& A) {\r\n \
    \ for (size_t i = 0; i < A.size(); i++) {\r\n    if(i) os << \" \";\r\n    os\
    \ << A[i];\r\n  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\\
    n\";\r\n  cout.flush();\r\n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head&& head, Tail&&... tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail))\
    \ cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\n}\r\n"
  code: "#define INT(...) \\\r\n  int __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ LL(...) \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define STR(...)\
    \ \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define CHR(...) \\\r\
    \n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...) \\\r\n  long\
    \ double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define VEC(type, name, size)\
    \ \\\r\n  vector<type> name(size);    \\\r\n  scan(name)\r\n#define VV(type, name,\
    \ h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  scan(name)\r\n\r\nvoid scan(int &a) { cin >> a; }\r\nvoid scan(long\
    \ long &a) { cin >> a; }\r\nvoid scan(char &a) { cin >> a; }\r\nvoid scan(double\
    \ &a) { cin >> a; }\r\nvoid scan(long double &a) { cin >> a; }\r\nvoid scan(string\
    \ &a) { cin >> a; }\r\ntemplate <class T, class S> void scan(pair<T, S> &p) {\
    \ scan(p.first), scan(p.second); }\r\ntemplate <class T> void scan(vector<T> &a)\
    \ {for(auto &i : a) scan(i);}\r\ntemplate <class T> void scan(T &a) { cin >> a;\
    \ }\r\nvoid IN() {}\r\ntemplate <class Head, class... Tail> void IN(Head &head,\
    \ Tail &...tail) {\r\n  scan(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate <typename\
    \ T, typename U>\r\nostream& operator<<(ostream& os, const pair<T, U>& A) {\r\n\
    \  os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nostream& operator<<(ostream& os, const vector<T>& A) {\r\n  for (size_t\
    \ i = 0; i < A.size(); i++) {\r\n    if(i) os << \" \";\r\n    os << A[i];\r\n\
    \  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\n\";\r\n  cout.flush();\r\
    \n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head&& head, Tail&&...\
    \ tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail)) cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/io2.hpp
  requiredBy: []
  timestamp: '2022-03-07 01:01:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/io2.hpp
layout: document
redirect_from:
- /library/other/io2.hpp
- /library/other/io2.hpp.html
title: other/io2.hpp
---
