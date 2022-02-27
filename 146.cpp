#include <bits/stdc++.h>
using namespace std;
class LRUCache {
 private:
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  int size;

 public:
  LRUCache(int capacity) : size(capacity) {}

  int get(int key) {
    auto iter = m.find(key);
    if (iter == m.end()) return -1;
    l.splice(l.begin(), l, iter->second);
    return iter->first;
  }

  void put(int key, int value) {
    auto iter = m.find(key);
    if (iter == m.end()) {
      if (l.size() >= size) {
        m.erase(l.rbegin()->first);
        l.pop_back();
      }
      l.push_front(make_pair(key, value));
      m[key] = l.begin();
    } else {
      iter->second->second = value;
      l.splice(l.begin(), l, iter->second);
    }
  }
};