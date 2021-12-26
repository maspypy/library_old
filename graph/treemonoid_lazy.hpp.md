---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid.hpp
    title: algebra/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
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
    \  merge(all(A), all(B), back_inserter(C));\n  return C;\n}\n#line 3 \"ds/lazysegtree.hpp\"\
    \n\n#line 2 \"algebra/monoid.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid\
    \ {\r\n  using F = function<E(E, E)>;\r\n  using G = function<E(E)>;\r\n  F f;\r\
    \n  E unit;\r\n  bool commute;\r\n  bool has_inverse;\r\n  G inverse;\r\n};\r\n\
    \r\ntemplate <typename E, typename OP>\r\nstruct Monoid_OP {\r\n  using F = function<E(E,\
    \ E)>;\r\n  using G = function<E(E, OP)>;\r\n  using H = function<OP(OP, OP)>;\r\
    \n  F f;\r\n  G g;\r\n  H h;\r\n  E unit;\r\n  OP OP_unit;\r\n  bool commute;\r\
    \n  bool OP_commute;\r\n};\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_reverse(Monoid<E>\
    \ Mono) {\r\n  auto rev_f = [=](E x, E y) -> E { return Mono.f(y, x); };\r\n \
    \ return Monoid<E>(\r\n    {rev_f, Mono.unit, Mono.commute, Mono.has_inverse,\
    \ Mono.inverse});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_add()\
    \ {\r\n  auto f = [](E x, E y) -> E { return x + y; };\r\n  auto g = [](E x) ->\
    \ E { return -x; };\r\n  return Monoid<E>({f, 0, true, true, g});\r\n}\r\n\r\n\
    template <typename E>\r\nMonoid<E> Monoid_min(E INF) {\r\n  auto f = [](E x, E\
    \ y) -> E { return min(x, y); };\r\n  return Monoid<E>({f, INF, true, false});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid<E> Monoid_max(E MINUS_INF) {\r\n  auto\
    \ f = [](E x, E y) -> E { return max(x, y); };\r\n  return Monoid<E>({f, MINUS_INF,\
    \ true, false});\r\n}\r\n\r\ntemplate <typename E>\r\nMonoid<pair<E, E>> Monoid_affine(bool\
    \ has_inverse = false) {\r\n  auto f = [](pair<E, E> x, pair<E, E> y) -> pair<E,\
    \ E> {\r\n    return {x.fi * y.fi, x.se * y.fi + y.se};\r\n  };\r\n  auto inv\
    \ = [&](pair<E, E> x) -> pair<E, E> {\r\n    // y = ax + b iff x = (1/a) y - (b/a)\r\
    \n    auto [a, b] = x;\r\n    a = E(1) / a;\r\n    return {a, a * (-b)};\r\n \
    \ };\r\n  return Monoid<pair<E, E>>({f, mp(E(1), E(0)), false, has_inverse, inv});\r\
    \n}\r\n\r\ntemplate <typename E>\r\nMonoid_OP<pair<E, E>, pair<E, E>> Monoid_cnt_sum_affine()\
    \ {\r\n  using P = pair<E, E>;\r\n  auto f = [](P x, P y) -> P { return P({x.fi\
    \ + y.fi, x.se + y.se}); };\r\n  auto g = [](P x, P y) -> P { return P({x.fi,\
    \ x.fi * y.se + x.se * y.fi}); };\r\n  auto h = [](P x, P y) -> P { return P({x.fi\
    \ * y.fi, x.se * y.fi + y.se}); };\r\n  return Monoid_OP<P, P>({f, g, h, P({0,\
    \ 0}), P({1, 0}), true, false});\r\n}\r\n#line 5 \"ds/lazysegtree.hpp\"\n\ntemplate\
    \ <typename E, typename OP>\nstruct LazySegTree {\n  using F = function<E(E, E)>;\n\
    \  using G = function<E(E, OP)>;\n  using H = function<OP(OP, OP)>;\n  int _n,\
    \ size, log;\n  vc<E> dat;\n  vc<OP> laz;\n  F seg_f;\n  G seg_g;\n  H seg_h;\n\
    \  E unit;\n  OP OP_unit;\n  bool OP_commute;\n\n  LazySegTree(Monoid_OP<E, OP>\
    \ Mono)\n      : seg_f(Mono.f)\n      , seg_g(Mono.g)\n      , seg_h(Mono.h)\n\
    \      , unit(Mono.unit)\n      , OP_unit(Mono.OP_unit)\n      , OP_commute(Mono.OP_commute)\
    \ {}\n\n  void init(int n) {\n    _n = n;\n    log = 1;\n    while ((1 << log)\
    \ < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, unit);\n    laz.assign(size,\
    \ OP_unit);\n  }\n\n  void build(const vector<E>& v) {\n    assert(v.size() ==\
    \ _n);\n    FOR(i, v.size()) { dat[size + i] = v[i]; }\n    FOR3_R(i, 1, size)\
    \ { update(i); }\n  }\n\n  void update(int k) { dat[k] = seg_f(dat[2 * k], dat[2\
    \ * k + 1]); }\n\n  void all_apply(int k, OP a) {\n    dat[k] = seg_g(dat[k],\
    \ a);\n    if (k < size) laz[k] = seg_h(laz[k], a);\n  }\n\n  void push(int k)\
    \ {\n    all_apply(2 * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k]\
    \ = OP_unit;\n  }\n\n  void set(int p, E x) {\n    assert(0 <= p && p < _n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  E get(int\
    \ p) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n  E prod(int l, int r)\
    \ {\n    assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return unit;\n\n\
    \    l += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n    \
    \  if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n\n    E sml = unit, smr = unit;\n    while (l < r) {\n \
    \     if (l & 1) sml = seg_f(sml, dat[l++]);\n      if (r & 1) smr = seg_f(dat[--r],\
    \ smr);\n      l >>= 1;\n      r >>= 1;\n    }\n\n    return seg_f(sml, smr);\n\
    \  }\n\n  E all_prod() { return dat[1]; }\n\n  void apply(int p, OP a) {\n   \
    \ assert(0 <= p && p < _n);\n    p += size;\n    if (!OP_commute)\n      for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    dat[p] = seg_g(dat[p], a);\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  void apply(int l, int r,\
    \ OP a) {\n    assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n\
    \n    l += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n   \
    \   if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r)\
    \ {\n        if (l & 1) all_apply(l++, a);\n        if (r & 1) all_apply(--r,\
    \ a);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n\
    \    }\n\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
    \ update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n   \
    \ }\n  }\n\n  template <typename C>\n  int max_right(C& check, int l) {\n    assert(0\
    \ <= l && l <= _n);\n    assert(check(unit));\n    if (l == _n) return _n;\n \
    \   l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n    E sm = unit;\n\
    \    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(seg_f(sm, dat[l])))\
    \ {\n        while (l < size) {\n          push(l);\n          l = (2 * l);\n\
    \          if (check(seg_f(sm, dat[l]))) {\n            sm = seg_f(sm, dat[l]);\n\
    \            l++;\n          }\n        }\n        return l - size;\n      }\n\
    \      sm = seg_f(sm, dat[l]);\n      l++;\n    } while ((l & -l) != l);\n   \
    \ return _n;\n  }\n\n  template <typename C>\n  int min_left(C& check, int r)\
    \ {\n    assert(0 <= r && r <= _n);\n    assert(check(unit));\n    if (r == 0)\
    \ return 0;\n    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >>\
    \ i);\n    E sm = unit;\n    do {\n      r--;\n      while (r > 1 && (r % 2))\
    \ r >>= 1;\n      if (!check(seg_f(dat[r], sm))) {\n        while (r < size) {\n\
    \          push(r);\n          r = (2 * r + 1);\n          if (check(seg_f(dat[r],\
    \ sm))) {\n            sm = seg_f(dat[r], sm);\n            r--;\n          }\n\
    \        }\n        return r + 1 - size;\n      }\n      sm = seg_f(dat[r], sm);\n\
    \    } while ((r & -r) != r);\n    return 0;\n  }\n\n  void debug() {\n    vc<E>\
    \ v(_n);\n    FOR(i, _n) v[i] = get(i);\n    print(\"lazysegtree getall:\", v);\n\
    \  }\n};\n#line 2 \"graph/treemonoid_lazy.hpp\"\n\r\ntemplate <typename HLD, typename\
    \ E, typename OP, bool edge = false,\r\n          bool commute = true, bool OP_commute\
    \ = false>\r\nstruct TreeMonoidLazy {\r\n  using F = function<E(E, E)>;\r\n  using\
    \ G = function<E(E, OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  HLD &hld;\r\
    \n  int N;\r\n  F seg_f;\r\n  E E_unit;\r\n  LazySegTree<E, OP, OP_commute> seg,\
    \ seg_r;\r\n\r\n  TreeMonoidLazy(HLD &hld, F seg_f, G seg_g, H seg_h, E E_unit,\
    \ OP OP_unit)\r\n      : hld(hld)\r\n      , N(hld.N)\r\n      , seg_f(seg_f)\r\
    \n      , E_unit(E_unit)\r\n      , seg(seg_f, seg_g, seg_h, E_unit, OP_unit)\r\
    \n      , seg_r([&](E x, E y) -> E { return seg_f(y, x); }, seg_g, seg_h, E_unit,\r\
    \n              OP_unit) {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\
    \n  };\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\
    \n    vc<E> seg_raw(N, E_unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\
    \n        seg_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\
    \n    if (!commute) seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x)\
    \ {\r\n    if (edge) i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i,\
    \ x);\r\n    if (!commute) seg_r.set(i, x);\r\n  }\r\n\r\n  E fold_path_nc(int\
    \ u, int v) {\r\n    E vl = E_unit, vr = E_unit;\r\n    while (1) {\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\
    \n        vr = seg_f(seg.fold(hld.LID[hld.head[v]], hld.LID[v] + 1), vr);\r\n\
    \        v = hld.parent[hld.head[v]];\r\n      } else {\r\n        vl = seg_f(vl,\
    \ seg_r.fold(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\n        u = hld.parent[hld.head[u]];\r\
    \n      }\r\n    }\r\n    E vm =\r\n      (hld.LID[u] < hld.LID[v] ? seg.fold(hld.LID[u]\
    \ + edge, hld.LID[v] + 1)\r\n                               : seg_r.fold(hld.LID[v]\
    \ + edge, hld.LID[u] + 1));\r\n    return seg_f(vl, seg_f(vm, vr));\r\n  }\r\n\
    \r\n  E fold_path(int u, int v) {\r\n    if (!commute) return fold_path_nc(u,\
    \ v);\r\n    E val = E_unit;\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v])\
    \ swap(u, v);\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      val = seg_f(seg.fold(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return seg_f(seg.fold(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\
    \n  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\n    print(\"\
    seg\");\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\n\
    \  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\
    \");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\
    \u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\u9593\u3002\");\r\n    print(\"\
    \u30D1\u30B9\u9806\u3092\u6C17\u306B\u3059\u308B\u5834\u5408\u306F\u3001commute=false\u3068\
    \u3059\u308B\u3002\");\r\n    print(\"\u95A2\u9023\");\r\n    print(\"- \u7FA4\
    \u306A\u3089\u30D1\u30B9\u30AF\u30A8\u30EA\u306F TreeGrp \u3067 O(logN) \u6642\
    \u9593\");\r\n    print(\"- \u5909\u66F4\u306A\u3057\u306A\u3089\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u306F TreeMonoid_static \u3067 O(logN) \u6642\u9593\");\r\n  }\r\n\
    };\r\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n\r\ntemplate <typename HLD, typename E,\
    \ typename OP, bool edge = false,\r\n          bool commute = true, bool OP_commute\
    \ = false>\r\nstruct TreeMonoidLazy {\r\n  using F = function<E(E, E)>;\r\n  using\
    \ G = function<E(E, OP)>;\r\n  using H = function<OP(OP, OP)>;\r\n  HLD &hld;\r\
    \n  int N;\r\n  F seg_f;\r\n  E E_unit;\r\n  LazySegTree<E, OP, OP_commute> seg,\
    \ seg_r;\r\n\r\n  TreeMonoidLazy(HLD &hld, F seg_f, G seg_g, H seg_h, E E_unit,\
    \ OP OP_unit)\r\n      : hld(hld)\r\n      , N(hld.N)\r\n      , seg_f(seg_f)\r\
    \n      , E_unit(E_unit)\r\n      , seg(seg_f, seg_g, seg_h, E_unit, OP_unit)\r\
    \n      , seg_r([&](E x, E y) -> E { return seg_f(y, x); }, seg_g, seg_h, E_unit,\r\
    \n              OP_unit) {\r\n    seg.init(N);\r\n    if (!commute) seg_r.init(N);\r\
    \n  };\r\n\r\n  void init(vc<E> &dat) {\r\n    // vertex index OR edge index\r\
    \n    vc<E> seg_raw(N, E_unit);\r\n    if (!edge) {\r\n      FOR(v, N) seg_raw[hld.LID[v]]\
    \ = dat[v];\r\n    } else {\r\n      FOR(i, N - 1) {\r\n        int v = hld.e_to_v[i];\r\
    \n        seg_raw[hld.LID[v]] = dat[i];\r\n      }\r\n    }\r\n    seg.build(seg_raw);\r\
    \n    if (!commute) seg_r.build(seg_raw);\r\n  }\r\n\r\n  void set(int i, E x)\
    \ {\r\n    if (edge) i = hld.e_to_v[i];\r\n    i = hld.LID[i];\r\n    seg.set(i,\
    \ x);\r\n    if (!commute) seg_r.set(i, x);\r\n  }\r\n\r\n  E fold_path_nc(int\
    \ u, int v) {\r\n    E vl = E_unit, vr = E_unit;\r\n    while (1) {\r\n      if\
    \ (hld.head[u] == hld.head[v]) break;\r\n      if (hld.LID[u] < hld.LID[v]) {\r\
    \n        vr = seg_f(seg.fold(hld.LID[hld.head[v]], hld.LID[v] + 1), vr);\r\n\
    \        v = hld.parent[hld.head[v]];\r\n      } else {\r\n        vl = seg_f(vl,\
    \ seg_r.fold(hld.LID[hld.head[u]], hld.LID[u] + 1));\r\n        u = hld.parent[hld.head[u]];\r\
    \n      }\r\n    }\r\n    E vm =\r\n      (hld.LID[u] < hld.LID[v] ? seg.fold(hld.LID[u]\
    \ + edge, hld.LID[v] + 1)\r\n                               : seg_r.fold(hld.LID[v]\
    \ + edge, hld.LID[u] + 1));\r\n    return seg_f(vl, seg_f(vm, vr));\r\n  }\r\n\
    \r\n  E fold_path(int u, int v) {\r\n    if (!commute) return fold_path_nc(u,\
    \ v);\r\n    E val = E_unit;\r\n    while (1) {\r\n      if (hld.LID[u] > hld.LID[v])\
    \ swap(u, v);\r\n      if (hld.head[u] == hld.head[v]) break;\r\n      val = seg_f(seg.fold(hld.LID[hld.head[v]],\
    \ hld.LID[v] + 1), val);\r\n      v = hld.parent[hld.head[v]];\r\n    }\r\n  \
    \  return seg_f(seg.fold(hld.LID[u] + edge, hld.LID[v] + 1), val);\r\n  }\r\n\r\
    \n  void debug() {\r\n    print(\"hld\");\r\n    hld.debug();\r\n    print(\"\
    seg\");\r\n    seg.debug();\r\n    print(\"seg_r\");\r\n    seg_r.debug();\r\n\
    \  }\r\n\r\n  void doc() {\r\n    print(\"HL\u5206\u89E3 + \u30BB\u30B0\u6728\u3002\
    \");\r\n    print(\"\u90E8\u5206\u6728\u30AF\u30A8\u30EA O(logN) \u6642\u9593\u3001\
    \u30D1\u30B9\u30AF\u30A8\u30EA O(log^2N) \u6642\u9593\u3002\");\r\n    print(\"\
    \u30D1\u30B9\u9806\u3092\u6C17\u306B\u3059\u308B\u5834\u5408\u306F\u3001commute=false\u3068\
    \u3059\u308B\u3002\");\r\n    print(\"\u95A2\u9023\");\r\n    print(\"- \u7FA4\
    \u306A\u3089\u30D1\u30B9\u30AF\u30A8\u30EA\u306F TreeGrp \u3067 O(logN) \u6642\
    \u9593\");\r\n    print(\"- \u5909\u66F4\u306A\u3057\u306A\u3089\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u306F TreeMonoid_static \u3067 O(logN) \u6642\u9593\");\r\n  }\r\n\
    };\r\n"
  dependsOn:
  - ds/lazysegtree.hpp
  - my_template.hpp
  - algebra/monoid.hpp
  isVerificationFile: false
  path: graph/treemonoid_lazy.hpp
  requiredBy: []
  timestamp: '2021-12-27 05:46:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/treemonoid_lazy.hpp
layout: document
redirect_from:
- /library/graph/treemonoid_lazy.hpp
- /library/graph/treemonoid_lazy.hpp.html
title: graph/treemonoid_lazy.hpp
---
