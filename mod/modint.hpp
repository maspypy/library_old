template< int mod >
struct modint {
  int x;

  modint() : x(0) {}

  modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  modint &operator+=(const modint &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  modint &operator-=(const modint &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  modint &operator*=(const modint &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }

  modint operator-() const { return modint(-x); }

  modint operator+(const modint &p) const { return modint(*this) += p; }

  modint operator-(const modint &p) const { return modint(*this) -= p; }

  modint operator*(const modint &p) const { return modint(*this) *= p; }

  modint operator/(const modint &p) const { return modint(*this) /= p; }

  bool operator==(const modint &p) const { return x == p.x; }

  bool operator!=(const modint &p) const { return x != p.x; }

  modint inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return modint(u);
  }

  modint pow(int64_t n) const {
    modint ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const modint &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, modint &a) {
    int64_t t;
    is >> t;
    a = modint< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

template< typename T >
struct ModCalc {
  vector<T> _fact = {1, 1};
  vector<T> _fact_inv = {1, 1};
  vector<T> _inv = {0, 1};
  
  T pow(T a, int n){
    T x(1);
    while(n) {
      if(n & 1) x *= a;
      a *= a;
      n >>= 1;
    }
    return x;
  }
  void expand(int n){
    while(_fact.size() <= n){
      auto i = _fact.size();
      _fact.eb(_fact[i-1] * T(i));
      auto q = T::get_mod() / i, r = T::get_mod() % i;
      _inv.eb(_inv[r] * T(T::get_mod()-q));
      _fact_inv.eb(_fact_inv[i-1] * _inv[i]);
    }
  }

  T fact(int n){
    if(n >= _fact.size()) expand(n);
    return _fact[n];
  }

  T fact_inv(int n){
    if(n >= _fact.size()) expand(n);
    return _fact_inv[n];
  }
  
  T inv(int n){
    if(n >= _fact.size()) expand(n);
    return _inv[n];
  }
  
  T C(ll n, ll k, bool large=false){
    assert(n >= 0);
    if (k < 0 || n < k) return 0;
    if (!large) return fact(n) * fact_inv(k) * fact_inv(n-k);
    k = min(k, n-k);
    T x(1);
    FOR(i, k){
      x *= n - i;
      x *= inv(i + 1);
    }
    return x;
  }
};

using modint107 = modint<1'000'000'007>;
using modint998 = modint<998'244'353>;
