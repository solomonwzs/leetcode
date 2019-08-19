#include <vector>
#include "leetcode.h"

using namespace std;


class Solution {
 public:
  int minimumTotal(vector<vector<int> > &triangle){
    if (triangle.size()==0){
      return 0;
    } else if (triangle.size()==1){
      return triangle[0][0];
    }

    vector<int> below_row_sum=triangle[triangle.size()-1];
    for (int i=triangle.size()-2; i>=0; --i){
      vector<int> row_sum=min_row_sum(triangle, below_row_sum, i);
      below_row_sum=row_sum;
    }

    return below_row_sum[0];
  }

 private:
  vector<int> min_row_sum(vector<vector<int> > &triangle, vector<int> &below_row_sum,
                          unsigned row){
    vector<int> out;
    for (unsigned i=0; i<row+1; ++i){
      out.push_back(triangle[row][i]+(below_row_sum[i]<below_row_sum[i+1]?
                                      below_row_sum[i]:
                                      below_row_sum[i+1]));
    }
    return out;
  }
};


#define end_of_int_array(_a) ((_a)+sizeof(_a)/sizeof(int))

int main(int argc, char **argv){
  vector<vector<int> > triangle;
  //int r0[]={2};
  //int r1[]={3, 4};
  //int r2[]={6, 5, 7};
  //int r3[]={4, 1, 8, 3};

  //triangle.push_back(vector<int>(r0, end_of_int_array(r0)));
  //triangle.push_back(vector<int>(r1, end_of_int_array(r1)));
  //triangle.push_back(vector<int>(r2, end_of_int_array(r2)));
  //triangle.push_back(vector<int>(r3, end_of_int_array(r3)));

  for (int i=1; i<=196; ++i){
    vector<int> v;
    for (int j=i; j<=i; ++j){
      v.push_back(i);
    }
    triangle.push_back(v);
  }

  Solution s;
  debug_log("%d\n", s.minimumTotal(triangle));

  return 0;
}
