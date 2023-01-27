#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<string> ans;
  void dfs(const string &s, int start, int step, string temp) {
    if (s.size() == start && step == 4) {
      temp.pop_back();
      ans.push_back(temp);
      return;
    }
    if (s.size() - start < 4 - step || s.size() - start > (4 - step) * 3) {
      return;
    }
    int num = 0;
    for (int i = start; i < start + 3; ++i) {
      num *= 10;
      num += s[i] - '0';
      if (num <= 255) {
        dfs(s, i + 1, step + 1, temp + to_string(num) + ".");
      }
      if (num == 0) return;
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    dfs(s, 0, 0, "");
    return ans;
  }
};