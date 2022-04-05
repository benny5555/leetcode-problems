#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minBitFlips(int start, int goal) {
    return __builtin_popcount(start ^ goal);
  }
};