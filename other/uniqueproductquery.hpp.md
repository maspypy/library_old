---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/703/problem/D
  bundledCode: "#line 2 \"ds/segtree.hpp\"\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using X = typename Monoid::value_type;\n  using value_type = X;\n  vc<X>\
    \ dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) :\
    \ SegTree(vc<X>(n, Monoid::unit)) {}\n  SegTree(vc<X> v) : n(len(v)) {\n    log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid::unit);\n    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1,\
    \ size) update(i);\n  }\n\n  X operator[](int i) { return dat[size + i]; }\n\n\
    \  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n\
    \  void set(int i, X x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while\
    \ (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n\
    \    assert(R <= n);\n    X vl = Monoid::unit, vr = Monoid::unit;\n    L += size,\
    \ R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n\
    \      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n  \
    \  }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return dat[1];}\n\
    \n  template <class F>\n  int max_right(F &check, int L) {\n    assert(0 <= L\
    \ && L <= n && check(Monoid::unit));\n    if (L == n) return n;\n    L += size;\n\
    \    X sm = Monoid::unit;\n    do {\n      while (L % 2 == 0) L >>= 1;\n     \
    \ if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n        \
    \  L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n            sm\
    \ = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n      \
    \  return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n      L++;\n\
    \    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class F>\n  int\
    \ min_left(F &check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit;\n    do {\n\
    \      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n#line 2 \"other/uniqueproductquery.hpp\"\
    \n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\ntemplate\
    \ <typename Mono>\r\nstruct UniqueProductQuery {\r\n  /*\r\n  [L, R) \u5185\u306E\
    \u8981\u7D20\u3092 UNIQUE \u3057\u305F\u4E0A\u3067\u3001f(x) \u306E\u7DCF\u7A4D\
    \u3092\u3068\u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\u3002\r\n  \u30AF\u30A8\
    \u30EA\u5148\u8AAD\u307F\u30BD\u30FC\u30C8\uFF0B\u30BB\u30B0\u6728\r\n  */\r\n\
    \  using X = typename Mono::value_type;\r\n  int N;\r\n  vc<X> A;\r\n  vc<pair<int,\
    \ int>> query;\r\n\r\n  UniqueProductQuery(vc<X> A) : N(len(A)), A(A) {}\r\n\r\
    \n  void add(int L, int R) {\r\n    assert(0 <= L && L <= R && R <= N);\r\n  \
    \  query.eb(L, R);\r\n  }\r\n\r\n  template <typename F>\r\n  vc<X> run(F f) {\r\
    \n    ll Q = len(query);\r\n    vc<X> ANS(Q);\r\n    vc<vc<int>> IDS(N + 1);\r\
    \n    FOR(q, Q) IDS[query[q].se].eb(q);\r\n    SegTree<Mono> seg(N);\r\n\r\n \
    \   unordered_map<X, int> pos;\r\n    pos.reserve(N);\r\n\r\n    FOR(i, N) {\r\
    \n      X x = A[i];\r\n      if (pos.count(x)) seg.set(pos[x], Mono::unit);\r\n\
    \      pos[x] = i;\r\n      seg.set(i, f(A[i]));\r\n      for (auto&& q: IDS[i\
    \ + 1]) {\r\n        auto [L, R] = query[q];\r\n        ANS[q] = seg.prod(L, R);\r\
    \n      }\r\n    }\r\n    return ANS;\r\n  }\r\n\r\n  vc<X> run() {\r\n    auto\
    \ f = [&](X x) -> X { return x; };\r\n    return run(f);\r\n  }\r\n};\n"
  code: "#include \"ds/segtree.hpp\"\r\n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\
    \ntemplate <typename Mono>\r\nstruct UniqueProductQuery {\r\n  /*\r\n  [L, R)\
    \ \u5185\u306E\u8981\u7D20\u3092 UNIQUE \u3057\u305F\u4E0A\u3067\u3001f(x) \u306E\
    \u7DCF\u7A4D\u3092\u3068\u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\u3002\r\n \
    \ \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u30BD\u30FC\u30C8\uFF0B\u30BB\u30B0\u6728\
    \r\n  */\r\n  using X = typename Mono::value_type;\r\n  int N;\r\n  vc<X> A;\r\
    \n  vc<pair<int, int>> query;\r\n\r\n  UniqueProductQuery(vc<X> A) : N(len(A)),\
    \ A(A) {}\r\n\r\n  void add(int L, int R) {\r\n    assert(0 <= L && L <= R &&\
    \ R <= N);\r\n    query.eb(L, R);\r\n  }\r\n\r\n  template <typename F>\r\n  vc<X>\
    \ run(F f) {\r\n    ll Q = len(query);\r\n    vc<X> ANS(Q);\r\n    vc<vc<int>>\
    \ IDS(N + 1);\r\n    FOR(q, Q) IDS[query[q].se].eb(q);\r\n    SegTree<Mono> seg(N);\r\
    \n\r\n    unordered_map<X, int> pos;\r\n    pos.reserve(N);\r\n\r\n    FOR(i,\
    \ N) {\r\n      X x = A[i];\r\n      if (pos.count(x)) seg.set(pos[x], Mono::unit);\r\
    \n      pos[x] = i;\r\n      seg.set(i, f(A[i]));\r\n      for (auto&& q: IDS[i\
    \ + 1]) {\r\n        auto [L, R] = query[q];\r\n        ANS[q] = seg.prod(L, R);\r\
    \n      }\r\n    }\r\n    return ANS;\r\n  }\r\n\r\n  vc<X> run() {\r\n    auto\
    \ f = [&](X x) -> X { return x; };\r\n    return run(f);\r\n  }\r\n};"
  dependsOn:
  - ds/segtree.hpp
  isVerificationFile: false
  path: other/uniqueproductquery.hpp
  requiredBy: []
  timestamp: '2022-02-11 06:56:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/uniqueproductquery.hpp
layout: document
redirect_from:
- /library/other/uniqueproductquery.hpp
- /library/other/uniqueproductquery.hpp.html
title: other/uniqueproductquery.hpp
---
