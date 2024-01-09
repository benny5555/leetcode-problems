#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> m;
    int ans = 0;
    int n = grid.size();
    for (auto& v : grid) {
      ++m[v];
    }
    for (int i = 0; i < n; ++i) {
      vector<int> v;
      for (int j = 0; j < n; ++j) {
        v.push_back(grid[j][i]);
      }
      ans += m[v];
    }
    return ans;
  }
};