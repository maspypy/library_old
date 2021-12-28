template <typename Graph>
vc<int> cycle_detection(Graph& G, bool is_edge) {
  assert(G.prepared);
  assert(G::directed);
  if (!is_edge) {
    auto C = cycle_detection(G, true);
    if (len(C) == 0) return C;
    vc<int> ANS(len(C) + 1);
    FOR(i, len(C)) {
      auto e = G.edges[C[i]];
      ANS[i + 0] = get<0>(e);
      ANS[i + 1] = get<1>(e);
    }
    return ANS;
  }

  int N = G.N;
  vc<int> used(N);
  vc<int> path; // edge
  vc<pair<int, int>> par(N);
  vector<int> ANS;

  auto dfs = [&](auto self, int v) -> void {
    used[v] = 1;
    for (auto&& [frm, to, cost, id] : G[v]) {
      if (len(ANS)) return;
      if (!used[to]) {
        par[to] = {v, id};
        self(self, to);
      }
      elif (used[to] == 1) {
        ANS = {id};
        int cur = v;
        while (cur != to) {
          ANS.eb(par[cur].se);
          cur = par[cur].fi;
        }
        reverse(all(ANS));
        return;
      }
    }
    used[v] = 2;
  };
  FOR(v, N) if (!used[v]) dfs(dfs, v);
  return ANS;
}