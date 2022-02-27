#include <bits/stdc++.h>
using namespace std;
class Solution {
  char rotate(char c) {
    switch (c) {
      case '0':
        return '0';
      case '1':
        return '1';
      case '6':
        return '9';
      case '9':
        return '6';
      default:
        return '8';
    }
  }

 public:
  bool isStrobogrammatic(string num) {
    int n = num.size();
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
      if (num[i] == '2' || num[i] == '3' || num[i] == '4' || num[i] == '5' ||
          num[i] == '7')
        return false;
      if (num[i] != rotate(num[j])) return false;
    }
    return true;
  }
};

int main() {
  Solution solution;
  cout << solution.isStrobogrammatic("2");
  return 0;
}