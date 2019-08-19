#include <vector>
#include "leetcode.h"

using namespace std;


class Solution{
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    unsigned len=gas.size();
    vector<int> v;
    for (unsigned i=0; i<len; ++i){
      v.push_back(gas[i]-cost[i]);
    }
    unsigned n=0;
    while (v[n]<0 && ++n<len);
    if (n==len){
      return -1;
    }

    vector<int> w;
    w.push_back(v[n]);
    int sum=v[n];
    for (unsigned i=n+1; i<n+len; ++i){
      unsigned idx=i%len;
      int s=v[idx]+w[i-n-1];
      sum+=v[idx];
      w.push_back(s<v[idx]?s:v[idx]);
    }

    if (sum<0){
      return -1;
    } else{
      int min=w[0];
      unsigned idx=0;
      for (unsigned i=1; i<len; ++i){
        if (w[i]<min){
          min=w[i];
          idx=i;
        }
      }
      return min>0?n:(n+idx+1)%len;
    }
  }
};


int main(int argc, char **argv){
  vector<int> gas;
  vector<int> cost;

  int n=argc/2;
  for (int i=1; i<n+1; ++i){
    gas.push_back(atoi(argv[i]));
    cost.push_back(atoi(argv[n+i]));
  }

  Solution s;
  debug_log("%d\n", s.canCompleteCircuit(gas, cost));

  return 0;
}
