#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long maxRunTime(int n, vector<int>& arr) {
    sort(arr.rbegin(), arr.rend());
    long long sum = accumulate(arr.begin(), arr.end(), 0ll);
    for (int num : arr) {
      if (num > sum / n) {
        --n;
        sum -= num;
      } else
        return sum / n;
    }
    return sum;
  }
};