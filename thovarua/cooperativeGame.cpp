#include <cstdio>

char s[100];

int getnumofDiffSpaces() {
  int ret, _;
  scanf("%d", &ret);
  for (int i = 0; i < ret; ++i)
    scanf("%d", &_);

  return ret;
}

void solve() {
  while (true) {
    // 0 is hare and 1 is tortoise
    // Move the hare
    printf("next 0\n");
    fflush(stdout);
    // this line just updates the board.
    getnumofDiffSpaces();
    // then move the tortoise
    printf("next 0 1\n");
    fflush(stdout);
    // if the tortoise meets the hare, stop looping
    if (getnumofDiffSpaces() == 2)
      break;
  }

  while (true) {
    printf("next 0 1 2 3 4 5 6 7 8 9\n");
    fflush(stdout);
    if (getnumofDiffSpaces() == 1)
      break;
  }

  printf("done\n");
  fflush(stdout);
}

int main() {
  solve();
  return 0;
}
