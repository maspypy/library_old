---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"my_template.hpp\"\n\n#include \"algebra/monoid.hpp\"\
    \n\ntemplate <typename E, typename OP>\nstruct LazySegTree {\n  using F = function<E(E,\
    \ E)>;\n  using G = function<E(E, OP)>;\n  using H = function<OP(OP, OP)>;\n \
    \ int _n, size, log;\n  vc<E> dat;\n  vc<OP> laz;\n  F seg_f;\n  G seg_g;\n  H\
    \ seg_h;\n  E unit;\n  OP OP_unit;\n  bool OP_commute;\n\n  LazySegTree(Monoid_OP<E,\
    \ OP> Mono)\n      : seg_f(Mono.f),\n        seg_g(Mono.g),\n        seg_h(Mono.h),\n\
    \        unit(Mono.unit),\n        OP_unit(Mono.OP_unit),\n        OP_commute(Mono.OP_commute)\
    \ {}\n\n  void init(int n) {\n    _n = n;\n    log = 1;\n    while ((1 << log)\
    \ < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, unit);\n    laz.assign(size,\
    \ OP_unit);\n  }\n\n  void build(const vector<E>& v) {\n    assert(len(v) == _n);\n\
    \    FOR(i, len(v)) { dat[size + i] = v[i]; }\n    FOR3_R(i, 1, size) { update(i);\
    \ }\n  }\n\n  void update(int k) { dat[k] = seg_f(dat[2 * k], dat[2 * k + 1]);\
    \ }\n\n  void all_apply(int k, OP a) {\n    dat[k] = seg_g(dat[k], a);\n    if\
    \ (k < size) laz[k] = seg_h(laz[k], a);\n  }\n\n  void push(int k) {\n    all_apply(2\
    \ * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = OP_unit;\n  }\n\
    \n  void set(int p, E x) {\n    assert(0 <= p && p < _n);\n    p += size;\n  \
    \  for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n  }\n\n  E get(int p) {\n    assert(0\
    \ <= p && p < _n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n    return dat[p];\n  }\n\n  E prod(int l, int r) {\n    assert(0 <=\
    \ l && l <= r && r <= _n);\n    if (l == r) return unit;\n\n    l += size;\n \
    \   r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \    }\n\n    E sml = unit, smr = unit;\n    while (l < r) {\n      if (l & 1)\
    \ sml = seg_f(sml, dat[l++]);\n      if (r & 1) smr = seg_f(dat[--r], smr);\n\
    \      l >>= 1;\n      r >>= 1;\n    }\n\n    return seg_f(sml, smr);\n  }\n\n\
    \  E all_prod() { return dat[1]; }\n\n  void apply(int p, OP a) {\n    assert(0\
    \ <= p && p < _n);\n    p += size;\n    if (!OP_commute)\n      for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    dat[p] = seg_g(dat[p], a);\n    for (int i =\
    \ 1; i <= log; i++) update(p >> i);\n  }\n\n  void apply(int l, int r, OP a) {\n\
    \    assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n\n    l +=\
    \ size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n \
    \       if (l & 1) all_apply(l++, a);\n        if (r & 1) all_apply(--r, a);\n\
    \        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n \
    \   }\n\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
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
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/lazysegtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lazysegtree.hpp
layout: document
redirect_from:
- /library/ds/lazysegtree.hpp
- /library/ds/lazysegtree.hpp.html
title: ds/lazysegtree.hpp
---
