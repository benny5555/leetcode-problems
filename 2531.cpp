#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isItPossible(string word1, string word2) {
    unordered_map<int, int> m1, m2;
    for (auto &c : word1) {
      ++m1[c];
    }
    for (auto &c : word2) {
      ++m2[c];
    }
    for (auto iter1 : m1) {
      for (auto iter2 : m2) {
        char i = iter1.first, j = iter2.first;
        if (!m1[i] || !m2[j]) continue;
        m1[i]--, m2[i]++, m1[j]++, m2[j]--;
        int cnt1 = 0, cnt2 = 0;
        for (auto iter : m1) {
          if (iter.second) ++cnt1;
        }
        for (auto iter : m2) {
          if (iter.second) ++cnt2;
        }
        if (cnt1 == cnt2) return true;
        m1[i]++, m2[i]--, m1[j]--, m2[j]++;
      }
    }
    return false;
  }
};