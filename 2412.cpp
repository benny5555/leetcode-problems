#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long minimumMoney(vector<vector<int>>& transactions) {
    long long sum_loss = 0;
    int max_cost = 0, max_cash = 0;
    for (auto& t : transactions) {
      if (t[0] > t[1]) {
        sum_loss += t[0] - t[1];
        max_cash = max(max_cash, t[1]);
      } else {
        max_cost = max(max_cost, t[0]);
      }
    }
    return sum_loss + max(max_cash, max_cost);
  }
};