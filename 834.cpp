#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> graph;
  vector<int> ans, cnt;

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    graph.resize(n);
    ans.assign(n, 0), cnt.assign(n, 1);
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    preorder(0, -1);
    postorder(0, -1);
    return ans;
  }
  void preorder(int now, int pre) {
    for (auto next : graph[now]) {
      if (next == pre) continue;
      preorder(next, now);
      cnt[now] += cnt[next];
      ans[now] += ans[next] + cnt[next];
    }
  }
  void postorder(int now, int pre) {
    for (auto next : graph[now]) {
      if (next == pre) continue;
      ans[next] = ans[now] - cnt[next] + cnt.size() - cnt[next];
      postorder(next, now);
    }
  }
};