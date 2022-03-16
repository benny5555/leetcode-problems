#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int digArtifacts(int n, vector<vector<int>>& artifacts,
                   vector<vector<int>>& dig) {
    vector<vector<bool>> vis(n, vector<bool>(n));
    for (auto& d : dig) {
      vis[d[0]][d[1]] = true;
    }
    int ans = 0;
    for (auto& art : artifacts) {
      auto a = art[0], b = art[1], c = art[2], d = art[3];
      bool flag = false;
      for (int i = a; i <= c; ++i) {
        for (int j = b; j <= d; ++j) {
          if (!vis[i][j]) {
            flag = true;
            break;
          }
        }
      }
      if (flag) continue;
      ++ans;
    }
    return ans;
  }
};