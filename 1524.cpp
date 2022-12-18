#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  const int mod = 1e9 + 7;
  using ll = long long;
  int numOfSubarrays(vector<int>& arr) {
    ll ans = 0, even = 0, odd = 0;
    for (auto num : arr) {
      ++even;
      if (num & 1) {
        swap(even, odd);
      }
      ans = (ans + odd) % mod;
    }
    return ans;
  }
};