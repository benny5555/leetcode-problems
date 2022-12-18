template <typename T>
struct UnionFind {
  vector<T> parent, size;
  UnionFind(int n) : parent(n), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }
  T find(T x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void unite(T u, T v) {
    T pu = find(u), pv = find(v);
    if (pu != pv) {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
  }
};