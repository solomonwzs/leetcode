#include <cstdio>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    map<int, set<int>> m;
    for (unsigned i = 0; i < arr.size(); ++i) {
      m[arr[i]].insert(i);
    }

    vector<int> mlen(arr.size(), 1);
    for (unsigned i = 0; i < arr.size() - 1; ++i) {
      int next = arr[i] + difference;
      auto x = m.find(next);
      if (x != m.end()) {
        for (auto j = x->second.upper_bound(i); j != x->second.end(); ++j) {
          if (mlen[*j] < mlen[i] + 1) {
            mlen[*j] = mlen[i] + 1;
          }
        }
      }
    }

    int ans = 1;
    for (auto i : mlen) {
      ans = max(i, ans);
    }

    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<int> arr = {1,3,5,7};
    printf("%d\n", s.longestSubsequence(arr, 1));
  }
  {
    vector<int> arr = {1,5,7,8,5,3,4,2,1};
    printf("%d\n", s.longestSubsequence(arr, -2));
  }
  return 0;
}
