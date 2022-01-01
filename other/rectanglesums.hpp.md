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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algebra/addgroup.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fenwick.hpp\"\r\n#include \"algebra/addgroup.hpp\"\r\n\r\n\
    template <typename WT = ll, bool SMALL = false>\r\nstruct RectangleSums {\r\n\
    \  int N;\r\n  int n, Q;\r\n  vi X, Y;\r\n  vi keyX, keyY;\r\n  ll min_x, max_x,\
    \ min_y, max_y;\r\n  vc<WT> wt;\r\n  vc<vc<pair<int, WT>>> add;\r\n  vc<vc<tuple<int,\
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
    \n    FenwickTree<AddGroup<WT>> bit(k);\r\n    FOR(x, len(add)) {\r\n      for\
    \ (auto&& t: query_l[x]) {\r\n        auto [q, yl, yr] = t;\r\n        ANS[q]\
    \ -= bit.sum(yl, yr);\r\n      }\r\n      for (auto&& t: query_r[x]) {\r\n   \
    \     auto [q, yl, yr] = t;\r\n        ANS[q] += bit.sum(yl, yr);\r\n      }\r\
    \n      for (auto&& t: add[x]) {\r\n        auto [y, w] = t;\r\n        bit.add(y,\
    \ w);\r\n      }\r\n      query_l[x].clear();\r\n      query_r[x].clear();\r\n\
    \    }\r\n    Q = 0;\r\n    return ANS;\r\n  }\r\n\r\n  void doc() {\r\n    print(\"\
    N \u500B\u306E\u70B9\u306F\u6700\u521D\u306B\u6C7A\u3081\u3066\u3057\u307E\u3046\
    \u3002\");\r\n    print(\"\u540C\u3058\u70B9\u7FA4\u306B\u5BFE\u3057\u3066\u30AF\
    \u30A8\u30EA\u3092\u3084\u308A\u76F4\u305B\u308B\u3002\"); // abc233-h\r\n   \
    \ print(\"SMALL=true \u306B\u3059\u308B\u3068\u3001\u5EA7\u5727\u3092\u3057\u306A\
    \u3044\u305F\u3081\u5C11\u3057\u9AD8\u901F\");\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/rectanglesums.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/rectanglesums.hpp
layout: document
redirect_from:
- /library/other/rectanglesums.hpp
- /library/other/rectanglesums.hpp.html
title: other/rectanglesums.hpp
---
