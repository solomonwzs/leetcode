#include <vector>
#include <map>
#include <cstdio>

using namespace std;

class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> m;
    for (auto &e : arr1) {
      m[e] += 1;
    }

    vector<int> ans = vector<int>(arr1.size());
    int i = 0;
    for (auto &e : arr2) {
      for (int j = 0; j < m[e]; ++j) {
        ans[i++] = e;
      }
      m.erase(e);
    }
    for (auto &e : m) {
      for (int j = 0; j < e.second; ++j) {
        ans[i++] = e.first;
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    auto ans = s.relativeSortArray(arr1, arr2);
    for (auto &i : ans) {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
