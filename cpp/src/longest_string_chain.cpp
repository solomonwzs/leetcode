#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool sort_by_length(string &i, string &j) { return i.length() > j.length(); }

class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    map<string, int> m;
    for (string word : words) {
      m[word] = 1;
    }

    sort(words.begin(), words.end(), sort_by_length);
    size_t minlen = words.rbegin()->length();

    int ans = 1;
    for (string word : words) {
      if (word.length() == minlen) {
        break;
      }
      int n = m.find(word)->second;

      string subword = word.substr(1, word.length() - 1);
      size_t i = 0;
      while (1) {
        auto it = m.find(subword);
        if (it != m.end() && n + 1 > it->second) {
          it->second = n + 1;
          if (it->second > ans) {
            ans = it->second;
          }
        }

        if (i < subword.length()) {
          subword[i] = word[i];
          ++i;
        } else {
          break;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  auto words = vector<string>{"a","b","ba","bca","bda","bdca"};
  cout << s.longestStrChain(words) << endl;
  return 0;
}
