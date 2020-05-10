#include <stdio.h>

#include <list>
#include <vector>

using std::list;
using std::vector;

class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<int> fa(n, -1);
    list<int> l;
    for (size_t i = 0; i < edges.size(); ++i) {
      fa[edges[i][1]] = edges[i][0];
    }
    for (size_t i = 0; i < hasApple.size(); ++i) {
      if (hasApple[i]) {
        l.push_back(i);
      }
    }

    while (l.size() != 0) {
      int child = *l.begin();
      int father = fa[child];
      // printf("%d-%d\n", father, child);
      l.pop_front();

      if (father == -1 || hasApple[father]) {
        continue;
      }
      hasApple[father] = true;
      l.push_back(father);
    }

    int cnt = 0;
    for (size_t i = 0; i < hasApple.size(); ++i) {
      if (hasApple[i]) {
        // printf(":%ld\n", i);
        cnt += 1;
      }
    }
    return cnt == 0 ? 0 : (cnt - 1) * 2;
  }
};

int main(int argc, char** argv) {
  Solution s;
  {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4},
                                 {1, 5}, {2, 3}, {2, 6}};
    vector<bool> hasApple = {false, false, true, false, false, true, false};
    printf("%d\n", s.minTime(7, edges, hasApple) == 6);
  }
  {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {0, 4}};
    vector<bool> hasApple = {false, false, false, true, false};
    printf("%d\n", s.minTime(5, edges, hasApple) == 4);
  }
  return 0;
}
