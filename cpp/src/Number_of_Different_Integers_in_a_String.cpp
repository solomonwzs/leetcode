#include <stdio.h>

#include <set>
#include <string>

class Solution {
 public:
  int numDifferentIntegers(std::string word) {
    std::set<std::string> s;
    ssize_t pos = word.find_first_of("1234567890");
    while (pos != std::string::npos) {
      const char *p = word.c_str() + pos + 1;
      for (; p - word.c_str() < word.length() && std::isdigit(*p); ++p) {
      }
      std::string tmp(word.c_str() + pos, p - word.c_str() - pos);
      ssize_t np = tmp.find_first_not_of("0");
      if (np == 0) {
        s.insert(tmp);
      } else if (np == std::string::npos) {
        s.insert("0");
      } else {
        s.insert(tmp.c_str() + np);
      }
      pos = word.find_first_of("1234567890", p - word.c_str());
    }
    return s.size();
  }
};

int main(int argc, char **argv) {
  Solution s;
  int n = s.numDifferentIntegers(argv[1]);
  printf("%d\n", n);
  return 0;
}
