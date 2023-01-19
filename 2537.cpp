#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    using ll = long long;
    ll ans = 0, cnt = 0;
    unordered_map<int, int> m;
    for (int i = 0, j = 0; j < nums.size();) {
      cnt += m[nums[j++]]++;
      while (cnt >= k) {
        cnt -= --m[nums[i++]];
      }
      ans += i;
    }
    return ans;
  }
};
