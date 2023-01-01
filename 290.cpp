#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, int> m1;
    unordered_map<string, int> m2;
    stringstream ss(s);
    string word;
    int i = 0;
    for (; ss >> word; ++i) {
      if (i >= pattern.size() || m1[pattern[i]] != m2[word]) return false;
      m1[pattern[i]] = m2[word] = i + 1;
    }
    return i == pattern.size();
  }
};