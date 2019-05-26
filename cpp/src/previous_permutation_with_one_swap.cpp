#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> prevPermOpt1(vector<int>& a) {
    size_t idx = a.size();
    for (size_t i = 0; i < a.size() - 1; ++i) {
      if (a[i] > a[i + 1]) {
        idx = i;
      }
    }

    if (idx < a.size()){
      size_t k = idx + 1;
      for (size_t j = idx + 1; j < a.size(); ++j) {
        if (a[j] < a[idx] && a[j] > a[k]) {
          k = j;
        }
      }

      int tmp = a[k];
      a[k] = a[idx];
      a[idx] = tmp;
    }
    return a;
  }
};

int
main(int argc, char **argv) {
  Solution s;
  auto a = vector<int>{3,2,1};
  auto b = s.prevPermOpt1(a);
  for (auto it = b.begin(); it != b.end(); ++it) {
    cout << *it << ' ';
  }
  cout << endl;
  return 0;
}
