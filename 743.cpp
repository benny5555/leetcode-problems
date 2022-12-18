#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto& e : times) {
      graph[e[0]].push_back(make_pair(e[1], e[2]));
    }
    vector<int> ans(n + 1, INT_MAX / 2);
    queue<int> que;
    que.push(k);
    ans[k] = 0;
    ans[0] = 0;
    while (que.size()) {
      auto now = que.front();
      que.pop();
      for (auto& next : graph[now]) {
        if (ans[next.first] > ans[now] + next.second) {
          ans[next.first] = ans[now] + next.second;
          que.push(next.first);
        }
      }
    }
    int mmax = *max_element(ans.begin(), ans.end());
    return mmax == INT_MAX / 2 ? -1 : mmax;
  }
};