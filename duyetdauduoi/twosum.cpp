// https://oj.vnoi.info/problem/twosum

void solve();

int main() {
  solve();
  return 0;
}

#define INT long long

#include <vector>
#define Array std::vector<INT>

#include <cstdio>

void solve() {
  Array a;
  INT n, best = 0;
  scanf("%lld", &n);
  for (int i = 0; i < n; ++i) {
    INT temp;
    scanf("%lld", &temp);
    a.push_back(temp);
  }

  for (INT i = 0; i < n - 1; ++i) {
    INT ia = i, ib = i + 1;
    INT sum = 0, count = 0;
    while (ia >= 0 || ib < n) {
      ++count;
      if (ib == n || (ia >= 0 && sum <= 0))
        sum += a[ia--];
      else
        sum -= a[ib++];

      if (sum == 0)
        best = std::max(best, count);
    }
  }
  printf("%lld", best);
}
