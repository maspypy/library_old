struct Mo {
  using ADD = function<void(int)>;
  using RM = function<void(int)>;
  using CALC = function<void(int)>;

  int width;
  vector<int> left, right, order;
  vector<bool> v;

  Mo(int N, int Q) : width((int)sqrt(N)), order(Q), v(N) {
    iota(begin(order), end(order), 0);
  }

  void add(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  void run(const ADD& add, const RM& rm, const CALC& calc) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if (ablock != bblock) return ablock < bblock;
      if (ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    auto push = [&](int idx) {
      v[idx].flip();
      if (v[idx])
        add(idx);
      else
        rm(idx);
    };
    for (auto idx : order) {
      while (nl > left[idx]) push(--nl);
      while (nr < right[idx]) push(nr++);
      while (nl < left[idx]) push(nl++);
      while (nr > right[idx]) push(--nr);
      calc(idx);
    }
  }
};
