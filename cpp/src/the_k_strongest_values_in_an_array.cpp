#include <stdio.h>

#include <algorithm>
#include <vector>

struct num_t {
  int ori;
  int nval;
};

bool comp(num_t a, num_t b) {
  return (a.nval > b.nval) || (a.nval == b.nval && a.ori > b.ori);
}

class Solution {
 public:
  std::vector<int> getStrongest(std::vector<int>& arr, int k) {
    std::sort(arr.begin(), arr.end());
    int mid = arr[(arr.size() - 1) / 2];

    std::vector<num_t> arr0;
    for (size_t i = 0; i < arr.size(); ++i) {
      arr0.push_back(num_t{arr[i], std::abs(arr[i] - mid)});
    }

    std::vector<int> ans;
    std::sort(arr0.begin(), arr0.end(), comp);

    // for (size_t i = 0; i < arr0.size(); ++i) {
    //   printf("%d ", arr0[i].nval);
    // }
    // printf("\n");

    for (int i = 0; i < k; ++i) {
      ans.push_back(arr0[i].ori);
    }

    return ans;
  }
};

int main(int argc, char** argv) {
  Solution s;
  {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> ans = s.getStrongest(arr, 2);
    for (size_t i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  {
    std::vector<int> arr = {1, 1, 3, 5, 5};
    std::vector<int> ans = s.getStrongest(arr, 2);
    for (size_t i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
