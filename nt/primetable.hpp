constexpr ll isqrt(ll n) {
  ll x = n, y = (n + 1) / 2;
  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }
  return x;
}

template <int LIM = (1 << 20)>
pair<bitset<LIM>, vc<int>> primetable() {
  bitset<LIM> is_prime;
  const int S = (int)round(sqrt(LIM)), R = LIM / 2;
  vc<int> primes = {2}, sieve(S + 1);
  primes.reserve(int(LIM / log(LIM) * 1.1));
  vc<pi> cp;
  for (int i = 3; i <= S; i += 2) {
    if (!sieve[i]) {
      cp.eb(i, i * i / 2);
      for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
    }
  }
  for (int L = 1; L <= R; L += S) {
    array<bool, S> block{};
    for (auto& [p, idx]: cp)
      for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;
    FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);
  }
  for (auto&& i :primes) is_prime[i] = 1;
  return {is_prime, primes};
}
