#include <vector>
#include <cstdio>

using namespace std;

class Solution {
 public:
  int maximumSum(vector<int>& arr) {
    int keep = 0;
    int del = 0;
    int ans = arr[0];
    if (arr.size() == 1) {
      return ans;
    }

    int max_num = arr[0];
    for (auto &i : arr) {
      if (i >= 0) {
        del += i;
      } else {
        del = max(del + i, keep);
      }
      keep += i;

      ans = max(ans, max(keep, del));
      keep = max(keep, 0);
      del = max(del, 0);
      max_num = max(max_num, i);
    }

    return ans == 0 ? max_num : ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<int> arr = {1, -2, 0, 3, -5, -6, 10};
    printf("%d\n", s.maximumSum(arr));
  }
  {
    vector<int> arr = {1, -2, -2, 3};
    printf("%d\n", s.maximumSum(arr));
  }
  {
    vector<int> arr = {-1, -1, -1, -1};
    printf("%d\n", s.maximumSum(arr));
  }
  return 0;
}
