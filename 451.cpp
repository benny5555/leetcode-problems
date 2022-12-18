#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  // string frequencySort(string s) {
  //   unordered_map<char, int> m;
  //   for (auto c : s) {
  //     m[c]++;
  //   }
  //   map<int, string> m2;
  //   for (auto iter : m) {
  //     m2[iter.second] += string(iter.second, iter.first);
  //   }
  //   string ans;
  //   for (auto iter = m2.rbegin(); iter != m2.rend(); ++iter) {
  //     ans += iter->second;
  //   }
  //   return ans;
  // }
  string frequencySort(string s) {
    string ans;
    unordered_map<char, int> m;
    for (auto c : s) {
      m[c]++;
    }
    vector<string> bucket(s.size() + 1);
    for (auto iter : m) {
      bucket[iter.second] += string(iter.second, iter.first);
    }
    for (int i = s.size(); i >= 0; --i) {
      if (!bucket[i].empty()) {
        ans += bucket[i];
      }
    }
    return ans;
  }
};