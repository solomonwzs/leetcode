#include <algorithm>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& a, int k) {
    int n = int(a.size());
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      int m = 0;
      for (int j = 1; j <= k && i - j + 1 >= 0; ++j) {
        m = max(m, a[i - j + 1]);
        dp[i] = max(dp[i], (i >= j ? dp[i - j] : 0) + m * j);
      }
    }
    return dp[n - 1];
  }
};

int main(int argc, char **argv) {
  Solution s;
  auto a = vector<int>{1,15,7,9,2,5,10};
  int k = 3;
  debug_log("%d\n", s.maxSumAfterPartitioning(a, k));
  return 0;
}
