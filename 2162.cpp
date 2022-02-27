#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minCostSetTime(int startAt, int moveCost, int pushCost,
                     int targetSeconds) {
    int maxmin = targetSeconds / 60, maxsec = targetSeconds % 60;
    auto func = [&](int min, int sec) {
      if (min > 99 || sec > 99 || min < 0 || sec < 0) return INT_MAX;
      auto s = to_string(min * 100 + sec);
      auto cur = (char)(startAt + '0');
      int ans = 0;
      for (auto c : s) {
        if (c == cur) {
          ans += pushCost;
        } else {
          ans += moveCost + pushCost;
          cur = c;
        }
      }
      return ans;
    };
    return min(func(maxmin, maxsec), func(maxmin - 1, maxsec + 60));
  }
};