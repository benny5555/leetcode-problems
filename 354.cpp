#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
      if (a[0] == b[0]) return a[1] > b[1];
      return a[0] < b[0];
    });
    vector<int> ans;
    for (auto& e : envelopes) {
      auto iter = lower_bound(ans.begin(), ans.end(), e[1]);
      if (iter == ans.end())
        ans.push_back(e[1]);
      else if (*iter > e[1])
        *iter = e[1];
    }
    return ans.size();
  }
};

int main() {
  vector<vector<int>> arr{{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}};
  Solution solution;
  solution.maxEnvelopes(arr);
  return 0;
}