#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> indegree(n);
    int cnt[100005][26]{};
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      ++indegree[e[1]];
    }
    queue<int> que;
    for (int i = 0; i < n; ++i) {
      if (!indegree[i]) {
        que.push(i);
        ++cnt[i][colors[i] - 'a'];
      }
    }
    int ans = 0, vis = 0;
    while (que.size()) {
      auto now = que.front();
      que.pop();
      int mmax = 0;
      for (int i = 0; i < 26; ++i) {
        mmax = max(mmax, cnt[now][i]);
      }
      ans = max(ans, mmax);
      ++vis;
      for (auto next : graph[now]) {
        for (int i = 0; i < 26; ++i) {
          cnt[next][i] =
              max(cnt[next][i], cnt[now][i] + (i == colors[next] - 'a'));
        }
        if (--indegree[next] == 0) {
          que.push(next);
        }
      }
    }
    return vis < n ? -1 : ans;
  }
};