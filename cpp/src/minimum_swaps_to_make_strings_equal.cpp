#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
 public:
  int minimumSwap(string s1, string s2) {
    int n_xy = 0;
    int n_yx = 0;
    for (unsigned i = 0; i < s1.length(); ++i) {
      if (s1[i] != s2[i]) {
        if (s1[i] == 'x') {
          n_xy += 1;
        } else {
          n_yx += 1;
        }
      }
    }
    if ((n_xy + n_yx) % 2 != 0) {
      return -1;
    }

    return (n_xy / 2) + (n_yx / 2) + (n_xy % 2) * 2;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    string s1("xxyyxyxyxx");
    string s2("xyyxyxxxyx");
    cout << s.minimumSwap(s1, s2) << endl;
  }
  return 0;
}
