template <int dep>
struct BinaryTrie {
  struct Node {
    ll cnt;
    int ch[2];
    Node() {
      cnt = 0;
      ch[0] = ch[1] = -1;
    }
  };

  vector<Node> data;
  BinaryTrie() { data.eb(Node()); }

  void insert(ll x, ll cnt = 1) {
    int p = 0;
    for (int i = dep - 1; i >= 0; --i) {
      data[p].cnt += cnt;
      int e = (x >> i) & 1;
      if (data[p].ch[e] == -1) {
        data[p].ch[e] = data.size();
        data.eb(Node());
      }
      p = data[p].ch[e];
    }
    data[p].cnt += cnt;
  }

  ll lower_bound(ll x, ll xor_val = 0) {
    // xor した結果、x 未満がいくつになるか
    int p = 0;
    ll ret = 0;
    for (int i = dep - 1; i >= 0; i--) {
      int e = (x >> i) & 1;
      int f = (xor_val >> i) & 1;
      if (e != f && data[p].ch[f] != -1) ret += data[data[p].ch[f]].cnt;
      if (data[p].ch[e] == -1) break;
      p = data[p].ch[e];
    }
    return ret;
  }

  ll find_kth(ll k, ll xor_val = 0) {
    if (k <= 0 || data[0].cnt < k) return -1;
    int p = 0;
    ll ret = 0;
    for (int i = dep - 1; i >= 0; --i) {
      int e = (xor_val >> i) & 1;
      if (data[p].ch[e] == -1 || data[data[p].ch[e]].cnt < k) {
        k -= (data[p].ch[e] == -1 ? 0 : data[data[p].ch[e]].cnt);
        e ^= 1;
      }
      p = data[p].ch[e];
      ret |= (ll(e)) << i;
    }
    return ret;
  }
};
