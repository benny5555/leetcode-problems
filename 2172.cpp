#include <bits/stdc++.h>
using namespace std;
class Solution1 {
 public:
  int maximumANDSum(vector<int>& nums, int numSlots) {
    int state = pow(3, numSlots) - 1;
    vector<int> memo(state + 1);
    function<int(int, int)> dp = [&](int i, int mask) {
      int& ans = memo[mask];
      if (ans > 0) return ans;
      if (i < 0) return 0;
      for (int slot = 1, bit = 1; slot <= numSlots; ++slot, bit *= 3) {
        if (mask / bit % 3 > 0) {
          ans = max(ans, (nums[i] & slot) + dp(i - 1, mask - bit));
        }
      }
      return ans;
    };
    return dp(nums.size() - 1, state);
  }
};
class Solution2 {
 public:
  int maximumANDSum(vector<int>& nums, int numSlots) {
    nums.resize(2 * numSlots);
    int n = nums.size();
    int state = 1 << n;
    vector<int> dp(state);
    for (int mask = 1; mask < state; ++mask) {
      int cnt = __builtin_popcount(mask), slot = (cnt + 1) / 2;
      for (int i = 0; i < n; ++i) {
        if (mask >> i & 1) {
          dp[mask] = max(dp[mask], dp[mask ^ (1 << i)] + (slot & nums[i]));
        }
      }
    }
    return dp[state - 1];
  }
};
template <typename T>
struct hungarian {
  int n;
  vector<int> matchx, matchy, pre;
  vector<bool> visx, visy;
  vector<T> x, y;
  vector<vector<T>> graph;
  vector<T> slack;
  T mmax, ans;
  queue<int> que;
  hungarian(int left, int right)
      : n(max(left, right)),
        mmax(numeric_limits<T>::max()),
        ans(0),
        graph(n, vector<T>(n)),
        matchx(n, -1),
        matchy(n, -1),
        pre(n),
        visx(n),
        visy(n),
        x(n, -mmax),
        y(n),
        slack(n) {}
  void addEdge(int u, int v, int w) { graph[u][v] = max(w, 0); }
  bool check(int v) {
    visy[v] = true;
    if (matchy[v] != -1) {
      que.push(matchy[v]);
      visx[matchy[v]] = true;
      return false;
    }
    while (v != -1) {
      matchy[v] = pre[v];
      swap(v, matchx[pre[v]]);
    }
    return true;
  }
};
int main() { return 0; }