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
  bundledCode: "#line 1 \"geo/angle_sort.hpp\"\nbool is_lower_plane(pair<ll, ll> P)\
    \ {\r\n  return (P.se < 0) || (P.se == 0 && P.fi < 0);\r\n}\r\n\r\nvector<int>\
    \ angle_sort(vector<pair<ll, ll>>& XY) {\r\n  vector<int> lower, origin, upper;\r\
    \n  pair<ll, ll> O = mp(0, 0);\r\n  FOR(i, len(XY)) {\r\n    if (XY[i] == O) origin.eb(i);\r\
    \n    elif (is_lower_plane(XY[i])) lower.eb(i);\r\n    else upper.eb(i);\r\n \
    \ }\r\n  sort(all(lower), [&](auto& i, auto& j) {\r\n    return XY[i].fi * XY[j].se\
    \ > XY[j].fi * XY[i].se;\r\n  });\r\n  sort(all(upper), [&](auto& i, auto& j)\
    \ {\r\n    return XY[i].fi * XY[j].se > XY[j].fi * XY[i].se;\r\n  });\r\n  auto&\
    \ I = lower;\r\n  I.insert(I.end(), all(origin));\r\n  I.insert(I.end(), all(upper));\r\
    \n  return I;\r\n}\r\n"
  code: "bool is_lower_plane(pair<ll, ll> P) {\r\n  return (P.se < 0) || (P.se ==\
    \ 0 && P.fi < 0);\r\n}\r\n\r\nvector<int> angle_sort(vector<pair<ll, ll>>& XY)\
    \ {\r\n  vector<int> lower, origin, upper;\r\n  pair<ll, ll> O = mp(0, 0);\r\n\
    \  FOR(i, len(XY)) {\r\n    if (XY[i] == O) origin.eb(i);\r\n    elif (is_lower_plane(XY[i]))\
    \ lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto&\
    \ i, auto& j) {\r\n    return XY[i].fi * XY[j].se > XY[j].fi * XY[i].se;\r\n \
    \ });\r\n  sort(all(upper), [&](auto& i, auto& j) {\r\n    return XY[i].fi * XY[j].se\
    \ > XY[j].fi * XY[i].se;\r\n  });\r\n  auto& I = lower;\r\n  I.insert(I.end(),\
    \ all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return I;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/angle_sort.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/angle_sort.hpp
layout: document
redirect_from:
- /library/geo/angle_sort.hpp
- /library/geo/angle_sort.hpp.html
title: geo/angle_sort.hpp
---
