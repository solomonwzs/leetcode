#include "leetcode.h"

using namespace std;


class Solution{
 public:
  bool isInterleave(string s1, string s2, string s3){
    int len1=s1.size();
    int len2=s2.size();
    int len3=s3.size();

    if (len1+len2!=len3){
      return false;
    }

    vector<vector<bool> > m(len1+1);
    for (int i=0; i<len1+1; ++i){
      m[i]=vector<bool>(len2+1);
      for (int j=0; j<len2+1; ++j){
        m[i][j]=false;
      }
    }
    m[0][0]=true;

    for (int l3=1; l3<=len3; ++l3){
      bool ok=false;
      for (int l1=l3-len2<0?0:l3-len2; l1<=l3 && l1<=len1; ++l1){
        int l2=l3-l1;
        m[l1][l2]=(l1>0 && m[l1-1][l2] && s1[l1-1]==s3[l3-1])
            || (l2>0 && m[l1][l2-1] && s2[l2-1]==s3[l3-1]);

        if (m[l1][l2]){
          ok=true;
        }
      }
      if (!ok){
        return false;
      }
    }

    return m[len1][len2];
  }
};


int main(int argc, char **argv){
  Solution s;
  string s1="bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
  string s2="babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
  string s3="babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababb"
      "bababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";

  debug_log("%d\n", s.isInterleave("a", "", "a"));
  for (int i=0; i<100; ++i){
    s.isInterleave(s1, s2, s3);
  }
  return 0;
}
