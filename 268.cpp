#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= nums[i];
            ans ^= i;
        }
        return ans;
    }
};