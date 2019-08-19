#include <cstdio>
#include <vector>

using namespace std;

struct point {
  int i;
  int j;

  point(int i, int j): i(i), j(j) {}
};

static vector<point> directions = vector<point>{point(1, 0), point{0, 1},
  point(-1, 0), point(0, -1)};

class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    int m = (int)grid.size();
    int n = (int)grid[0].size();
    vector<point> plist;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          plist.push_back(point(i, j));
        }
      }
    }

    unsigned len = plist.size();
    unsigned cur = 0;
    int ans = 0;
    while (cur < len) {
      bool add = false;
      for (; cur < len; ++cur) {
        point p = plist[cur];
        for (auto &d : directions) {
          int i0 = p.i + d.i;
          int j0 = p.j + d.j;

          if ((0 <= i0 && i0 < m) && (0 <= j0 && j0 < n) &&
              grid[i0][j0] == 0) {
            add = true;
            grid[i0][j0] = 1;
            plist.push_back(point(i0, j0));
          }
        }
      }
      if (add) { ans += 1; }
      len = plist.size();
    }

    return ans == 0 ? -1 : ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<vector<int>> grid = vector<vector<int>> {
      {1,0,1},
      {0,0,0},
      {1,0,1}
    };
    printf("%d\n", s.maxDistance(grid));
  }
  {
    vector<vector<int>> grid = vector<vector<int>> {
      {1,1,1},
      {1,1,1},
      {1,1,1}
    };
    printf("%d\n", s.maxDistance(grid));
  }
  return 0;
}
