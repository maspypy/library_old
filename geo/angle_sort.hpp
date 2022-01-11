bool is_lower_plane(pair<ll, ll> P) {
  return (P.se < 0) || (P.se == 0 && P.fi < 0);
}

vector<int> angle_sort(vector<pair<ll, ll>>& XY) {
  vector<int> lower, origin, upper;
  pair<ll, ll> O = mp(0, 0);
  FOR(i, len(XY)) {
    if (XY[i] == O) origin.eb(i);
    elif (is_lower_plane(XY[i])) lower.eb(i);
    else upper.eb(i);
  }
  sort(all(lower), [&](auto& i, auto& j) {
    return XY[i].fi * XY[j].se > XY[j].fi * XY[i].se;
  });
  sort(all(upper), [&](auto& i, auto& j) {
    return XY[i].fi * XY[j].se > XY[j].fi * XY[i].se;
  });
  auto& I = lower;
  I.insert(I.end(), all(origin));
  I.insert(I.end(), all(upper));
  return I;
}
