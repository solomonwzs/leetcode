#include <cstdio>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    unsigned            m   = mat.size();
    unsigned            n   = mat[0].size();
    int                 ans = 0;
    vector<vector<int>> sum(m, vector<int>(n, 0));

    for (unsigned i = 0; i < m; ++i) {
      for (unsigned j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          sum[i][j] = mat[i][j];
        } else if (i == 0) {
          sum[i][j] = mat[i][j] + sum[i][j - 1];
        } else if (j == 0) {
          sum[i][j] = mat[i][j] + sum[i - 1][j];
        } else {
          sum[i][j] =
              mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

          for (unsigned k = (unsigned)ans; k <= min(i, j) + 1; ++k) {
            int tmp = 0;
            if (k == 0) {
              tmp = 0;
            } else if (k == 1) {
              tmp = mat[i][j];
            } else if (i < k || j < k) {
              tmp = sum[i][j] - (i < k ? 0 : sum[i - k][j]) -
                    (j < k ? 0 : sum[i][j - k]);
            } else {
              tmp = sum[i][j] -
                    (sum[i - k][j] + sum[i][j - k] - sum[i - k][j - k]);
            }

            if (tmp <= threshold && ans < (int)k) {
              ans = k;
            } else if (tmp > threshold || i < k || j < k) {
              break;
            }
          }
        }
      }
    }

    return ans;
  }
};
