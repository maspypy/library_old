#include "graph/base.hpp"
#include "graph/check_bipartite.hpp"

template <typename Graph>
struct BipartiteMatching {
  int N;
  Graph& G;
  vc<int> color;
  vc<int> dist, match;
  vc<int> vis;

  BipartiteMatching(Graph& G) : G(G), N(G.N), dist(G.N, -1), match(G.N, -1) {
    color = check_bipartite(G);
    assert(color[0] != -1);
    while (1) {
      bfs();
      vis.assign(N, false);
      int flow = 0;
      FOR(v, N) if (!color[v] && match[v] == -1 && dfs(v))++ flow;
      if (!flow) break;
    }
  }

  void bfs() {
    dist.assign(N, -1);
    queue<int> que;
    FOR(v, N) if (!color[v] && match[v] == -1) que.emplace(v), dist[v] = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto&& e: G[v]) {
        int w = match[e.to];
        if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que.emplace(w);
      }
    }
  }

  bool dfs(int v) {
    vis[v] = 1;
    for (auto&& e: G[v]) {
      int w = match[e.to];
      if (w == -1 || (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {
        match[e.to] = v, match[v] = e.to;
        return true;
      }
    }
    return false;
  }

  vc<pair<int, int>> matching() {
    vc<pair<int, int>> res;
    FOR(v, N) if (v < match[v]) res.eb(v, match[v]);
    return res;
  }

  vc<int> vertex_cover() {
    vc<int> isin = color;
    FOR(v, N) if (!color[v] && dist[v] == -1) {
      isin[v] = 1;
      for (auto&& e: G[v]) isin[e.to] = 0;
    }
    vc<int> res;
    FOR(v, N) if (isin[v]) res.eb(v);
    return res;
  }

  vc<int> independent_set() {
    vc<int> isin = color;
    FOR(v, N) if (!color[v] && dist[v] == -1) {
      isin[v] = 1;
      for (auto&& e: G[v]) isin[e.to] = 0;
    }
    vc<int> res;
    FOR(v, N) if (!isin[v]) res.eb(v);
    return res;
  }

  vc<int> edge_cover() {
    vc<bool> done(N);
    vc<int> res;
    for (auto&& e: G.edges) {
      if (done[e.frm] || done[e.to]) continue;
      if (match[e.frm] == e.to) {
        res.eb(e.id);
        done[e.frm] = done[e.to] = 1;
      }
    }
    for (auto&& e: G.edges) {
      if (!done[e.frm]) {
        res.eb(e.id);
        done[e.frm] = 1;
      }
      if (!done[e.to]) {
        res.eb(e.id);
        done[e.to] = 1;
      }
    }
    sort(all(res));
    return res;
  }

  void debug() {
    print("match", match);
    print("min vertex covor", vertex_cover());
    print("max indep set", independent_set());
    print("min edge cover", edge_cover());
  }
};