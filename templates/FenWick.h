#include <bits/stdc++.h>
template <typename T>
class FenWick {
 private:
  T n;
  vector<T> arr;

 public:
  FenWick(int limit) : n(limit), arr(n + 1) {}
  void update(int i, T delta) {
    for (; i <= n; i += i & -i) {
      arr[i] += delta;
    }
  }
  T query(int i) {
    T ans = 0;
    for (; i > 0; i -= i & -i) {
      ans += arr[i];
    }
    return ans;
  }
};