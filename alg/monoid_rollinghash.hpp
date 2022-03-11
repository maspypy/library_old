struct Monoid_Rolling_Hash {
  using value_type = pi; // pow of base, val
  using X = value_type;
  static constexpr ll M61 = (1LL << 61) - 1;
  static ll add(ll a, ll b) {
    if ((a += b) >= M61) a -= M61;
    return a;
  }
  static ll mul(ll a, ll b) {
    const ll MASK30 = (1LL << 30) - 1;
    const ll MASK31 = (1LL << 31) - 1;
    const ll MASK61 = (1LL << 61) - 1;
    ll au = a >> 31, ad = a & MASK31;
    ll bu = b >> 31, bd = b & MASK31;
    ll x = ad * bu + au * bd;
    ll xu = x >> 30, xd = x & MASK30;
    x = au * bu * 2 + xu + (xd << 31) + ad * bd;
    xu = x >> 61, xd = x & MASK61;
    x = xu + xd;
    if (x >= MASK61) x -= MASK61;
    return x;
  }
  static X op(X x, X y) {
    return {mul(x.fi, y.fi), add(mul(x.se, y.fi), y.se)};
  }
  static constexpr X unit = X(1, 0);
  static constexpr bool commute = false;
};