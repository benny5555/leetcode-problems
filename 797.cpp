#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> ans;
  vector<int> temp;
  void dfs(int now, int ind, vector<vector<int>>& graph) {
    temp[ind] = now;
    if (now == graph.size() - 1) {
      ans.push_back(vector<int>(temp.begin(), temp.begin() + ind + 1));
      return;
    }
    for (auto next : graph[now]) {
      dfs(next, ind + 1, graph);
    }
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    temp = vector<int>(graph.size() + 1);
    dfs(0, 0, graph);
    return ans;
  }
};