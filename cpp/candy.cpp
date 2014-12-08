#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


class Solution {
 public:
  int candy(vector<int> &ratings) {
    vector<int> v;
    v.push_back(0);

    for (int i=1; i<ratings.size(); ++i){
      if (ratings[i-1]==ratings[i]){
        v.push_back(0);
      } else if (ratings[i-1]<ratings[i]){
        v.push_back(1);
      } else{
        v.push_back(-1);
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
