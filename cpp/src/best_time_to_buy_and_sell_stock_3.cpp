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

    int slope=prices[0]<prices[1]?1:-1;
    int last=prices[1];
    vector<int> prices0;
    prices0.push_back(prices[0]);
    for (unsigned i=1; i<prices.size(); ++i){
      if (slope==1 && last>prices[i]){
        slope=-1;
        prices0.push_back(last);
      } else if (slope==-1 && last<prices[i]){
        slope=1;
        prices0.push_back(last);
      }
      last=prices[i];
    }
    prices0.push_back(last);

    int max=std::numeric_limits<int>::min();
    for (unsigned i=prices0[0]<prices0[1]?1:0;
         i<prices0.size();
         i+=2){
      int p0=sub_max_profit(prices0, 0, i);
      int p1=sub_max_profit(prices0, i+1, prices0.size()-1);

      if (p0+p1>max){
        max=p0+p1;
      }
    }
    return max;
  }

 private:
  int sub_max_profit(vector<int> &prices, int start, int end){
    if (end-start+1<2){
      return 0;
    }

    int max=std::numeric_limits<int>::min();
    int min=std::numeric_limits<int>::max();
    for (int i=start; i<=end; ++i){
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
