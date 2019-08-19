#include "leetcode.h"
#include <algorithm>

using namespace std;


class Solution{
 public:
  vector<vector<int> > subsets(vector<int> &s){
    sort(s.begin(), s.end());
    vector<vector<int> > list(s.size()+1);
    list[0]=vector<int>(0);
    for (unsigned i=0; i<s.size(); ++i){
      list[i+1]=vector<int>(1);
      list[i+1][0]=s[i];
    }

    unsigned idx=1;
    while (idx<list.size()){
      int last=list[idx].back();
      for (unsigned i=0; i<s.size(); ++i){
        if (s[i]>last){
          vector<int> ss=list[idx];
          ss.push_back(s[i]);
          list.push_back(ss);
        }
      }
      ++idx;
    }

    return list;
  }
};


int main(int argc, char **argv){
  vector<int> S = {4, 1, 0};

  Solution s;
  vector<vector<int> > out=s.subsets(S);
  for (unsigned i=0; i<out.size(); ++i){
    printf("[ ");
    for (unsigned j=0; j<out[i].size(); ++j){
      printf("%d ", out[i][j]);
    }
    printf("]\n");
  }

  return 0;
}
