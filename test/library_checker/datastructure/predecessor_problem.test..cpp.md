---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/library_checker/datastructure/predecessor_problem.test..cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#line\
    \ 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    using ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\nusing pi\
    \ = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T> using vc = vector<T>;\n\
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
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 1 \"ds/fastset.hpp\"\
    \nstruct FastSet {\r\n  using uint = unsigned;\r\n  using ull = unsigned long\
    \ long;\r\n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull\
    \ x) { return __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n\
    \  int n, lg;\r\n  vc<vc<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do {\r\
    \n      seg.push_back(vc<ull>((_n + B - 1) / B));\r\n      _n = (_n + B - 1) /\
    \ B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n  bool operator[](int\
    \ i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }\r\n  void insert(int\
    \ i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] |= 1ULL <<\
    \ (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void erase(int i) {\r\n    for\
    \ (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL << (i % B));\r\n\
    \      if (seg[h][i / B])\r\n        break;\r\n      i /= B;\r\n    }\r\n  }\r\
    \n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\r\n  int next(int i) {\r\n\
    \    for (int h = 0; h < lg; h++) {\r\n      if (i / B == seg[h].size())\r\n \
    \       break;\r\n      ull d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\
    \n        i = i / B + 1;\r\n        continue;\r\n      }\r\n      // find\r\n\
    \      i += bsf(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *=\
    \ B;\r\n        i += bsf(seg[g][i / B]);\r\n      }\r\n      return i;\r\n   \
    \ }\r\n    return n;\r\n  }\r\n  // x\u4EE5\u4E0B\u6700\u5927\u306E\u8981\u7D20\
    \r\n  int prev(int i) {\r\n    if(i < 0) return -1;\r\n    chmin(i, n - 1);\r\n\
    \    for (int h = 0; h < lg; h++) {\r\n      if (i == -1)\r\n        break;\r\n\
    \      ull d = seg[h][i / B] << (63 - i % 64);\r\n      if (!d) {\r\n        i\
    \ = i / B - 1;\r\n        continue;\r\n      }\r\n      // find\r\n      i +=\
    \ bsr(d) - (B - 1);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *=\
    \ B;\r\n        i += bsr(seg[g][i / B]);\r\n      }\r\n      return i;\r\n   \
    \ }\r\n    return -1;\r\n  }\r\n  void print(){\r\n    for(int i=0;i<n;++i) cout\
    \ << (*this)[i];\r\n    cout << endl;\r\n  }\r\n};\n#line 4 \"test/library_checker/datastructure/predecessor_problem.test..cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  FastSet ss(N);\n  STR(S);\n  FOR(x, N) {\n\
    \    if (S[x] == '1') ss.insert(x);\n  }\n\n  FOR(_, Q) {\n    LL(t, k);\n   \
    \ if (t == 0) { ss.insert(k); }\n    elif (t == 1) { ss.erase(k); }\n    elif\
    \ (t == 2) { print(ss[k]); }\n    elif (t == 3) {\n      ll x = ss.next(k);\n\
    \      if (x == N) x = -1;\n      print(x);\n    }\n    elif (t == 4) { print(ss.prev(k));\
    \ }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"my_template.hpp\"\n#include \"ds/fastset.hpp\"\n\nvoid solve() {\n\
    \  LL(N, Q);\n  FastSet ss(N);\n  STR(S);\n  FOR(x, N) {\n    if (S[x] == '1')\
    \ ss.insert(x);\n  }\n\n  FOR(_, Q) {\n    LL(t, k);\n    if (t == 0) { ss.insert(k);\
    \ }\n    elif (t == 1) { ss.erase(k); }\n    elif (t == 2) { print(ss[k]); }\n\
    \    elif (t == 3) {\n      ll x = ss.next(k);\n      if (x == N) x = -1;\n  \
    \    print(x);\n    }\n    elif (t == 4) { print(ss.prev(k)); }\n  }\n}\n\nsigned\
    \ main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/fastset.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/predecessor_problem.test..cpp
  requiredBy: []
  timestamp: '2021-12-26 03:01:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/predecessor_problem.test..cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/predecessor_problem.test..cpp
- /verify/test/library_checker/datastructure/predecessor_problem.test..cpp.html
title: test/library_checker/datastructure/predecessor_problem.test..cpp
---
