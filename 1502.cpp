#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int k = abs(arr[1] - arr[0]);
    int n = arr.size();
    for (int i = 1; i < n - 1; ++i) {
      if (abs(arr[i + 1] - arr[i]) != k) {
        return false;
      }
    }
    return true;
  }
};