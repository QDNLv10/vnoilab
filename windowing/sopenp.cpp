// https://oj.vnoi.info/problem/sopenp

void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <unordered_map>
#include <vector>

#define INT long long
#define Map std::unordered_map<INT, INT>
#define Array std::vector<INT>

INT &incVal(Map &b, INT key, INT val) {
  if (b.find(key) == b.end()) {
    b[key] = 0;
  }
  return b[key] += val;
}

void solve() {
  //
  INT n, l, u;
  scanf("%lld %lld %lld", &n, &l, &u);
  Array a;
  Map b1, b2;
  for (int i = 0; i < n; ++i) {
    INT temp;
    scanf("%lld", &temp);
    a.push_back(temp);
  }

  INT ia1 = 0, ia2 = 0, count1 = 0, count2 = 0;
  INT ret1 = 0, ret2 = 0;
  for (int ib = 0; ib < n; ++ib) {
    if (incVal(b1, a[ib], 1) == 1) {
      ++count1;
    }
    if (incVal(b2, a[ib], 1) == 1) {
      ++count2;
    }

    while (count1 > l - 1) {
      if (incVal(b1, a[ia1++], -1) == 0)
        --count1;
    }

    while (count2 > u) {
      if (incVal(b2, a[ia2++], -1) == 0)
        --count2;
    }

    ret1 += ib - ia1 + 1;
    ret2 += ib - ia2 + 1;
  }
  printf("%lld", ret2 - ret1);
}
