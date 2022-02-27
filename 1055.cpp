#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestWay(string source, string target) {
        int ans = 0;
        vector<vector<int>> pointers(26);
        for (int i = 0; i < source.size(); ++i) {
            int ind = source[i] - 'a';
            pointers[ind].push_back(i);
        }
        for (int i = 0, j = -1; i < target.size();) {
            int ind = target[i] - 'a';
            if (pointers[ind].size() == 0) return -1;
            auto start = upper_bound(pointers[ind].begin(), pointers[ind].end(), j);
            if (start == pointers[ind].end()) {
                j = -1, ++ans;
            } else {
                j = *start, ++i;
            }
        }
        return ans + 1;
    }
};