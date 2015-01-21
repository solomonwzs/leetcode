#include <string>
#include <vector>
#include "utils.h"

using namespace std;


struct char_count{
  char ch;
  int count;
  char_count(char x, int y): ch(x), count(y){}
};


class Solution {
 public:
  int numDistinct(string S, string T){
    vector<char_count> sc=process_str(S);
    vector<char_count> tc=process_str(T);

    return 0;
  }

 private:
  vector<char_count> process_str(string s){
    vector<char_count> v;

    if (s.size()!=0){
      char_count cc=char_count(s[0], 1);
      
      for (unsigned i=1; i<s.size(); ++i){
        if (s[i]==cc.ch){
          ++cc.count;
        } else{
          v.push_back(cc);
          cc=char_count(s[i], 1);
        }
      }
      v.push_back(cc);
    }

    return v;
  }
};


int main(int argc, char **argv){
  string S=string(argv[1]);
  string T=string(argv[2]);

  Solution s;
  debug_log("%d\n", s.numDistinct(S, T));

  return 0;
}
