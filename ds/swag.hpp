template <typename T>
struct SWAG {
  using F = function<T(T, T)>;
  int L, R;
  F f;
  T e;
  vc<T>& dat;
  vc<T> cum_l;
  T cum_r;
  SWAG(F f, T e, vc<T>& dat)
      : L(0), R(0), f(f), e(e), dat(dat), cum_l({e}), cum_r(e) {}

  void push() { cum_r = f(cum_r, dat[R++]); }
  void pop() {
    cum_l.pop_back();
    ++L;
    if (len(cum_l) == 0) {
      cum_l = {e};
      FOR3_R(i, L, R) cum_l.eb(f(dat[i], cum_l.back()));
      cum_r = e;
    }
  }
  T fold(int l, int r) {
    assert(L <= l);
    assert(R <= r);
    while (R < r) push();
    while (L < l) pop();
    return f(cum_l.back(), cum_r);
  }
};
