tuple<ll, ll, ll, ll> Farey_lr(ll a, ll b) {
  assert(a > 0 && b > 0);
  /*
  Farey 数列で、a/b が最初に現れるときの、左右を求める。
  a/b = 19/12 → (x1/y1, x2/y2) = (11/7, 8/5) → (11,7,8,5) を返す。
  */
  if (a == b)
    return {0, 1, 1, 0};
  ll q = (a - 1) / b;
  auto [x1, y1, x2, y2] = Farey_lr(b, a - q * b);
  return {q * x2 + y2, x2, q * x1 + y1, x1};
}

tuple<ll, ll, ll> extgcd(ll a, ll b) {
  assert(a > 0);
  // ax - by = d の最小解 (x, y, d) を返す。
  if (b == 0)
    return {1, 0, a};
  auto [x1, y1, x2, y2] = Farey_lr(a, b);
  ll d = a / (x1 + x2);
  return {y1, x1, d};
}

