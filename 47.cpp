#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    int temp = 0;
    vector<bool> picked;
    unordered_set<int> vis;

    void dfs(vector<int> &nums, int depth) {
        if (depth == nums.size()) {
            if (!vis.count(temp)) {
                vis.insert(temp);
                vector<int> t;
                while (temp) {
                    t.push_back(temp % 10);
                    temp /= 10;
                }
                if (t.size() == 3) ans.push_back(t);
            }
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!picked[i]) {
                picked[i] = true;
                temp = temp * 10 + nums[i];
                dfs(nums, depth + 1);
                picked[i] = false;
                temp /= 10;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        picked = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }
};