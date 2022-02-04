struct Point {
  ll x, y;
  Point(ll x=0, ll y=0) : x(x), y(y) {}

  template <typename S, typename T>
  Point(pair<S, T> p) : x(p.fi), y(p.se) {}

  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  ll det(Point p) const { return x * p.y - y * p.x; }
  ll dot(Point p) const { return x * p.x + y * p.y; }
  bool operator<(Point p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  bool operator==(Point p) const { return x == p.x && y == p.y; }
  Point operator-() const { return {-x, -y}; }
};
