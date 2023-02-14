#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countOdds(int low, int high) {
    int cnt = 0;
    if (low & 1) ++cnt;
    if (high & 1) ++cnt;
    if (cnt) {
      return (high - low) / 2 + 1;
    }
    return (high - low) / 2;
  }
};