#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int n = s.size(), l = 0, r = 0, cnt1 = 0, cnt2 = 0, mmax = 0;
    unordered_set<string> mset;
    for (auto c : s) {
      if (c == '(')
        ++l, ++cnt1;
      else if (c == ')') {
        if (l > 0)
          --l;
        else
          ++r;
        ++cnt2;
      }
    }
    mmax = min(cnt1, cnt2);
    int len = n - l - r;
    function<void(int, string, int, int, int)> dfs =
        [&](int ind, string str, int left, int right, int score) {
          if (left < 0 || right < 0 || score < 0 || score > mmax) return;
          if (left == 0 && right == 0 && str.size() == len) mset.insert(str);
          if (ind == n) return;
          if (s[ind] == '(') {
            dfs(ind + 1, str + s[ind], left, right, score + 1);
            dfs(ind + 1, str, left - 1, right, score);
          } else if (s[ind] == ')') {
            dfs(ind + 1, str + s[ind], left, right, score - 1);
            dfs(ind + 1, str, left, right - 1, score);
          } else {
            dfs(ind + 1, str + s[ind], left, right, score);
          }
        };
    dfs(0, "", l, r, 0);
    return vector<string>(mset.begin(), mset.end());
  }
};