#include <vector>
#include "utils.h"

using namespace std;


#define LOWEST    0
#define HEIGHTEST 1

struct point{
  unsigned idx;
  int height;
};

class Solution {
 public:
  int candy(vector<int> &ratings) {
    if (ratings.size()==1){
      return 1;
    }

    int sum=0;
    unsigned left=0;
    unsigned right=1;
    while (right<ratings.size()-1){
      if (ratings[right]!=ratings[right-1]){
        ++right;
      } else{
        sum+=this->candy0(ratings, left, right-1);

        left=right;
        while (left+1<ratings.size()-1 && ratings[left]==ratings[left+1]){
          ++sum;
          ++left;
        }
        right=left+1;
      }
    }
    sum+=this->candy0(ratings, left, right);
    return sum;
  }

 private:
  int candy0(vector<int> &ratings, unsigned left, unsigned right){
    if (left==right){
      return 1;
    }

    if (right-left==1){
      return ratings[left]==ratings[right]?2:3;
    }

    vector<point> vp;
    point p;
    p.idx=left;
    p.height=ratings[left]>ratings[left+1]?HEIGHTEST:LOWEST;
    vp.push_back(p);
    for (unsigned i=left+1; i<right; ++i){
      if (ratings[i-1]<ratings[i] && ratings[i]>ratings[i+1]){
        p.idx=i;
        p.height=HEIGHTEST;
        vp.push_back(p);
      } else if (ratings[i-1]>ratings[i] && ratings[i]<ratings[i+1]){
        p.idx=i;
        p.height=LOWEST;
        vp.push_back(p);
      }
    }
    p.idx=right;
    p.height=ratings[right]>ratings[right-1]?HEIGHTEST:LOWEST;
    vp.push_back(p);

    int sum=0;
    int prev_len=0;
    for (unsigned i=1; i<vp.size(); ++i){
      if (vp[i-1].height==HEIGHTEST){
        int len=vp[i].idx-vp[i-1].idx;
        sum+=this->sum_len(len)-1+(prev_len>len?prev_len+1:len+1);
      } else{
        prev_len=vp[i].idx-vp[i-1].idx;
        sum+=this->sum_len(prev_len);
      }
    }
    if (vp[vp.size()-1].height==HEIGHTEST){
      sum+=prev_len+1;
    } else{
      ++sum;
    }

    return sum;
  }

  int sum_len(int len){
    int sum=0;
    for (int i=1; i<=len; ++i){
      sum+=i;
    }
    return sum;
  }
};


int main(int argc, char **argv){
  vector<int> v;
  for (int i=1; i<argc; ++i){
    v.push_back(atoi(argv[i]));
  }

  Solution s;
  debug_log("%d\n", s.candy(v));

  return 0;
}
