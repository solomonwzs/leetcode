#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstdio>

using namespace std;

class Solution {
 public:
  int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                            int num_wanted, int use_limit) {
    vector<uint64_t> ol(values.size());
    for (size_t i = 0; i < values.size(); ++i) {
      uint64_t k = (uint64_t)values[i] << 32 | (uint64_t)labels[i];
      ol[i] = k;
    }
    sort(ol.begin(), ol.end());

    int ans = 0;
    unordered_map<int, int> stat;
    for (auto it = ol.rbegin(); it != ol.rend() && num_wanted > 0; ++it) {
      int value = (int)(*it >> 32);
      int label = (int)(*it & 0xffffffff);

      auto s = stat.find(label);
      if (s == stat.end()) {
        stat[label] = 1;
        ans += value;
        num_wanted -= 1;
      } else if (s->second < use_limit) {
        s->second += 1;
        ans += value;
        num_wanted -= 1;
      }
    }

    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<int> values = {5, 4, 3, 2, 1};
    vector<int> labels = {1, 1, 2, 2, 3};
    printf("%d\n", s.largestValsFromLabels(values, labels, 3, 1));
  }
  {
    vector<int> values = {5, 4, 3, 2, 1};
    vector<int> labels = {1, 3, 3, 3, 2};
    printf("%d\n", s.largestValsFromLabels(values, labels, 3, 2));
  }
  return 0;
}
