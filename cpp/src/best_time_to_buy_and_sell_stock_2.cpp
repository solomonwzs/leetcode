#include <limits>
#include <vector>
#include "leetcode.h"

using namespace std;


class Solution{
 public:
  int maxProfit(vector<int> &prices){
    if (prices.size()<2){
      return 0;
    }

    int sum=0;
    for (unsigned i=0; i<prices.size()-1; ++i){
      if (prices[i+1]>prices[i]){
        sum+=prices[i+1]-prices[i];
      }
    }
    return sum;
  }
};


int main(int argc, char **argv){
  vector<int> prices;
  for (int i=1; i<argc; ++i){
    prices.push_back(atoi(argv[i]));
  }

  Solution s;
  debug_log("%d\n", s.maxProfit(prices));

  return 0;
}
