#include <string>
#include <vector>
#include "leetcode.h"

using namespace std;


class Solution {
 public:
  //int numDistinct(string S, string T){
  //  unsigned slen=S.size();
  //  unsigned tlen=T.size();

  //  if (slen<tlen){
  //    return 0;
  //  } else if (tlen==0){
  //    return 1;
  //  }

  //  vector<int> r1(slen);
  //  r1[0]=S[0]==T[0]?1:0;
  //  for (unsigned i=1; i<slen; ++i){
  //    r1[i]=S[i]==T[0]?r1[i-1]+1:r1[i-1];
  //  }

  //  for (unsigned ti=1; ti<tlen; ++ti){
  //    vector<int> r0=r1;

  //    r1[ti-1]=0;
  //    for (unsigned si=ti; si<slen; ++si){
  //      r1[si]=S[si]==T[ti]?r0[si-1]+r1[si-1]:r1[si-1];
  //    }
  //  }

  //  return r1[slen-1];
  //}

  int numDistinct(string S, string T){
    unsigned slen=S.size();
    unsigned tlen=T.size();

    if (slen<tlen){
      return 0;
    } else if (tlen==0){
      return 1;
    }

    vector<vector<int> > v(tlen);
    v[0]=vector<int>(slen);
    v[0][0]=S[0]==T[0]?1:0;
    for (unsigned i=1; i<slen; ++i){
      v[0][i]=S[i]==T[0]?v[0][i-1]+1:v[0][i-1];
    }

    for (unsigned ti=1; ti<tlen; ++ti){
      v[ti]=vector<int>(slen-ti);
      v[ti][0]=(S[ti]==T[ti] && v[ti-1][0]==1)?1:0;
      for (unsigned si=ti+1; si<slen; ++si){
        int idx=si-ti;
        v[ti][idx]=S[si]==T[ti]?v[ti-1][idx]+v[ti][idx-1]:v[ti][idx-1];
      }
    }

    return v[tlen-1][slen-tlen];
  }
};


int main(int argc, char **argv){
  string S=string(argv[1]);
  string T=string(argv[2]);

  Solution s;
  debug_log("%d\n", s.numDistinct(S, T));

  return 0;
}
