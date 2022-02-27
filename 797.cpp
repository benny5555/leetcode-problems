#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<vector<int>> &graph, int start) {
        temp.push_back(start);
        if (start == graph.size() - 1) {
            ans.push_back(temp);
        }
        for (auto next : graph[start]) {
            dfs(graph, next);
        }
        temp.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        dfs(graph, 0);
        return ans;
    }
};