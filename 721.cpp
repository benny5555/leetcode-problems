#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    struct UnionFind {
        vector<int> parent;
        UnionFind() {
        }
        UnionFind(int n) :
            parent(n) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu != pv) {
                parent[pu] = pv;
            }
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> ans;
        unordered_map<string, int> m1;
        int n = accounts.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            int m = accounts[i].size();
            for (int j = 1; j < m; ++j) {
                auto &s = accounts[i][j];
                if (!m1.count(s)) {
                    m1[s] = i;
                } else {
                    uf.unite(i, m1[s]);
                }
            }
        }
        unordered_map<int, vector<string>> m2;
        for (auto &iter : m1) {
            m2[uf.find(iter.second)].emplace_back(iter.first);
        }
        for (auto &iter : m2) {
            auto ind = iter.first;
            auto &v = iter.second;
            sort(v.begin(), v.end());
            vector<string> temp(1, accounts[ind][0]);
            temp.insert(temp.end(), v.begin(), v.end());
            ans.emplace_back(temp);
        }
        return ans;
    }
};