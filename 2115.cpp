#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> findAllRecipes(vector<string>& recipes,
                                vector<vector<string>>& ingredients,
                                vector<string>& supplies) {
    vector<string> ans;
    unordered_set<string> s(supplies.begin(), supplies.end());
    unordered_map<string, int> indegree;
    unordered_map<string, vector<string>> graph;
    for (auto& r : recipes) indegree[r] = 0;
    int n = recipes.size();
    for (int i = 0; i < n; ++i) {
      for (auto& str : ingredients[i]) {
        if (!s.count(str)) {
          ++indegree[recipes[i]];
          graph[str].push_back(recipes[i]);
        }
      }
    }
    queue<string> que;
    for (auto& s : recipes) {
      if (indegree[s] == 0) que.push(s);
    }
    while (que.size()) {
      int size = que.size();
      while (size--) {
        auto temp = que.front();
        que.pop();
        ans.push_back(temp);
        for (auto& next : graph[temp]) {
          if (--indegree[next] == 0) que.push(next);
        }
      }
    }
    return ans;
  }
};