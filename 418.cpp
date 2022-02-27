#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int num = 0, n = sentence.size();
    unordered_map<int, int> m;
    for (int i = 0; i < rows; ++i) {
      int start = num % n;
      if (m.count(start))
        num += m[start];
      else {
        int cnt = 0, len = 0;
        for (int j = start; len < cols; j = (j + 1) % n, ++cnt) {
          if (len + sentence[j].size() > cols) break;
          len += sentence[j].size() + 1;
        }
        num += cnt;
        m[start] = cnt;
      }
    }
    return num / n;
  }
};