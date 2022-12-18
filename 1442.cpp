#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    // https://leetcode.cn/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/solution/xing-cheng-liang-ge-yi-huo-xiang-deng-sh-jud0/
    //  arr.insert(arr.begin(), 0);
    //  int n = arr.size(), ans = 0;
    //  for (int i = 1; i < n; ++i) {
    //    arr[i] ^= arr[i - 1];
    //  }
    //  for (int i = 0; i < n; ++i) {
    //    for (int j = i + 1; j < n; ++j) {
    //      if (arr[i] == arr[j + 1]) {
    //        ans += j - i;
    //      }
    //    }
    //  }
    //  return ans;

    // int n = arr.size(), ans = 0, prefix = 0;
    // unordered_map<int, int> cnt{{0, 1}}, total;
    // for (int i = 0; i < n; ++i) {
    //   prefix ^= arr[i];
    //   ans += cnt[prefix]++ * i - total[prefix];
    //   total[prefix] += i + 1;
    // }
    // return ans;

    int n = arr.size(), ans = 0, prefix = 0;
    unordered_map<int, vector<int>> m{{0, {-1}}};
    for (int k = 0; k < n; ++k) {
      prefix ^= arr[k];
      for (auto i : m[prefix]) {
        ans += k - i - 1;
      }
      m[prefix].push_back(k);
    }
    return ans;
  }
};