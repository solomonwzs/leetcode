#include <string.h>

#include <map>
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::string evaluate(std::string s,
                       std::vector<std::vector<std::string>> &knowledge) {
    std::map<std::string, std::string> m;
    for (auto i : knowledge) {
      m.insert(std::pair<std::string, std::string>(i[0], i[1]));
    }

    std::string ans;
    const char *p = s.c_str();
    for (;;) {
      const char *left = strchr(p, '(');
      if (left == nullptr) {
        ans.append(p);
        break;
      }
      ans.append(p, left - p);

      const char *right = strchr(left, ')');
      std::string key(left + 1, right - left - 1);
      auto it = m.find(key);
      if (it == m.end()) {
        ans.push_back('?');
      } else {
        ans.append(it->second);
      }
      p = right + 1;
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    std::vector<std::vector<std::string>> knowledge = {{"name", "bob"},
                                                       {"age", "two"}};
    printf("%s\n", s.evaluate("(name)is(age)yearsold", knowledge).c_str());
  }
  {
    std::vector<std::vector<std::string>> knowledge = {{"a", "b"}};
    printf("%s\n", s.evaluate("hi(name)", knowledge).c_str());
  }
  return 0;
}
