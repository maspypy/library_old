---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group_add.hpp
    title: algebra/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: ds/mo.hpp
    title: ds/mo.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \r\n#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing\
    \ pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing uint = unsigned int;\nusing\
    \ ull = unsigned long long;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 3 \"test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp\"\
    \n\r\n#line 2 \"algebra/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\n\
    struct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\n\ntemplate\
    \ <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename AbelGroup::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n\
    \  FenwickTree(int n) : n(n), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n\
    \    dat.assign(n, AbelGroup::unit);\n  }\n  FenwickTree(vc<E> v) : n(len(v)),\
    \ total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n    dat = v;\n  \
    \  FOR3(i, 1, n + 1) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j -\
    \ 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n  E sum(int k) {\n\
    \    E ret = AbelGroup::unit;\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E sum(int L, int R) {\n    E pos = AbelGroup::unit;\n\
    \    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -=\
    \ R & -R;\n    }\n    E neg = AbelGroup::unit;\n    while (R < L) {\n      neg\
    \ = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\n  }\n\n  E sum_all() { return total; }\n\n  void\
    \ add(int k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <=\
    \ n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  template\
    \ <class F>\n  int max_right(F& check) {\n    assert(f(E(0)));\n    ll i = 0;\n\
    \    E s = AbelGroup::unit;\n    int k = 1;\n    int N = len(dat) + 1;\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k - 1]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n\
    \      }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth_element(E\
    \ k) {\n    auto check = [&](E x) -> bool { return x < k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n#line 1 \"ds/mo.hpp\"\
    \nstruct Mo {\r\n  int n;\r\n  vector<pair<int, int> > lr;\r\n\r\n  explicit Mo(int\
    \ n) : n(n) {}\r\n\r\n  void add(int l, int r) { /* [l, r) */\r\n    lr.emplace_back(l,\
    \ r);\r\n  }\r\n\r\n  template <typename AL, typename AR, typename EL, typename\
    \ ER, typename O>\r\n  void build(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left,\r\n             const ER &erase_right, const O &out) {\r\n \
    \   int q = (int)lr.size();\r\n    int bs = n / min<int>(n, sqrt(q));\r\n    vector<int>\
    \ ord(q);\r\n    iota(begin(ord), end(ord), 0);\r\n    sort(begin(ord), end(ord),\
    \ [&](int a, int b) {\r\n      int ablock = lr[a].first / bs, bblock = lr[b].first\
    \ / bs;\r\n      if (ablock != bblock) return ablock < bblock;\r\n      return\
    \ (ablock & 1) ? lr[a].second > lr[b].second\r\n                          : lr[a].second\
    \ < lr[b].second;\r\n    });\r\n    int l = 0, r = 0;\r\n    for (auto idx: ord)\
    \ {\r\n      while (l > lr[idx].first) add_left(--l);\r\n      while (r < lr[idx].second)\
    \ add_right(r++);\r\n      while (l < lr[idx].first) erase_left(l++);\r\n    \
    \  while (r > lr[idx].second) erase_right(--r);\r\n      out(idx);\r\n    }\r\n\
    \  }\r\n\r\n  template <typename A, typename E, typename O>\r\n  void build(const\
    \ A &add, const E &erase, const O &out) {\r\n    build(add, add, erase, erase,\
    \ out);\r\n  }\r\n};\n#line 6 \"test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  vi key = A;\r\n \
    \ UNIQUE(key);\r\n\r\n  for (auto&& x : A) x = LB(key, x);\r\n  ll K = len(key);\r\
    \n  FenwickTree<Group_Add<int>> bit(K);\r\n\r\n  Mo mo(N);\r\n  vi ANS(Q);\r\n\
    \  FOR(_, Q) {\r\n    LL(L, R);\r\n    mo.add(L, R);\r\n  }\r\n\r\n  ll inv =\
    \ 0;\r\n  auto add_l = [&](int i) -> void {\r\n    int x = A[i];\r\n    inv +=\
    \ bit.sum(x);\r\n    bit.add(x, +1);\r\n  };\r\n  auto rm_l = [&](int i) -> void\
    \ {\r\n    int x = A[i];\r\n    bit.add(x, -1);\r\n    inv -= bit.sum(x);\r\n\
    \  };\r\n  auto add_r = [&](int i) -> void {\r\n    int x = A[i];\r\n    inv +=\
    \ bit.sum_all() - bit.sum(x + 1);\r\n    bit.add(x, +1);\r\n  };\r\n  auto rm_r\
    \ = [&](int i) -> void {\r\n    int x = A[i];\r\n    bit.add(x, -1);\r\n    inv\
    \ -= bit.sum_all() - bit.sum(x + 1);\r\n  };\r\n  auto calc = [&](int i) -> void\
    \ { ANS[i] = inv; };\r\n  mo.build(add_l, add_r, rm_l, rm_r, calc);\r\n  for (auto&&\
    \ x : ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \r\n#include \"my_template.hpp\"\r\n\r\n#include \"ds/fenwick.hpp\"\r\n#include\
    \ \"ds/mo.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n \
    \ vi key = A;\r\n  UNIQUE(key);\r\n\r\n  for (auto&& x : A) x = LB(key, x);\r\n\
    \  ll K = len(key);\r\n  FenwickTree<Group_Add<int>> bit(K);\r\n\r\n  Mo mo(N);\r\
    \n  vi ANS(Q);\r\n  FOR(_, Q) {\r\n    LL(L, R);\r\n    mo.add(L, R);\r\n  }\r\
    \n\r\n  ll inv = 0;\r\n  auto add_l = [&](int i) -> void {\r\n    int x = A[i];\r\
    \n    inv += bit.sum(x);\r\n    bit.add(x, +1);\r\n  };\r\n  auto rm_l = [&](int\
    \ i) -> void {\r\n    int x = A[i];\r\n    bit.add(x, -1);\r\n    inv -= bit.sum(x);\r\
    \n  };\r\n  auto add_r = [&](int i) -> void {\r\n    int x = A[i];\r\n    inv\
    \ += bit.sum_all() - bit.sum(x + 1);\r\n    bit.add(x, +1);\r\n  };\r\n  auto\
    \ rm_r = [&](int i) -> void {\r\n    int x = A[i];\r\n    bit.add(x, -1);\r\n\
    \    inv -= bit.sum_all() - bit.sum(x + 1);\r\n  };\r\n  auto calc = [&](int i)\
    \ -> void { ANS[i] = inv; };\r\n  mo.build(add_l, add_r, rm_l, rm_r, calc);\r\n\
    \  for (auto&& x : ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - ds/fenwick.hpp
  - algebra/group_add.hpp
  - ds/mo.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
  requiredBy: []
  timestamp: '2022-01-03 02:37:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
- /verify/test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp.html
title: test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
---