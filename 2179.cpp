#include <bits/stdc++.h>
using namespace std;
class Solution1 {
 public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    long long ans = 0;
    int n = nums1.size();
    vector<long long> tree(n + 1), ind(n);
    for (int i = 0; i < n; ++i) {
      ind[nums1[i]] = i;
    }
    for (int i = 1; i < n - 1; ++i) {
      for (int j = ind[nums2[i - 1]] + 1; j <= n; j += j & -j) {
        ++tree[j];
      }
      long long less = 0, mid = ind[nums2[i]];
      for (int j = mid; j; j &= j - 1) {
        less += tree[j];
      }
      ans += less * (n - 1 - mid - (i - less));
    }
    return ans;
  }
};
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
class Solution {
 public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    long long ans = 0;
    int n = nums1.size();
    FenWick<int> fw(n);
    vector<long long> ind(n);
    for (int i = 0; i < n; ++i) {
      ind[nums2[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
      int mid = ind[nums1[i]];
      int left = fw.query(mid), right = n - mid - (fw.query(n) - fw.query(mid));
      ans += 1ll * left * right;
      fw.update(mid, 1);
    }
    return ans;
  }
};