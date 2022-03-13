#include <bits/stdc++.h>
using namespace std;
int __gcd(int a, int b) {
  int c = 0;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
class Solution {
 public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans;
    for (int num : nums) {
      while (1) {
        int gcd = ans.empty() ? 1 : __gcd(num, ans.back());
        if (gcd == 1) break;
        num *= ans.back() / gcd;
        ans.pop_back();
      }
      ans.push_back(num);
    }
    return ans;
  }
};