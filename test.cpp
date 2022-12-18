#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      int a = queries[i][0], b = queries[i][1];
      int temp = 2;
      while (1) {
        if (a == b) {
          printf("a = %d, b = %d\n", a, b);
          break;
        }

        if (a > b) {
          a /= 2;
        } else {
          b /= 2;
        }
        ++temp;
      }
      ans[i] = temp - 1;
    }
    return ans;
  }
};