#include <cstdio>
#include <vector>

typedef std::vector<int> Array;

int binarySearch(Array &arr, int val) {
  int start = 0, end = arr.size() - 1;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == val)
      return mid;

    if (arr[mid] < val)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}

void solve() {
  Array a{1, 2, 3, 4, 6};
  int ret = binarySearch(a, 5);
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}
