#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (n > 0) {
            while (n) {
                if (n & 1) ans *= x;
                x *= x;
                n /= 2;
            }
        } else {
            while (n) {
                if (n & 1) ans /= x;
                x *= x;
                n /= 2;
            }
        }
        return ans;
    }
};

int main() {
    double n;
    cin >> n;
    Solution solution;
    cout << solution.myPow(n, 10);
    return 0;
}