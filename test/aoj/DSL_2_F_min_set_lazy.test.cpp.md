---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_min_set.hpp
    title: algebra/lazy_min_set.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_min.hpp
    title: algebra/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_set.hpp
    title: algebra/monoid_set.hpp
  - icon: ':heavy_check_mark:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F_min_set_lazy.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\r\n#line\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n#line 2 \"ds/lazysegtree.hpp\"\
    \n\ntemplate <typename Lazy>\nstruct LazySegTree {\n  using Monoid_X = typename\
    \ Lazy::X_structure;\n  using Monoid_A = typename Lazy::A_structure;\n  using\
    \ X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  int n, log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n  LazySegTree() : LazySegTree(0)\
    \ {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n, Monoid_X::unit)) {}\n  LazySegTree(vc<X>\
    \ v) : n(len(v)) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, Monoid_X::unit);\n    laz.assign(size,\
    \ Monoid_A::unit);\n    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size)\
    \ update(i);\n  }\n\n  void update(int k) { dat[k] = Monoid_X::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n\n  void all_apply(int k, A a) {\n    dat[k] = Lazy::act(dat[k],\
    \ a);\n    if (k < size) laz[k] = Monoid_A::op(laz[k], a);\n  }\n\n  void push(int\
    \ k) {\n    all_apply(2 * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n   \
    \ laz[k] = Monoid_A::unit;\n  }\n\n  void set(int p, X x) {\n    assert(0 <= p\
    \ && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n\
    \    dat[p] = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n\
    \  X get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n  vc<X> get_all()\
    \ {\n    FOR(i, size) push(i);\n    return {dat.begin() + size, dat.begin() +\
    \ size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    if (l == r) return Monoid_X::unit;\n\n    l += size;\n    r +=\
    \ size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) !=\
    \ l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\
    \n    X xl = Monoid_X::unit, xr = Monoid_X::unit;\n    while (l < r) {\n     \
    \ if (l & 1) xl = Monoid_X::op(xl, dat[l++]);\n      if (r & 1) xr = Monoid_X::op(dat[--r],\
    \ xr);\n      l >>= 1;\n      r >>= 1;\n    }\n\n    return Monoid_X::op(xl, xr);\n\
    \  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int p, A a) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    dat[p] = Lazy::act(dat[p], a);\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  void apply(int l, int r,\
    \ A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\n\
    \    l += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n    \
    \  if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r)\
    \ {\n        if (l & 1) all_apply(l++, a);\n        if (r & 1) all_apply(--r,\
    \ a);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n\
    \    }\n\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
    \ update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n   \
    \ }\n  }\n\n  template <typename C>\n  int max_right(C& check, int l) {\n    assert(0\
    \ <= l && l <= n);\n    assert(check(Monoid_X::unit));\n    if (l == n) return\
    \ n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n    X\
    \ sm = Monoid_X::unit;\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if\
    \ (!check(Monoid_X::op(sm, dat[l]))) {\n        while (l < size) {\n         \
    \ push(l);\n          l = (2 * l);\n          if (check(Monoid_X::op(sm, dat[l])))\
    \ {\n            sm = Monoid_X::op(sm, dat[l]);\n            l++;\n          }\n\
    \        }\n        return l - size;\n      }\n      sm = Monoid_X::op(sm, dat[l]);\n\
    \      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\n  template <typename\
    \ C>\n  int min_left(C& check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(Monoid_X::unit));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = Monoid_X::unit;\n    do {\n      r--;\n    \
    \  while (r > 1 && (r % 2)) r >>= 1;\n      if (!check(Monoid_X::op(dat[r], sm)))\
    \ {\n        while (r < size) {\n          push(r);\n          r = (2 * r + 1);\n\
    \          if (check(Monoid_X::op(dat[r], sm))) {\n            sm = Monoid_X::op(dat[r],\
    \ sm);\n            r--;\n          }\n        }\n        return r + 1 - size;\n\
    \      }\n      sm = Monoid_X::op(dat[r], sm);\n    } while ((r & -r) != r);\n\
    \    return 0;\n  }\n\n  void debug() { print(\"lazysegtree getall:\", get_all());\
    \ }\n};\n#line 1 \"algebra/monoid_min.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit = INF;\r\
    \n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"algebra/monoid_set.hpp\"\
    \ntemplate <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit = none_val;\r\n  static constexpr bool\
    \ commute = false;\r\n};\n#line 3 \"algebra/lazy_min_set.hpp\"\n\r\ntemplate <typename\
    \ E, E INF, E none_val>\r\nstruct Lazy_Min_Set {\r\n  using MX = Monoid_Min<E,\
    \ INF>;\r\n  using MA = Monoid_Set<E, none_val>;\r\n  using X_structure = MX;\r\
    \n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using\
    \ A = typename MA::value_type;\r\n  static constexpr X act(const X &x, const A\
    \ &a) { return (a==none_val ? x : a) ;}\r\n};\r\n#line 5 \"test/aoj/DSL_2_F_min_set_lazy.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  const ll MAX = (1LL << 31) - 1;\r\n \
    \ using Lazy = Lazy_Min_Set<ll, MAX, -1>;\r\n  LazySegTree<Lazy> seg(N);\r\n \
    \ FOR(_, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(L, R, x);\r\n   \
    \   seg.apply(L, ++R, x);\r\n    } else {\r\n      LL(L, R);\r\n      print(seg.prod(L,\
    \ ++R));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  ll T =\
    \ 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"ds/lazysegtree.hpp\"\r\n#include\
    \ \"algebra/lazy_min_set.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  const\
    \ ll MAX = (1LL << 31) - 1;\r\n  using Lazy = Lazy_Min_Set<ll, MAX, -1>;\r\n \
    \ LazySegTree<Lazy> seg(N);\r\n  FOR(_, Q) {\r\n    LL(t);\r\n    if (t == 0)\
    \ {\r\n      LL(L, R, x);\r\n      seg.apply(L, ++R, x);\r\n    } else {\r\n \
    \     LL(L, R);\r\n      print(seg.prod(L, ++R));\r\n    }\r\n  }\r\n}\r\n\r\n\
    signed main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n \
    \ cout << setprecision(15);\r\n\r\n  ll T = 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - ds/lazysegtree.hpp
  - algebra/lazy_min_set.hpp
  - algebra/monoid_min.hpp
  - algebra/monoid_set.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 00:19:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F_min_set_lazy.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F_min_set_lazy.test.cpp
- /verify/test/aoj/DSL_2_F_min_set_lazy.test.cpp.html
title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
---
