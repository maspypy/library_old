struct BipartiteMatching {
  int n, m;
  vector<vector<int>> graph;
  vector<int> dist, match;
  vector<bool> used, vv;
  bool calculated;

  BipartiteMatching(int n, int m)
      : n(n), m(m), graph(n), match(m, -1), used(n), calculated(false) {}

  void add(int u, int v) {
    graph[u].push_back(v);
    calculated = false;
  }

  void bfs() {
    dist.assign(graph.size(), -1);
    queue<int> que;
    for (int i = 0; i < graph.size(); i++) {
      if (!used[i]) {
        que.emplace(i);
        dist[i] = 0;
      }
    }

    while (!que.empty()) {
      int a = que.front();
      que.pop();
      for (auto &b : graph[a]) {
        int c = match[b];
        if (c >= 0 && dist[c] == -1) {
          dist[c] = dist[a] + 1;
          que.emplace(c);
        }
      }
    }
  }

  bool dfs(int a) {
    vv[a] = true;
    for (auto &b : graph[a]) {
      int c = match[b];
      if (c < 0 || (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {
        match[b] = a;
        used[a] = true;
        return (true);
      }
    }
    return (false);
  }

  void calc() {
    if (calculated) return;
    while (true) {
      bfs();
      vv.assign(graph.size(), false);
      int flow = 0;
      for (int i = 0; i < graph.size(); i++) {
        if (!used[i] && dfs(i)) ++flow;
      }
      if (flow == 0) break;
    }
    calculated = true;
  }

  vector<pair<int, int>> max_matching() {
    calc();
    vector<pair<int, int>> matching;
    FOR(r, m) {
      if (match[r] != -1) matching.eb(match[r], r);
    }
    return matching;
  }

  pair<vector<int>, vector<int>> min_vertex_cover() {
    calc();
    vector<bool> covered(m);
    vector<int> A, B;
    FOR(l, n) if (dist[l] != -1) {
      A.eb(l);
      FORIN(r, graph[l]) covered[r] = true;
    }
    FOR(r, m) if (!covered[r]) B.eb(r);
    return {A, B};
  }

  pair<vector<int>, vector<int>> max_independent_set() {
    calc();
    vector<bool> covered(m);
    vector<int> A, B;
    FOR(l, n) if (dist[l] != -1) {
      A.eb(l);
      FORIN(r, graph[l]) covered[r] = true;
    }
    FOR(l, n) if (dist[l] == -1) A.eb(l);
    FOR(r, m) if (covered[r]) B.eb(r);
    return {A, B};
  }

  vector<pair<int, int>> min_edge_cover() {
    auto E = max_matching();
    vector<bool> done_l(n), done_r(m);
    for (auto &&[l, r] : E) { done_l[l] = done_r[r] = true; }
    FOR(l, n) FORIN(r, graph[l]) {
      if (!done_l[l]) E.eb(l, r);
      if (!done_r[r]) E.eb(l, r);
      done_l[l] = done_r[r] = true;
    }
    FOR(l, n) if (!done_l[l]) return {};
    FOR(r, m) if (!done_r[r]) return {};
    return E;
  }
};
