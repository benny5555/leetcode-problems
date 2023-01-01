#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool primes[1000005]{};
  vector<int> closestPrimes(int left, int right) {
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = false;
    for (int i = 2; i < 1000001; ++i) {
      if (primes[i]) {
        int t = 1000001 / i;
        for (int j = 2; j < t; ++j) {
          primes[i * j] = false;
        }
      }
    }
    int i = -1, j = -1;
    int ans = INT_MAX;
    int a, b;
    for (int k = left; k <= right; ++k) {
      if (primes[k]) {
        if (j == -1)
          j = k;
        else {
          i = j;
          j = k;
          if (j - i < ans) {
            ans = j - i;
            a = i, b = j;
          }
        }
      }
    }
    if (i == -1) return {-1, -1};
    return vector<int>{a, b};
  }
};