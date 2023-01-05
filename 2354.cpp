#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    long long cnt[30]{}, ans = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for (auto num : s) {
      ++cnt[__builtin_popcount(num)];
    }
    for (int i = 1; i < 30; ++i) {
      for (int j = 1; j < 30; ++j) {
        if (i + j >= k) {
          ans += cnt[i] * cnt[j];
        }
      }
    }
    return ans;
  }
};