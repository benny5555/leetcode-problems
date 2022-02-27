#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<long long> sumOfThree(long long num) {
    vector<long long> ans;
    if (num % 3 == 0) {
      long long temp = num / 3 - 1;
      for (int i = 0; i < 3; ++i) {
        ans.push_back(temp++);
      }
    }
    return ans;
  }
};