// https://lqdoj.edu.vn/problem/findpair

#include <cstdio>
void solve();
int main() {
  solve();
  return 0;
}

#include <vector>

#define INT long long
#define Array std::vector<INT>

void solve() {
  Array a;
  INT n, x;
  scanf("%lld %lld", &n, &x);
  for (int i = 0; i < n; ++i) {
    INT temp;
    scanf("%lld", &temp);
    a.push_back(temp);
  }

  // Duyệt đầu đuôi loại 2.

  INT ia = 0, ib = n - 1;
  while (ia < ib) {
    int sum = a[ia] + a[ib];

    if (sum == x) {
      printf("%lld %lld\n", ia + 1, ib + 1);
      return;
    }

    if (sum <= x)
      ++ia;
    else
      --ib;
  }

  printf("No solution\n");
}
