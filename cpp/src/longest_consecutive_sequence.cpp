#include <map>
#include <vector>
#include "leetcode.h"

using namespace std;


class Solution{
 public:
  int longestConsecutive(vector<int> &num){
    map<int, bool> m;
    for (unsigned i=0; i<num.size(); ++i){
      m.insert(pair<int, bool>(num[i], true));
    }

    int max=0;
    for (unsigned i=0; i<num.size(); ++i){
      int n=num[i];

      if (m.find(n)==m.end()){
        continue;
      } else{
        m.erase(n);
        int len=1;

        for (int j=n-1; m.find(j)!=m.end(); --j){
          ++len;
          m.erase(j);
        }
        for (int j=n+1; m.find(j)!=m.end(); ++j){
          ++len;
          m.erase(j);
        }

        if (len>max){
          max=len;
        }
      }
    }

    return max;
  }
};


int main(int argc, char **argv){
  vector<int> num;
  for (int i=1; i<argc; ++i){
    num.push_back(atoi(argv[i]));
  }

  Solution s;
  debug_log("%d\n", s.longestConsecutive(num));

  return 0;
}
