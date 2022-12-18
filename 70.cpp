#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int climbStairs(int n) {
    if (n < 3) return n;
    int first = 1, second = 2;
    int ans = 0;
    for (int i = 3; i <= n; ++i) {
      ans = first + second;
      first = second;
      second = ans;
    }
    return ans;
  }
};