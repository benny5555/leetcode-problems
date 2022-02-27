#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& ans) {
    vector<int> dp;
    int n = ans.size();
    for (int i = 0; i < n; ++i) {
      if (dp.empty() || dp.back() <= ans[i]) {
        dp.push_back(ans[i]);
        ans[i] = dp.size();
      } else {
        int ind = upper_bound(dp.begin(), dp.end(), ans[i]) - dp.begin();
        dp[ind] = ans[i];
        ans[i] = ++ind;
      }
    }
    return ans;
  }
};