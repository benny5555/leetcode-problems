#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int addDigits(int num) {
    while (to_string(num).size() != 1) {
      int temp = 0, x = num;
      while (x) {
        temp += x % 10;
        x /= 10;
      }
      num = temp;
    }
    return num;
  }
};