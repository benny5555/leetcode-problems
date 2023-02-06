#include <bits/stdc++.h>
using namespace std;
long long fastpower(long long base, long long n, long long mod) {
  long long ans = 1;
  while (n) {
    if (n & 1) {
      ans = ans * base % mod;
    }
    base = base * base % mod;
    n >>= 1;
  }
  return ans;
}
class Solution {
 public:
  int monkeyMove(int n) {
    int mod = 1e9 + 7;
    return (fastpower(2, n, mod) - 2 + mod) % mod;
  }
};