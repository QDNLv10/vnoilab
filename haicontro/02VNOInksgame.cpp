// https://oj.vnoi.info/problem/nksgame

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

#define Array std::vector<int>
#define Loop(n) for (int i = 0; i < n; ++i)

void inpArr(Array &a, int n) {
  a.clear();
  Loop(n) {
    int temp;
    scanf("%d", &temp);
    a.push_back(temp);
  }
}

void sortArr(Array &a) { std::sort(a.begin(), a.end()); }

void solve() {
  int n;
  scanf("%d", &n);
  Array a, b;
  inpArr(a, n);
  inpArr(b, n);
  sortArr(a);
  sortArr(b);

  int ia = 0, ib = n - 1;
  int best = (int)INFINITY;

  while (ia < n - 1 || ib > 0) {
    int sum = a[ia] + b[ib];

    best = std::min(best, abs(sum));

    if (best == 0) {
      printf("0\n");
      return;
    }

    if (ib == 0 || (ia < n - 1 && sum <= 0))
      ++ia;
    else
      --ib;
  }

  printf("%d\n", best);
}

int main() {
  solve();
  return 0;
};
