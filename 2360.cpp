#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size(), ans = -1;
    vector<int> time(n);
    for (int i = 0, clock = 1; i < n; ++i) {
      if (time[i]) continue;
      for (int now = i, start = clock; now != -1; now = edges[now]) {
        if (time[now]) {
          if (time[now] >= start) {
            ans = max(ans, clock - time[now]);
          }
          break;
        }
        time[now] = clock++;
      }
    }
    return ans;
  }
};