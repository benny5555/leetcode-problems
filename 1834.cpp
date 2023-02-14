#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<int> ans, ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(),
         [&](int a, int b) { return tasks[a][0] < tasks[b][0]; });
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (long i = 0, time = INT_MIN; i < n || pq.size();) {
      while (i < n && tasks[ind[i]][0] <= time) {
        pq.push(make_pair(tasks[ind[i]][1], ind[i]));
        ++i;
      }
      if (pq.size()) {
        auto [process, cur_ind] = pq.top();
        pq.pop();
        time += process;
        ans.push_back(cur_ind);
      } else {
        time = tasks[ind[i]][0];
      }
    }
    return ans;
  }
};