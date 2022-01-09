template <class T, is_modint_t<T>* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  // mod をとる回数を減らしてみる
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(T, C, N, K);
  const ull MOD2 = 8ull * T::get_mod() * T::get_mod();
  FOR(n, N) {
    vc<ull> tmp(K);
    FOR(m, M) FOR(k, K) {
      tmp[k] += ull(A[n][m].val) * B[m][k].val;
      if (tmp[k] >= MOD2) tmp[k] -= MOD2;
    }
    FOR(k, K) C[n][k] = tmp[k];
  }
  return C;
}

template <class T, is_not_modint_t<T>* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(T, C, N, K);
  FOR(n, N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];
  return C;
}
