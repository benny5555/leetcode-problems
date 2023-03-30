#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size(), cnt = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      if (v[i]) continue;
      if (++cnt > 26) return "";
      for (int j = i; j < n; ++j) {
        if (lcp[i][j]) {
          v[j] = cnt;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int temp = i + 1 < n && j + 1 < n ? lcp[i + 1][j + 1] : 0;
        temp = v[i] == v[j] ? temp + 1 : 0;
        if (temp != lcp[i][j]) return "";
      }
    }
    string ans;
    for (auto c : v) {
      ans += c + 'a' - 1;
    }
    return ans;
  }
};