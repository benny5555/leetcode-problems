#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int convertTime(string current, string correct) {
    int ans = 0;
    string a = current.substr(0, 2), b = current.substr(3, 2),
           c = correct.substr(0, 2), d = correct.substr(3, 2);
    int now_hour = stoi(a), now_minute = stoi(b), target_hour = stoi(c),
        target_minute = stoi(d);
    if (target_minute != now_minute) {
      int gap = target_minute - now_minute;
      if (gap < 0) gap += 60, --ans;
      while (gap) {
        if (gap >= 15)
          ++ans, gap -= 15;
        else if (gap >= 5)
          ++ans, gap -= 5;
        else
          ++ans, gap -= 1;
      }
    }
    if (now_hour != target_hour) {
      int gap = target_hour - now_hour;
      if (gap < 0) gap += 24;
      ans += gap;
    }
    return ans;
  }
};