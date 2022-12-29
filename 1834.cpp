#include <bits/stdc++.h>
using namespace std;
class Solution {
  using pii = pair<int, int>;

 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int n = tasks.size();
    vector<int> ans, ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(),
         [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
    for (long i = 0, time = INT_MIN; i < n || pq.size();) {
      while (i < n && tasks[ind[i]][0] <= time) {
        pq.push({tasks[ind[i]][1], ind[i]});
        ++i;
      }
      if (pq.size()) {
        int process = pq.top().first, index = pq.top().second;
        time += process;
        ans.push_back(index);
        pq.pop();
      } else {
        time = tasks[ind[i]][0];
      }
    }
    return ans;
  }
};