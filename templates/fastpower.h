long long fastpower(long long base, long long n, long long mod) {
  long long ans = 1;
  while (n) {
    if (n & 1) {
      ans = ans * base % mod;
    }
    base = base * base % mod;
    n >>= 1;
  }
  return ans;
}