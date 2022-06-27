#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string digitSum(string s, int k) {
    while (s.size() > k) {
      string temp;
      for (int i = 0; i < s.size();) {
        int sum = 0, j = i;
        for (; j < s.size() && j < i + k; ++j) {
          sum += s[j] - '0';
        }
        temp += to_string(sum);
        i = j;
      }
      s = temp;
    }
    return s;
  }
};