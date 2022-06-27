#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> countRectangles(vector<vector<int>>& rectangles,
                              vector<vector<int>>& points) {
    vector<int> ans;
    vector<vector<int>> m(101);
    for (auto& r : rectangles) {
      m[r[1]].push_back(r[0]);
    }
    for (int i = 0; i < 101; ++i) {
      sort(m[i].begin(), m[i].end());
    }
    for (auto& p : points) {
      int temp = 0;
      for (int i = p[1]; i < 101; ++i) {
        auto start = lower_bound(m[i].begin(), m[i].end(), p[0]);
        temp += m[i].end() - start;
      }
      ans.push_back(temp);
    }
    return ans;
  }
};
