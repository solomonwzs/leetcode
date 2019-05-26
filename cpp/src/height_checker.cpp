#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> order = vector<int>(heights.size());
    for (size_t i = 0; i < heights.size(); ++i) {
      order[i] = heights[i];
    }

    std::sort(order.begin(), order.end());
    int ans = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
      if (order[i] != heights[i]) {
        ans += 1;
      }
    }
    return ans;
  }
};


int
main(int argc, char **argv) {
  Solution s;
  auto h = vector<int>{1, 1, 4, 2, 1, 3};
  cout << s.heightChecker(h) << endl;
  return 0;
}
