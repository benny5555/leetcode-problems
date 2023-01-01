#include <bits/stdc++.h>
using namespace std;

vector<int> prime_factors(long input) {
  vector<int> ans;
  for (int i = 2; input >= 2;) {
    if (input % i == 0) {
      ans.push_back(i);
      input /= i;
    } else {
      i++;
    }
  }
  return ans;
}