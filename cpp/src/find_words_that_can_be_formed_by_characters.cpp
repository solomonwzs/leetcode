#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int cnt_chars[26] = {0};
    for (auto &ch : chars) {
      cnt_chars[ch - 'a'] += 1;
    }

    int ans = 0;
    for (auto &word : words) {
      int cnt_word_chars[26] = {0};
      for (auto &ch : word) {
        cnt_word_chars[ch - 'a'] += 1;
      }

      bool ok = true;
      for (int i = 0; i < 26; ++i) {
        if (cnt_word_chars[i] > cnt_chars[i]) {
          ok = false;
          break;
        }
      }

      if (ok) {
        ans += word.length();
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    vector<string> words = {"cat","bt","hat","tree"};
    printf("%d\n", s.countCharacters(words, "atach"));
  }
  {
    vector<string> words = {"hello","world","leetcode"};
    printf("%d\n", s.countCharacters(words, "welldonehoneyr"));
  }
  return 0;
}
