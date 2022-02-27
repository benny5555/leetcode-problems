#include <bits/stdc++.h>
using namespace std;
// class Solution {
//  private:
//   int dp[1001][2]{0}, mod = 1e9 + 7;
//   long dfs(int now, int n, bool preGap) {
//     if (now > n) return 0;
//     if (now == n) return !preGap;
//     if (dp[now][preGap]) return dp[now][preGap];
//     if (preGap) {
//       return dp[now][preGap] =
//                  (dfs(now + 1, n, false) + dfs(now + 1, n, true)) % mod;
//     }
//     return dp[now][preGap] = (dfs(now + 1, n, false) + dfs(now + 2, n, false)
//     +
//                               2l * dfs(now + 2, n, true)) %
//                              mod;
//   }

//  public:
//   int numTilings(int n) { return dfs(0, n, false); }
// };
class Solution {
 public:
  int numTilings(int n) {
    int mod = 1e9 + 7;
    // vector<vector<int>> dp(n + 2, vector<int>(2));
    vector<vector<int>> dp(3, vector<int>(2));
    dp[1] = {1, 1}, dp[2] = {2, 2};
    for (int i = 3; i <= n; ++i) {
      //   dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + 2l * dp[i - 2][1]) % mod;
      //   dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
      dp[i % 3][0] =
          (dp[(i - 1) % 3][0] + dp[(i - 2) % 3][0] + 2l * dp[(i - 2) % 3][1]) %
          mod;
      dp[i % 3][1] = (dp[(i - 1) % 3][0] + dp[(i - 1) % 3][1]) % mod;
    }
    return dp[n % 3][0];
  }
};