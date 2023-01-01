#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countDigits(int num) {
    vector<int> digits;
    int x = num;
    while (x) {
      digits.push_back(x % 10);
      x /= 10;
    }
    int ans = 0;
    for (auto digit : digits) {
      if (num % digit == 0) ++ans;
    }
    return ans;
  }
};