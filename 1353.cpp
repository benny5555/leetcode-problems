#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    int ans = 0, i = 0, d = 0, n = events.size();
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    while (pq.size() || i < n) {
      if (pq.size() == 0) {
        d = events[i][0];
      }
      while (i < n && events[i][0] <= d) {
        pq.push(events[i++][1]);
      }
      pq.pop();
      ++ans, ++d;
      while (pq.size() && pq.top() < d) {
        pq.pop();
      }
    }
    return ans;
  }
};