#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumTime(string s) {
    int n = s.size();
    vector<int> left(n + 5), right(n + 5);
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == '0') {
        left[i] = min(i - 1, left[i - 1]);
      } else {
        left[i] = min(i, left[i - 1] + 2);
      }
    }
    for (int i = n; i > 0; --i) {
      if (s[i - 1] == '0') {
        right[i] = min(n - i, right[i + 1]);
      } else {
        right[i] = min(n - i + 1, right[i + 1] + 2);
      }
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == '0') {
        ans = min(ans, left[i] + right[i]);
      }
    }
    return ans;
  }
};