#pragma once

// frm, to, cap, cost
template <typename T>
struct Edge{
  int frm, to;
  T cost;
  int id;
};

template <typename T, bool directed = false>
struct Graph {
  int N, M;
  using cost_type = T;
  using edge_type = Edge<T>;
  vector<edge_type> edges;
  vector<int> indptr;
  vector<edge_type> csr_edges;
  bool prepared;

  class OutgoingEdges {
  public:
    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}

    const edge_type* begin() const {
      if (l == r) { return 0; }
      return &G->csr_edges[l];
    }

    const edge_type* end() const {
      if (l == r) { return 0; }
      return &G->csr_edges[r];
    }

  private:
    int l, r;
    const Graph* G;
  };

  bool is_prepared() { return prepared; }
  constexpr bool is_directed() { return directed; }

  Graph() {}
  Graph(int N) : N(N), M(0), prepared(0) {}

  void add(int frm, int to, T cost = 1, int i = -1) {
    assert(!prepared);
    assert(0 <= frm && frm < N && 0 <= to && to < N);
    if (i == -1) i = M;
    auto e = edge_type({frm, to, cost, i});
    edges.eb(e);
    ++M;
  }

  void prepare() {
    assert(!prepared);
    prepared = true;
    indptr.assign(N + 1, 0);
    for (auto&& [frm, to, cost, id]: edges) {
      indptr[frm + 1]++;
      if (!directed) indptr[to + 1]++;
    }
    FOR(v, N) indptr[v + 1] += indptr[v];
    auto counter = indptr;
    csr_edges.resize(indptr.back() + 1);
    for (auto&& [frm, to, cost, id]: edges) {
      csr_edges[counter[frm]++] = {frm, to, cost, id};
      if (!directed) csr_edges[counter[to]++] = {to, frm, cost, id};
    }
  }

  OutgoingEdges operator[](int v) const {
    assert(prepared);
    return {this, indptr[v], indptr[v + 1]};
  }

  void debug() {
    print("Graph");
    if (!prepared) {
      print("frm to cost id");
      for (auto&& e: edges) print(e);
    } else {
      print("indptr", indptr);
      print("frm to cost id");
      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);
    }
  }

  int size() { return N; }
};
