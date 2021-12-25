---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/rectanglesums.hpp
    title: other/rectanglesums.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/rectangle_sum_sweep.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 2\
    \ \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing pi =\
    \ pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T> using vc = vector<T>;\n\
    template <class T> using vvc = vector<vc<T>>;\ntemplate <class T> using vvvc =\
    \ vector<vvc<T>>;\ntemplate <class T> using vvvvc = vector<vvvc<T>>;\ntemplate\
    \ <class T> using vvvvvc = vector<vvvvc<T>>;\ntemplate <class T> using pq = priority_queue<T>;\n\
    template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;\n\n#define\
    \ vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define VEC(type, name,\
    \ size)                                                                      \
    \                                                            \\\n    vector<type>\
    \ name(size);                                                                \
    \                                                                   \\\n    IN(name)\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define VV(type, name, h, w)                                                 \
    \                                                                            \
    \      \\\n    vector<vector<type>> name(h, vector<type>(w));                \
    \                                                                            \
    \                 \\\n    IN(name)\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)                                                        \
    \                                                                 \\\n    vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i, m, n)\
    \ for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i = (ll)(n)-1;\
    \ (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m);\
    \ --(i))\n#define FORIN(x, A) for (auto&& x : A)\n#define FOR_nCk(s, n, k) \\\n\
    \  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \\\n  tmp_var = s | (s\
    \ - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s)\
    \ + 1))) \n#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1)\
    \ & s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n\n#define\
    \ elif else if\n\nusing ull = unsigned long long;\nusing uint = unsigned int;\n\
    int popcnt(uint x) {\n  return __builtin_popcount(x);\n}\nint popcnt(int x) {\n\
    \  return __builtin_popcount(x);\n}\nint popcnt(ull x) {\n  return __builtin_popcountll(x);\n\
    }\nint popcnt(ll x) {\n  return __builtin_popcountll(x);\n}\nint bsr(uint x) {\n\
    \  return 31 - __builtin_clz(x);\n}\nint bsr(ull x) {\n  return 63 - __builtin_clzll(x);\n\
    }\nint ctz(int x) {\n  return __builtin_ctz(x);\n}\nint ctz(ll x) {\n  return\
    \ __builtin_ctzll(x);\n}\nint ctz(ull x) {\n  return __builtin_ctzll(x);\n}\n\n\
    #define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define SUM(v) accumulate(all(v), 0LL)\n#define\
    \ MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\n#define\
    \ LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\nll ceil(ll x, ll y) {\n    assert(y >= 1);\n    return (x > 0 ?\
    \ (x + y - 1) / y : x / y);\n}\n\nll floor(ll x, ll y) {\n    assert(y >= 1);\n\
    \    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\nll mod(ll x, ll y) {\n  return\
    \ x - y * floor(x, y);\n}\n\n#define INT(...) \\\n  int __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n\
    #define LL(...) \\\n  ll __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define STR(...)\
    \ \\\n  string __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define CHR(...) \\\n  char\
    \ __VA_ARGS__; \\\n  IN(__VA_ARGS__)\n#define DBL(...) \\\n  long double __VA_ARGS__;\
    \ \\\n  IN(__VA_ARGS__)\nvoid scan(int &a) { cin >> a; }\nvoid scan(long long\
    \ &a) { cin >> a; }\nvoid scan(char &a) { cin >> a; }\nvoid scan(double &a) {\
    \ cin >> a; }\nvoid scan(long double &a) { cin >> a; }\nvoid scan(string &a) {\
    \ cin >> a; }\ntemplate <class T, class S> void scan(pair<T, S> &p) { scan(p.first),\
    \ scan(p.second); }\ntemplate <class T> void scan(vector<T> &a) {for(auto &i :\
    \ a) scan(i);}\ntemplate <class T> void scan(T &a) { cin >> a; }\nvoid IN() {}\n\
    template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {\n  scan(head);\n\
    \  IN(tail...);\n}\n\nll isqrt(ll n) {\n  ll x = n, y = (n + 1) / 2;\n  while\
    \ (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }\n  return x;\n}\n\nvi s_to_vi(string\
    \ S, char first_char='a'){\n  vi A(S.size());\n  FOR(i, S.size()){\n    A[i] =\
    \ S[i] - first_char;\n  }\n  return A;\n}\n\ntemplate <typename T, typename U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& A) {\n  os << A.fi << \" \"\
    \ << A.se;\n  return os;\n}\n\ntemplate <typename T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& A) {\n  for (size_t i = 0; i < A.size(); i++) {\n    if(i)\
    \ os << \" \";\n    os << A[i];\n  }\n  return os;\n}\n\nvoid print() {\n  cout\
    \ << \"\\n\";\n}\n\ntemplate <class Head, class... Tail>\nvoid print(Head&& head,\
    \ Tail&&... tail) {\n  cout << head;\n  if (sizeof...(Tail)) cout << \" \";\n\
    \  print(forward<Tail>(tail)...);\n}\n\nconst string YESNO[2] = {\"NO\", \"YES\"\
    };\nconst string YesNo[2] = {\"No\", \"Yes\"};\nconst string yesno[2] = {\"no\"\
    , \"yes\"};\nvoid YES(bool t = 1) { cout << YESNO[t] << endl; }\nvoid NO(bool\
    \ t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { cout << YesNo[t] << endl; }\nvoid\
    \ No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { cout << yesno[t] << endl;\
    \ }\nvoid no(bool t = 1) { yes(!t); }\n\ntemplate <typename T>\nvector<T> cumsum(vector<T>\
    \ A) {\n  ll N = A.size();\n  vector<T> B(N + 1);\n  B[0] = T(0);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  return B;\n}\n\nvi bin_count(vi& A, ll size)\
    \ {\n  vi C(size);\n  for (auto&& x : A) {\n    ++C[x];\n  }\n  return C;\n}\n\
    \ntemplate <typename T>\nvi argsort(vector<T>& A){\n  vi ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids), [&](ll i, ll j){\n    return A[i] < A[j] || (A[i] == A[j]\
    \ && i < j);\n  });\n  return ids;\n}\n\nll binary_search(function<bool(ll)> check,\
    \ ll ok, ll ng) {\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    if (check(x))\n      ok = x;\n    else\n      ng = x;\n  }\n  return ok;\n\
    }\n\ntemplate <class T, class S> inline bool chmax(T &a, const S &b) { return\
    \ (a < b ? a = b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a,\
    \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\ntemplate <typename T>\nvc<T>\
    \ merge_sort(vc<T>& A, vc<T>& B) {\n  vc<T> C;\n  C.reserve(A.size() + B.size());\n\
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 4 \"test/library_checker/datastructure/rectangle_sum_sweep.test.cpp\"\
    \n\n#line 2 \"ds/fenwick.hpp\"\ntemplate <typename T>\nstruct FenwickTree {\n\
    \  vector<T> data;\n  T total;\n\n  FenwickTree(int sz) : total(0) { data.assign(++sz,\
    \ 0); }\n\n  void build(vector<T>& raw_data) {\n    assert(len(data) == len(raw_data)\
    \ + 1);\n    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];\n    FOR(i, len(data))\
    \ {\n      int j = i + (i & -i);\n      if (j < len(data)) data[j] += data[i];\n\
    \    }\n  }\n\n  T sum(int k) {\n    T ret = 0;\n    for (; k > 0; k -= k & -k)\
    \ ret += data[k];\n    return (ret);\n  }\n\n  T sum(int L, int R) {\n    T ret\
    \ = 0;\n    while (L < R) {\n      ret += data[R];\n      R -= R & -R;\n    }\n\
    \    while (R < L) {\n      ret -= data[L];\n      L -= L & -L;\n    }\n    return\
    \ ret;\n  }\n\n  T sum_all() { return total; }\n\n  void add(int k, T x) {\n \
    \   total += x;\n    for (++k; k < data.size(); k += k & -k) data[k] += x;\n \
    \ }\n\n  template <class F>\n  int max_right(F& check) {\n    assert(f(T(0)));\n\
    \    ll i = 0;\n    T s = 0;\n    int k = 1;\n    int N = len(data);\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(s + data[i\
    \ + k])) {\n        i += k;\n        s += data[i];\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int find_kth_element(T k) {\n    auto check =\
    \ [&](T x) -> bool { return x < k; };\n    return max_right(check);\n  }\n};\n\
    \ntemplate <typename T>\nstruct Fenwick_RAQ {\n  int N;\n  FenwickTree<T> bit0;\n\
    \  FenwickTree<T> bit1;\n\n  Fenwick_RAQ(int N) : N(N), bit0(N), bit1(N) {}\n\n\
    \  void add(ll L, ll R, T val) {\n    bit0.add(L, -val * L);\n    bit1.add(L,\
    \ +val);\n    bit0.add(R, +val * R);\n    bit1.add(R, -val);\n  }\n\n  T sum(ll\
    \ L, ll R) {\n    T sum_R = R * bit1.sum(R) + bit0.sum(R);\n    T sum_L = L *\
    \ bit1.sum(L) + bit0.sum(L);\n    return sum_R - sum_L;\n  }\n};\n#line 2 \"other/rectanglesums.hpp\"\
    \n\r\ntemplate <typename WT = ll, bool SMALL = false>\r\nstruct RectangleSums\
    \ {\r\n  int N;\r\n  int n, Q;\r\n  vi X, Y;\r\n  vi keyX, keyY;\r\n  ll min_x,\
    \ max_x, min_y, max_y;\r\n  vc<WT> wt;\r\n  vc<vc<pair<int, WT>>> add;\r\n  vc<vc<tuple<int,\
    \ int, int>>> query_l;\r\n  vc<vc<tuple<int, int, int>>> query_r;\r\n\r\n  RectangleSums(int\
    \ N)\r\n      : N(N), n(0), Q(0), X(N), Y(N), keyX(N), keyY(N), wt(N) {}\r\n\r\
    \n  void add_pt(ll x, ll y, WT w = 1) {\r\n    X[n] = x, Y[n] = y, wt[n] = w,\
    \ keyX[n] = x, keyY[n] = y;\r\n    ++n;\r\n    if (n == N) { compress(); }\r\n\
    \  }\r\n\r\n  void compress() {\r\n    if (!SMALL) {\r\n      UNIQUE(keyX), UNIQUE(keyY);\r\
    \n      add.resize(len(keyX) + 1);\r\n      FOR(i, N) {\r\n        ll x = X[i],\
    \ y = Y[i], w = wt[i];\r\n        x = LB(keyX, x), y = LB(keyY, y);\r\n      \
    \  add[x].eb(y, w);\r\n      }\r\n    } else {\r\n      min_x = (N == 0 ? 0 :\
    \ MIN(X));\r\n      max_x = (N == 0 ? 0 : MAX(X));\r\n      min_y = (N == 0 ?\
    \ 0 : MIN(Y));\r\n      max_y = (N == 0 ? 0 : MAX(Y));\r\n      add.resize(max_x\
    \ - min_x + 2);\r\n      FOR(i, N) {\r\n        ll x = X[i], y = Y[i], w = wt[i];\r\
    \n        x -= min_x, y -= min_y;\r\n        add[x].eb(y, w);\r\n      }\r\n \
    \   }\r\n    query_l.resize(len(add));\r\n    query_r.resize(len(add));\r\n  }\r\
    \n\r\n  void add_rect(ll xl, ll xr, ll yl, ll yr) {\r\n    assert(n == N);\r\n\
    \    if (!SMALL) {\r\n      xl = LB(keyX, xl), xr = LB(keyX, xr);\r\n      yl\
    \ = LB(keyY, yl), yr = LB(keyY, yr);\r\n    } else {\r\n      xl -= min_x, xr\
    \ -= min_x;\r\n      yl -= min_y, yr -= min_y;\r\n      xl = clamp(xl, 0LL, max_x\
    \ - min_x + 1);\r\n      xr = clamp(xr, 0LL, max_x - min_x + 1);\r\n      yl =\
    \ clamp(yl, 0LL, max_y - min_y + 1);\r\n      yr = clamp(yr, 0LL, max_y - min_y\
    \ + 1);\r\n    }\r\n    query_l[xl].eb(Q, yl, yr);\r\n    query_r[xr].eb(Q, yl,\
    \ yr);\r\n    ++Q;\r\n  }\r\n\r\n  vc<WT> calc() {\r\n    assert(n == N);\r\n\
    \    vc<WT> ANS(Q);\r\n    int k = (SMALL ? max_y - min_y + 2 : len(keyY) + 1);\r\
    \n    FenwickTree<WT> bit(k);\r\n    FOR(x, len(add)) {\r\n      FORIN(t, query_l[x])\
    \ {\r\n        auto [q, yl, yr] = t;\r\n        ANS[q] -= bit.sum(yl, yr);\r\n\
    \      }\r\n      FORIN(t, query_r[x]) {\r\n        auto [q, yl, yr] = t;\r\n\
    \        ANS[q] += bit.sum(yl, yr);\r\n      }\r\n      FORIN(t, add[x]) {\r\n\
    \        auto [y, w] = t;\r\n        bit.add(y, w);\r\n      }\r\n      query_l[x].clear();\r\
    \n      query_r[x].clear();\r\n    }\r\n    Q = 0;\r\n    return ANS;\r\n  }\r\
    \n\r\n  void doc() {\r\n    print(\"N \u500B\u306E\u70B9\u306F\u6700\u521D\u306B\
    \u6C7A\u3081\u3066\u3057\u307E\u3046\u3002\");\r\n    print(\"\u540C\u3058\u70B9\
    \u7FA4\u306B\u5BFE\u3057\u3066\u30AF\u30A8\u30EA\u3092\u3084\u308A\u76F4\u305B\
    \u308B\u3002\"); // abc233-h\r\n    print(\"SMALL=true \u306B\u3059\u308B\u3068\
    \u3001\u5EA7\u5727\u3092\u3057\u306A\u3044\u305F\u3081\u5C11\u3057\u9AD8\u901F\
    \");\r\n  }\r\n};\r\n#line 7 \"test/library_checker/datastructure/rectangle_sum_sweep.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  RectangleSums RS(N);\n  FOR(_, N) {\n    LL(x,\
    \ y, w);\n    RS.add_pt(x, y, w);\n  }\n  FOR(_, Q) {\n    LL(l, d, r, u);\n \
    \   RS.add_rect(l, r, d, u);\n  }\n  auto ANS = RS.calc();\n  FORIN(x, ANS) print(x);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"my_template.hpp\"\n\n#include \"ds/fenwick.hpp\"\n#include \"other/rectanglesums.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  RectangleSums RS(N);\n  FOR(_, N) {\n    LL(x,\
    \ y, w);\n    RS.add_pt(x, y, w);\n  }\n  FOR(_, Q) {\n    LL(l, d, r, u);\n \
    \   RS.add_rect(l, r, d, u);\n  }\n  auto ANS = RS.calc();\n  FORIN(x, ANS) print(x);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/fenwick.hpp
  - other/rectanglesums.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  requiredBy: []
  timestamp: '2021-12-26 04:31:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
- /verify/test/library_checker/datastructure/rectangle_sum_sweep.test.cpp.html
title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
---
