#include <bits/stdc++.h>
using namespace std;
class SummaryRanges {
  map<int, int> m;

 public:
  SummaryRanges() {}

  void addNum(int value) {
    auto iter = m.lower_bound(value);
    bool merge = false;
    if (iter != m.begin()) {
      if (auto pre = prev(iter); pre->second + 1 >= value) {
        pre->second = max(value, pre->second);
        merge = true;
      }
    }
    if (iter != m.end()) {
      if (iter->first - 1 <= value) {
        if (merge) {
          auto pre = prev(iter);
          pre->second = max(pre->second, iter->second);
          m.erase(iter);
        } else {
          merge = true;
          if (iter->first != value) {
            m[value] = iter->second;
            m.erase(iter);
          }
        }
      }
    }
    if (!merge) {
      m[value] = value;
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    for (auto& iter : m) {
      ans.push_back({iter.first, iter.second});
    }
    return ans;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */