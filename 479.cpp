#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int mod = 1337;

 public:
  int largestPalindrome(int n) {
    if (n == 1) return 9;
    int high = pow(10, n) - 1, low = pow(10, n - 1);
    for (int i = high; i >= low; --i) {
      string front = to_string(i);
      string back(front);
      reverse(back.begin(), back.end());
      long long product = stol(front + back);
      for (long long j = high; j * j >= product; --j) {
        if (product % j == 0) return product % mod;
      }
    }
    return -1;
  }
};

int main() {
  Solution solution;
  solution.largestPalindrome(2);
  return 0;
}