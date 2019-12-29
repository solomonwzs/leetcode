#include <cstdio>
#include <vector>

using namespace std;

vector<int> genSequentialDigits() {
  static vector<int> d =
      vector<int>{111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
  vector<int> res = vector<int>{12, 23, 34, 45, 56, 67, 78, 89};
  unsigned    di  = 0;
  unsigned    i   = 0;
  int         h   = 100;
  int         hn  = 0;
  while (i < res.size() && di < d.size()) {
    if (d[di] < res[i]) {
      di += 1;
      h *= 10;
      hn = 0;
    } else {
      int x = res[i] + d[di] + h * hn;
      hn += 1;
      if (x % 10 != 0) {
        res.push_back(x);
      }
      i += 1;
    }
  }
  return res;
}

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> res;
    for (auto i : m_diglist) {
      if (low <= i && i <= high) {
        res.push_back(i);
      }
    }
    return res;
  }

 private:
  static vector<int> m_diglist;
};

vector<int> Solution::m_diglist = genSequentialDigits();

int main(int argc, char **argv) {
  vector<int> res = genSequentialDigits();
  for (auto i : res) {
    printf("%d ", i);
  }
  return 0;
}
