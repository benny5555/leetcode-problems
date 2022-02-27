#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  unordered_map<int, vector<int>> graph;
  unordered_map<int, int> indegree;
  vector<vector<int>> ans;
  void dfs(int start) {
    while (graph[start].size()) {
      int next = graph[start].back();
      graph[start].pop_back();
      dfs(next);
      ans.push_back({start, next});
    }
  }

 public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    for (auto& p : pairs) {
      ++indegree[p[0]];
      --indegree[p[1]];
      graph[p[0]].push_back(p[1]);
    }
    int start = pairs[0][0];
    for (auto iter : indegree) {
      if (iter.second > 0) {
        start = iter.first;
        break;
      }
    }
    dfs(start);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};