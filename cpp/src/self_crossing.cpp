#include <vector>
#include "utils.h"

using namespace std;

#define check6(_l0, _l1, _l2, _l3, _l4, _l5) \
    ((_l1) + (_l5) >= (_l3) && (_l0) + (_l4) >= (_l2) && \
     (_l2) >= (_l4) && (_l2) >= (_l0) && \
     (_l3) >= (_l5) && (_l3) >= (_l1))

#define check5(_l0, _l1, _l2, _l3, _l4) \
    ((_l1) == (_l3) && (_l0) + (_l4) == (_l2))

#define check4(_l0, _l1, _l2, _l3) \
    ((_l3) >= (_l1) && (_l0) >= (_l2))

class Solution {
 public:
  bool isSelfCrossing(vector<int> &x){
    for (size_t i = 3; i < x.size(); i++) {
      int l0 = x[i];
      int l1 = x[i - 1];
      int l2 = x[i - 2];
      int l3 = x[i - 3];
      int l4;
      int l5;

      if (check4(l0, l1, l2, l3)){
        return true;
      }
      if (i >= 4) {
        l4 = x[i - 4];
        if (check5(l0, l1, l2, l3, l4)) {
          return true;
        }
      }
      if (i >= 5) {
        l5 = x[i - 5];
        if (check6(l0, l1, l2, l3, l4, l5)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char **argv) {
  // vector<int> x = {2, 1, 1, 2};
  // vector<int> x = {1, 1, 2, 1, 1}; // 1
  // vector<int> x = {3, 3, 3, 2, 1, 1}; // 0
  vector<int> x = {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1}; // 0
  Solution s;
  debug_log("%d\n", s.isSelfCrossing(x));
  return 0;
}
