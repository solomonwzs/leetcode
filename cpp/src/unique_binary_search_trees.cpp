#include "leetcode.h"

using namespace std;


class Solution{
 public:
  int numTrees(int n){
    vector<int> cache(n+1);
    for (unsigned i=0; i<cache.size(); ++i){
      cache[i]=0;
    }
    return f(n, cache);
  }

 private:
  int f(int n, vector<int> &cache){
    if (cache[n]!=0){
      return cache[n];
    } else if (n==0 || n==1){
      cache[n]=1;
    } else{
      cache[n]=0;
      for (int left=0; left<n; ++left){
        cache[n]+=f(left, cache)*f(n-left-1, cache);
      }
    }
    return cache[n];
  }
};


int main(int argc, char **argv){
  Solution s;
  debug_log("%d\n", s.numTrees(atoi(argv[1])));
  return 0;
}
