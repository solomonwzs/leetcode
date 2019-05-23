#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  string removeDuplicates(string s) {
    vector<char> stack;
    for (auto ch = s.begin(); ch != s.end(); ++ch) {
      if (!stack.empty() && stack[stack.size() - 1] == *ch) {
        stack.pop_back();
      } else {
        stack.push_back(*ch);
      }
    }

    if (stack.empty()) {
      return "";
    } else {
      return string(stack.begin(), stack.end());
    }
  }
};

int
main(int argc, char **argv) {
  Solution s;
  cout << s.removeDuplicates("abbaca") << endl;
  return 0;
}
