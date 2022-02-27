#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int cnt(vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m - 1; ++j) {
        if (grid[i][j] && grid[i - 1][j]) {
          grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j + 1]) + 1;
          ans += grid[i][j] - 1;
        }
      }
      return ans;
    }
  }

 public:
  int countPyramids(vector<vector<int>>& grid) {
    int ans = cnt(grid);
    reverse(grid.begin(), grid.end());
    ans += cnt(grid);
    return ans;
  }
};
int main() {
  vector<vector<int>> grid = {
      {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 0, 0, 1}};
  Solution solution;
  solution.countPyramids(grid);
  return 0;
}