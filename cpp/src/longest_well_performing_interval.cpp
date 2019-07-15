#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

class Solution {
 public:
  int longestWPI(vector<int>& hours) {
    int k = 0;
    int ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < (int)hours.size(); ++i) {
      k += hours[i] > 8 ? 1 : -1;
      if (k > 0) {
        ans = i + 1;
      } else {
        if (m.find(k) == m.end()) {
          m[k] = i;
        }
        if (m.find(k - 1) != m.end()) {
          ans = max(ans, i - m[k - 1]);
        }
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<int> hours = {9,9,6,0,6,6,9};
    printf("%d\n", s.longestWPI(hours));
  }
  {
    vector<int> hours = {6,9,9};
    printf("%d\n", s.longestWPI(hours));
  }
  {
    vector<int> hours = {6,6,9};
    printf("%d\n", s.longestWPI(hours));
  }
  return 0;
}
