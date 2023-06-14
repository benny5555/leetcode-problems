#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    auto p = upper_bound(letters.begin(), letters.end(), target);
    if (p == letters.end()) return letters.front();
    return *p;
  }
};