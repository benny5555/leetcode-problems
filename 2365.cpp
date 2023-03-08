#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    long long ans = 0, n = tasks.size();
    unordered_map<int, long long> m;
    for (int x : tasks) {
      if (m.count(x)) {
        m[x] = ans = max(ans, m[x] + space) + 1;
      } else {
        m[x] = ++ans;
      }
    }
    return ans;
  }
};