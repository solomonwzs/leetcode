#include <limits>
#include <vector>
#include "utils.h"

using namespace std;


class Solution{
 public:
  int maxProfit(vector<int> &prices){
    if (prices.size()==0){
      return 0;
    }

    int max=std::numeric_limits<int>::min();
    int min=std::numeric_limits<int>::max();
    for (unsigned i=0; i<prices.size(); ++i){
      if (prices[i]<min){
        min=prices[i];
      }
      if (prices[i]-min>max){
        max=prices[i]-min;
      }
    }
    return max;
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
