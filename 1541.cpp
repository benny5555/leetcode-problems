#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minInsertions(string s) {
    int ans = 0;
    int cnt = 0;
    int n = s.size();
    for (int i = 0; s[i]; ++i) {
      if (s[i] == '(')
        ++cnt;
      else if (s[i] == ')') {
        bool flag = (i < n - 1 && s[i + 1] == ')');
        if (cnt > 0) {
          if (flag)
            ++i;
          else
            ++ans;
          --cnt;
        } else {
          if (flag)
            ++ans, ++i;
          else
            ans += 2;
        }
      }
    }
    return ans + 2 * cnt;
  }
};