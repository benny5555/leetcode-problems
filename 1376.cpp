#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    int ans = 0;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
      if (manager[i] != -1) {
        graph[manager[i]].push_back(i);
      }
    }
    queue<pair<int, int>> que;
    que.push(make_pair(headID, 0));
    while (que.size()) {
      auto now = que.front();
      que.pop();
      ans = max(ans, now.second);
      for (auto next : graph[now.first]) {
        que.push({next, informTime[now.first] + now.second});
      }
    }
    return ans;
  }
};