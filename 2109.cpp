#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    string ans;
    int i = 0, j = 0;
    int n = s.size(), m = spaces.size();
    while (i < n && j < m) {
      if (i == spaces[j]) ans.push_back(' '), ++j;
      ans.push_back(s[i++]);
    }
    ans.insert(ans.end(), s.begin() + i, s.end());
    return ans;
  }
};