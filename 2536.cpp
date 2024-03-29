#include <bits/stdc++.h>
using namespace std;
struct Diff2d {
  vector<vector<int>> diff;
  void set(int m, int n, vector<vector<int>>& arr) {
    diff.assign(m, vector<int>(n));
    for (auto& a : arr) {
      int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
      ++diff[x1][y1];
      if (x2 + 1 < m && y2 + 1 < n) ++diff[x2 + 1][y2 + 1];
      if (x2 + 1 < m) --diff[x2 + 1][y1];
      if (y2 + 1 < n) --diff[x1][y2 + 1];
    }
  }
  void sum() {
    int m = diff.size(), n = diff[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        diff[i][j] += diff[i][j - 1];
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        diff[i][j] += diff[i - 1][j];
      }
    }
  }
};
class Solution {
 public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    Diff2d ans;
    ans.set(n, n, queries);
    ans.sum();
    return ans.diff;
  }
};