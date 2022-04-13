#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<vector<int>> ans(2);
    unordered_map<int, int> m;
    for (auto& match : matches) {
      m[match[0]];
      ++m[match[1]];
    }
    for (auto iter : m) {
      if (iter.second == 1) {
        ans[1].push_back(iter.first);
      }
      if (iter.second == 0) {
        ans[0].push_back(iter.first);
      }
    }
    sort(ans[0].begin(), ans[0].end());
    sort(ans[1].begin(), ans[1].end());
    return ans;
  }
};