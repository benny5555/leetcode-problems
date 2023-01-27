#include <bits/stdc++.h>
using namespace std;
class Solution {
#define v vector
  using ll = long long;
  ll mmax = 0;
  int ans = 0, n;
  v<v<int>> children;
  int dfs(int now) {
    ll temp = 1, cnt = 1;
    for (auto next : children[now]) {
      auto c = dfs(next);
      temp *= c;
      cnt += c;
    }
    int other = n - cnt;
    if (other) temp *= other;
    if (temp > mmax) {
      mmax = temp;
      ans = 0;
    }
    if (temp == mmax) ++ans;
    return cnt;
  }

 public:
  int countHighestScoreNodes(vector<int>& parents) {
    n = parents.size();
    children.resize(n);
    for (int i = 1; i < n; ++i) {
      children[parents[i]].push_back(i);
    }
    dfs(0);
    return ans;
  }
};