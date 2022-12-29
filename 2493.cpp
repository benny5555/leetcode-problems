#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n + 1);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INT_MAX / 2));
    function<void(int)> bfs = [&](int start) {
      queue<int> que;
      que.push(start);
      dis[start][start] = 1;
      while (que.size()) {
        auto now = que.front();
        que.pop();
        for (auto next : graph[now]) {
          if (dis[start][next] > dis[start][now] + 1) {
            dis[start][next] = dis[start][now] + 1;
            que.push(next);
          }
        }
      }
    };
    for (int i = 1; i <= n; ++i) {
      bfs(i);
    }
    int loop[505]{};
    int ans = 0;
    bool flag = false;
    vector<int> temp;
    function<void(int, int)> dfs = [&](int now, int color) {
      loop[now] = color;
      temp.push_back(now);
      for (auto next : graph[now]) {
        if (!loop[next]) {
          dfs(next, -color);
        } else if (loop[next] == color) {
          flag = false;
        }
      }
    };
    for (int i = 1; i <= n; ++i) {
      if (!loop[i]) {
        temp.clear();
        flag = true;
        dfs(i, 1);
        if (flag == false) return -1;
        int t = 0;
        for (auto i : temp) {
          for (auto j : temp) {
            t = max(t, dis[i][j]);
          }
        }
        ans += t;
      }
    }
    return ans;
  }
};