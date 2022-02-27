#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    if (n == 1) return true;
    while (n != 1) {
      if (n & 1) return false;
      n >>= 1;
    }
    return true;
  }
};