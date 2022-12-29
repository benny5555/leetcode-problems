#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    vector<unordered_set<int>> graph(n + 1);
    for (auto& e : edges) {
      graph[e[0]].insert(e[1]);
      graph[e[1]].insert(e[0]);
    }
    vector<int> odd;
    for (int i = 1; i <= n; ++i) {
      if (graph[i].size() & 1) odd.push_back(i);
    }
    if (odd.size() == 2) {
      for (int i = 1; i <= n; ++i) {
        if (graph[odd[0]].count(i) == 0 && graph[odd[1]].count(i) == 0) {
          return true;
        }
      }
    }
    if (odd.size() == 4) {
      return graph[odd[0]].count(odd[1]) == 0 &&
                 graph[odd[2]].count(odd[3]) == 0 ||
             graph[odd[0]].count(odd[2]) == 0 &&
                 graph[odd[1]].count(odd[3]) == 0 ||
             graph[odd[0]].count(odd[3]) == 0 &&
                 graph[odd[1]].count(odd[2]) == 0;
    }
    return odd.size() == 0;
  }
};
