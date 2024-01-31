// https://oj.vnoi.info/problem/krect

void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define INT long long
#define Array std::vector<std::string>

#define Map std::map<char, INT>

INT incVal(Map &b, char key, INT val) {
  if (b.find(key) == b.end()) {
    b[key] = 0;
  }
  b[key] += val;
  return b[key];
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
  for (INT ixb = 0; ixb < n; ++ixb) {
    for (INT ixa = 0; ixa <= ixb; ++ixa) {
      INT iya1 = 0, iya2 = 0, count1 = 0, count2 = 0;
      INT ret1 = 0, ret2 = 0;
      b1.clear();
      b2.clear();
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
