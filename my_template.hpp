#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using uint = unsigned int;
using ull = unsigned long long;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
  vector<type> name(size);    \
  IN(name)
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  IN(name)
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR_(n) for (ll _ = 0; (_) < (ll)(n); ++(_))
#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return 31 - __builtin_clz(x); }
int topbit(uint x) { return 31 - __builtin_clz(x); }
int topbit(ll x) { return 63 - __builtin_clzll(x); }
int topbit(ull x) { return 63 - __builtin_clzll(x); }
// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)
int lowbit(int x) { return 31 - __builtin_clz(x); }
int lowbit(uint x) { return 31 - __builtin_clz(x); }
int lowbit(ll x) { return 63 - __builtin_clzll(x); }
int lowbit(ull x) { return 63 - __builtin_clzll(x); }

ll ceil(ll x, ll y) { return (x > 0 ? (x + y - 1) / y : x / y); }
ll floor(ll x, ll y) { return (x > 0 ? x / y : (x - y + 1) / y); }
pi divmod(ll x, ll y) {
  ll q = floor(x, y);
  return {q, x - q * y};
}

namespace yosupo_IO {

template <class T>
using is_signed_int128 =
    typename std::conditional<is_same<T, __int128_t>::value
                                  || is_same<T, __int128>::value,
                              true_type, false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<is_same<T, __uint128_t>::value
                                  || is_same<T, unsigned __int128>::value,
                              true_type, false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<is_same<T, __int128_t>::value, __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value
                                  || is_signed_int128<T>::value
                                  || is_unsigned_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_signed<T>::value)
                                  || is_signed_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_unsigned<T>::value)
                                  || is_unsigned_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

template <class T>
using is_integral_t = enable_if_t<is_integral<T>::value>;

template <class T>
using is_signed_int_t = enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = enable_if_t<is_unsigned_int<T>::value>;

namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} // namespace detail

template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};

template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;
template <typename T>
using is_not_modint_t = enable_if_t<!is_modint<T>::value>;

template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

struct Scanner {
public:
  Scanner(const Scanner &) = delete;
  Scanner &operator=(const Scanner &) = delete;

  Scanner(FILE *fp) : fd(fileno(fp)) { line[0] = 127; }

  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }

  int read_unsafe() { return 0; }
  template <class H, class... T>
  int read_unsafe(H &h, T &... t) {
    bool f = read_single(h);
    if (!f) return 0;
    return 1 + read_unsafe(t...);
  }

  int close() { return ::close(fd); }

private:
  static constexpr int SIZE = 1 << 15;

  int fd = -1;
  array<char, SIZE + 1> line;
  int st = 0, ed = 0;
  bool eof = false;

  bool read_single(string &ref) {
    if (!skip_space()) return false;
    ref = "";
    while (true) {
      char c = top();
      if (c <= ' ') break;
      ref += c;
      st++;
    }
    return true;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }

  template <class T, enable_if_t<is_same<T, char>::value> * = nullptr>
  bool read_single(T &ref) {
    if (!skip_space<50>()) return false;
    ref = top();
    st++;
    return true;
  }

  template <class T, is_signed_int_t<T> * = nullptr,
            enable_if_t<!is_same<T, char>::value> * = nullptr>
  bool read_single(T &sref) {
    using U = to_unsigned_t<T>;
    if (!skip_space<50>()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    U ref = 0;
    do { ref = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');
    sref = neg ? -ref : ref;
    return true;
  }
  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<!is_same<U, char>::value> * = nullptr>
  bool read_single(U &ref) {
    if (!skip_space<50>()) return false;
    ref = 0;
    do { ref = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');
    return true;
  }

  bool reread() {
    if (ed - st >= 50) return true;
    if (st > SIZE / 2) {
      std::memmove(line.data(), line.data() + st, ed - st);
      ed -= st;
      st = 0;
    }
    if (eof) return false;
    auto u = ::read(fd, line.data() + ed, SIZE - ed);
    if (u == 0) {
      eof = true;
      line[ed] = '\0';
      u = 1;
    }
    ed += int(u);
    line[ed] = char(127);
    return true;
  }

  char top() {
    if (st == ed) {
      bool f = reread();
      assert(f);
    }
    return line[st];
  }

  template <int TOKEN_LEN = 0>
  bool skip_space() {
    while (true) {
      while (line[st] <= ' ') st++;
      if (ed - st > TOKEN_LEN) return true;
      if (st > ed) st = ed;
      for (auto i = st; i < ed; i++) {
        if (line[i] <= ' ') return true;
      }
      if (!reread()) return false;
    }
  }
};

struct Printer {
public:
  template <char sep = ' ', bool F = false>
  void write() {}
  template <char sep = ' ', bool F = false, class H, class... T>
  void write(const H &h, const T &... t) {
    if (F) write_single(sep);
    write_single(h);
    write<true>(t...);
  }
  template <char sep = ' ', class... T>
  void writeln(const T &... t) {
    write<sep>(t...);
    write_single('\n');
  }

  Printer(FILE *_fp) : fd(fileno(_fp)) {}
  ~Printer() { flush(); }

  int close() {
    flush();
    return ::close(fd);
  }

  void flush() {
    if (pos) {
      auto res = ::write(fd, line.data(), pos);
      assert(res != -1);
      pos = 0;
    }
  }

private:
  static array<array<char, 2>, 100> small;
  static array<unsigned long long, 20> tens;

  static constexpr size_t SIZE = 1 << 15;
  int fd;
  array<char, SIZE> line;
  size_t pos = 0;
  std::stringstream ss;

  template <class T, enable_if_t<is_same<char, T>::value> * = nullptr>
  void write_single(const T &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }

  template <class T, is_signed_int_t<T> * = nullptr,
            enable_if_t<!is_same<char, T>::value> * = nullptr>
  void write_single(const T &val) {
    using U = to_unsigned_t<T>;
    if (val == 0) {
      write_single('0');
      return;
    }
    if (pos > SIZE - 50) flush();
    U uval = val;
    if (val < 0) {
      write_single('-');
      uval = -uval;
    }
    write_unsigned(uval);
  }

  template <class T, is_modint_t<T> * = nullptr>
  void write_single(const T &val) {
    write_single(val.val);
  }

  static int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
  }
  static int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
  }
  static int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
  }

  template <class U, is_unsigned_int_t<U> * = nullptr>
  void write_single(U uval) {
    if (uval == 0) {
      write_single('0');
      return;
    }
    if (pos > SIZE - 50) flush();

    write_unsigned(uval);
  }

  template <class U, is_unsigned_int_t<U> * = nullptr>
  static int calc_len(U x) {
    int i = (bsr(1ULL * x) * 3 + 3) / 10;
    if (x < tens[i])
      return i;
    else
      return i + 1;
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<2 >= sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    size_t len = calc_len(uval);
    pos += len;

    char *ptr = line.data() + pos;
    while (uval >= 100) {
      ptr -= 2;
      memcpy(ptr, small[uval % 100].data(), 2);
      uval /= 100;
    }
    if (uval >= 10) {
      memcpy(ptr - 2, small[uval].data(), 2);
    } else {
      *(ptr - 1) = char('0' + uval);
    }
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<4 == sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    array<char, 8> buf;
    memcpy(buf.data() + 6, small[uval % 100].data(), 2);
    memcpy(buf.data() + 4, small[uval / 100 % 100].data(), 2);
    memcpy(buf.data() + 2, small[uval / 10000 % 100].data(), 2);
    memcpy(buf.data() + 0, small[uval / 1000000 % 100].data(), 2);

    if (uval >= 100000000) {
      if (uval >= 1000000000) {
        memcpy(line.data() + pos, small[uval / 100000000 % 100].data(), 2);
        pos += 2;
      } else {
        line[pos] = char('0' + uval / 100000000);
        pos++;
      }
      memcpy(line.data() + pos, buf.data(), 8);
      pos += 8;
    } else {
      size_t len = calc_len(uval);
      memcpy(line.data() + pos, buf.data() + (8 - len), len);
      pos += len;
    }
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<8 == sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    size_t len = calc_len(uval);
    pos += len;

    char *ptr = line.data() + pos;
    while (uval >= 100) {
      ptr -= 2;
      memcpy(ptr, small[uval % 100].data(), 2);
      uval /= 100;
    }
    if (uval >= 10) {
      memcpy(ptr - 2, small[uval].data(), 2);
    } else {
      *(ptr - 1) = char('0' + uval);
    }
  }

  template <class U, enable_if_t<is_unsigned_int128<U>::value> * = nullptr>
  void write_unsigned(U uval) {
    static array<char, 50> buf;
    size_t len = 0;
    while (uval > 0) {
      buf[len++] = char((uval % 10) + '0');
      uval /= 10;
    }
    std::reverse(buf.begin(), buf.begin() + len);
    memcpy(line.data() + pos, buf.data(), len);
    pos += len;
  }

  void write_single(const std::string &s) {
    for (char c: s) write_single(c);
  }
  void write_single(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T>
  void write_single(const std::vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};

array<array<char, 2>, 100> Printer::small = [] {
  array<array<char, 2>, 100> table;
  for (int i = 0; i <= 99; i++) {
    table[i][1] = char('0' + (i % 10));
    table[i][0] = char('0' + (i / 10 % 10));
  }
  return table;
}();
array<ull, 20> Printer::tens = [] {
  array<ull, 20> table;
  for (int i = 0; i < 20; i++) {
    table[i] = 1;
    for (int j = 0; j < i; j++) { table[i] *= 10; }
  }
  return table;
}();

} // namespace yosupo_IO

using namespace yosupo_IO;
Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

#define INT(...)   \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...)    \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...)           \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { scanner.read(a); }
void scan(ll &a) { scanner.read(a); }
void scan(ull &a) { scanner.read(a); }
void scan(char &a) { scanner.read(a); }
void scan(double &a) { scanner.read(a); }
// void scan(long double &a) { scanner.read(a); }
void scan(string &a) { scanner.read(a); }
template <class T, class U>
void scan(pair<T, U> &p) {
  scan(p.first), scan(p.second);
}
template <class A, class B, class C>
void scan(tuple<A, B, C> &p) {
  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));
}
template <class A, class B, class C, class D>
void scan(tuple<A, B, C, D> &p) {
  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p)), scan(get<3>(p));
}
template <class T>
void scan(vector<T> &a) {
  for (auto &&i: a) scan(i);
}
template <class T> // modint
void scan(T &a) {
  ll x;
  scanner.read(x);
  a = x;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail) {
  scan(head);
  IN(tail...);
}

vi s_to_vi(string S, char first_char = 'a') {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

void print() { printer.writeln(); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> &A) {
  int N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vc<int> bin_count(vi &A, int size) {
  vc<int> C(size);
  for (auto &x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(vector<T> &A) {
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
