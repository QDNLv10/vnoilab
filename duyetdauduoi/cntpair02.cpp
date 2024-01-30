// https://lqdoj.edu.vn/problem/cntpair02

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
  INT n, k;
  scanf("%lld %lld", &n, &k);

  for (INT i = 0; i < n; ++i) {
    INT temp;
    scanf("%lld", &temp);
    a.push_back(temp);
  }

  INT ia = 0, ib = n - 1, count = 0;

  // Duyệt đầu đuôi loại 2

  while (ia < ib) {
    INT sum = a[ia] + a[ib];
    INT tia = ia, tib = ib;
    while (tia < n - 1 && a[tia] == a[tia + 1]) {
      ++tia;
    }

    while (tib > 0 && a[tib] == a[tib - 1]) {
      --tib;
    }

    if (sum == k) {
      if (a[ia] != a[ib]) {
        count += (tia - ia + 1) * (ib - tib + 1);
      }

      else {
        count += (tia - ia) * (tia - ia + 1) / 2;
      }
    }

    if (sum <= k)
      ia = tia + 1;
    else
      ib = tib - 1;
  }

  printf("%lld\n", count);
}
