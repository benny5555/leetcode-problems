#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    int ans = 0;
    for (auto& s : sentences) {
      stringstream ss(s);
      string temp;
      int cnt = 0;
      while (ss >> temp) ++cnt;
      ans = max(ans, cnt);
    }
    return ans;
  }
};