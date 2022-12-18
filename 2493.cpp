#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> graph, dis;
  vector<int> kara;
  int loop[505]{0}, n;
  bool flag;

  void bfs(int start) {
    dis[start][start] = 1;
    queue<int> que;
    que.push(start);
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
  }
  // bipartite judgement
  void dfs(int now, int d = 1) {
    loop[now] = d;
    kara.push_back(now);
    for (auto next : graph[now]) {
      if (!loop[next]) {
        dfs(next, -d);
      } else if (loop[next] == d) {
        flag = false;
      }
    }
  }

 public:
  int magnificentSets(int num, vector<vector<int>>& edges) {
    n = num;
    graph = vector<vector<int>>(n + 1);
    dis = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX / 2));
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    for (int i = 1; i <= n; ++i) {
      bfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (!loop[i]) {
        flag = true;
        kara.clear();
        dfs(i);
        if (!flag) return -1;
        int temp = 0;
        for (auto i : kara) {
          for (auto j : kara) {
            temp = max(temp, dis[i][j]);
          }
        }
        ans += temp;
      }
    }
    return ans;
  }
};