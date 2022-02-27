#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool func(const string &a, const string &b, vector<int> &arr, vector<int> &ind, int x) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (ind[i] >= x && a[i] == b[j])
                ++i, ++j;
            else
                ++i;
        }
        return j == b.size();
    }

public:
    int maximumRemovals(string &s, string &p, vector<int> &arr) {
        int l = 0, r = arr.size();
        vector<int> ind(s.size(), INT_MAX);
        for (int i = 0; i < arr.size(); ++i) ind[arr[i]] = i;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (func(s, p, arr, ind, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    string s = "abcbddddd", p = "abcd";
    vector<int> removables{3, 2, 1, 4, 5, 6};
    Solution solution;
    cout << solution.maximumRemovals(s, p, removables);
    return 0;
}