#include <bits/stdc++.h>
using namespace std;
class Solution {
  long long sum(long long n) {
    int ans = 0;
    while (n) {
      ans += n % 10;
      n /= 10;
    }
    return ans;
  }

 public:
  long long makeIntegerBeautiful(long long n, int target) {
    long long originaln = n, base = 1;
    while (sum(n) > target) {
      n = n / 10 + 1;
      base *= 10;
    }
    return n * base - originaln;
  }
};