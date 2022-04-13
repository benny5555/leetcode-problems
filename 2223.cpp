#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> ans(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
      if (i <= r && ans[i - l] < r - i + 1) {
        ans[i] = ans[i - l];
      } else {
        ans[i] = max(0, r - i + 1);
        while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]]) ++ans[i];
      }
      if (i + ans[i] - 1 > r) l = i, r = i + ans[i] - 1;
    }
    return ans;
  }

 public:
  long long sumScores(string s) {
    vector<int> ans = move(z_function(s));
    return accumulate(ans.begin(), ans.end(), 0ll) + s.size();
  }
};