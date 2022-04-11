template <class Monoid>
struct DisjointSparse {
  using X = typename Monoid::value_type;
  using value_type = X;
  int n, log;
  vc<X> dat;

  DisjointSparse(const vc<X>& A) : n(len(A)) {
    log = 1;
    while ((1 << log) < n) ++log;
    dat.reserve(log * n);
    FOR(i, log) FOR(j, n) dat.eb(A[j]);

    FOR(i, log) {
      int s = n * i;
      int b = 1 << i;
      for (int m = b; m <= n; m += 2 * b) {
        int L = m - b, R = min(n, m + b);
        FOR3_R(j, L + 1, m) {
          dat[s + j - 1] = Monoid::op(dat[s + j - 1], dat[s + j]);
        }
        FOR3(j, m, R - 1) {
          dat[s + j + 1] = Monoid::op(dat[s + j], dat[s + j + 1]);
        }
      }
    }
  }

  X prod(int L, int R) {
    if (L == R) return Monoid::unit();
    --R;
    if (L == R) return dat[L];
    int k = 31 - __builtin_clz(L ^ R);
    return Monoid::op(dat[n * k + L], dat[n * k + R]);
  }

  void debug() {
    print("disjoint sparse table");
    FOR(i, log) {
      vc<X> tmp = {dat.begin() + n * i, dat.begin() + n * (i + 1)};
      print(tmp);
    }
  }
};
