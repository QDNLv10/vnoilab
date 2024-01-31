// https://oj.vnoi.info/problem/vmquabeo

#include <cmath>
#include <cstdlib>
void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <deque>
#include <vector>

#define INT long long
#define Array std::vector<INT>

void printDeque(std::deque<INT> &d) {
  for (auto val : d) {
    printf("%lld ", val);
  }
  printf("\n");
}

void solve() {
  Array a;
  INT n, l, d;
  INT ret = 0;
  scanf("%lld %lld %lld", &n, &l, &d);
  ++l;
  for (INT i = 0; i < n; ++i) {
    INT temp;
    scanf("%lld", &temp);
    a.push_back(temp);
  }

  std::deque<INT> dmax, dmin;

  int ia = 0;

  for (INT ib = 0; ib < n; ++ib) {
    while (!dmax.empty() && a[dmax.back()] <= a[ib])
      dmax.pop_back();

    while (!dmin.empty() && a[dmin.back()] >= a[ib])
      dmin.pop_back();

    dmax.push_back(ib);
    dmin.push_back(ib);

    while (std::abs(a[dmax.front()] - a[dmin.front()]) > d) {
      ++ia;

      if (dmax.front() < ia)
        dmax.pop_front();

      if (dmin.front() < ia)
        dmin.pop_front();
    }

    if (ib - ia + 1 >= l) {
      ret += (ib - ia + 1) - (l - 1);
    }
  }

  printf("%lld\n", ret);
}
