#include <bits/stdc++.h>
using namespace std;
int read4(char *buf4);
class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    int ans = 0;
    while (1) {
      int temp = read4(buf + ans);
      ans += temp;
      if (temp != 4) break;
    }
    return min(ans, n);
  }
};