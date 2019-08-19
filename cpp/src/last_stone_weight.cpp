#include <map>
#include <vector>

#include "leetcode.h"

using namespace std;


class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    map<int, int> m;
    for (auto it = stones.begin(); it != stones.end(); ++it) {
      m[*it] += 1;
    }

    while (m.size() > 1 || (m.size() == 1 && m.begin()->second > 1)) {
      auto it = --m.end();
      if (it->second > 2) {
        it->second -= 2;
      } else if (it->second == 2) {
        m.erase(it);
      } else {
        int stone1 = it->first;
        --it;
        int stone2 = it->first;
        if (it->second > 1) {
          it->second -= 1;
        } else {
          m.erase(it);
        }
        m.erase(stone1);
        m[stone1 - stone2] += 1;
      }
    }
    return m.size() == 0 ? 0 : m.begin()->first;;
  }
};

int main(int argc, char **argv) {
  Solution s;
  vector<int> stones = vector<int>{2,7,7};
  int ans = s.lastStoneWeight(stones);
  debug_log("%d\n", ans);
  return 0;
}
