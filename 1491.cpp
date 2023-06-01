#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  double average(vector<int>& salary) {
    double mmin = 1e9, mmax = -1e9, sum = 0;
    for (double x : salary) {
      mmin = min(mmin, x);
      mmax = max(mmax, x);
      sum += x;
    }
    return (sum - mmin - mmax) / (salary.size() - 2);
  }
};