#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int dp[10001][7][7]{};

 public:
  int distinctSequences(int n, int one = 0, int two = 0) {
    if (n == 0) {
      return 1;
    }
    if (dp[n][one][two] == 0) {
      for (int i = 1; i < 7; ++i) {
        if (i != one && i != two && (gcd(i, one) == 1 || one == 0)) {
          dp[n][one][two] =
              (dp[n][one][two] + distinctSequences(n - 1, i, one)) % 1000000007;
        }
      }
    }
    return dp[n][one][two];
  }
};