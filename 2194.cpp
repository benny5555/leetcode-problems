#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> cellsInRange(string s) {
    vector<string> ans;
    char astart = s[0], start = s[1], aend = s[3], end = s[4];
    for (char i = astart; i <= aend; ++i) {
      for (char j = start; j <= end; ++j) {
        string temp;
        temp.push_back(i);
        temp.push_back(j);
        ans.push_back(temp);
      }
    }
    return ans;
  }
};
