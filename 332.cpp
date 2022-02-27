#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  vector<string> ans;
  map<string, multiset<string>> graph;

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    for (auto& t : tickets) {
      graph[t[0]].insert(t[1]);
    }
    dfs("JFK");
    reverse(ans.begin(), ans.end());
    return ans;
  }
  void dfs(string start) {
    while (graph[start].size()) {
      string next = *graph[start].begin();
      graph[start].erase(graph[start].begin());
      dfs(next);
    }
    ans.push_back(start);
  }
};