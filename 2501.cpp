#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    auto msqrt = [](int n) { return (int)floor(sqrt(n)); };
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    unordered_map<int, int> m;
    int ans = 0;
    for (int num : nums) {
      m[num] = 1;
      int sqr = 0;
      while ((sqr = msqrt(num)) && sqr * sqr == num && m.count(sqr)) {
        ++m[sqr], num = sqr;
      }
    }
    for (auto iter : m) {
      ans = max(ans, iter.second);
    }
    return ans >= 2 ? ans : -1;
  }
};