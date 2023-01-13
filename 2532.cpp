#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findCrossingTime(int n, int k, vector<vector<int>>& time) {
    using pii = pair<int, int>;
    priority_queue<pii> left, right;
    set<pii> put, pick;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
      left.push({time[i][0] + time[i][2], i});
    }
    while (n) {
      while (put.size() && put.begin()->first <= ans) {
        int i = put.begin()->second;
        left.push({time[i][0] + time[i][2], i});
        put.erase(put.begin());
      }
      while (pick.size() && pick.begin()->first <= ans) {
        int i = pick.begin()->second;
        right.push({time[i][0] + time[i][2], i});
        pick.erase(pick.begin());
      }
      if (right.size()) {
        int i = right.top().second;
        right.pop();
        ans += time[i][2];
        put.insert({ans + time[i][3], i});
        --n;
      } else if (left.size() && n > pick.size()) {
        int i = left.top().second;
        left.pop();
        ans += time[i][0];
        pick.insert({ans + time[i][1], i});
      } else {
        int nextl =
                put.size() && n > pick.size() ? put.begin()->first : INT_MAX,
            nextr = pick.size() ? pick.begin()->first : INT_MAX;
        ans = max(ans, min(nextl, nextr));
      }
    }
    return ans;
  }
};