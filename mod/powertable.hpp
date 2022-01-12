#include "nt/primetable.hpp"

template<typename mint>
vc<mint> powertable_1(mint a, ll N) {
  // table of a^i
  vc<mint> f(N, 1);
  FOR(i, N - 1) f[i + 1] = a * f[i];
  return f;
}

template<typename mint, int LIM>
vc<mint> powertable_2(ll e, ll N) {
  // table of i^e. LIM 以下の素数テーブルを利用する. 
  auto primes = primetable<LIM>();
  vc<mint> f(N, 1);
  f[0] = mint(0).pow(e);
  for(auto&& p : primes){
    mint xp = mint(p).pow(e);
    ll pp = p;
    while(pp < N){
      ll i = pp;
      while(i < N){
        f[i] *= xp;
        i += pp;
      }
      pp *= p;
    }
  }
  return f;
}

