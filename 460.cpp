#include <bits/stdc++.h>
using namespace std;
class LFUCache {
  struct Node {
    int key, val, freq;
  };
  int mmin, capacity;
  unordered_map<int, list<Node>::iterator> keymap;
  unordered_map<int, list<Node>> freqmap;

 public:
  LFUCache(int c) : mmin(0), capacity(c) {}

  int get(int key) {
    auto iter = keymap.find(key);
    if (iter == keymap.end()) return -1;
    auto node = iter->second;
    int val = node->val, freq = node->freq;
    freqmap[freq].erase(node);
    if (freqmap[freq].size() == 0) {
      if (mmin == freq) ++mmin;
      freqmap.erase(freq);
    }
    ++freq;
    freqmap[freq].push_front({key, val, freq});
    keymap[key] = freqmap[freq].begin();
    return val;
  }

  void put(int key, int value) {
    if (capacity == 0) return;
    auto iter = keymap.find(key);
    if (iter == keymap.end()) {
      if (keymap.size() == capacity) {
        auto last = freqmap[mmin].back();
        freqmap[mmin].pop_back();
        keymap.erase(last.key);
      }
      mmin = 1;
      freqmap[mmin].push_front({key, value, 1});
      keymap[key] = freqmap[mmin].begin();
    } else {
      auto node = iter->second;
      int freq = node->freq;
      freqmap[freq].erase(node);
      if (freqmap[freq].size() == 0) {
        if (mmin == freq) ++mmin;
        freqmap.erase(freq);
      }
      ++freq;
      freqmap[freq].push_front({key, value, freq});
      keymap[key] = freqmap[freq].begin();
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */