#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool del[1005]{};

  int minDeletionSize(vector<string>& strs) {
    int n = strs[0].size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < strs.size(); ++j) {
        if (!del[i] && j && strs[j][i] < strs[j - 1][i]) {
          del[i] = true;
          ++ans;
        }
      }
    }
    return ans;
  }
};