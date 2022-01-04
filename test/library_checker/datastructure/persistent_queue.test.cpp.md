---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: persistent_ds/array.hpp
    title: persistent_ds/array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/library_checker/datastructure/persistent_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\r\n#line\
    \ 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing ll8 = __int128;\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\nusing uint = unsigned int;\nusing ull = unsigned long long;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define VEC(type, name, size) \\\n  vector<type> name(size);    \\\n  IN(name)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  IN(name)\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR_(n) for (ll _ = 0; (_) < (ll)(n);\
    \ ++(_))\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i,\
    \ m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i\
    \ = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1;\
    \ (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t =\
    \ (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x)\
    \ ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(uint x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(ull x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return 31 - __builtin_clz(x); }\nint topbit(uint x) { return\
    \ 31 - __builtin_clz(x); }\nint topbit(ll x) { return 63 - __builtin_clzll(x);\
    \ }\nint topbit(ull x) { return 63 - __builtin_clzll(x); }\n// (0, 1, 2, 3, 4)\
    \ -> (32 or 64, 0, 1, 0, 2)\nint lowbit(int x) { return 31 - __builtin_clz(x);\
    \ }\nint lowbit(uint x) { return 31 - __builtin_clz(x); }\nint lowbit(ll x) {\
    \ return 63 - __builtin_clzll(x); }\nint lowbit(ull x) { return 63 - __builtin_clzll(x);\
    \ }\n\nll ceil(ll x, ll y) { return (x > 0 ? (x + y - 1) / y : x / y); }\nll floor(ll\
    \ x, ll y) { return (x > 0 ? x / y : (x - y + 1) / y); }\npi divmod(ll x, ll y)\
    \ {\n  ll q = floor(x, y);\n  return {q, x - q * y};\n}\n\n#define INT(...)  \
    \ \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define LL(...)   \\\n  ll __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\n#define STR(...)      \\\n  string __VA_ARGS__; \\\n\
    \  IN(__VA_ARGS__)\n#define CHR(...)    \\\n  char __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define DBL(...)           \\\n  long double __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    void scan(int &a) { cin >> a; }\nvoid scan(long long &a) { cin >> a; }\nvoid scan(char\
    \ &a) { cin >> a; }\nvoid scan(double &a) { cin >> a; }\nvoid scan(long double\
    \ &a) { cin >> a; }\nvoid scan(string &a) { cin >> a; }\ntemplate <class T>\n\
    void scan(pair<T, T> &p) {\n  scan(p.first), scan(p.second);\n}\ntemplate <class\
    \ T>\nvoid scan(tuple<T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));\n\
    }\ntemplate <class T>\nvoid scan(tuple<T, T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)),\
    \ scan(get<2>(p)), scan(get<3>(p));\n}\ntemplate <class T>\nvoid scan(vector<T>\
    \ &a) {\n  for (auto &i: a) scan(i);\n}\ntemplate <class T>\nvoid scan(T &a) {\n\
    \  cin >> a;\n}\nvoid IN() {}\ntemplate <class Head, class... Tail>\nvoid IN(Head\
    \ &head, Tail &... tail) {\n  scan(head);\n  IN(tail...);\n}\n\nvi s_to_vi(string\
    \ S, char first_char = 'a') {\n  vi A(S.size());\n  FOR(i, S.size()) { A[i] =\
    \ S[i] - first_char; }\n  return A;\n}\n\ntemplate <typename T, typename U>\n\
    ostream &operator<<(ostream &os, const pair<T, U> &A) {\n  os << A.fi << \" \"\
    \ << A.se;\n  return os;\n}\ntemplate <typename T1, typename T2, typename T3>\n\
    ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &t) {\n  os << get<0>(t)\
    \ << \" \" << get<1>(t) << \" \" << get<2>(t);\n  return os;\n}\ntemplate <typename\
    \ T1, typename T2, typename T3, typename T4>\nostream &operator<<(ostream &os,\
    \ const tuple<T1, T2, T3, T4> &t) {\n  os << get<0>(t) << \" \" << get<1>(t) <<\
    \ \" \" << get<2>(t) << \" \" << get<3>(t);\n  return os;\n}\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &A) {\n  for (size_t i\
    \ = 0; i < A.size(); i++) {\n    if (i) os << \" \";\n    os << A[i];\n  }\n \
    \ return os;\n}\n\nvoid print() { cout << \"\\n\"; }\ntemplate <class Head, class...\
    \ Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  cout << head;\n  if (sizeof...(Tail))\
    \ cout << \" \";\n  print(forward<Tail>(tail)...);\n}\n\nvoid YES(bool t = 1)\
    \ { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid No(bool t = 1) { Yes(!t); }\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t);\
    \ }\n\ntemplate <typename T>\nvector<T> cumsum(vector<T> &A) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  B[0] = T(0);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  return B;\n}\n\nvc<int> bin_count(vi &A, int size) {\n  vc<int> C(size);\n\
    \  for (auto &x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int>\
    \ argsort(vector<T> &A) {\n  vector<int> ids(A.size());\n  iota(all(ids), 0);\n\
    \  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j); });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check,\
    \ ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n      ng = x;\n\
    \  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a,\
    \ const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/persistent_queue.test.cpp\"\
    \n\r\n#line 2 \"persistent_ds/array.hpp\"\n\r\ntemplate <typename T, int shift\
    \ = 4>\r\nstruct PersistentArray {\r\n  struct node;\r\n  using np = node*;\r\n\
    \  struct node {\r\n    T data;\r\n    np ch[1 << shift] = {};\r\n  };\r\n\r\n\
    \  static constexpr int mask = (1 << shift) - 1;\r\n  np root = nullptr;\r\n \
    \ PersistentArray() {}\r\n  np get_root() { return root; }\r\n  T get(int idx,\
    \ np t) {\r\n    if (!t) return 0;\r\n    if (idx == 0) {\r\n      return t->data;\r\
    \n    } else {\r\n      return get(idx >> shift, t->ch[idx & mask]);\r\n    }\r\
    \n  }\r\n\r\n  void destructive_set(int idx, T val, np& t) {\r\n    // \u7834\u58CA\
    \u7684\u306A\u5024\u306E\u5909\u66F4\u3002\u4E3B\u306B\u521D\u671F\u5316\u306B\
    \u4F7F\u3046\u3002\r\n    if (!t) t = new node();\r\n    if (idx == 0)\r\n   \
    \   t->data = val;\r\n    else {\r\n      destructive_set(idx >> shift, val, t->ch[idx\
    \ & mask]);\r\n    }\r\n  }\r\n\r\n  np set(int idx, T val, const np& t) {\r\n\
    \    // set \u3057\u305F\u3042\u3068\u306E\u6C38\u7D9A\u914D\u5217\u306E root\
    \ node pointer \u3092\u8FD4\u3059\r\n    np res = new node();\r\n    if (t) {\r\
    \n      memcpy(res->ch, t->ch, sizeof(t->ch));\r\n      res->data = t->data;\r\
    \n    }\r\n    if (idx == 0) {\r\n      res->data = val;\r\n    } else {\r\n \
    \     res->ch[idx & mask] = set(idx >> shift, val, res->ch[idx & mask]);\r\n \
    \   }\r\n    return res;\r\n  }\r\n};\r\n#line 5 \"test/library_checker/datastructure/persistent_queue.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(Q);\r\n  vi L(Q + 1), R(Q + 1);\r\n\r\n  using PA\
    \ = PersistentArray<int>;\r\n  using np = PA::np;\r\n  vc<np> PAS(Q + 1);\r\n\
    \  PA array;\r\n  PAS[0] = array.get_root();\r\n  L[0] = 0, R[0] = 0;\r\n  FOR(q,\
    \ Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(k, x);\r\n      ++k;\r\n\
    \      PAS[q + 1] = array.set(R[k], x, PAS[k]);\r\n      L[q + 1] = L[k];\r\n\
    \      R[q + 1] = R[k] + 1;\r\n    }\r\n    elif (t == 1) {\r\n      LL(k);\r\n\
    \      ++k;\r\n      print(array.get(L[k], PAS[k]));\r\n      PAS[q + 1] = PAS[k];\r\
    \n      L[q + 1] = L[k] + 1;\r\n      R[q + 1] = R[k];\r\n    }\r\n  }\r\n}\r\n\
    \r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\r\n\
    #include \"my_template.hpp\"\r\n\r\n#include \"persistent_ds/array.hpp\"\r\n\r\
    \nvoid solve() {\r\n  LL(Q);\r\n  vi L(Q + 1), R(Q + 1);\r\n\r\n  using PA = PersistentArray<int>;\r\
    \n  using np = PA::np;\r\n  vc<np> PAS(Q + 1);\r\n  PA array;\r\n  PAS[0] = array.get_root();\r\
    \n  L[0] = 0, R[0] = 0;\r\n  FOR(q, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n\
    \      LL(k, x);\r\n      ++k;\r\n      PAS[q + 1] = array.set(R[k], x, PAS[k]);\r\
    \n      L[q + 1] = L[k];\r\n      R[q + 1] = R[k] + 1;\r\n    }\r\n    elif (t\
    \ == 1) {\r\n      LL(k);\r\n      ++k;\r\n      print(array.get(L[k], PAS[k]));\r\
    \n      PAS[q + 1] = PAS[k];\r\n      L[q + 1] = L[k] + 1;\r\n      R[q + 1] =\
    \ R[k];\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - persistent_ds/array.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/persistent_queue.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 00:19:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/persistent_queue.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/persistent_queue.test.cpp
- /verify/test/library_checker/datastructure/persistent_queue.test.cpp.html
title: test/library_checker/datastructure/persistent_queue.test.cpp
---
