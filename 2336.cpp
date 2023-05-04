#include <bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet {
 public:
  int cur;
  set<int> added;
  SmallestInfiniteSet() : cur(1) {}

  int popSmallest() {
    if (added.size()) {
      int ans = *added.begin();
      added.erase(added.begin());
      return ans;
    }
    return cur++;
  }

  void addBack(int num) {
    if (num < cur) {
      added.insert(num);
    }
  }
};