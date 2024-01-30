// https://oj.vnoi.info/problem/ndccard

#include <algorithm>
void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <vector>

#define INT long long
#define Array std::vector<INT>

void solve() {
  Array a;
  INT n, m;
  scanf("%lld %lld", &n, &m);

  for (INT i = 0; i < n; ++i) {
    INT temp;
    scanf("%lld", &temp);
    a.push_back(temp);
  }

  std::sort(a.begin(), a.end());
  INT best = 0;

  for (int ia = 0; ia < n - 1; ++ia) {
    INT m2 = m - a[ia];
    INT ib = ia + 1, ic = n - 1;
    while (ib < ic) {
      INT sum = a[ib] + a[ic];
      if (sum <= m2) {
        best = std::max(best, sum + a[ia]);
        ++ib;
      } else
        --ic;
    }
  }

  printf("%lld\n", best);
}
