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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/fps_inv.hpp:\
    \ line -1: no such header\n"
  code: "#include \"polynomial/fps_inv.hpp\"\r\n\r\ntemplate <typename mint>\r\nstruct\
    \ SubproductTree {\r\n  int m;\r\n  int sz;\r\n  vc<vc<mint>> T;\r\n  SubproductTree(const\
    \ vc<mint>& x) {\r\n    m = len(x);\r\n    sz = 1;\r\n    while (sz < m) sz *=\
    \ 2;\r\n    T.resize(2 * sz);\r\n    FOR(i, sz) T[sz + i] = {1, (i < m ? -x[i]\
    \ : 0)};\r\n    FOR3_R(i, 1, sz) T[i] = convolution(T[2 * i], T[2 * i + 1]);\r\
    \n  }\r\n\r\n  vc<mint> mid_prod(vc<mint>& a, vc<mint>& b) {\r\n    assert(len(a)\
    \ >= len(b) && !b.empty());\r\n    if (min(len(b), len(a) - len(b) + 1) <= 60)\
    \ {\r\n      vc<mint> res(len(a) - len(b) + 1);\r\n      FOR(i, len(res)) FOR(j,\
    \ len(b)) res[i] += b[j] * a[i + j];\r\n      return res;\r\n    }\r\n    int\
    \ n = 1 << std::__lg(2 * len(a) - 1);\r\n    vc<mint> fa(n), fb(n);\r\n    std::copy(a.begin(),\
    \ a.end(), fa.begin());\r\n    std::copy(b.rbegin(), b.rend(), fb.begin());\r\n\
    \    ntt(fa, 0), ntt(fb, 0);\r\n    FOR(i, n) fa[i] *= fb[i];\r\n    ntt(fa, 1);\r\
    \n    fa.resize(len(a));\r\n    fa.erase(fa.begin(), fa.begin() + len(b) - 1);\r\
    \n    return fa;\r\n  }\r\n\r\n  vc<mint> evaluation(vc<mint>& f) {\r\n    int\
    \ n = len(f);\r\n    f.resize(2 * n - 1);\r\n    vc<vc<mint>> g(2 * sz);\r\n \
    \   g[1] = T[1];\r\n    g[1].resize(n);\r\n    g[1] = fps_inv(g[1]);\r\n    g[1]\
    \ = mid_prod(f, g[1]);\r\n    g[1].resize(sz);\r\n\r\n    FOR3(i, 1, sz) {\r\n\
    \      g[2 * i] = mid_prod(g[i], T[2 * i + 1]);\r\n      g[2 * i + 1] = mid_prod(g[i],\
    \ T[2 * i]);\r\n    }\r\n    vc<mint> vals(m);\r\n    FOR(i, m) vals[i] = g[sz\
    \ + i][0];\r\n    return vals;\r\n  }\r\n\r\n  vc<mint> interpolation(vc<mint>&\
    \ y) {\r\n    assert(len(y) == m);\r\n    vc<mint> a(m);\r\n    FOR(i, m) a[i]\
    \ = T[1][m - i - 1] * (i + 1);\r\n\r\n    a = evaluation(a);\r\n    vc<vc<mint>>\
    \ t(2 * sz);\r\n    FOR(i, sz) t[sz + i] = {(i < m ? y[i] / a[i] : 0)};\r\n  \
    \  FOR3_R(i, 1, sz) {\r\n      t[i] = convolution(t[2 * i], T[2 * i + 1]);\r\n\
    \      auto tt = convolution(t[2 * i + 1], T[2 * i]);\r\n      FOR(k, len(t[i]))\
    \ t[i][k] += tt[k];\r\n    }\r\n    t[1].resize(m);\r\n    reverse(all(t[1]));\r\
    \n    return t[1];\r\n  }\r\n};\r\n\r\ntemplate<typename mint>\r\nvc<mint> multipoint_eval(vc<mint>&\
    \ f, vc<mint>& x){\r\n  SubproductTree<mint> F(x);\r\n  return F.evaluation(f);\r\
    \n}\r\n\r\ntemplate<typename mint>\r\nvc<mint> multipoint_interpolate(vc<mint>&\
    \ x, vc<mint>& y){\r\n  SubproductTree<mint> F(x);\r\n  return F.interpolation(y);\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/multipoint.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/multipoint.hpp
layout: document
redirect_from:
- /library/poly/multipoint.hpp
- /library/poly/multipoint.hpp.html
title: poly/multipoint.hpp
---
