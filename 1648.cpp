#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    using LL = long long;
    int mod = 1e9 + 7;
    LL func(vector<int> &inventory, int x) {
        LL ans = 0;
        for (int num : inventory) {
            ans += max(num - x, 0);
        }
        return ans;
    }
    LL ASSum(LL a, LL b) {
        return (a + b) * (b - a + 1) / 2;
    }

public:
    int maxProfit(vector<int> &inventory, int orders) {
        LL ans = 0;
        long long l = 0, r = *max_element(inventory.begin(), inventory.end());
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (func(inventory, mid) >= orders)
                l = mid;
            else
                r = mid - 1;
        }
        LL rest = func(inventory, l) - orders;
        for (long long num : inventory) {
            if (num > l) {
                if (rest) {
                    --rest;
                    ans += ASSum(l + 2, num);
                } else
                    ans += ASSum(l + 1, num);
            }
        }
        return ans % mod;
    }
};

int main() {
    vector<int> inventory{5, 4, 4};
    Solution solution;
    cout << solution.maxProfit(inventory, 5) << endl;
    return 0;
}