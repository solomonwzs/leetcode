#include <string>
#include <vector>
#include "utils.h"

using namespace std;


class Solution {
 public:
  vector< vector<string> > partition(string s){
    vector< vector<string> > r;
    unsigned len=s.size();
    if (len==0){
      return r;
    }

    vector< vector<unsigned> > v(len+1);
    for (int i=len-1; i>=0; --i){
      for (unsigned j=i+1; j<len+1; ++j){
        string sub=s.substr(i, j-i);
        if (this->is_palindrome(sub)){
          v[i].push_back(j);
        }
      }
    }

    vector<string> vs;
    this->gen(s, r, vs, v, 0);

    return r;
  }

 private:
  int is_palindrome(string s){
    unsigned len=s.size();
    for (unsigned i=0; i<len/2; ++i){
      if (s[i]!=s[len-i-1]){
        return 0;
      }
    }
    return 1;
  }

  void gen(string &s, vector< vector<string> > &r,  vector<string> &vs,
           vector< vector<unsigned> > &v, unsigned idx){
    if (idx==s.size()){
      r.push_back(vs);
    } else{
      for (unsigned i=0; i<v[idx].size(); ++i){
        string sub=s.substr(idx, v[idx][i]-idx);
        vs.push_back(sub);
        this->gen(s, r, vs, v, v[idx][i]);
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
