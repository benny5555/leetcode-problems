#include <bits/stdc++.h>
using namespace std;
vector<bool> primes_vector(int n) {
  vector<bool> primes(n, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i < n; ++i) {
    if (primes[i]) {
      int t = n / i;
      for (int j = 2; j < t; ++j) {
        primes[i * j] = false;
      }
    }
  }
  return primes;
}
