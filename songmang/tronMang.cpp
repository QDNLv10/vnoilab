#include <cstdio>
#include <vector>

#define Array std::vector<int>

void tronMang(const Array &a, const Array &b) {
  int ia = 0, ib = 0;
  int na = a.size(), nb = b.size();
  Array c;

  // Song mảng loại 1

  while (ia < na || ib < nb) {
    if (ib == nb || (ia < na && a[ia] < b[ib]))
      c.push_back(a[ia++]);
    else
      c.push_back(b[ib++]);
  }

  for (auto val : c)
    printf("%d ", val);
  printf("\n");
}

int main() { tronMang(Array{2, 2, 3, 5, 7, 8}, Array{1, 3, 4, 5, 6, 9}); }
