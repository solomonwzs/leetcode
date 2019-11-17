#include <vector>
#include <cstdio>

using namespace std;

class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    size_t n = grid.size();
    size_t m = grid[0].size();
    k = k % (n * m);
    if (k == 0) {
      return grid;
    }

    k = (n * m) - k;
    vector<vector<int>> res;
    int x = k / m;
    int y = k % m;
    for (size_t i = 0; i < n; ++i) {
      res.push_back(vector<int>(m));
      for (size_t j = 0; j < m; ++j) {
        res[i][j] = grid[x][y];

        y += 1;
        if (y == (int)m) {
          y = 0;
          x += 1;
        }
        if (x == (int)n) {
          x = 0;
        }
      }
    }
    return res;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<vector<int>> grid = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
    vector<vector<int>> res = s.shiftGrid(grid, 3);
    for (size_t i = 0; i < res.size(); ++i) {
      for (size_t j = 0; j < res[0].size(); ++j) {
        printf("%d ", res[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
