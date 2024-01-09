#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minImpossibleOR(vector<int>& nums) {
    int ans = 1;
    unordered_set<int> s(nums.begin(), nums.end());
    while (s.count(ans)) {
      ans <<= 1;
    }
    return ans;
  }
};