#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minOperations(int n) {
    int ans = 0;
    while (n) {
      if ((n & 3) == 3) {
        ++ans;
        ++n;
      } else {
        ans += n & 1;
        n >>= 1;
      }
    }
    return ans;
  }
};