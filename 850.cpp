#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    vector<int> x;
    int mod = 1e9 + 7;
    for (auto& r : rectangles) {
      x.push_back(r[0]);
      x.push_back(r[2]);
    }
    sort(x.begin(), x.end());
    auto enditer = unique(x.begin(), x.end());
    x.erase(enditer, x.end());
    unordered_map<int, int> x_i;
    for (int i = 0; i < x.size(); ++i) {
      x_i[x[i]] = i;
    }
    vector<int> cnt(x.size());
    vector<tuple<int, int, int, int>> interval;
    for (auto& r : rectangles) {
      int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
      interval.push_back({y1, x1, x2, 1});
      interval.push_back({y2, x1, x2, -1});
    }
    sort(interval.begin(), interval.end());
    long long cur_y = 0, cur_x_sum = 0, ans = 0;
    for (auto& [y, x1, x2, sig] : interval) {
      ans = (ans + (y - cur_y) * cur_x_sum) % mod;
      cur_y = y;
      for (int i = x_i[x1]; i < x_i[x2]; ++i) {
        cnt[i] += sig;
      }
      cur_x_sum = 0;
      for (int i = 0; i < x.size(); ++i) {
        if (cnt[i]) {
          cur_x_sum += x[i + 1] - x[i];
        }
      }
    }
    return ans;
  }
};