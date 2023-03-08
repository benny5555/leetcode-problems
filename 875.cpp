#include <bits/stdc++.h>
using namespace std;
class Solution {
  int time(vector<int>& arr, int x) {
    int ans = 0;
    for (int num : arr) {
      ans += (num + x - 1) / x;
    }
    return ans;
  }

 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    while (l < r) {
      int mid = (l + r) / 2;
      if (time(piles, mid) <= h) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};