#pragma once

template <typename T>
struct Edge {
  int frm, to;
  T cost;
  int id;
  Edge(int a, int b, T c, int d) : frm(a), to(b), cost(c), id(d) {}
};

template <typename T, bool directed = false>
struct Graph {
  int N, M;
  using value_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<vector<edge_type>> G;
  Graph() {}
  Graph(int N) : N(N), M(0), G(N), directed(bl) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    if (i == -1) i = M;
    auto e = edge_type(frm, to, cost, i);
    edges.eb(e);
    G[frm].eb(e);
    if (!directed) {
      auto e_rev = edge_type(to, frm, cost, i);
      G[to].eb(e_rev);
    }
    ++M;
  }

  void debug(bool detail = false) {
    FOR(v, N) {
      cout << v << " :";
      for (auto e: G[v]) {
        if (detail)
          cout << " (" << e.frm << "," << e.to << "," << e.cost << "," << e.id
               << ")";
        else
          cout << " " << e.to;
      }
      cout << "\n";
    }
  }
  int size() { return N; }

  vector<edge_type>& operator[](int v) { return G[v]; }
};
