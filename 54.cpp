#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int dir[4][2]{0, 1, 1, 0, 0, -1, -1, 0};

 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> ans;
    int x = 0, y = 0, d = 0;
    ans.push_back(matrix[x][y]);
    matrix[x][y] = 0;
    int mmax = m * n;
    while (ans.size() != mmax) {
      int tempx = x + dir[d][0], tempy = y + dir[d][1];
      if (tempx < 0 || tempx >= n || tempy < 0 || tempy >= m ||
          matrix[tempx][tempy] == 0) {
        ++d;
        if (d == 4) d = 0;
      }
      x += dir[d][0], y += dir[d][1];
      ans.push_back(matrix[x][y]);
      matrix[x][y] = 0;
    }
    return ans;
  }
};