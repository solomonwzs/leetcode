#include <stdio.h>

#include <algorithm>
#include <string>

#define is_vowel(ch) \
  (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')

class Solution {
 public:
  int maxVowels(std::string s, int k) {
    size_t l = 0;
    size_t r = std::min((size_t)k, s.length());

    int ans = 0;
    for (size_t i = l; i < r; ++i) {
      if (is_vowel(s[i])) {
        ans += 1;
      }
    }

    int n = ans;
    for (r = r + 1; r <= s.length(); ++r) {
      if (is_vowel(s[l])) {
        n -= 1;
      }
      if (is_vowel(s[r - 1])) {
        n += 1;
      }
      l += 1;
      // printf("%s %d\n", s.substr(l, k).c_str(), n);
      if (n > ans) {
        ans = n;
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  printf("%d\n", s.maxVowels("abciiidef", 3));
  printf("%d\n", s.maxVowels("weallloveyou", 7));
  return 0;
}
