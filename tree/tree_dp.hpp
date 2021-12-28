template <typename E, typename F1, typename F2, typename F3, typename T>
pair<vc<T>, vc<T>> tree_dp(E& ET, F1 f_ee, F2 f_ev, F3 f_ve, T unit) {
  auto& V = ET.V;
  auto& G = ET.G;
  auto& par = ET.parent;
  ll N = len(V);
  vc<T> dp_v(N), dp_e(N);
  FOR_R(i, N) {
    auto v = V[i];
    T dp = unit;
    FORIN(e, G[v]) if (e.to != par[v]) {
      dp_e[e.to] = f_ve(dp_v[e.to], e.id);
      dp = f_ee(dp, dp_e[e.to]);
    }
    dp_v[v] = f_ev(dp, v);
  }
  return {dp_v, dp_e};
}
