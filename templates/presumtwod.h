#include <bits/stdc++.h>
using namespace std;
struct Presum2d {
  vector<vector<int>> presum2d;
  vector<vector<int>> twodpresum(vector<vector<int>>& arr) {
    int m = arr.size(), n = arr[0].size();
    presum2d.assign(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        presum2d[i][j] = arr[i - 1][j - 1] + presum2d[i][j - 1] +
                         presum2d[i - 1][j] - presum2d[i - 1][j - 1];
      }
    }
    return presum2d;
  }
  int sum2d(int x1, int y1, int x2, int y2) {
    return presum2d[x2 + 1][y2 + 1] + presum2d[x1][y1] - presum2d[x1][y2 + 1] -
           presum2d[x2 + 1][y1];
  }
};

vector<vector<int>> twodprexor(vector<vector<int>>& arr) {
  int m = arr.size(), n = arr[0].size();
  vector<vector<int>> ans(m + 1, vector<int>(n + 1));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans[i][j] =
          ans[i - 1][j] ^ ans[i][j - 1] ^ ans[i - 1][j - 1] ^ arr[i - 1][j - 1];
    }
  }
}