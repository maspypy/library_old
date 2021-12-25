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
  bundledCode: "#line 1 \"ds/binarytrie.hpp\"\ntemplate <int dep>\nstruct BinaryTrie\
    \ {\n  struct Node {\n    ll cnt;\n    int ch[2];\n    Node() {\n      cnt = 0;\n\
    \      ch[0] = ch[1] = -1;\n    }\n  };\n\n  vector<Node> data;\n  BinaryTrie()\
    \ { data.eb(Node()); }\n\n  void insert(ll x, ll cnt = 1) {\n    int p = 0;\n\
    \    for (int i = dep - 1; i >= 0; --i) {\n      data[p].cnt += cnt;\n      int\
    \ e = (x >> i) & 1;\n      if (data[p].ch[e] == -1) {\n        data[p].ch[e] =\
    \ data.size();\n        data.eb(Node());\n      }\n      p = data[p].ch[e];\n\
    \    }\n    data[p].cnt += cnt;\n  }\n\n  ll lower_bound(ll x, ll xor_val = 0)\
    \ {\n    // xor \u3057\u305F\u7D50\u679C\u3001x \u672A\u6E80\u304C\u3044\u304F\
    \u3064\u306B\u306A\u308B\u304B\n    int p = 0;\n    ll ret = 0;\n    for (int\
    \ i = dep - 1; i >= 0; i--) {\n      int e = (x >> i) & 1;\n      int f = (xor_val\
    \ >> i) & 1;\n      if (e != f && data[p].ch[f] != -1) ret += data[data[p].ch[f]].cnt;\n\
    \      if (data[p].ch[e] == -1) break;\n      p = data[p].ch[e];\n    }\n    return\
    \ ret;\n  }\n\n  ll find_kth(ll k, ll xor_val = 0) {\n    if (k <= 0 || data[0].cnt\
    \ < k) return -1;\n    int p = 0;\n    ll ret = 0;\n    for (int i = dep - 1;\
    \ i >= 0; --i) {\n      int e = (xor_val >> i) & 1;\n      if (data[p].ch[e] ==\
    \ -1 || data[data[p].ch[e]].cnt < k) {\n        k -= (data[p].ch[e] == -1 ? 0\
    \ : data[data[p].ch[e]].cnt);\n        e ^= 1;\n      }\n      p = data[p].ch[e];\n\
    \      ret |= (ll(e)) << i;\n    }\n    return ret;\n  }\n};\n"
  code: "template <int dep>\nstruct BinaryTrie {\n  struct Node {\n    ll cnt;\n \
    \   int ch[2];\n    Node() {\n      cnt = 0;\n      ch[0] = ch[1] = -1;\n    }\n\
    \  };\n\n  vector<Node> data;\n  BinaryTrie() { data.eb(Node()); }\n\n  void insert(ll\
    \ x, ll cnt = 1) {\n    int p = 0;\n    for (int i = dep - 1; i >= 0; --i) {\n\
    \      data[p].cnt += cnt;\n      int e = (x >> i) & 1;\n      if (data[p].ch[e]\
    \ == -1) {\n        data[p].ch[e] = data.size();\n        data.eb(Node());\n \
    \     }\n      p = data[p].ch[e];\n    }\n    data[p].cnt += cnt;\n  }\n\n  ll\
    \ lower_bound(ll x, ll xor_val = 0) {\n    // xor \u3057\u305F\u7D50\u679C\u3001\
    x \u672A\u6E80\u304C\u3044\u304F\u3064\u306B\u306A\u308B\u304B\n    int p = 0;\n\
    \    ll ret = 0;\n    for (int i = dep - 1; i >= 0; i--) {\n      int e = (x >>\
    \ i) & 1;\n      int f = (xor_val >> i) & 1;\n      if (e != f && data[p].ch[f]\
    \ != -1) ret += data[data[p].ch[f]].cnt;\n      if (data[p].ch[e] == -1) break;\n\
    \      p = data[p].ch[e];\n    }\n    return ret;\n  }\n\n  ll find_kth(ll k,\
    \ ll xor_val = 0) {\n    if (k <= 0 || data[0].cnt < k) return -1;\n    int p\
    \ = 0;\n    ll ret = 0;\n    for (int i = dep - 1; i >= 0; --i) {\n      int e\
    \ = (xor_val >> i) & 1;\n      if (data[p].ch[e] == -1 || data[data[p].ch[e]].cnt\
    \ < k) {\n        k -= (data[p].ch[e] == -1 ? 0 : data[data[p].ch[e]].cnt);\n\
    \        e ^= 1;\n      }\n      p = data[p].ch[e];\n      ret |= (ll(e)) << i;\n\
    \    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/binarytrie.hpp
  requiredBy: []
  timestamp: '2021-12-25 22:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/binarytrie.hpp
layout: document
redirect_from:
- /library/ds/binarytrie.hpp
- /library/ds/binarytrie.hpp.html
title: ds/binarytrie.hpp
---
