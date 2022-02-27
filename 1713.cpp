#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    int n = target.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) m[target[i]] = i;
    vector<int> ans;
    for (int num : arr) {
      if (!m.count(num)) continue;
      if (ans.empty() || ans.back() < m[num])
        ans.push_back(m[num]);
      else
        *lower_bound(ans.begin(), ans.end(), m[num]) = m[num];
    }
    return target.size() - ans.size();
  }
};