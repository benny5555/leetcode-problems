#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int ans = INT_MAX, i = INT_MAX, j = INT_MAX;
    for (int k = 0; k < wordsDict.size(); ++k) {
      if (wordsDict[k] == word1) {
        i = k;
        if (j != INT_MAX) ans = min(ans, abs(i - j));
      } else if (wordsDict[k] == word2) {
        j = k;
        if (i != INT_MAX) ans = min(ans, abs(i - j));
      }
    }
    return ans;
  }
};