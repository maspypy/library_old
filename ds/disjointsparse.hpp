#include "algebra/monoid.hpp"

template <typename E>
struct DisjointSparse {
  using F = function<E(E, E)>;
  F f;
  E e;
  int N, log;
  vc<vc<E>> dat;

  DisjointSparse(Monoid<E> Mono, vc<E> A) : f(Mono.f), e(Mono.unit), N(len(A)) {
    log = 1;
    while ((1 << log) < N) ++log;
    dat.assign(log, A);

    FOR(i, log) {
      auto& v = dat[i];
      int B = 1 << i;
      for (int M = B; M <= N; M += 2 * B) {
        int L = M - B, R = min(N, M + B);
        FOR3_R(j, L + 1, M) v[j - 1] = f(v[j - 1], v[j]);
        FOR3(j, M, R - 1) v[j + 1] = f(v[j], v[j + 1]);
      }
    }
  }

  E prod(int L, int R) {
    if (L == R) return e;
    --R;
    if (L == R) return dat[0][L];
    int k = 31 - __builtin_clz(L ^ R);
    return f(dat[k][L], dat[k][R]);
  }

  void debug() { FOR(i, log) print(dat[i]); }
};