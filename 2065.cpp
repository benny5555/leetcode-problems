#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int ans = INT_MIN;
    vector<int> vis;
    vector<vector<pair<int, int>>> graph;
    void dfs(vector<int> &values, int maxTime, int start, int time, int score) {
        if (time > maxTime) return;
        if (!vis[start]) score += values[start];
        ++vis[start];
        if (start == 0 && score > ans) ans = score;
        for (auto &next : graph[start]) {
            int e = next.first, v = next.second;
            dfs(values, maxTime, e, time + v, score);
        }
        --vis[start];
    }

public:
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime) {
        int n = values.size();
        graph = vector<vector<pair<int, int>>>(n);
        vis = vector<int>(n);
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        dfs(values, maxTime, 0, 0, 0);
        return ans;
    }
};