#include <bits/stdc++.h>
using namespace std;
class Solution {
  int func(int x) {
    int ans = 0;
    while (x) {
      ans += x % 10;
      x /= 10;
    }
    return ans;
  }

 public:
  int countEven(int num) {
    int ans = 0;
    for (int i = 1; i <= num; ++i) {
      if (func(i) % 2 == 0) ++ans;
    }
    return ans;
  }
};