#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int power[10]{0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
  int func(int x) {
    int ans = 0;
    while (x) {
      ans += power[x % 10];
      x /= 10;
    }
    return ans;
  }

 public:
  bool isHappy(int n) {
    if (n == 1) return true;
    int slow = n, fast = n;
    do {
      slow = func(slow);
      fast = func(func(fast));
      if (slow == 1 || fast == 1) return true;
    } while (slow != fast);
    return false;
  }
};