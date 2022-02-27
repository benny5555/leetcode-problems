#include <bits/stdc++.h>
using namespace std;
class SORTracker {
 private:
  struct node {
    int score;
    string name;
    bool operator<(const node &b) const {
      if (score == b.score) return name < b.name;
      return score > b.score;
    }
  };
  set<node> s;
  set<node>::iterator it = s.end();

 public:
  SORTracker() {}

  void add(string name, int score) {
    auto temp = s.insert({score, name}).first;
    if (it == s.end() || (*temp) < (*it)) --it;
  }

  string get() { return (it++)->name; }
};