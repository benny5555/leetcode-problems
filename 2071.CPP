#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int l = 0, r = min(n, m);
        while (l < r) {
            int mid = (l + r + 1) / 2, need = 0;
            multiset<int> s(workers.end() - mid, workers.end());
            for (int i = mid - 1; i >= 0; --i) {
                auto iter = prev(s.end());
                if (*iter < tasks[i]) {
                    iter = s.lower_bound(tasks[i] - strength);
                    if (iter == s.end() || ++need > pills) break;
                }
                s.erase(iter);
            }
            if (s.empty())
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    vector<int> tasks = {5, 9, 8, 5, 9}, workers = {1, 6, 4, 2, 6};
    int pills = 1, strength = 5;
    Solution solution;
    cout << solution.maxTaskAssign(tasks, workers, pills, strength);
    return 0;
}