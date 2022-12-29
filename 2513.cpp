#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    long left = 0, right = 1e17, LCM = lcm(divisor1, divisor2);
    while (left < right) {
      long mid = (left + right) / 2;
      bool x = mid - mid / divisor1 >= uniqueCnt1;
      bool y = mid - mid / divisor2 >= uniqueCnt2;
      bool z = mid / mid / LCM >= uniqueCnt1 + uniqueCnt2;
      if (x && y && z) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
/*class Solution:
    def minimizeSet(self, D1: int, D2: int, C1: int, C2: int) -> int:

        L, R, G = 0, 10**10, lcm(D1, D2)

        while L < R:

            M = (L+R)//2                # [0] try middle value

            x = M - M//D1 >= C1         # [1] criterion 1
            y = M - M//D2 >= C2         # [2] criterion 2
            z = M - M//G  >= C1 + C2    # [3] criterion 3

            if x and y and z : R = M    # [4] classical step of
            else             : L = M+1  #     the binary search

        return L*/