#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    for (auto x : arr) {
      if (x <= k) {
        ++k;
      }
    }
    return k;
    // int n = arr.size(), l = 0, r = n;
    // while (l < r) {
    //   int mid = (l + r) / 2;
    //   if (arr[mid] - 1 - mid < k) {
    //     l = mid + 1;
    //   } else {
    //     r = mid;
    //   }
    // }
    // return l + k;  // k - (arr[l - 1] - (l - 1) - 1) + arr[l - 1]
  }
};