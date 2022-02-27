#include <bits/stdc++.h>
using namespace std;
class Solution {
    int func(vector<int> &quantities, int x) {
        int ans = 0;
        for (int num : quantities) {
            ans += (num + x - 1) / x;
        }
        return ans;
    }

public:
    int minimizedMaximum(int n, vector<int> &quantities) {
        int l = 1, r = 1e5;
        while (l < r) {
            int mid = (l + r) / 2;
            if (func(quantities, mid) > n)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};