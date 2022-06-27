#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countLatticePoints(vector<vector<int>>& circles) {
    set<pair<int, int>> s;
    int n = circles.size();
    for (auto& p : circles) {
      int a = p[0], b = p[1], r = p[2];
      for (int x = -r; x <= r; ++x) {
        for (int y = -r; y <= r; ++y) {
          if (x * x + y * y <= r * r) {
            s.insert({x + a, y + b});
          }
        }
      }
    }
    return s.size();
  }
};