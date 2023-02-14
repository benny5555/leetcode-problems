#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> minInterval(vector<vector<int>>& intervals,
                          vector<int>& queries) {
    int n = queries.size(), m = intervals.size();
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> ans(n, -1), ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(intervals.begin(), intervals.end());
    sort(ind.begin(), ind.end(),
         [&](int a, int b) { return queries[a] < queries[b]; });
    int i = 0;
    for (int now : ind) {
      while (i < m && intervals[i][0] <= queries[now]) {
        int l = intervals[i][0], r = intervals[i++][1];
        pq.push(make_pair(r - l + 1, r));
      }
      while (pq.size() && pq.top().second < queries[now]) {
        pq.pop();
      }
      if (pq.size()) {
        ans[now] = pq.top().first;
      }
    }
    return ans;
  }
};