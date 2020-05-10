#include <stdio.h>

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    auto it = target.begin();
    for (int i = 1; i <= n && it != target.end(); ++i) {
      ans.push_back("Push");
      if (i == *it) {
        ++it;
      } else {
        ans.push_back("Pop");
      }
    }
    return ans;
  }
};

int main(int argc, char** argv) {
  Solution s;
  {
    vector<int> target = {1, 2};
    auto ans = s.buildArray(target, 4);
    for (auto s : ans) {
      printf("%s ", s.c_str());
    }
    printf("\n");
  }
  return 0;
}
