#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int ans = -1, mmin = INT_MAX, n = edges.size();
    vector<int> m1(n, -1), m2(n, -1);
    for (int i = node1, dist = 0; i != -1 && m1[i] == -1; i = edges[i]) {
      m1[i] = dist++;
    }
    for (int i = node2, dist = 0; i != -1 && m2[i] == -1; i = edges[i]) {
      m2[i] = dist++;
      if (m1[i] != -1 && max(m1[i], m2[i]) <= mmin) {
        ans = max(m1[i], m2[i]) == mmin ? min(ans, i) : i;
        mmin = max(m1[i], m2[i]);
      }
    }
    return ans;
  }
};