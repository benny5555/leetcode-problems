#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> presum(m + 1, vector<int>(n + 1));
    vector<int> ans;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        presum[i][j] = presum[i - 1][j] ^ presum[i][j - 1] ^
                       presum[i - 1][j - 1] ^ matrix[i - 1][j - 1];
        ans.push_back(presum[i][j]);
      }
    }
    nth_element(ans.begin(), ans.begin() + k - 1, ans.end(), greater<int>());
    return ans[k - 1];
  }
};