#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int ans = 0;
    queue<pair<int, int>> last7, last30;
    for (auto d : days) {
      while (last7.size() && last7.front().first + 7 <= d) last7.pop();
      while (last30.size() && last30.front().first + 30 <= d) last30.pop();
      last7.push(make_pair(d, ans + costs[1]));
      last30.push(make_pair(d, ans + costs[2]));
      ans = min({ans + costs[0], last7.front().second, last30.front().second});
    }
    return ans;
  }
};