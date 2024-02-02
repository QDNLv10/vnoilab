// https://oj.vnoi.info/problem/power

#include <cmath>
void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>

#define INT long long
#define EPS 1e-5

bool running(int cand, INT l, INT r, int &ret) {
  float temp = log(r) / log(cand);
  float itemp = std::floor(temp);
  float r2 = std::pow(cand, itemp);

  if (r2 >= l) {
    ret = (int)temp;
    return false;
  }
  return true;
}

void testcase(int ord) {
  INT l, r;
  scanf("%lld %lld", &l, &r);
  int ret;
  int cand = 1;
  while (running(cand + 1, l, r, ret)) {
    ++cand;
  }

  printf("Case #%d: %d\n", ord + 1, ret);
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    testcase(i);
}
