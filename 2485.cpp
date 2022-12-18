#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int pivotInteger(int n) {
    // math
    int sum = n * (n + 1) / 2;
    int x = sqrt(sum);
    return x * x == sum ? x : -1;
    // binary search
  }
};