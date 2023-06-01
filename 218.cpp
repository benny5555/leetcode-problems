#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    vector<int> bounds;
    for (auto& b : buildings) {
      bounds.push_back(b[0]);
      bounds.push_back(b[1]);
    }
    sort(bounds.begin(), bounds.end());
    using pii = pair<int, int>;
    auto cmp = [](const pii& a, const pii& b) { return a.second < b.second; };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    int i = 0, n = buildings.size();
    for (auto& b : bounds) {
      while (i < n && buildings[i][0] <= b) {
        pq.push(make_pair(buildings[i][1], buildings[i][2]));
        ++i;
      }
      while (pq.size() && pq.top().first <= b) {
        pq.pop();
      }
      int mmax = pq.size() ? pq.top().second : 0;
      if (ans.empty() || ans.back()[1] != mmax) {
        ans.push_back({b, mmax});
      }
    }
    return ans;
  }
};