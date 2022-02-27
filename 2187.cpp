#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  long long func(vector<int>& time, long long x) {
    unsigned long long ans = 0;
    for (int num : time) {
      if (ans + x / num > LLONG_MAX) return LLONG_MAX;
      ans += x / num;
    }
    return ans;
  }

 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    unsigned long long left = 1, right = LLONG_MAX - 2;
    while (left < right) {
      unsigned long long mid = (right - left) / 2 + left;
      if (func(time, mid) < totalTrips) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};