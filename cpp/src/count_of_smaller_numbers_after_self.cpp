#include "leetcode.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class FenwickTree {
 private:
  int n;
  vector<int> sumArray;

  inline int lowbit(int x) {
    return x & -x;
  }

 public:
  FenwickTree(int n): n(n), sumArray(n + 1, 0) {}

  void add(int x, int val) {
    while (x <= this->n) {
      this->sumArray[x] += val;
      x += this->lowbit(x);
    }
  }

  int sum(int x) {
    int res = 0;
    while (x > 0) {
      res += sumArray[x];
      x -= this->lowbit(x);
    }
    return res;
  }
};

class Solution {
 private:
  map<int, int> orderDict(vector<int> & nums) {
    map<int, int> dict;
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    int order = 1;
    int prev = sorted[0];
    dict.insert(pair<int, int>(prev, order));
    for (size_t i = 1; i < sorted.size(); i++) {
      if (sorted[i] != prev) {
        order += 1;
        prev = sorted[i];
        dict[prev] = order;
      }
    }
    return dict;
  }

 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    if (nums.size() == 0) {
      return res;
    }

    map<int, int> dict = this->orderDict(nums);
    FenwickTree tree(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      res[i] = tree.sum(dict[nums[i]] - 1);
      tree.add(dict[nums[i]], 1);
    }
    return res;
  }
};

int main(int argc, char **argv) {
  vector<int> nums = {5, 2, 1, 2, 6, 1};
  Solution s;
  vector<int> res = s.countSmaller(nums);
  for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
    debug_log("%d\n", *it);
  }
  return 0;
}
