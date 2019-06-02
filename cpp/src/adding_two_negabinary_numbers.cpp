#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    if (arr1.size() < arr2.size()) {
      return addNegabinary(arr2, arr1);
    }
    
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    size_t n = arr1.size();
    vector<int> ans(n + 2);

    for (size_t i = 0; i < n; ++i) {
      ans[i] += arr1[i];
      if (i < arr2.size()) {
        ans[i] += arr2[i];
      }

      if (ans[i] > 1) {
        ans[i] -= 2;
        ans[i + 1] -= 1;
      } else if (ans[i] < 0) {
        ans[i] += 2;
        ans[i + 1] += 1;
      }
    }

    if (ans[n] == 0) {
      ans.pop_back();
      ans.pop_back();
    } else if (ans[n] == 1) {
      ans.pop_back();
    } else if (ans[n] < 0){
      ans[n] += 2;
      ans[n + 1] = 1;
    }

    while (*ans.rbegin() == 0 && ans.size() > 1) {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto arr1 = vector<int>{1, 1, 1, 1, 1};
    auto arr2 = vector<int>{1, 0, 1};
    for (auto i : s.addNegabinary(arr1, arr2)) {
      cout << i;
    }
    cout << endl;
  }
  {
    auto arr1 = vector<int>{1};
    auto arr2 = vector<int>{1, 1};
    for (auto i : s.addNegabinary(arr1, arr2)) {
      cout << i;
    }
    cout << endl;
  }
  return 0;
}
