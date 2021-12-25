template <typename T>
void centroid_decomposition(Graph<T>& G, function<void(vi&, vi&, vi&)> calc) {
  // V, par, dep に対する計算関数を渡す。

  ll N = G.N;
  vc<bool> DONE(N);
  vi sz(N);
  vi par(N);
  vi dep(N);

  auto find_centroid = [&](ll root) -> ll {
    vi V = {root};
    par[root] = -1;
    ll l = 0;
    while (l < V.size()) {
      ll v = V[l++];
      FORIN(e, G[v]) {
        ll to = e.to;
        if (to == par[v] || DONE[to]) continue;
        V.eb(to);
        par[to] = v;
      }
    }
    ll n = V.size();
    reverse(all(V));
    FORIN(v, V) sz[v] = 0;
    FORIN(v, V) {
      sz[v] += 1;
      if (n - sz[v] <= n / 2) return v;
      sz[par[v]] += sz[v];
    }
    assert(false);
    return root;
  };

  FOR(root, N) {
    while (!DONE[root]) {
      ll cent = find_centroid(root);
      vi V = {cent};
      par[cent] = -1;
      dep[cent] = 0;
      ll l = 0;
      while (l < V.size()) {
        ll v = V[l++];
        FORIN(e, G[v]) {
          ll to = e.to;
          if (to == par[v] || DONE[to]) continue;
          V.eb(to);
          par[to] = v;
          dep[to] = dep[v] + 1;
        }
      }
      DONE[cent] = true;
      calc(V, par, dep);
    }
  }
  return;
}
