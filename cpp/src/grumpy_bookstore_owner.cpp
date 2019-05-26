#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int x) {
    auto update = vector<int>(customers.size());
    update[0] = 0;
    for (int i = 0; i < x; ++i) {
      if (grumpy[i] == 1) {
        update[0] += customers[i];
      }
    }
    int m = update[0];
    for (size_t i = 1; i < customers.size(); ++i) {
      update[i] = update[i - 1];
      if (grumpy[i - 1] == 1) {
        update[i] -= customers[i - 1];
      }
      if (i + x - 1 < customers.size() && grumpy[i + x - 1] == 1) {
        update[i] += customers[i + x - 1];
      }
      if (m < update[i]) {
        m = update[i];
      }
    }

    int ans = 0;
    for (size_t i = 0; i < customers.size(); ++i) {
      if (grumpy[i] == 0) {
        ans += customers[i];
      }
    }
    return ans + m;
  }
};

int
main(int argc, char **argv) {
  Solution s;
  auto c = vector<int>{1,0,1,2,1,1,7,5};
  auto g = vector<int>{0,1,0,1,0,1,0,1};
  cout << s.maxSatisfied(c, g, 3) << endl;
  return 0;
}
