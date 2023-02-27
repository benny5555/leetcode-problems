#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumTime(string s) {
    // int n = s.size();
    // vector<int> left(n + 2), right(n + 2);
    // for (int i = 1; i <= n; ++i) {
    //   if (s[i - 1] == '0') {
    //     left[i] = min(left[i - 1], i - 1);
    //   } else {
    //     left[i] = min(i, left[i - 1] + 2);
    //   }
    // }
    // for (int i = n; i > 0; --i) {
    //   if (s[i - 1] == '0') {
    //     right[i] = min(right[i + 1], n - i);
    //   } else {
    //     right[i] = min(right[i + 1] + 2, n - i + 1);
    //   }
    // }
    // int ans = n;
    // for (int i = 1; i <= n; ++i) {
    //   if (s[i - 1] == '0') {
    //     ans = min(ans, left[i] + right[i]);
    //   }
    // }
    // return ans;
    int n = s.size(), ans = n, left = 0;
    for (int i = 0; s[i]; ++i) {
      left = min(i + 1, left + (s[i] - '0') * 2);
      ans = min(ans, left + n - i - 1);
    }
    return ans;
  }
};