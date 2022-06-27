#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumNumbers(int num, int k) {
    if (num == 0) return 0;
    if (k == 0) {
      if (num % 10 == 0) {
        return 1;
      } else {
        return -1;
      }
    }
    for (int i = 1; i < 11; ++i) {
      if (num >= k * i) {
        if ((num - k * i) % 10 == 0) {
          return i;
        }
      }
    }
    return -1;
  }
};