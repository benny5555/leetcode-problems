#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long countPairs(vector<int>& nums, int k) {
    long long ans = 0;
    unordered_map<int, int> m;
    for (int num : nums) {
      long long x = gcd(num, k);
      for (auto iter : m) {
        if (iter.first * x % k == 0) ans += iter.second;
      }
      ++m[x];
    }
    return ans;
  }
};