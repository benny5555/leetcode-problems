#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int dir[4][2]{0, 1, 1, 0, 0, -1, -1, 0};
    int d = 0, num = 0, x = 0, y = 0;
    while (num++ < n * n) {
      ans[x][y] = num;
      int nx = x + dir[d][0], ny = y + dir[d][1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n || ans[nx][ny]) {
        d = (d + 1) % 4;
        nx = x + dir[d][0], ny = y + dir[d][1];
      }
      x = nx, y = ny;
    }
    return ans;
  }
};