#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define m_num(_i) ((int)((_i) & 0xffffffff))
#define m_cnt(_i) ((int)((_i) >> 32))

class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    map<int, int> m;
    for (auto it = barcodes.begin(); it != barcodes.end(); ++it) {
      m[*it] += 1;
    }
    vector<uint64_t> slist;
    slist.reserve(m.size());
    for (auto it = m.begin(); it != m.end(); ++it) {
      slist.push_back((uint64_t)it->second << 32 | (uint64_t)it->first);
    }
    sort(slist.begin(), slist.end());

    vector<int> ans(barcodes.size());
    size_t pos = 0;
    for (auto i = slist.rbegin(); i != slist.rend(); i++) {
      int num = m_num(*i);
      for (int cnt = m_cnt(*i); cnt > 0; --cnt, pos += 2) {
        if (pos >= ans.size()) {
          pos = 1;
        }
        ans[pos] = num;
      }
    }
    return ans;
  }
};

int
main(int argc, char **argv) {
  Solution s;
  {
    auto barcodes = vector<int>{1,1,1,2,2,2};
    auto ans = s.rearrangeBarcodes(barcodes);
    for (size_t i = 0; i < ans.size(); ++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  {
    auto barcodes = vector<int>{7,7,7,8,5,7,5,5,5,8};
    auto ans = s.rearrangeBarcodes(barcodes);
    for (size_t i = 0; i < ans.size(); ++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
