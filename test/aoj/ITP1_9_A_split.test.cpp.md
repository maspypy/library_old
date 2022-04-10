---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io2.hpp
    title: other/io2.hpp
  - icon: ':heavy_check_mark:'
    path: string/split.hpp
    title: string/split.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A
  bundledCode: "#line 1 \"test/aoj/ITP1_9_A_split.test.cpp\"\n#define PROBLEM \\\n\
    \  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A\"\n#line\
    \ 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR_(n) for (ll _ = 0; (_) < (ll)(n);\
    \ ++(_))\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i,\
    \ m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i\
    \ = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1;\
    \ (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t =\
    \ (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x)\
    \ ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define stoi stoll\n\
    \ntemplate <typename T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x==0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x==0 ?\
    \ -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint\
    \ lowbit(int x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint lowbit(u32\
    \ x) { return (x==0 ? -1 : 31 - __builtin_clz(x)); }\nint lowbit(ll x) { return\
    \ (x==0 ? -1 : 63 - __builtin_clzll(x)); }\nint lowbit(u64 x) { return (x==0 ?\
    \ -1 : 63 - __builtin_clzll(x)); }\n\ntemplate <typename T, typename U>\nT ceil(T\
    \ x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename\
    \ T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) /\
    \ y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T x, U y) {\n\
    \  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool\
    \ chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b,\
    \ 1 : 0);\n}\n\nvi s_to_vi(string S, char first_char = 'a') {\n  vi A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename T, typename CNT\
    \ = int>\nvc<CNT> bincount(vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(vector<T>\
    \ &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });\n\
    \  return ids;\n}\n#line 1 \"other/io2.hpp\"\n#define INT(...) \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...) \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define STR(...) \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ CHR(...) \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...)\
    \ \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin >> a; }\r\
    \nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin >> a; }\r\n\
    void read(double &a) { cin >> a; }\r\nvoid read(long double &a) { cin >> a; }\r\
    \nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class S> void read(pair<T,\
    \ S> &p) { read(p.first), read(p.second); }\r\ntemplate <class T> void read(vector<T>\
    \ &a) {for(auto &i : a) read(i);}\r\ntemplate <class T> void read(T &a) { cin\
    \ >> a; }\r\nvoid IN() {}\r\ntemplate <class Head, class... Tail> void IN(Head\
    \ &head, Tail &...tail) {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate\
    \ <typename T, typename U>\r\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ A) {\r\n  os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nostream& operator<<(ostream& os, const vector<T>& A) {\r\n \
    \ for (size_t i = 0; i < A.size(); i++) {\r\n    if(i) os << \" \";\r\n    os\
    \ << A[i];\r\n  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\\
    n\";\r\n  cout.flush();\r\n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head&& head, Tail&&... tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail))\
    \ cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\n}\r\n#line 1 \"string/split.hpp\"\
    \nvc<string> split(string S, char sep = ',') {\r\n  vc<string> res = {\"\"};\r\
    \n  for (auto&& s: S) {\r\n    if (s == sep)\r\n      res.eb(\"\");\r\n    else\r\
    \n      res.back() += s;\r\n  }\r\n  return res;\r\n}\r\n\r\nvc<string> split(string\
    \ S, string seps = \" ,\") {\r\n  vc<string> res = {\"\"};\r\n  for (auto&& s:\
    \ S) {\r\n    if (count(all(seps), s))\r\n      res.eb(\"\");\r\n    else\r\n\
    \      res.back() += s;\r\n  }\r\n  return res;\r\n}\r\n#line 6 \"test/aoj/ITP1_9_A_split.test.cpp\"\
    \n\nvoid solve() {\n  STR(T);\n  string S;\n  ll ANS = 0;\n  while (getline(cin,\
    \ S)) {\n    for (auto&& token: split(S, ' ')) {\n      for (auto&& t: token)\n\
    \        if (isupper(t)) t = tolower(t);\n      ANS += token == T;\n    }\n  }\n\
    \  print(ANS);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A\"\
    \n#include \"my_template.hpp\"\n#include \"other/io2.hpp\"\n#include \"string/split.hpp\"\
    \n\nvoid solve() {\n  STR(T);\n  string S;\n  ll ANS = 0;\n  while (getline(cin,\
    \ S)) {\n    for (auto&& token: split(S, ' ')) {\n      for (auto&& t: token)\n\
    \        if (isupper(t)) t = tolower(t);\n      ANS += token == T;\n    }\n  }\n\
    \  print(ANS);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io2.hpp
  - string/split.hpp
  isVerificationFile: true
  path: test/aoj/ITP1_9_A_split.test.cpp
  requiredBy: []
  timestamp: '2022-04-09 21:41:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_9_A_split.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_9_A_split.test.cpp
- /verify/test/aoj/ITP1_9_A_split.test.cpp.html
title: test/aoj/ITP1_9_A_split.test.cpp
---
