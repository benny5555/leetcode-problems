#include <bits/stdc++.h>

using namespace std;
class Solution1 {
  int memo[12][100005];
  int dfs(int i, int cnt, vector<int>& alice) {
    if (i >= 12 || cnt < 1) return 0;
    if (memo[i][cnt] != -1) return memo[i][cnt];
    int ans = dfs(i + 1, cnt, alice);
    if (cnt > alice[i]) {
      ans = max(ans, dfs(i + 1, cnt - alice[i] - 1, alice) + i);
    }
    return memo[i][cnt] = ans;
  }

 public:
  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    vector<int> ans(12);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < 12; ++i) {
      if (dfs(i, numArrows, aliceArrows) !=
          dfs(i + 1, numArrows, aliceArrows)) {
        ans[i] = aliceArrows[i] + 1;
        numArrows -= ans[i];
      }
    }

    // In case of having remain arrows then it means in all sections Bob always
    // win
    //   then we can distribute the remain to any section, here we simple choose
    //   first section.
    ans[0] += numArrows;
    return ans;
  }
};
class Solution2 {
 public:
  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    vector<int> ans(12);
    vector<int> t(12);
    int mmax = 0;
    function<void(int, int, int, vector<int>&)> dfs =
        [&](int i, int left, int score, vector<int>& temp) {
          if (i == 12) {
            if (score > mmax) {
              mmax = score;
              ans = temp;
            }
            return;
          }
          dfs(i + 1, left, score, temp);
          int need = aliceArrows[i] + 1;
          if (left >= need) {
            int old = temp[i];
            temp[i] = need;
            dfs(i + 1, left - need, score + i, temp);
            temp[i] = old;
          }
        };
    dfs(0, numArrows, 0, t);
    ans[0] += numArrows - accumulate(ans.begin(), ans.end(), 0);
    return ans;
  }
};
// bit mask
class Solution3 {
 public:
  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    vector<int> ans(12);
    int state = 1 << 12, mmax = 0;
    function<int(int, int)> func = [&](int mask, int left) {
      int ans = 0;
      for (int i = 0; i < 12; ++i) {
        if (mask >> i & 1) {
          int need = aliceArrows[i] + 1;
          if (need > left) return 0;
          left -= need;
          ans += i;
        }
      }
      return ans;
    };
    for (int i = 0; i < state; ++i) {
      int score = func(i, numArrows);
      if (score > mmax) {
        mmax = score;
        ans = vector<int>(12);
        for (int j = 0; j < 12; ++j) {
          if (i >> j & 1) {
            ans[j] = aliceArrows[j] + 1;
          }
        }
        ans[0] += numArrows - accumulate(ans.begin(), ans.end(), 0);
      }
    }
    return ans;
  }
};