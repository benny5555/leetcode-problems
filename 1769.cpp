#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n);
    for (int i = 0, ball = 0, temp = 0; i < n; ++i) {
      ans[i] += temp;
      ball += boxes[i] - '0';
      temp += ball;
    }
    for (int i = n - 1, ball = 0, temp = 0; i >= 0; --i) {
      ans[i] += temp;
      ball += boxes[i] - '0';
      temp += ball;
    }
    return ans;
  }
};