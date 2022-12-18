#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix[0].size(), m = matrix.size();
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[i][j] += min({matrix[i - 1][j], matrix[i - 1][max(j - 1, 0)],
                             matrix[i - 1][min(n - 1, j + 1)]});
      }
    }
    return *min_element(matrix.back().begin(), matrix.back().end());
  }
};