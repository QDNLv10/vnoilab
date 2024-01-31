// https://lqdoj.edu.vn/problem/torhar

void solve();

int main() {
  solve();
  return 0;
}

#include <cstdio>

#define INT long long

struct animal {
  INT remainder, digit, divisor;

  animal(INT num_, INT divisor_) : remainder(num_), divisor(divisor_) {}

  animal &operator()() {
    digit = remainder * 10 / divisor;
    remainder = remainder * 10 % divisor;
    return *this;
  }
};

void solve() {
  INT x, y;
  scanf("%lld %lld", &x, &y);
  INT divident = x, divisor = y;
  INT intpart = divident / divisor, remainder = divident % divisor;
  printf("%lld.", intpart);

  animal tortoise(remainder, divisor), tortoise2(remainder, divisor),
      hare(remainder, divisor);

  do {
    tortoise();
    hare()();
  } while (tortoise.remainder != hare.remainder);

  while (tortoise.remainder != tortoise2.remainder) {
    tortoise();
    tortoise2();
    printf("%lld", tortoise2.digit);
  }

  printf("(");

  do {
    tortoise();
    printf("%lld", tortoise.digit);
  } while (tortoise.remainder != tortoise2.remainder);

  printf(")\n");
  return;
}
