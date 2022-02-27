#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long sum = 0, mmin = 0, mmax = 0;
    for (int num : differences) {
      sum += num;
      mmin = min(mmin, sum);
      mmax = max(mmax, sum);
    }
    long long low = lower - mmin, high = upper - mmax;
    return max(0ll, high - low + 1);
  }
};