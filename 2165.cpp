#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long smallestNumber(long long num) {
    bool flag = num > 0 ? true : false;
    num = abs(num);
    string s = to_string(num);
    long long ans = 0;
    if (flag) {
      sort(s.begin(), s.end());
      int ind = s.find_first_not_of('0');
      string zeros = s.substr(0, ind);
      string temp = s.substr(ind);
      temp.insert(temp.begin() + 1, zeros.begin(), zeros.end());
      ans = stoll(temp);
    } else {
      sort(s.rbegin(), s.rend());
      ans = stoll(s);
      ans = -ans;
    }
    return ans;
  }
};