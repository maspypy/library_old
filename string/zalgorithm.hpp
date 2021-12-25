template <class T>
std::vector<int> z_algorithm(const std::vector<T>& s) {
  int n = int(s.size());
  if (n == 0) return {};
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    int& k = z[i];
    k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
    while (i + k < n && s[k] == s[i + k]) k++;
    if (j + z[j] < i + z[i]) j = i;
  }
  z[0] = n;
  return z;
}

std::vector<int> z_algorithm(const std::string& s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return z_algorithm(s2);
}