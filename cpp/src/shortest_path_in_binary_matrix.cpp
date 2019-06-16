#include <vector>
#include <cstdio>

using namespace std;

static int directions[8][2] = {
  {-1, -1}, {-1,  0}, {-1,  1},
  { 0, -1},           { 0,  1},
  { 1, -1}, { 1,  0}, { 1,  1}
};

struct location {
  int row;
  int col;
};

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    size_t n = grid.size();
    auto p = vector<vector<int>>(n);
    for (size_t i = 0; i < n; ++i) {
      p[i] = vector<int>(n);
      for (size_t j = 0; j < n; ++j) {
        p[i][j] = -1;
      }
    }

    vector<struct location> l;
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
      return -1;
    }

    l.push_back({0, 0});
    p[0][0] = 1;
    for (size_t i = 0; i < l.size() && p[n - 1][n - 1] == -1; ++i) {
      int row = l[i].row;
      int col = l[i].col;
      for (size_t j = 0; j < 8; ++j) {
        int nrow = l[i].row + directions[j][0];
        int ncol = l[i].col + directions[j][1];
        if (0 <= nrow && nrow < (int)n && 0 <= ncol && ncol < (int)n &&
            grid[nrow][ncol] == 0 &&  p[nrow][ncol] == -1) {
          p[nrow][ncol] = p[row][col] + 1;
          l.push_back({nrow, ncol});
        }
      }
    }
    return p[n - 1][n - 1];
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto grid = vector<vector<int>> {
      {0, 1},
      {1, 0},
    };
    printf("%d\n", s.shortestPathBinaryMatrix(grid));
  }
  {
    auto grid = vector<vector<int>> {
      {0, 0, 0},
      {1, 1, 0},
      {1, 1, 0},
    };
    printf("%d\n", s.shortestPathBinaryMatrix(grid));
  }
  return 0;
}
