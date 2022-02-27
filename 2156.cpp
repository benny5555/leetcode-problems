#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string subStrHash(string s, int power, int mod, int k, int hashValue) {
    long long hash = 0, n = s.size(), pk = power, ind = 0;
    for (int i = n - 1; i >= 0; --i) {
      hash = (hash * power + s[i] - 96) % mod;
      if (i <= n - k) {
        if (i < n - k) {
          hash = (hash - pk * (s[i + k] - 96) % mod + mod) % mod;
        }
        if (hash == hashValue) {
          ind = i;
        }
      } else {
        pk = (pk * power) % mod;
      }
    }
    return s.substr(ind, k);
  }
};