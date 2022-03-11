#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<int> ans;
    vector<pair<int, int>> p;
    for (int i = 0; i < nums.size(); ++i) {
      int temp = 0, factor = 1;
      int x = nums[i];
      if (nums[i] == 0) {
        temp += mapping[0];
      }
      while (x) {
        temp += mapping[x % 10] * factor;
        x /= 10;
        factor *= 10;
      }
      p.push_back({temp, i});
    }
    sort(p.begin(), p.end());
    for (auto iter : p) {
      ans.push_back(nums[iter.second]);
    }
    return ans;
  }
};