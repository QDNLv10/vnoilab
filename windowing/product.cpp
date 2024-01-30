// https://oj.vnoi.info/problem/product

#include <algorithm>
#include <cmath>
void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <iostream>
#include <string>

#define INT long long
#define EPS 1e-6
#define LOG(x) log(x) / log(297)

bool equals(double &a, double &b) { return fabs(a - b) < EPS; }

void solve() {

  std::string n;
  std::cin >> n;

  INT lenn = std::min((INT)20, (INT)n.size());
  double temp = 0;
  for (INT i = 0; i < lenn; ++i) {
    temp = temp * 10 + n[i] - '0';
  }
  double logn = LOG(temp) + LOG(10) * (n.size() - lenn);

  INT ia = 1, ib = 1;
  double logprod = 0;
  while (!equals(logprod, logn)) {
    if (logprod > logn) {
      logprod -= LOG(ia++);
    } else {
      logprod += LOG(++ib);
    }
  }
  printf("%lld %lld\n", ia, ib);
}
