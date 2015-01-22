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
    unsigned slen=S.size();
    unsigned tlen=T.size();

    vector<int> r0(slen);
    vector<int> r1(slen);

    r0[0]=S[0]==T[0]?1:0;
    for (unsigned i=1; i<slen; ++i){
      r0[i]=S[i]==T[0]?r0[i]+1:r0[i];
    }

    for (unsigned ti=1; ti<tlen; ++ti){
      r1[ti]=(r0[ti-1]!=0 && S[ti]==T[ti])?1:0;
      for (unsigned si=ti+1; si<slen; ++si){
        if (S[si]!=T[ti]){
          r1[si]=r1[si-1];
        } else{
          r1[si]=r0[si];
        }
      }
    }

    return 0;
  }
};


int main(int argc, char **argv){
  string S=string(argv[1]);
  string T=string(argv[2]);

  Solution s;
  debug_log("%d\n", s.numDistinct(S, T));

  return 0;
}
