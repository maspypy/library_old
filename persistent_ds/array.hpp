#pragma once

template <typename T, int shift = 4>
struct PersistentArray {
  struct node;
  using np = node*;
  struct node {
    T data;
    np ch[1 << shift] = {};
  };

  static constexpr int mask = (1 << shift) - 1;
  np root = nullptr;
  PersistentArray() {}
  np get_root() { return root; }
  T get(int idx, np t) {
    if (!t) return 0;
    if (idx == 0) {
      return t->data;
    } else {
      return get(idx >> shift, t->ch[idx & mask]);
    }
  }

  void destructive_set(int idx, T val, np& t) {
    // 破壊的な値の変更。主に初期化に使う。
    if (!t) t = new node();
    if (idx == 0)
      t->data = val;
    else {
      destructive_set(idx >> shift, val, t->ch[idx & mask]);
    }
  }

  np set(int idx, T val, const np& t) {
    // set したあとの永続配列の root node pointer を返す
    np res = new node();
    if (t) {
      memcpy(res->ch, t->ch, sizeof(t->ch));
      res->data = t->data;
    }
    if (idx == 0) {
      res->data = val;
    } else {
      res->ch[idx & mask] = set(idx >> shift, val, res->ch[idx & mask]);
    }
    return res;
  }
};
