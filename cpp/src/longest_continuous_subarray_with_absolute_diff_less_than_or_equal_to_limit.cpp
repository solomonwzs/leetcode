#include <stdio.h>

#include <algorithm>
#include <set>
#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums, int limit) {
    std::multiset<int> s;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      s.insert(nums[i]);
      while (s.size() > 0 && *s.rbegin() - *s.begin() > limit) {
        s.erase(s.find(nums[j]));
        j += 1;
      }
      ans = std::max(ans, i - j + 1);
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  Solution s;
  {
    std::vector<int> nums = {8, 2, 4, 7};
    printf("%d\n", s.longestSubarray(nums, 4));
  }
  return 0;
}
