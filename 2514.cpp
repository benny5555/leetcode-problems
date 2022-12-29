#include <bits/stdc++.h>
using namespace std;
class Solution {
  using ll = long long;
  ll mod = 1e9 + 7, fact[100002]{1, 1}, inv_fact[100002]{1, 1};
  ll modmul(ll a, ll b) { return (a * b) % mod; }

 public:
  int countAnagrams(string s) {
    if (fact[2] == 0) {
      vector<ll> inv(100002, 1);
      for (int i = 2; i < 100002; ++i) {
        fact[i] = modmul(fact[i - 1], i);
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        inv_fact[i] = modmul(inv_fact[i - 1], inv[i]);
      }
    }
    stringstream ss(s);
    string word;
    int ans = 1;
    while (ss >> word) {
      ll cnt[26]{}, temp = fact[word.size()];
      for (auto c : word) {
        ++cnt[c - 'a'];
      }
      for (auto c : cnt) {
        temp = modmul(inv_fact[c], temp);
      }
      ans = modmul(ans, temp);
    }
    return ans;
  }
};