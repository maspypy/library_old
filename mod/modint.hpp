template <int mod>
struct modint {
  int val;

  constexpr modint(const ll val = 0) noexcept
      : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}

  bool operator<(const modint &other) const {
    return val < other.val;
  } // To use std::map

  modint &operator+=(const modint &p) {
    if ((val += p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += mod - p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = (int)(1LL * val * p.val % mod);
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint(-val); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }

  modint inverse() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return modint(u);
  }

  modint pow(int64_t n) const {
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const modint &p) { return os << p.val; }
  static int get_mod() { return mod; }
};

template <typename T>
struct ModCalc {
  vector<T> _fact = {1, 1};
  vector<T> _fact_inv = {1, 1};
  vector<T> _inv = {0, 1};

  T pow(T a, int n) {
    T x(1);
    while (n) {
      if (n & 1) x *= a;
      a *= a;
      n >>= 1;
    }
    return x;
  }
  void expand(int n) {
    while (_fact.size() <= n) {
      auto i = _fact.size();
      _fact.eb(_fact[i - 1] * T(i));
      auto q = T::get_mod() / i, r = T::get_mod() % i;
      _inv.eb(_inv[r] * T(T::get_mod() - q));
      _fact_inv.eb(_fact_inv[i - 1] * _inv[i]);
    }
  }

  T fact(int n) {
    if (n >= _fact.size()) expand(n);
    return _fact[n];
  }

  T fact_inv(int n) {
    if (n >= _fact.size()) expand(n);
    return _fact_inv[n];
  }

  T inv(int n) {
    if (n >= _fact.size()) expand(n);
    return _inv[n];
  }

  T C(ll n, ll k, bool large = false) {
    assert(n >= 0);
    if (k < 0 || n < k) return 0;
    if (!large) return fact(n) * fact_inv(k) * fact_inv(n - k);
    k = min(k, n - k);
    T x(1);
    FOR(i, k) {
      x *= n - i;
      x *= inv(i + 1);
    }
    return x;
  }
};

using modint107 = modint<1'000'000'007>;
using modint998 = modint<998'244'353>;
