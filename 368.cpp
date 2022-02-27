#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        if (!n) return {};
        vector<int> ans;
        vector<int> dp(n, 1), parent(n, -1);
        int max_size = 1, max_index = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (max_size < dp[i]) {
                max_size = dp[i];
                max_index = i;
            }
        }
        while (max_index != -1) {
            ans.push_back(nums[max_index]);
            max_index = parent[max_index];
        }
        return ans;
    }
};