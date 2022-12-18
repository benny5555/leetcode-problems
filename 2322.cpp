#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int xor_value[1000]{}, last_child[1000]{};

  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int ids = 0, ans = INT_MAX;
    vector<vector<int>> graph(nums.size());
    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    function<int(int, int)> dfs = [&](int i, int parent) {
      int ans = nums[i];
      for (auto next : graph[i]) {
        if (next != parent) {
          int id = ids++;
          xor_value[id] = dfs(next, i);
          last_child[id] = ids;
          ans ^= xor_value[id];
        }
      }
      return ans;
    };
    int all = dfs(0, -1);
    for (int i = 0; i < ids; ++i) {
      for (int j = i + 1; j < ids; ++j) {
        int p1 = j < last_child[i] ? all ^ xor_value[i]
                                   : all ^ xor_value[i] ^ xor_value[j];
        int p2 = j < last_child[i] ? xor_value[i] ^ xor_value[j] : xor_value[i];
        ans =
            min(ans, max({p1, p2, xor_value[j]}) - min({p1, p2, xor_value[j]}));
      }
    }
    return ans;
  }
};