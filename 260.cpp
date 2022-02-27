#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        vector<int> ans(2);
        int xornum = 0;
        for (int num : nums) {
            xornum ^= num;
        }
        int mask = (xornum == INT_MIN ? xornum : xornum & (-xornum));
        for (int num : nums) {
            if (mask & num) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
};