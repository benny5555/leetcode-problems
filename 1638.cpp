#include <bits/stdc++.h>
using namespace std;
// class Solution {
//   int helper(const string &s, const string &t, int i, int j) {
//     int ans = 0, pre = 0, cur = 0;
//     for (int n = s.size(), m = t.size(); i < n && j < m; ++i, ++j) {
//       ++cur;
//       if (s[i] != t[j]) {
//         pre = cur, cur = 0;
//       }
//       ans += pre;
//     }
//     return ans;
//   }

//  public:
//   int countSubstrings(string s, string t) {
//     int ans = 0;
//     for (int i = 0; i < s.size(); ++i) {
//       ans += helper(s, t, i, 0);
//     }
//     for (int i = 1; i < t.size(); ++i) {
//       ans += helper(s, t, 0, i);
//     }
//     return ans;
//   }
// };
class Solution {
 public:
  int countSubstrings(string s, string t) {
    int ans = 0, n = s.size(), m = t.size();
    int left[101][101]{}, right[101][101]{};
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s[i - 1] == t[j - 1]) {
          left[i][j] = 1 + left[i - 1][j - 1];
        }
      }
    }
    for (int i = n; i > 0; --i) {
      for (int j = m; j > 0; --j) {
        if (s[i - 1] == t[j - 1]) {
          right[i - 1][j - 1] = 1 + right[i][j];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i] != t[j]) {
          ans += (left[i][j] + 1) * (right[i + 1][j + 1] + 1);
        }
      }
    }
    return ans;
  }
};