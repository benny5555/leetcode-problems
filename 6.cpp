#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;
    vector<string> strs(numRows);
    int row = 0, dir = 1;
    string ans;
    for (auto c : s) {
      strs[row].push_back(c);
      if (row == 0) {
        dir = 1;
      } else if (row == numRows - 1) {
        dir = -1;
      }
      row += dir;
    }
    for (auto& temp : strs) {
      ans += temp;
    }
    return ans;
  }
};