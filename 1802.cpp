#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long func(int n, int ind, int x) {
        long long left = max(0, x - ind), right = max(0, x - (n - 1 - ind));
        long long ans = (left + x) * (x - left + 1) / 2 + (right + x) * (x - right + 1) / 2;
        return ans - x;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int l = 0, r = maxSum;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (func(n, index, mid) <= maxSum)
                l = mid;
            else
                r = mid - 1;
        }
        return l + 1;
    }
};

class Solution1 {
    long long func(int n, int index, int x) {
        long long left = max(0, x - index), right = max(0, x - (n - 1 - index));
        long long ans = (left + x) * (x - left + 1) / 2 + (right + x) * (x - right + 1) / 2;
        return ans - x;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int l = 0, r = maxSum + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (func(n, index, mid) > maxSum)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
int main() {
    Solution solution;
    solution.maxValue(4, 0, 4);
    return 0;
}