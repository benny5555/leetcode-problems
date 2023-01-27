#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    int cnt[1005]{};
    for (auto& t : trust) {
      ++cnt[t[1]];
      --cnt[t[0]];
    }
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] == n - 1) return i;
    }
    return -1;
  }
};