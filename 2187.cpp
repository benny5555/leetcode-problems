#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long fun(vector<int>& time, unsigned long long x) {
    int n = time.size();
    unsigned long long ans = 0;
    for (int t : time) {
      if (ans + x / t > LLONG_MAX) return LLONG_MAX;
      ans += x / t;
    }
    return ans;
  }
  long long minimumTime(vector<int>& time, int totalTrips) {
    using usll = unsigned long long;
    usll l = 1, r = 1e15;
    while (l < r) {
      usll mid = (r - l) / 2 + l;
      if (fun(time, mid) < totalTrips) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};