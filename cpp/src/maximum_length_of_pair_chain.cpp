#include <vector>
#include <algorithm>
#include <limits>
#include "leetcode.h"

using namespace std;


static bool
less_second(const vector<int> &p0, const vector<int> &p1) {
  return p0[1] < p1[1];
}


class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), less_second);

    vector<int> dp(pairs.size() + 1);
    dp[0] = numeric_limits<int>::min();
    unsigned len = 1;
    for (vector<vector<int>>::iterator pair = pairs.begin();
         pair != pairs.end();
         ++pair) {
      int x = (*pair)[0];
      int y = (*pair)[1];

      unsigned ix = lower_bound(dp.begin(), dp.begin() + len, x) - dp.begin();
      if (ix == len) {
        dp[len] = y;
        len += 1;
      } else if (y < dp[ix]) {
        dp[ix] = y;
      }
    }

    return len - 1;
  }
};


int
main(int argc, char **argv){
  vector<vector<int>> pairs(3);

  pairs[0] = vector<int>(2);
  pairs[0][0] = 3;
  pairs[0][1] = 4;

  pairs[1] = vector<int>(2);
  pairs[1][0] = 2;
  pairs[1][1] = 3;

  pairs[2] = vector<int>(2);
  pairs[2][0] = 1;
  pairs[2][1] = 2;

  Solution s;
  int len = s.findLongestChain(pairs);

  debug_log("%d\n", len);

  return 0;
}
