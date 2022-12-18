#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
      if (color[i]) continue;
      queue<int> que;
      color[i] = 1;
      for (que.push(i); que.size(); que.pop()) {
        auto now = que.front();
        for (auto next : graph[now]) {
          if (!color[next]) {
            color[next] = -color[now];
            que.push(next);
          } else if (color[next] == color[now])
            return false;
        }
      }
    }
    return true;
  }
};