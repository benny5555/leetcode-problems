#include <bits/stdc++.h>
using namespace std;
template <typename T>
class FenWick {
 private:
  T n;
  vector<T> arr;

 public:
  FenWick() : n(0), arr(0) {}
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
class NumArray {
  vector<int> arr;
  FenWick<int> tree;

 public:
  NumArray(vector<int>& nums) {
    arr = nums;
    int n = arr.size();
    tree = FenWick<int>(n);
    for (int i = 0; i < n; ++i) {
      tree.update(i + 1, arr[i]);
    }
  }

  void update(int index, int val) {
    tree.update(index + 1, val - arr[index]);
    arr[index] = val;
  }

  int sumRange(int left, int right) {
    return tree.query(right + 1) - tree.query(left);
  }
};