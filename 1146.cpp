#include <bits/stdc++.h>
using namespace std;
class SnapshotArray {
  vector<map<int, int>> snaps;
  int id;

 public:
  SnapshotArray(int length) : id(0) {
    snaps.resize(length);
    for (int i = 0; i < length; ++i) {
      snaps[i][id] = 0;
    }
  }

  void set(int index, int val) { snaps[index][id] = val; }

  int snap() { return id++; }

  int get(int index, int snap_id) {
    return prev(snaps[index].upper_bound(snap_id))->second;
  }
};