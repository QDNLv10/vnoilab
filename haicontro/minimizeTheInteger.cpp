// https://codeforces.com/problemset/problem/1251/C

#include <cstdio>
#include <iostream>
#include <string>

void solve();

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    solve();
  return 0;
}

void solve() {
  std::string even, odd, inp;
  std::cin >> inp;
  for (char c : inp) {
    if (c % 2)
      odd.push_back(c);
    else
      even.push_back(c);
  }

  int ie = 0, io = 0, ne = even.size(), no = odd.size();
  while (ie < ne || io < no) {

    if (io == no || (ie < ne && even[ie] < odd[io]))
      printf("%c", even[ie++]);
    else
      printf("%c", odd[io++]);
  }
  printf("\n");
}
