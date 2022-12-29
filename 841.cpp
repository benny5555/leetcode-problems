#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    queue<int> que;
    que.push(0);
    int n = rooms.size();
    unordered_set<int> vis;
    vis.insert(0);
    while (que.size()) {
      auto now = que.front();
      que.pop();
      vector<int> temp(rooms[now].begin(), rooms[now].end());
      for (auto next : temp) {
        if (vis.count(next)) continue;
        que.push(next);
        vis.insert(next);
      }
    }
    return vis.size() == n;
  }
};