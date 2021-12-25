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
  bundledCode: "#line 1 \"graph/centroiddecomp.hpp\"\ntemplate <typename T>\r\nvoid\
    \ centroid_decomposition(Graph<T>& G, function<void(vi&, vi&, vi&)> calc) {\r\n\
    \  // V, par, dep \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u95A2\u6570\u3092\u6E21\
    \u3059\u3002\r\n\r\n  ll N = G.N;\r\n  vc<bool> DONE(N);\r\n  vi sz(N);\r\n  vi\
    \ par(N);\r\n  vi dep(N);\r\n\r\n  auto find_centroid = [&](ll root) -> ll {\r\
    \n    vi V = {root};\r\n    par[root] = -1;\r\n    ll l = 0;\r\n    while (l <\
    \ V.size()) {\r\n      ll v = V[l++];\r\n      FORIN(e, G[v]) {\r\n        ll\
    \ to = e.to;\r\n        if (to == par[v] || DONE[to]) continue;\r\n        V.eb(to);\r\
    \n        par[to] = v;\r\n      }\r\n    }\r\n    ll n = V.size();\r\n    reverse(all(V));\r\
    \n    FORIN(v, V) sz[v] = 0;\r\n    FORIN(v, V) {\r\n      sz[v] += 1;\r\n   \
    \   if (n - sz[v] <= n / 2) return v;\r\n      sz[par[v]] += sz[v];\r\n    }\r\
    \n    assert(false);\r\n    return root;\r\n  };\r\n\r\n  FOR(root, N) {\r\n \
    \   while (!DONE[root]) {\r\n      ll cent = find_centroid(root);\r\n      vi\
    \ V = {cent};\r\n      par[cent] = -1;\r\n      dep[cent] = 0;\r\n      ll l =\
    \ 0;\r\n      while (l < V.size()) {\r\n        ll v = V[l++];\r\n        FORIN(e,\
    \ G[v]) {\r\n          ll to = e.to;\r\n          if (to == par[v] || DONE[to])\
    \ continue;\r\n          V.eb(to);\r\n          par[to] = v;\r\n          dep[to]\
    \ = dep[v] + 1;\r\n        }\r\n      }\r\n      DONE[cent] = true;\r\n      calc(V,\
    \ par, dep);\r\n    }\r\n  }\r\n  return;\r\n}\r\n"
  code: "template <typename T>\r\nvoid centroid_decomposition(Graph<T>& G, function<void(vi&,\
    \ vi&, vi&)> calc) {\r\n  // V, par, dep \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u95A2\
    \u6570\u3092\u6E21\u3059\u3002\r\n\r\n  ll N = G.N;\r\n  vc<bool> DONE(N);\r\n\
    \  vi sz(N);\r\n  vi par(N);\r\n  vi dep(N);\r\n\r\n  auto find_centroid = [&](ll\
    \ root) -> ll {\r\n    vi V = {root};\r\n    par[root] = -1;\r\n    ll l = 0;\r\
    \n    while (l < V.size()) {\r\n      ll v = V[l++];\r\n      FORIN(e, G[v]) {\r\
    \n        ll to = e.to;\r\n        if (to == par[v] || DONE[to]) continue;\r\n\
    \        V.eb(to);\r\n        par[to] = v;\r\n      }\r\n    }\r\n    ll n = V.size();\r\
    \n    reverse(all(V));\r\n    FORIN(v, V) sz[v] = 0;\r\n    FORIN(v, V) {\r\n\
    \      sz[v] += 1;\r\n      if (n - sz[v] <= n / 2) return v;\r\n      sz[par[v]]\
    \ += sz[v];\r\n    }\r\n    assert(false);\r\n    return root;\r\n  };\r\n\r\n\
    \  FOR(root, N) {\r\n    while (!DONE[root]) {\r\n      ll cent = find_centroid(root);\r\
    \n      vi V = {cent};\r\n      par[cent] = -1;\r\n      dep[cent] = 0;\r\n  \
    \    ll l = 0;\r\n      while (l < V.size()) {\r\n        ll v = V[l++];\r\n \
    \       FORIN(e, G[v]) {\r\n          ll to = e.to;\r\n          if (to == par[v]\
    \ || DONE[to]) continue;\r\n          V.eb(to);\r\n          par[to] = v;\r\n\
    \          dep[to] = dep[v] + 1;\r\n        }\r\n      }\r\n      DONE[cent] =\
    \ true;\r\n      calc(V, par, dep);\r\n    }\r\n  }\r\n  return;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/centroiddecomp.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/centroiddecomp.hpp
layout: document
redirect_from:
- /library/graph/centroiddecomp.hpp
- /library/graph/centroiddecomp.hpp.html
title: graph/centroiddecomp.hpp
---
