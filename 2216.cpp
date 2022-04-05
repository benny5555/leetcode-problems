#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int minDeletion(vector<int>& nums) {
    int ans = 0, pre = -1;
    for (int num : nums) {
      if (num == pre)
        ++ans;
      else {
        pre = pre < 0 ? num : -1;
      }
    }
    return ans + (pre > -1);
  }
};