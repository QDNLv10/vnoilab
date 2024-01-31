// https://codeforces.com/gym/100503/problem/D

void solve();

#include <cstdio>

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  solve();
  return 0;
}

#define INT long long

struct Animal {
  INT a, b, c, val;
  Animal(INT a_, INT b_, INT c_, INT val_) : a(a_), b(b_), c(c_), val(val_) {}

  Animal &operator()() {
    val = (a * val + val % b) % c;
    return (*this);
  }
};

void solve() {
  INT a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  Animal start = {a, b, c, 1};
  Animal tortoise = start, hare = start;

  auto check = [](INT &num) {
    if (num > 2e7) {
      printf("-1\n");
      return true;
    }
    return false;
  };

  do {
    tortoise();
    hare()();
  } while (tortoise.val != hare.val);

  Animal tortoise2 = start;

  INT count = 0;
  while (tortoise.val != tortoise2.val) {
    tortoise();
    tortoise2();
    if (check(++count))
      return;
  }

  do {
    tortoise();
    if (check(++count))
      return;
  } while (tortoise.val != tortoise2.val);

  printf("%lld\n", count);
}
