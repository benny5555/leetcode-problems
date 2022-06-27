#include <bits/stdc++.h>
using namespace std;

array<int, 2> operator+(const array<int, 2> &l, const array<int, 2> &r) {
  return {l[0] + r[0], l[1] + r[1]};
}
array<int, 2> operator-(const array<int, 2> &l, const array<int, 2> &r) {
  return {l[0] - r[0], l[1] - r[1]};
}
int pairs(const array<int, 2> &p) { return min(p[0], p[1]); }

class Solution {
  int num_factors(int i, int f) {
    return i % f ? 0 : 1 + num_factors(i / f, f);
  }

 public:
  int maxTrailingZeros(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<array<int, 2>>> horizon(n, vector<array<int, 2>>(m + 1)),
        vertical(n + 1, vector<array<int, 2>>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        array<int, 2> f25 = {num_factors(grid[i][j], 2),
                             num_factors(grid[i][j], 5)};
        vertical[i + 1][j] = vertical[i][j] + f25;
        horizon[i][j + 1] = horizon[i][j] + f25;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        auto v1 = vertical[i + 1][j], v2 = vertical[n][j] - vertical[i][j];
        auto h1 = horizon[i][j], h2 = horizon[i][m] - horizon[i][j + 1];
        ans = max({ans, pairs(v1 + h1), pairs(v1 + h2), pairs(v2 + h1),
                   pairs(v2 + h2)});
      }
    }
    return ans;
  }
};