#include <string>
#include <vector>
#include "utils.h"

using namespace std;


class Solution {
 public:
  int minCut(string s){
    int len=s.size();
    if (len==0){
      return 0;
    }

    vector< vector<int> > v(len);
    for (int i=0; i<len; ++i){
      for (int j=i; j<len; ++j){
        string sub=s.substr(i, j-i+1);
        if (this->is_palindrome(sub)){
          v[i].push_back(j);
        }
      }
    }

    vector<int> r(len+1);
    for (int i=0; i<len+1; ++i){
      r[i]=i-1;
    }

    for (int i=0; i<len; ++i){
      for (unsigned j=0; j<v[i].size(); ++j){
        int next=v[i][j];
        string sub=s.substr(i, next-i+1);
        if (r[next+1]>r[i]+1){
          r[next+1]=r[i]+1;
        }
      }
    }

    return r[len];
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
};


int main(int argc, char **argv){
  string str=argv[1];
  Solution s;

  debug_log("%d\n", s.minCut(str));
  return 0;
}
