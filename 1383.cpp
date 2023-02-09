#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    vector<pair<int, int>> workers;
    for (int i = 0; i < n; ++i) {
      workers.push_back({efficiency[i], speed[i]});
    }
    sort(workers.rbegin(), workers.rend());
    long long spd = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& [e, s] : workers) {
      pq.push(s);
      spd += s;
      if (pq.size() > k) {
        spd -= pq.top();
        pq.pop();
      }
      ans = max(ans, spd * e);
    }
    return ans % (int)(1e9 + 7);
  }
};
