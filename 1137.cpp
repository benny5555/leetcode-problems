#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int tribonacci(int n) {
    if (n <= 2) return n == 2 ? 1 : n;
    int one = 0, two = 1, three = 1;
    int ans = 0;
    for (int i = 3; i <= n; ++i) {
      int temp = one + two + three;
      one = two, two = three, three = temp;
    }
    return one + two + three;
  }
};