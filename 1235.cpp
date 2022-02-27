#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    struct node {
        int s, e, w;
        bool operator<(const node &b) const {
            return e < b.e;
        }
    };

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int n = endTime.size();
        vector<node> graph;
        for (int i = 0; i < n; ++i) {
            graph.push_back({startTime[i], endTime[i], profit[i]});
        }
        map<int, int> dp;
        sort(graph.begin(), graph.end());
        for (auto &job : graph) {
            auto pre = dp.upper_bound(job.s);
            int money = 0;
            if (pre != dp.begin()) {
                money += prev(pre)->second;
            }
            money += job.w;
            if (dp.empty() || money > dp.rbegin()->second) dp[job.e] = money;
        }
        return dp.rbegin()->second;
    }
};

int main() {
    vector<int> startTime{1, 2, 3, 4, 6}, endTime{3, 5, 10, 6, 9}, profit{20, 20, 100, 70, 60};
    Solution solution;
    solution.jobScheduling(startTime, endTime, profit);
    return 0;
}