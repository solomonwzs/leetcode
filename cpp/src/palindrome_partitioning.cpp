#include <string>
#include <vector>
#include "leetcode.h"

using namespace std;


class Solution {
 public:
  vector< vector<string> > partition(string s){
    vector< vector<string> > r;
    int len=s.size();
    if (len==0){
      return r;
    }

    vector< vector<int> > v=this->gen_jump_list(s);

    vector<string> vs;
    this->gen(s, r, vs, v, 0);

    return r;
  }

 private:
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
    int len=s.size();
    for (int i=0; i<len/2; ++i){
      if (s[i]!=s[len-i-1]){
        return 0;
      }
    }
    return 1;
  }

  void gen(string &s, vector< vector<string> > &r,  vector<string> &vs,
           vector< vector<int> > &v, int idx){
    if (idx==(int)s.size()){
      r.push_back(vs);
    } else{
      for (int i=0; i<(int)v[idx].size(); ++i){
        string sub=s.substr(idx, v[idx][i]-idx+1);
        vs.push_back(sub);
        this->gen(s, r, vs, v, v[idx][i]+1);
        vs.pop_back();
      }
    }
  }
};


int main(int argc, char **argv){
  string str=argv[1];
  Solution s;
  vector< vector<string> > v;

  v=s.partition(str);
  for (unsigned i=0; i<v.size(); ++i){
    for (unsigned j=0; j<v[i].size(); ++j){
      printf("[%s] ", v[i][j].c_str());
    }
    printf("\n");
  }
  return 0;
}
