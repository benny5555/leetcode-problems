#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buy = -prices[0], cooldown = 0, sell = 0;
    for (int i = 1; i < n; ++i) {
      int newbuy = max(buy, sell - prices[i]);
      int newcooldown = buy + prices[i];
      int newsell = max(sell, cooldown);
      buy = newbuy, cooldown = newcooldown, sell = newsell;
    }
    return max(cooldown, sell);
  }
};