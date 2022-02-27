#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    double func(vector<int> &dist, int x) {
        double ans = 0;
        int n = dist.size();
        for (int i = 0; i < n - 1; ++i) {
            ans += ceil((double)dist[i] / x);
        }
        ans += (double)dist[n - 1] / x;
        return ans;
    }

public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int n = dist.size();
        if (hour <= n) return -1;
        int l = 1, r = 0x3f3f3f3f;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (func(dist, mid) > hour)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

int main() {
    vector<int> dist{1, 3, 2};
    double hour = 2.7;
    Solution solution;
    solution.minSpeedOnTime(dist, hour);
    return 0;
}