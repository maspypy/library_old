struct Point {
  ll x, y;
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
