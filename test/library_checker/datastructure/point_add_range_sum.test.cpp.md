---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing pi\
    \ = pair<ll, ll>;\nusing vi = vector<ll>;\nusing uint = unsigned int;\nusing ull\
    \ = unsigned long long;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define VEC(type,\
    \ name, size) \\\n  vector<type> name(size);    \\\n  IN(name)\n#define vv(type,\
    \ name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  IN(name)\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n);\
    \ ++(i))\n#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define\
    \ FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n)\
    \ for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for\
    \ (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \nint popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(uint x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(ull x) { return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4)\
    \ -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return 31 - __builtin_clz(x); }\nint\
    \ topbit(uint x) { return 31 - __builtin_clz(x); }\nint topbit(ll x) { return\
    \ 63 - __builtin_clzll(x); }\nint topbit(ull x) { return 63 - __builtin_clzll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)\nint lowbit(int x) { return\
    \ 31 - __builtin_clz(x); }\nint lowbit(uint x) { return 31 - __builtin_clz(x);\
    \ }\nint lowbit(ll x) { return 63 - __builtin_clzll(x); }\nint lowbit(ull x) {\
    \ return 63 - __builtin_clzll(x); }\n\nll ceil(ll x, ll y) { return (x > 0 ? (x\
    \ + y - 1) / y : x / y); }\nll floor(ll x, ll y) { return (x > 0 ? x / y : (x\
    \ - y + 1) / y); }\npi divmod(ll x, ll y) {\n  ll q = floor(x, y);\n  return {q,\
    \ x - q * y};\n}\n\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define LL(...)   \\\n  ll __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define STR(...)\
    \      \\\n  string __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define CHR(...)    \\\
    \n  char __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define DBL(...)           \\\n \
    \ long double __VA_ARGS__; \\\n  IN(__VA_ARGS__)\nvoid scan(int &a) { cin >> a;\
    \ }\nvoid scan(long long &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\n\
    void scan(double &a) { cin >> a; }\nvoid scan(long double &a) { cin >> a; }\n\
    void scan(string &a) { cin >> a; }\ntemplate <class T>\nvoid scan(pair<T, T> &p)\
    \ {\n  scan(p.first), scan(p.second);\n}\ntemplate <class T>\nvoid scan(tuple<T,\
    \ T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));\n}\ntemplate\
    \ <class T>\nvoid scan(tuple<T, T, T, T> &p) {\n  scan(get<0>(p)), scan(get<1>(p)),\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/point_add_range_sum.test.cpp\"\
    \n\n#line 2 \"ds/fenwick.hpp\"\ntemplate <typename T>\nstruct FenwickTree {\n\
    \  vector<T> data;\n  T total;\n\n  FenwickTree() : total(0) {}\n  FenwickTree(int\
    \ sz) : total(0) { data.assign(++sz, 0); }\n\n  void init(int n) { data.assign(++n,\
    \ 0); }\n\n  void build(vector<T>& raw_data) {\n    assert(len(data) == len(raw_data)\
    \ + 1);\n    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];\n    FOR(i, len(data))\
    \ {\n      int j = i + (i & -i);\n      if (j < len(data)) data[j] += data[i];\n\
    \    }\n  }\n\n  T sum(int k) {\n    T ret = 0;\n    for (; k > 0; k -= k & -k)\
    \ ret += data[k];\n    return (ret);\n  }\n\n  T sum(int L, int R) {\n    T ret\
    \ = 0;\n    while (L < R) {\n      ret += data[R];\n      R -= R & -R;\n    }\n\
    \    while (R < L) {\n      ret -= data[L];\n      L -= L & -L;\n    }\n    return\
    \ ret;\n  }\n\n  T sum_all() { return total; }\n\n  void add(int k, T x) {\n \
    \   total += x;\n    for (++k; k < len(data); k += k & -k) data[k] += x;\n  }\n\
    \n  template <class F>\n  int max_right(F& check) {\n    assert(f(T(0)));\n  \
    \  ll i = 0;\n    T s = 0;\n    int k = 1;\n    int N = len(data);\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(s + data[i\
    \ + k])) {\n        i += k;\n        s += data[i];\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int find_kth_element(T k) {\n    auto check =\
    \ [&](T x) -> bool { return x < k; };\n    return max_right(check);\n  }\n\n \
    \ void debug() { print(data); }\n};\n\ntemplate <typename T>\nstruct Fenwick_RAQ\
    \ {\n  int N;\n  FenwickTree<T> bit0;\n  FenwickTree<T> bit1;\n\n  Fenwick_RAQ(int\
    \ N) : N(N), bit0(N), bit1(N) {}\n  Fenwick_RAQ() {}\n\n  void init(int n) {\n\
    \    N = n;\n    bit0.init(n);\n    bit1.init(n);\n  }\n\n  void build(vc<T>&\
    \ v) { bit0.build(v); }\n\n  void add_at(ll i, T val) { bit0.add(i, val); }\n\n\
    \  void add_range(ll L, ll R, T val) {\n    bit0.add(L, -val * L);\n    bit1.add(L,\
    \ +val);\n    bit0.add(R, +val * R);\n    bit1.add(R, -val);\n  }\n\n  T sum(ll\
    \ L, ll R) {\n    T sum_R = R * bit1.sum(R) + bit0.sum(R);\n    T sum_L = L *\
    \ bit1.sum(L) + bit0.sum(L);\n    return sum_R - sum_L;\n  }\n};\n#line 5 \"test/library_checker/datastructure/point_add_range_sum.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n  FenwickTree<ll> bit(N);\n\
    \  bit.build(A);\n\n  FOR(_, Q) {\n    LL(t, a, b);\n    if (t == 0) {\n     \
    \ bit.add(a, b);\n    } else {\n      print(bit.sum(a, b));\n    }\n  }\n}\n\n\
    signed main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout <<\
    \ setprecision(15);\n\n  solve();\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"my_template.hpp\"\n\n#include \"ds/fenwick.hpp\"\n\nvoid solve() {\n\
    \  LL(N, Q);\n  VEC(ll, A, N);\n  FenwickTree<ll> bit(N);\n  bit.build(A);\n\n\
    \  FOR(_, Q) {\n    LL(t, a, b);\n    if (t == 0) {\n      bit.add(a, b);\n  \
    \  } else {\n      print(bit.sum(a, b));\n    }\n  }\n}\n\nsigned main() {\n \
    \ cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n\n"
  dependsOn:
  - my_template.hpp
  - ds/fenwick.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 02:24:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_range_sum.test.cpp
- /verify/test/library_checker/datastructure/point_add_range_sum.test.cpp.html
title: test/library_checker/datastructure/point_add_range_sum.test.cpp
---
