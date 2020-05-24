#include <stdio.h>
#include <string.h>

#include <string>

class Solution {
 public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    int ans = 0;
    size_t found = 0;
    for (found = sentence.find_first_not_of(" ", found);
         found != std::string::npos;) {
      ans += 1;
      if (strncmp(sentence.c_str() + found, searchWord.c_str(),
                  searchWord.length()) == 0) {
        return ans;
      }
      found = sentence.find_first_of(" ", found);
      found = sentence.find_first_not_of(" ", found);
    }
    return -1;
  }
};

int main(int argc, char **argv) {
  Solution s;
  printf("%d\n", s.isPrefixOfWord("i love eating burger", "burg"));
  printf("%d\n", s.isPrefixOfWord("i am tired", "burg"));
  return 0;
}
