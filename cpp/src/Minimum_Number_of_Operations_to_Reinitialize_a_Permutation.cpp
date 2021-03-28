#include <stdio.h>
#include <stdlib.h>

class Solution {
 public:
  int reinitializePermutation(int n) {
    int m = 1;
    int cnt = 0;
    do {
      m = (m & 1) == 0 ? m / 2 : m / 2 + n / 2;
      cnt += 1;
    } while (m != 1);
    return cnt;
  }
};

int main(int argc, char **argv) {
  Solution s;
  printf("%d\n", s.reinitializePermutation(atoi(argv[1])));
  return 0;
}
