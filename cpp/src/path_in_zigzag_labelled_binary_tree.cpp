#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    int row = 1;
    for (int i = 1; (i << row) - 1 < label; ++row);

    vector<int> ans(row);
    ans[row - 1] = label;
    for (int i = row - 2; i >= 0; --i) {
      int a = 1 << i;
      int b = (1 << (i + 1)) - 1;

      int x = label >> 1;
      ans[i] = a + b - x;
      label = ans[i];
    }

    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto ans = s.pathInZigZagTree(14);
    for (unsigned i = 0; i < ans.size(); ++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  {
    auto ans = s.pathInZigZagTree(26);
    for (unsigned i = 0; i < ans.size(); ++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
