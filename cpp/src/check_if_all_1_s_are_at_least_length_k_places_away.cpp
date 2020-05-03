#include <vector>

class Solution {
 public:
  bool kLengthApart(std::vector<int>& nums, int k) {
    int prev = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        if (prev != -1 && i - prev - 1 < k) {
          return false;
        }
        prev = i;
      }
    }
    return true;
  }
};

int main(int argc, char **argv) {
  return 0;
}
