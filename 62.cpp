#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        double ans = 1;
        int N = m + n - 2;
        int r = min(m, n) - 1;
        for (int i = 1; i <= r; ++i, --N) {
            ans *= N;
            ans /= i;
        }
        return (int)ans;
    }
};