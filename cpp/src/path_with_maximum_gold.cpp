#include <cstdio>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int ans = 0;
    for (unsigned x = 0; x < grid.size(); ++x) {
      for (unsigned y = 0; y < grid[x].size(); ++y) {
        if (grid[x][y] > 0) {
          ans = max(ans, grid[x][y] + dfs(grid, x, y));
        }
      }
    }
    return ans;
  }

 private:
  const static int directions[4][2];

  int dfs(vector<vector<int>> &grid, unsigned x, unsigned y) {
    int tmp = grid[x][y];
    grid[x][y] = 0;
    int res = 0;
    for (int i = 0; i < 4; ++i) {
      int x0 = x + directions[i][0];
      int y0 = y + directions[i][1];
      if (x0 >= 0 && x0 < (int)grid.size() &&
          y0 >= 0 && y0 < (int)grid[x0].size() &&
          grid[x0][y0] != 0) {
        res = max(res, grid[x0][y0] + dfs(grid, x0, y0));
      }
    }
    grid[x][y] = tmp;
    return res;
  }
};

const int Solution::directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    printf("%d\n", s.getMaximumGold(grid));
  }
  return 0;
}
