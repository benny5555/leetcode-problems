#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool checkValidString(string s) {
    int mmin = 0, mmax = 0;
    for (auto c : s) {
      if (c == '(') {
        ++mmin, ++mmax;
      } else if (c == ')') {
        mmin = max(--mmin, 0), --mmax;
      } else {
        mmin = max(--mmin, 0), ++mmax;
      }
      if (mmax < 0) {
        return false;
      }
    }
    return mmin == 0;
  }
};
int main() {
  Solution solution;
  solution.checkValidString("(*)");
  return 0;
}