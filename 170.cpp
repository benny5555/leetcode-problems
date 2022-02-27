#include <bits/stdc++.h>
using namespace std;
class TwoSum {
 private:
  unordered_map<long long, int> m;

 public:
  TwoSum() {}

  void add(int number) { ++m[number]; }

  bool find(int value) {
    for (auto iter : m) {
      if (iter.first == value - iter.first) {
        if (iter.second >= 2) return true;
      } else {
        if (m.count(value - iter.first)) return true;
      }
    }
    return false;
  }
};