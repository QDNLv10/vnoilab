// https://codeforces.com/problemset/problem/1036/D

void solve();
int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <vector>

#define Array std::vector<int>
#define INT long long

void inpArr(Array &a, int n) {
  for (int i = 0; i < n; ++i) {
    INT temp;
    scanf("%lld", &temp);
    a.push_back(temp);
  }
}

void solve() {
  INT m, n;
  Array a, b;
  scanf("%lld", &m);
  inpArr(a, m);
  scanf("%lld", &n);
  inpArr(b, n);

  INT sum = 0;
  INT count = 0;
  INT ia = 0, ib = 0;

  // Song mảng loại 1

  while (ia < m || ib < n) {
    if (ib == n || (ia < m && sum <= 0))
      sum += a[ia++];
    else
      sum -= b[ib++];

    if (sum == 0)
      ++count;
  }

  if (count < 1 || sum != 0)
    printf("-1\n");
  else
    printf("%lld\n", count);
}
