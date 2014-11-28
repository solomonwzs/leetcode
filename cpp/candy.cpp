#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


class Solution {
 public:
  int candy(vector<int> &ratings) {
    vector<int> v(ratings.size());
    int prev=1;
    v[0]=1;
    for (int i=1; i<v.size(); ++i){
      if (ratings[i]<ratings[i-1]){
      }
    }

    return v[v.size()];
  }
};


int main(int argc, char **argv){
  vector<int> v;
  for (int i=1; i<argc; ++i){
    v.push_back(atoi(argv[i]));
  }
  return 0;
}
