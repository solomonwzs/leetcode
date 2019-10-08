#include <vector>
#include <cstdio>

using namespace std;

class Solution {
 public:
  int minCostToMoveChips(vector<int>& chips) {
    int m[2] = {0, 0};
    for (auto i : chips) {
      m[i & 1] += 1;
    }
    return m[0] < m[1] ? m[0] : m[1];
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<int> chips = {1,2,3};
    printf("%d\n", s.minCostToMoveChips(chips));
  }
  {
    vector<int> chips = {2,2,2,3,3};
    printf("%d\n", s.minCostToMoveChips(chips));
  }
  {
    vector<int> chips = {1,2,2,2,2};
    printf("%d\n", s.minCostToMoveChips(chips));
  }
  {
    vector<int> chips = {6,4,7,8,2,10,2,7,9,7};
    printf("%d\n", s.minCostToMoveChips(chips));
  }
  return 0;
}
