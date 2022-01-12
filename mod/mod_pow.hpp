ll mod_pow(ll a, ll n, int mod){
  a %= mod;
  ll p = a;
  ll v = 1;
  while(n){
    if(n & 1) v = v * p % mod;
    p = p * p % mod;
    n >>= 1;
  }
  return v;
}