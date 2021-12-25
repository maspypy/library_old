#include "my_template.hpp"

template <typename T>
struct xy {
  T x, y;
  xy() {}
  xy(pair<T, T> p) : x(p.fi), y(p.se) {}
  xy(T x, T y) : x(x), y(y) {}
  xy operator+(const xy rhs) { return xy(x + rhs.x, y + rhs.y); }
  xy operator-(const xy rhs) { return xy(x - rhs.x, y - rhs.y); }
  xy operator*(const T k) { return xy(x * k, y * k); }
  T dot(const xy rhs) { return x * rhs.x + y * rhs.y; }
  T det(const xy rhs) { return x * rhs.y - y * rhs.x; }
};

template <typename T>
int iSP(xy<T> A, xy<T> B, xy<T> C) {
  // https://www.ioi-jp.org/camp/2017/2017-sp_camp-hide.pdf
  T d = (B - A).det(C - A);
  if (d > 0) return 1;
  if (d < 0) return -1;
  if ((B - A).dot(C - A) < 0) return -2;
  if ((A - B).dot(C - B) < 0) return 2;
  return 0;
}

template <typename T>
bool intersect_segment(xy<T> A, xy<T> B, xy<T> C, xy<T> D, bool strict = false) {
  assert(!strict);
  bool b1 = iSP(A, B, C) * iSP(A, B, D) <= 0;
  bool b2 = iSP(C, D, A) * iSP(C, D, B) <= 0;
  return b1 && b2;
}