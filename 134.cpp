#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gases, vector<int>& costs) {
    int n = costs.size(), total_cost = 0, total_gas = 0, cur_cost = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      total_cost += costs[i];
      total_gas += gases[i];
      cur_cost += gases[i] - costs[i];
      if (cur_cost < 0) {
        cur_cost = 0, ans = i + 1;
      }
    }
    return total_cost > total_gas ? -1 : ans;
  }
};