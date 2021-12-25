struct QuotientGenerator {
  ll N;
  ll R;
  QuotientGenerator(ll N) : N(N), R(N){};
  operator bool() const { return R > 0; }
  tuple<ll, ll, ll> operator()() {
    ll q = N / R;
    ll L = N / (q + 1);
    tuple<ll, ll, ll> t = mt(q, L + 1, R + 1);
    R = L;
    return t;
  }
};