#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    int n = cost.size();
    int ans = 0;
    sort(cost.rbegin(), cost.rend());
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
      if (cnt % 3 == 0) {
        ++cnt;
        continue;
      }
      ans += cost[i], ++cnt;
    }
    return ans;
  }
};