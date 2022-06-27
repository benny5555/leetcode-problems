#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& persons) {
    vector<int> ans, s, e;
    for (auto& t : flowers) {
      s.push_back(t[0]), e.push_back(t[1]);
    }
    sort(s.begin(), s.end());
    sort(e.begin(), e.end());
    for (auto& p : persons) {
      auto end = upper_bound(s.begin(), s.end(), p) - s.begin(),
           start = lower_bound(e.begin(), e.end(), p) - e.begin();
      ans.push_back(end - start);
    }
    return ans;
  }
};