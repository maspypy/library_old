const ll INF = 1LL << 40;

struct CntSumMinMax {
  struct X {
    ll cnt, sum, min, max, minc, maxc, min2, max2;
    bool fail;
  };
  using value_type = X;
  static X op(const X& x, const X& y) {
    if (x.min > x.max) return y;
    if (y.min > y.max) return x;
    X z;
    z.cnt = x.cnt + y.cnt, z.sum = x.sum + y.sum;

    z.min = min(x.min, y.min), z.max = max(x.max, y.max);
    z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);
    z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);

    z.min2 = z.max;
    if (z.min < x.min && x.min < z.min2) z.min2 = x.min;
    if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;
    if (z.min < y.min && y.min < z.min2) z.min2 = y.min;
    if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;

    z.max2 = z.min;
    if (z.max > x.max && x.max > z.max2) z.max2 = x.max;
    if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;
    if (z.max > y.max && y.max > z.max2) z.max2 = y.max;
    if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;

    z.fail = 0;
    return z;
  }
  static constexpr X unit = {0, 0, INF, -INF, 0, 0, INF, -INF, 0};
  bool commute = true;
};

struct AddChminChmax {
  struct X {
    ll add, min, max;
  };
  using value_type = X;
  static constexpr X op(const X& x, const X& y) {
    auto [a, b, c] = x;
    auto [d, e, f] = y;
    a += d, b += d, c += d;
    b = min(b, e), c = min(c, e);
    c = max(c, f);
    return {a, b, c};
  }
  static constexpr X unit = {0, INF, -INF};
  bool commute = false;
};

struct Lazy {
  using MX = CntSumMinMax;
  using MA = AddChminChmax;
  using X_structure = MX;
  using A_structure = MA;
  using X = MX::value_type;
  using A = MA::value_type;
  static X act(X& x, const A& a) {
    assert(!x.fail);
    if (x.cnt == 0) return x;
    x.sum += x.cnt * a.add;
    x.min += a.add, x.max += a.add;
    x.min2 += a.add, x.max2 += a.add;

    if (a.min == INF && a.max == -INF) return x;

    ll before_min = x.min, before_max = x.max;
    chmin(x.min, a.min), chmax(x.min, a.max);
    chmin(x.max, a.min), chmax(x.max, a.max);

    if (x.min == x.max) {
      x.sum = x.max * x.cnt;
      x.max2 = x.min2 = x.max;
      x.maxc = x.minc = x.cnt;
    }
    elif (x.max2 <= x.min) {
      x.max2 = x.min, x.min2 = x.max;
      x.minc = x.cnt - x.maxc;
      x.sum = x.max * x.maxc + x.min * x.minc;
    }
    elif (x.min2 >= x.max) {
      x.max2 = x.min, x.min2 = x.max;
      x.maxc = x.cnt - x.minc;
      x.sum = x.max * x.maxc + x.min * x.minc;
    }
    elif (x.min < x.min2 && x.max > x.max2) {
      x.sum += (x.min - before_min) * x.minc;
      x.sum += (x.max - before_max) * x.maxc;
    }
    else {
      x.fail = 1;
    }
    return x;
  }
};
