#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void merge_sort(int l, int r, vector<int> &nums, vector<int> &ans, vector<int> &temp, vector<int> &ind) {
        if (r - l <= 1) return;
        int mid = l + (r - l) / 2;
        merge_sort(l, mid, nums, ans, temp, ind);
        merge_sort(mid, r, nums, ans, temp, ind);
        int x = l, y = mid, loc = 0;
        int cnt = 0;
        while (x < mid || y < r) {
            if (y >= r || (x < mid && nums[ind[x]] <= nums[ind[y]])) {
                temp[loc++] = ind[x];
                ans[ind[x++]] += cnt;
            } else {
                temp[loc++] = ind[y++];
                ++cnt;
            }
        }
        move(temp.begin(), temp.begin() + r - l, ind.begin() + l);
    }

public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n), temp(n), ind(n);
        iota(ind.begin(), ind.end(), 0);
        merge_sort(0, n, nums, ans, temp, ind);
        return ans;
    }
};

int main() {
    vector<int> nums{5, 2, 6, 1};
    Solution solution;

    for (auto num : solution.countSmaller(nums)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}