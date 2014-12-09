#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


#define LOWEST 0
#define HEIGHTEST 1

struct point{
  int ratings;
  int num;
};

struct m_point{
  unsigned idx;
  int height;
};

class Solution {
 public:
  int candy(vector<int> &ratings) {
    vector<point> r;
    point p;
    p.ratings=ratings[0];
    p.num=1;
    for (unsigned i=1; i<ratings.size(); ++i){
      if (ratings[i]==p.ratings){
        ++p.num;
      } else{
        r.push_back(p);
        p.ratings=ratings[i];
        p.num=1;
      }
    }
    r.push_back(p);

    for (unsigned i=0; i<r.size(); ++i){
      printf("[%d %d]\n", r[i].ratings, r[i].num);
    }

    unsigned len=r.size();
    if (len==1){
      return r[0].num;
    }

    vector<m_point> mv;
    m_point m;
    m.idx=0;
    m.height=r[0].ratings>r[1].ratings?HEIGHTEST:LOWEST;
    mv.push_back(m);
    for (unsigned i=1; i<len-1; ++i){
      if (r[i-1].ratings>r[i].ratings && r[i].ratings<r[i+1].ratings){
        m.idx=i;
        m.height=LOWEST;
        mv.push_back(m);
      } else if (r[i-1].ratings<r[i].ratings && r[i].ratings>r[i+1].ratings){
        m.idx=i;
        m.height=HEIGHTEST;
        mv.push_back(m);
      }
    }
    m.idx=len-1;
    m.height=r[len-1].ratings>r[len-2].ratings?HEIGHTEST:LOWEST;
    mv.push_back(m);

    for (unsigned i=0; i<mv.size(); ++i){
      printf("<%d %d>\n", mv[i].idx, mv[i].height);
    }

    int sum=0;
    int h;
    for (unsigned i=1; i<mv.size(); ++i){
      m_point a=mv[i-1];
      m_point b=mv[i];

      if (a.height==LOWEST){
        h=1;
        for (unsigned j=a.idx; j<b.idx; ++j){
          sum+=h*r[j].num;
          ++h;
        }
      } else{
        h=1;
        for (unsigned j=b.idx; j>=a.idx; --j){
          sum+=h*r[j].num;
          ++h;
        }
      }

      printf(":%d\n", sum);
    }
    if (mv[mv.size()-1].height==HEIGHTEST){
      sum+=h*r[mv[mv.size()-1].idx].num;
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
  printf("%d\n", s.candy(v));

  return 0;
}
