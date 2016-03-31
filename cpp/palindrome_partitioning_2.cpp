#include <string>
#include <vector>
#include "utils.h"

using namespace std;


class Solution {
 public:
  int minCut(string s){
    return this->manacher(s);
  }

 private:
  int minCut1(string s){
    int len=s.size();
    if (len==0){
      return 0;
    }

    vector< vector<int> > v=this->gen_jump_list(s);

    vector<int> r(len+1);
    for (int i=0; i<len+1; ++i){
      r[i]=i-1;
    }

    for (int i=0; i<len; ++i){
      for (unsigned j=0; j<v[i].size(); ++j){
        int next=v[i][j];
        if (r[next+1]>r[i]+1){
          r[next+1]=r[i]+1;
        }
      }
    }

    return r[len];
  }

  int manacher(string s){
    string ns = "#";
    int len=s.size();
    for (int i=0; i<len; ++i){
      ns.push_back(s[i]);
      ns.push_back('#');
    }
    int nlen=ns.size();
    vector<int> p(nlen);
    vector<int> q(len);

    for (int i=0; i<len; ++i){
      q[i]=i;
    }

    p[0]=0;
    int idx=0;
    int mx=0;
    for (int i=1; i<nlen; ++i){
      if (i<mx){
        p[i]=mx-i>=p[idx*2-i]?p[idx*2-i]:mx-i;
      } else{
        p[i]=0;
      }

      while (i-p[i]-1>=0 && i+p[i]+1<nlen &&
             ns[i-p[i]-1]==ns[i+p[i]+1]){
        ++p[i];
      }

      if (i+p[i]>mx){
        idx=i;
        mx=i+p[i];
      }
      
      if (ns[i]!='#'){
        if (i/2-1>0 && q[i/2]>q[i/2-1]+1){
          q[i/2]=q[i/2-1]+1;
        }
      }
      for (int j=ns[i]=='#'?i+1:i+2; j<=i+p[i]; j+=2){
        int lidx=(i*2-j)/2;
        int ridx=j/2;

        if (lidx==0){
          q[ridx]=0;
        } else{
          if (q[ridx]>q[ridx-1]+1){
            q[ridx]=q[ridx-1]+1;
          }
          if (q[ridx]>q[lidx-1]+1){
            q[ridx]=q[lidx-1]+1;
          }
        }
      }
    }

    return q[len-1];
  }

  vector< vector<int> > gen_jump_list(string s){
    int len=s.size();

    vector< vector<int> > v(len);
    for (int left=0; left<len; ++left){
      int right=left;
      while (s[left]==s[right] && right<len){
        v[left].push_back(right++);
      }

      int diff_pos=right;
      int same_len=right-left;
      while (right<len){
        if (s[right]==s[left]){
          if (right-diff_pos==same_len
              && this->is_palindrome(s.substr(left, right-left+1))){
            v[left].push_back(right);
          }
        } else{
          diff_pos=right;
        }
        ++right;
      }
    }

    return v;
  }

  int is_palindrome(string s){
    unsigned len=s.size();
    for (unsigned i=0; i<len/2; ++i){
      if (s[i]!=s[len-i-1]){
        return 0;
      }
    }
    return 1;
  }
};


int main(int argc, char **argv){
  string str=argv[1];
  Solution s;

  debug_log("%d\n", s.minCut(str));
  return 0;
}
