vc<ll>& primetable(int LIM) {
  ++LIM;
  const int S = 32768;
  static int done = 2;
  static vc<ll> primes = {2}, sieve(S + 1);

  if(done >= LIM) return primes;
  done  = LIM;

  primes = {2}, sieve.assign(S + 1, 0);
  const int R = LIM / 2;  
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
  return primes;
}
