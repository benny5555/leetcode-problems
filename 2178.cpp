#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    vector<long long> ans;
    if (finalSum % 2 == 0) {
      long long temp = 2, sum = 0;
      while (sum + temp <= finalSum) {
        ans.push_back(temp);
        sum += temp;
        temp += 2;
      }
      ans[ans.size() - 1] += abs(finalSum - sum);
    }
    return ans;
  }
};