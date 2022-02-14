vc<string> split(string S, char sep = ',') {
  vc<string> res = {""};
  for (auto&& s: S) {
    if (s == sep)
      res.eb("");
    else
      res.back() += s;
  }
  return res;
}
