#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumSum(int num) {
    int ans = INT_MAX;
    string s = to_string(num);
    sort(s.begin(), s.end());
    string a = "", b = "";
    a.push_back(s[0]), a.push_back(s[3]), b.push_back(s[1]), b.push_back(s[2]);
    ans = stoi(a) + stoi(b);
    return ans;
  }
};