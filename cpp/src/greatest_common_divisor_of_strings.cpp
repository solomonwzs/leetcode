#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    size_t minlen = min(str1.length(), str2.length());
    for (size_t len = minlen; len > 0; --len) {
      if (str1.length() % len != 0 || str2.length() % len != 0) {
        continue;
      }

      string sub = str1.substr(0, len);
      bool ok = true;
      for (size_t i = len; ok && i < str1.length(); i += len) {
        if (sub != str1.substr(i, len)) {
          ok = false;
          break;
        }
      }

      for (size_t i = 0; ok && i < str2.length(); i += len) {
        if (sub != str2.substr(i, len)) {
          ok = false;
          break;
        }
      }

      if (ok) {
        return sub;
      }
    }
    return "";
  }
};

int main(int argc, char **argv) {
  Solution s;
  cout << s.gcdOfStrings("ABCABC", "ABC") << endl;
  cout << s.gcdOfStrings("ABABAB", "ABAB") << endl;
  cout << s.gcdOfStrings("LEFT", "CODE") << endl;
  return 0;
}
