#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int mid, int m, int n) {
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans += min(mid / i, n);
        }
        return ans;
    }

public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (func(mid, m, n) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};