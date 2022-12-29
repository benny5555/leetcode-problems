#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    for (auto& q : queries) {
      int a = q[0], b = q[1];
      int temp = 1;
      while (a != b) {
        if (a > b) {
          a /= 2;
        } else {
          b /= 2;
        }
        ++temp;
      }
      ans.push_back(temp);
    }
    return ans;
  }
};