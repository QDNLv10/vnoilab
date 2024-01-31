// https://oj.vnoi.info/problem/krect

void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define INT long long
#define Array std::vector<std::string>

#define Map std::vector<INT>

INT incVal(Map &b, char key, INT val) {
  b[key - 'A'] += val;
  return b[key - 'A'];
}

void clearMap(Map &b) {
  b.clear();
  for (char c = 'A'; c <= 'Z'; ++c) {
    b.push_back(0);
  }
}

void solve() {
  Map b1, b2;
  INT m, n, k;
  Array a;
  scanf("%lld %lld %lld", &m, &n, &k);
  for (INT i = 0; i < m; ++i) {
    std::string temp;
    std::cin >> temp;
    a.push_back(temp);
  }

  INT ret = 0;
  for (INT ixa = 0; ixa < n; ++ixa) {
    for (INT ixb = ixa; ixb < n; ++ixb) {
      INT iya1 = 0, iya2 = 0, count1 = 0, count2 = 0;
      INT ret1 = 0, ret2 = 0;
      clearMap(b1);
      clearMap(b2);
      for (INT iyb = 0; iyb < m; ++iyb) {

        for (INT i = ixa; i <= ixb; ++i) {
          if (incVal(b1, a[iyb][i], 1) == 1)
            ++count1;
          if (incVal(b2, a[iyb][i], 1) == 1)
            ++count2;
        }

        while (count1 > k) {
          for (INT i = ixa; i <= ixb; ++i) {
            if (incVal(b1, a[iya1][i], -1) == 0)
              --count1;
          }
          ++iya1;
        }

        while (count2 > k - 1) {
          for (INT i = ixa; i <= ixb; ++i) {
            if (incVal(b2, a[iya2][i], -1) == 0)
              --count2;
          }
          ++iya2;
        }

        ret1 += iyb - iya1 + 1;
        ret2 += iyb - iya2 + 1;
      }

      ret += ret1 - ret2;
    }
  }

  printf("%lld\n", ret);
}
