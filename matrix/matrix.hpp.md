---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing ll8 = __int128;\nusing ld = long double;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T> using vc\
    \ = vector<T>;\ntemplate <class T> using vvc = vector<vc<T>>;\ntemplate <class\
    \ T> using vvvc = vector<vvc<T>>;\ntemplate <class T> using vvvvc = vector<vvvc<T>>;\n\
    template <class T> using vvvvvc = vector<vvvvc<T>>;\ntemplate <class T> using\
    \ pq = priority_queue<T>;\ntemplate <class T> using pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define VEC(type, name, size)                                                \
    \                                                                            \
    \      \\\n    vector<type> name(size);                                      \
    \                                                                            \
    \                 \\\n    IN(name)\n#define vv(type, name, h, ...) vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define VV(type, name, h, w)           \
    \                                                                            \
    \                                            \\\n    vector<vector<type>> name(h,\
    \ vector<type>(w));                                                          \
    \                                                   \\\n    IN(name)\n#define\
    \ vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...)        \
    \                                                                            \
    \                                     \\\n    vector<vector<vector<vector<type>>>>\
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
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 3 \"matrix/matrix.hpp\"\
    \ntemplate <typename T>\r\nstruct Matrix {\r\n  int H, W;\r\n  vector<vector<T>>\
    \ data;\r\n\r\n  Matrix(int H, int W) : H(H), W(W), data(H, vector<T>(W, 0)){};\r\
    \n  vector<T>& operator[](int i) { return data[i]; }\r\n  Matrix<T> operator*(Matrix<T>&\
    \ other) {\r\n    assert(W == other.H);\r\n    int a = H, b = W, c = other.W;\r\
    \n    Matrix<T> C(a, c);\r\n    FOR(i, a) {\r\n      FOR(j, b) {\r\n        FOR(k,\
    \ c) { C[i][k] += data[i][j] * other[j][k]; }\r\n      }\r\n    }\r\n    return\
    \ C;\r\n  }\r\n  void eye() { FOR(i, H) FOR(j, W) data[i][j] = (i == j ? 1 : 0);\
    \ }\r\n  Matrix<T> pow(ll K) {\r\n    Matrix<T> P(H, H);\r\n    P.eye();\r\n \
    \   Matrix<T> Q(H, H);\r\n    FOR(i, H) FOR(j, H) Q[i][j] = data[i][j];\r\n  \
    \  while (K) {\r\n      if (K & 1) P = P * Q;\r\n      Q = Q * Q;\r\n      K >>=\
    \ 1;\r\n    }\r\n    return P;\r\n  }\r\n};\r\n\r\n\r\ntemplate <class T>\r\n\
    bool is_zero(const T& a) {\r\n  return a == T(0);\r\n}\r\n\r\ntemplate <class\
    \ T>\r\nint row_reduce(std::vector<std::vector<T>>& a, int limit = -1) {\r\n \
    \ int h = std::size(a);\r\n  if (h == 0) return 0;\r\n  int w = std::size(a[0]),\
    \ rank = 0;\r\n  if (limit < 0 or w < limit) limit = w;\r\n  for (int p = 0; p\
    \ < limit; ++p) {\r\n    for (int i = rank + 1; i < h; ++i)\r\n      if constexpr\
    \ (std::is_floating_point_v<T>) {\r\n        if (std::abs(a[rank][p]) < std::abs(a[i][p]))\
    \ std::swap(a[rank], a[i]);\r\n      } else if (not is_zero(a[i][p])) {\r\n  \
    \      std::swap(a[rank], a[i]);\r\n        break;\r\n      }\r\n    if (is_zero(a[rank][p]))\
    \ continue;\r\n    T inv = T(1) / a[rank][p];\r\n    for (auto&& e : a[rank])\
    \ e *= inv;\r\n    for (int i = 0; i < h; ++i)\r\n      if (i != rank and not\
    \ is_zero(a[i][p])) {\r\n        for (int j = p + 1; j < w; ++j) a[i][j] -= a[rank][j]\
    \ * a[i][p];\r\n        a[i][p] = 0;\r\n      }\r\n    if (++rank == h) break;\r\
    \n  }\r\n  return rank;\r\n}\r\n\r\ntemplate <class T>\r\nstd::pair<std::vector<T>,\
    \ std::vector<std::vector<T>>> solve_linear(\r\n  std::vector<std::vector<T>>\
    \ a, const std::vector<T>& b) {\r\n  assert(std::size(a) == std::size(b));\r\n\
    \  assert(not std::empty(a));\r\n  int h = std::size(a), w = std::size(a[0]);\r\
    \n  for (int i = 0; i < h; ++i) a[i].push_back(b[i]);\r\n  int rank = row_reduce(a,\
    \ w);\r\n  for (int i = rank; i < h; ++i)\r\n    if (not is_zero(a[i][w])) return\
    \ {};\r\n  std::vector<T> x(w);\r\n  std::vector pivot(w, -1);\r\n  for (int i\
    \ = 0, j = 0; i < rank; ++i) {\r\n    while (is_zero(a[i][j])) ++j;\r\n    x[j]\
    \ = a[i][w];\r\n    pivot[j] = i;\r\n  }\r\n  std::vector<std::vector<T>> basis;\r\
    \n  for (int p = 0; p < w; ++p)\r\n    if (pivot[p] == -1) {\r\n      basis.emplace_back(w);\r\
    \n      basis.back()[p] = -1;\r\n      for (int j = 0; j < p; ++j)\r\n       \
    \ if (pivot[j] != -1) basis.back()[j] = a[pivot[j]][p];\r\n    }\r\n  return {x,\
    \ basis};\r\n}\r\n"
  code: "#pragma once\r\n#include \"my_template.hpp\"\r\ntemplate <typename T>\r\n\
    struct Matrix {\r\n  int H, W;\r\n  vector<vector<T>> data;\r\n\r\n  Matrix(int\
    \ H, int W) : H(H), W(W), data(H, vector<T>(W, 0)){};\r\n  vector<T>& operator[](int\
    \ i) { return data[i]; }\r\n  Matrix<T> operator*(Matrix<T>& other) {\r\n    assert(W\
    \ == other.H);\r\n    int a = H, b = W, c = other.W;\r\n    Matrix<T> C(a, c);\r\
    \n    FOR(i, a) {\r\n      FOR(j, b) {\r\n        FOR(k, c) { C[i][k] += data[i][j]\
    \ * other[j][k]; }\r\n      }\r\n    }\r\n    return C;\r\n  }\r\n  void eye()\
    \ { FOR(i, H) FOR(j, W) data[i][j] = (i == j ? 1 : 0); }\r\n  Matrix<T> pow(ll\
    \ K) {\r\n    Matrix<T> P(H, H);\r\n    P.eye();\r\n    Matrix<T> Q(H, H);\r\n\
    \    FOR(i, H) FOR(j, H) Q[i][j] = data[i][j];\r\n    while (K) {\r\n      if\
    \ (K & 1) P = P * Q;\r\n      Q = Q * Q;\r\n      K >>= 1;\r\n    }\r\n    return\
    \ P;\r\n  }\r\n};\r\n\r\n\r\ntemplate <class T>\r\nbool is_zero(const T& a) {\r\
    \n  return a == T(0);\r\n}\r\n\r\ntemplate <class T>\r\nint row_reduce(std::vector<std::vector<T>>&\
    \ a, int limit = -1) {\r\n  int h = std::size(a);\r\n  if (h == 0) return 0;\r\
    \n  int w = std::size(a[0]), rank = 0;\r\n  if (limit < 0 or w < limit) limit\
    \ = w;\r\n  for (int p = 0; p < limit; ++p) {\r\n    for (int i = rank + 1; i\
    \ < h; ++i)\r\n      if constexpr (std::is_floating_point_v<T>) {\r\n        if\
    \ (std::abs(a[rank][p]) < std::abs(a[i][p])) std::swap(a[rank], a[i]);\r\n   \
    \   } else if (not is_zero(a[i][p])) {\r\n        std::swap(a[rank], a[i]);\r\n\
    \        break;\r\n      }\r\n    if (is_zero(a[rank][p])) continue;\r\n    T\
    \ inv = T(1) / a[rank][p];\r\n    for (auto&& e : a[rank]) e *= inv;\r\n    for\
    \ (int i = 0; i < h; ++i)\r\n      if (i != rank and not is_zero(a[i][p])) {\r\
    \n        for (int j = p + 1; j < w; ++j) a[i][j] -= a[rank][j] * a[i][p];\r\n\
    \        a[i][p] = 0;\r\n      }\r\n    if (++rank == h) break;\r\n  }\r\n  return\
    \ rank;\r\n}\r\n\r\ntemplate <class T>\r\nstd::pair<std::vector<T>, std::vector<std::vector<T>>>\
    \ solve_linear(\r\n  std::vector<std::vector<T>> a, const std::vector<T>& b) {\r\
    \n  assert(std::size(a) == std::size(b));\r\n  assert(not std::empty(a));\r\n\
    \  int h = std::size(a), w = std::size(a[0]);\r\n  for (int i = 0; i < h; ++i)\
    \ a[i].push_back(b[i]);\r\n  int rank = row_reduce(a, w);\r\n  for (int i = rank;\
    \ i < h; ++i)\r\n    if (not is_zero(a[i][w])) return {};\r\n  std::vector<T>\
    \ x(w);\r\n  std::vector pivot(w, -1);\r\n  for (int i = 0, j = 0; i < rank; ++i)\
    \ {\r\n    while (is_zero(a[i][j])) ++j;\r\n    x[j] = a[i][w];\r\n    pivot[j]\
    \ = i;\r\n  }\r\n  std::vector<std::vector<T>> basis;\r\n  for (int p = 0; p <\
    \ w; ++p)\r\n    if (pivot[p] == -1) {\r\n      basis.emplace_back(w);\r\n   \
    \   basis.back()[p] = -1;\r\n      for (int j = 0; j < p; ++j)\r\n        if (pivot[j]\
    \ != -1) basis.back()[j] = a[pivot[j]][p];\r\n    }\r\n  return {x, basis};\r\n\
    }\r\n"
  dependsOn:
  - my_template.hpp
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: matrix/matrix.hpp
---
