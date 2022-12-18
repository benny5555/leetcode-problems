#include <bits/stdc++.h>
using namespace std;
// class Allocator {
//   unordered_map<int, vector<pair<int, int>>> m;
//   map<int, int> ind_size;

//  public:
//   Allocator(int n) { ind_size[0] = n; }

//   int allocate(int size, int mID) {
//     for (auto iter = ind_size.begin(); iter != ind_size.end(); ++iter) {
//       if (iter->second >= size) {
//         int i = iter->first, sz = iter->second;
//         m[mID].push_back({i, size});
//         if (sz > size) {
//           ind_size[i + size] = sz - size;
//         }
//         ind_size.erase(iter);
//         return i;
//       }
//     }
//     return -1;
//   }

//   int free(int mID) {
//     int ans = 0;
//     if (m.count(mID)) {
//       for (auto& p : m[mID]) {
//         int i = p.first, size = p.second;
//         auto ind_size_iter = ind_size.insert({i, size}).first;
//         if (auto nxt = next(ind_size_iter);
//             nxt != ind_size.end() && i + size == nxt->first) {
//           ind_size_iter->second += nxt->second;
//           ind_size.erase(nxt);
//         }
//         if (ind_size_iter != ind_size.begin()) {
//           if (auto pre = prev(ind_size_iter); pre->first + pre->second == i)
//           {
//             pre->second += ind_size_iter->second;
//             ind_size.erase(ind_size_iter);
//           }
//         }
//         ans += p.second;
//       }
//       m.erase(mID);
//     }
//     return ans;
//   }
// };
struct Information {
  int ind, size;
  Information(int ind, int size) : ind(ind), size(size) {}
  Information() : ind(0), size(0) {}
};
bool operator<(const Information &a, const Information &b) {
  if (a.ind == b.ind) return a.size < b.size;
  return a.ind < b.ind;
}
class Allocator {
  set<Information> s;
  unordered_map<int, vector<Information>> m;

 public:
  Allocator(int n) { s.insert(Information(0, n)); }

  int allocate(int size, int mID) {
    for (auto &info : s) {
      if (info.size >= size) {
        m[mID].push_back(Information(info.ind, size));
        if (info.size > size) {
          s.insert(Information(info.ind + size, info.size - size));
        }
        int ans = info.ind;
        s.erase(info);
        return ans;
      }
    }
    return -1;
  }

  int free(int mID) {
    int ans = 0;
    if (m.count(mID)) {
      for (auto &info : m[mID]) {
        auto iter = s.insert({info.ind, info.size}).first;
        if (auto n = next(iter);
            n != s.end() && iter->ind + iter->size == n->ind) {
          auto temp = s.insert({iter->ind, iter->size + n->size}).first;
          s.erase(n);
          s.erase(iter);
          iter = temp;
        }
        if (iter != s.begin()) {
          if (auto pre = prev(iter); pre->ind + pre->size == iter->ind) {
            auto temp = s.insert({pre->ind, pre->size + iter->size});
            s.erase(iter);
            s.erase(pre);
          }
        }
        ans += info.size;
      }
      m.erase(mID);
    }
    return ans;
  }
};