#include <vector>
#include "leetcode.h"

using namespace std;


class Solution{
 public:
  vector<vector<int> > generate(int numRows){
    vector<vector<int> > out;

    for (int i=0; i<numRows; ++i){
      vector<int> row(i+1);
      row[0]=1;;
      for (int j=1; j<i; ++j){
        row[j]=out[i-1][j-1]+out[i-1][j];
      }
      row[i]=1;
      out.push_back(row);
    }

    return out;
  }
};


int main(int argc, char **argv){
  Solution s;
  vector<vector<int> > out=s.generate(atoi(argv[1]));

  for (unsigned i=0; i<out.size(); ++i){
    for (unsigned j=0; j<i+1; ++j){
      printf("%d ", out[i][j]);
    }
    printf("\n");
  }
  return 0;
}
