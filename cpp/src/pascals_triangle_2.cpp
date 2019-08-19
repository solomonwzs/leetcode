#include <vector>
#include "leetcode.h"

using namespace std;


class Solution{
 public:
  vector<int> getRow(int rowIndex){
    vector<int> out;
    vector<int> next_row(rowIndex+1);

    out.push_back(1);
    for (int i=1; i<rowIndex+1; ++i){
      next_row[0]=1;
      for (int j=1; j<i; ++j){
        next_row[j]=out[j-1]+out[j];
      }
      next_row[i]=1;

      out=next_row;
    }

    return out;
  }
};


int main(int argc, char **argv){
  Solution s;
  vector<int> out=s.getRow(atoi(argv[1]));

  for (unsigned i=0; i<out.size(); ++i){
    printf("%d ", out[i]);
  }
  printf("\n");
  return 0;
}
