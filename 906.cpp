#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  bool ispalin(unsigned long long x) {
    auto ori = x, rev = x;
    rev = 0;
    while (x) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }
    return rev == ori;
  }

 public:
  int superpalindromesInRange(string l, string r) {
    int ans = 0;
    auto left = stoull(l), right = stoull(r);
    int pivot = 1e5;
    for (int i = 1; i < pivot; ++i) {
      string temp = to_string(i);
      for (int j = temp.size() - 2; j > -1; --j) temp.push_back(temp[j]);
      auto num = stoull(temp);
      num *= num;
      if (num > right) break;
      if (num >= left && ispalin(num)) ++ans;
    }
    for (int i = 1; i < pivot; ++i) {
      string temp = to_string(i);
      for (int j = temp.size() - 1; j > -1; --j) temp.push_back(temp[j]);
      auto num = stoull(temp);
      num *= num;
      if (num > right) break;
      if (num >= left && ispalin(num)) ++ans;
    }
    return ans;
  }
};

int main() {
  string left{"4"}, right{"1000"};
  Solution solution;
  cout << solution.superpalindromesInRange(left, right);
  return 0;
}