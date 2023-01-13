#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (ans >= n - i || ans > n / 2) {
        break;
      }
      unordered_map<int, int> m;
      for (int j = i + 1; j < n; ++j) {
        int x = points[i][0] - points[j][0];
        int y = points[i][1] - points[j][1];
        if (x == 0) {
          y = 1;
        } else if (y == 0) {
          x = 1;
        } else {
          if (y < 0) {
            x = -x;
            y = -y;
          }
          int gcd_xy = gcd(abs(x), abs(y));
          x /= gcd_xy, y /= gcd_xy;
        }
        ++m[y + x * 20001];
      }
      int mmax = 0;
      for (auto& iter : m) {
        mmax = max(mmax, iter.second + 1);
      }
      ans = max(ans, mmax);
    }
    return ans;
  }
};