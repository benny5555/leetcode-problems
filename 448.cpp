#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ans;
        int n = nums.size();
        for (int num : nums) {
            int ind = abs(num) - 1;
            nums[ind] = nums[ind] > 0 ? -nums[ind] : nums[ind];
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};

int main() {
    vector<int> nums{
        4, 3, 2, 7, 8, 2, 3, 1};
    Solution solution;
    solution.findDisappearedNumbers(nums);
    return 0;
}