vc<pi> maximal_rectangles(vector<ll> H) {
  /*
  高さ H[i] のヒストグラムが与えられる。各 i に対して、
  i 番目の bar を含む極大長方形を返す。極大長方形が [l,r) x [0,H[i]]
  のときに、pair (l, r) を入れる。
  */
  ll N = len(H);
  vc<pi> LR(N);
  vi st;
  FOR(i, N) {
    while (!st.empty() && H[st.back()] >= H[i]) st.pop_back();
    LR[i].fi = (st.empty() ? 0 : st.back() + 1);
    st.eb(i);
  }
  st.clear();
  FOR_R(i, N) {
    while (!st.empty() && H[st.back()] >= H[i]) st.pop_back();
    LR[i].se = (st.empty() ? N : st.back());
    st.eb(i);
  }
  return LR;
}
