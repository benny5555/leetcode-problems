#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> prime_factors(long input) {
    int i = 2;
    vector<int> result;
    for (; input >= 2;) {
      if (input % i == 0) {
        result.push_back(i);
        input /= i;
      } else {
        i++;
      }
    }
    return result;
  }

  int distinctPrimeFactors(vector<int>& nums) {
    unordered_set<int> s;
    for (int num : nums) {
      auto temp = prime_factors(num);
      s.insert(temp.begin(), temp.end());
    }
    return s.size();
  }
};