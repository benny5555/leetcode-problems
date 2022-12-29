#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < words.size(); ++i) {
      m[words[i]].push_back(i);
    }
    int n = words.size();
    if (!m.count(target)) return -1;
    int a = abs(startIndex - m[target]);
    int b = INT_MAX;
    for (int i = 0; i < words.size(); ++i) {
      if ((startIndex - i) % n == m[target]) {
        b = i;
        break;
      }
    }
    return min(a, b);
  }
};