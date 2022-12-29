#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<int> getFactors(int n) {
    vector<int> ans;
    for (int i = 2; i <= n;) {
      if (n % i == 0) {
        n /= i;
        ans.push_back(i);
      } else {
        ++i;
      }
    }
    return ans;
  }

 public:
  int smallestValue(int n) {
    vector<int> last;
    while (1) {
      auto temp = getFactors(n);
      if (last == temp) {
        return accumulate(temp.begin(), temp.end(), 0);
      }
      n = accumulate(temp.begin(), temp.end(), 0);
    }
    return n;
  }
};
