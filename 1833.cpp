#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    int n = costs.size();
    sort(costs.begin(), costs.end());
    for (int i = 0; i < n; ++i) {
      if (coins >= costs[i]) {
        coins -= costs[i];
      } else {
        return i;
      }
    }
    return n;
  }
};