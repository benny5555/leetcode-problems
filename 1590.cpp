#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    using ll = long long;
    int ans = INT_MAX, n = nums.size(), remainder = 0;
    ll need = accumulate(nums.begin(), nums.end(), 0ll) % p;
    unordered_map<int, int> last{{0, -1}};
    for (int i = 0; i < n; ++i) {
      remainder = (remainder + nums[i]) % p;
      last[remainder] = i;
      int lastremainder = (remainder - need + p) % p;
      if (last.count(lastremainder)) {
        ans = min(ans, i - last[lastremainder]);
      }
    }
    return ans < n ? ans : -1;
  }
};