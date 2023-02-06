#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> temp;
  temp.push_back({2, 1, 5});
  temp.push_back({2, -1, 50});
  sort(temp.begin(), temp.end());
  for (auto& t : temp) {
    for (auto num : t) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
