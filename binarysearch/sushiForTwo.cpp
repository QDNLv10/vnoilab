// https://codeforces.com/problemset/problem/1138/A

void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>
#include <vector>

typedef std::vector<int> Array;

void solve() {
  int n;
  scanf("%d", &n);
  Array arr;
  for (int i = 0; i < n; ++i) {
    int temp;
    scanf("%d", &temp);
    arr.push_back(temp);
  }
  int best = 0;
  int count = 0;
  int countpre = 0;

  int i = 0;
  while (i < n - 1 && arr[i] == arr[0]) {
    ++count;
    ++i;
  }

  for (; i < n; ++i) {
    if (arr[i] == arr[i - 1]) {
      ++count;

    } else {
      best = std::max(best, std::min(count, countpre));
      countpre = count;
      count = 1;
    }
  }
  best = std::max(best, std::min(count, countpre));

  printf("%d\n", best * 2);
}
