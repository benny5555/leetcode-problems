#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int strStr(string haystack, string needle) {
    int n = needle.size();
    if (!n) return 0;
    vector<int> next(n);
    for (int i = 1, j = 0; needle[i]; ++i) {
      if (j && needle[i] != needle[j]) j = next[j - 1];
      if (needle[i] == needle[j]) ++j;
      next[i] = j;
    }
    for (int i = 0, j = 0; haystack[i]; ++i) {
      while (j && haystack[i] != needle[j]) j = next[j - 1];
      if (haystack[i] == needle[j]) ++j;
      if (j == needle.size()) return i - j + 1;
    }
    return -1;
  }
};
