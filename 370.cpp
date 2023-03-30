#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> ans(length + 1);
    for (auto& u : updates) {
      ans[u[0]] += u[2];
      ans[u[1] + 1] -= u[2];
    }
    for (int i = 1; i < length; ++i) {
      ans[i] += ans[i - 1];
    }
    ans.pop_back();
    return ans;
  }
};