#pragma once

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c), id(d) {}
};

template <typename T>
struct Graph {
  int N, M;
  using edge_t = Edge<T>;
  vector<edge_t> edges;
  vector<vector<edge_t>> G;
  bool directed;
  Graph() {}
  Graph(int N, bool bl = false) : N(N), M(0), G(N), directed(bl) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    if (i == -1) i = M;
    auto e = edge_t(frm, to, cost, i);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_t(to, frm, cost, i);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void debug(bool detail = false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e: G[v]) {
        if (detail)
          cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id << ")";
        else
          cout << " " << e.to;
      }
      cout << "\n";
    }
  }

  vector<int> degrees() {
    vector<int> deg(N);
    for (auto&& e: edges) {
      deg[e.frm]++;
      deg[e.to]++;
    }
    return deg;
  }

  int size() { return N; }

  vector<edge_t>& operator[](int v) { return G[v]; }
};
