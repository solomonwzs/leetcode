#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


#define LOWEST 0
#define HEIGHTEST 1
#define MIN 1<<(sizeof(int)*8-1)

struct point{
  int rating;
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
    p.rating=ratings[0];
    p.num=1;
    for (unsigned i=1; i<ratings.size(); ++i){
      if (ratings[i]==p.rating){
        ++p.num;
      } else{
        r.push_back(p);
        p.rating=ratings[i];
        p.num=1;
      }
    }
    r.push_back(p);

    if (r.size()==1){
      return r[0].num;
    }

    vector<point> sr;
    if (r[0].num>1 && r[0].rating>r[1].rating){
      p.rating=MIN;
      p.num=r[0].num-1;
      sr.push_back(p);

      r[0].num=1;
    }
    sr.push_back(r[0]);
    for (unsigned i=1; i<r.size()-1; ++i){
      int num=r[i].num;
      if (num>2
          && ((r[i-1].rating<r[i].rating && r[i].rating<r[i+1].rating)
              || (r[i-1].rating>r[i].rating && r[i].rating>r[i+1].rating))){
        p.rating=MIN;
        p.num=r[i].num-2;
        r[i].num=1;
        sr.push_back(r[i]);
        sr.push_back(p);
        sr.push_back(r[i]);
      } else if (num>1 && r[i-1].rating<r[i].rating
                 && r[i].rating>r[i+1].rating){
        p.rating=r[i-1].rating+1;
        p.num=1;
        sr.push_back(p);

        if (num>2){
          p.rating=MIN;
          p.num=num-2;
          sr.push_back(p);
        }

        p.rating=r[i+1].rating+1;
        p.num=1;
        sr.push_back(p);
      } else{
        sr.push_back(r[i]);
      }
    }
    if (r[r.size()-1].num>1 && r[r.size()-1].rating>r[r.size()-2].rating){
      p.rating=r[r.size()-1].rating;
      p.num=1;
      sr.push_back(p);

      p.rating=MIN;
      p.num=r[r.size()-1].num-1;
      sr.push_back(p);
    } else{
      sr.push_back(r[r.size()-1]);
    }

    for (unsigned i=0; i<sr.size(); ++i){
      printf("[%d %d]\n", sr[i].rating, sr[i].num);
    }

    unsigned len=r.size();
    if (len==1){
      return r[0].num;
    }

    vector<m_point> mv;
    m_point m;
    m.idx=0;
    m.height=r[0].rating>r[1].rating?HEIGHTEST:LOWEST;
    mv.push_back(m);
    for (unsigned i=1; i<len-1; ++i){
      if (r[i-1].rating>r[i].rating && r[i].rating<r[i+1].rating){
        m.idx=i;
        m.height=LOWEST;
        mv.push_back(m);
      } else if (r[i-1].rating<r[i].rating && r[i].rating>r[i+1].rating){
        m.idx=i;
        m.height=HEIGHTEST;
        mv.push_back(m);
      }
    }
    m.idx=len-1;
    m.height=r[len-1].rating>r[len-2].rating?HEIGHTEST:LOWEST;
    mv.push_back(m);

    for (unsigned i=0; i<mv.size(); ++i){
      printf("<%d %d>\n", mv[i].idx, mv[i].height);
    }

    int sum=0;
    int h;
    int prev_h=0;
    for (unsigned i=1; i<mv.size(); ++i){
      m_point a=mv[i-1];
      m_point b=mv[i];

      if (a.height==LOWEST){
        h=1;
        for (unsigned j=a.idx; j<b.idx; ++j){
          sum+=(r[j].num>2?h*2+r[j].num-2:h*r[j].num);
          ++h;
        }
        prev_h=h;
      } else{
        h=2;
        for (unsigned j=b.idx-1; j>a.idx; --j){
          sum+=(r[j].num>2?h*2+r[j].num-2:h*r[j].num);
          ++h;
        }

        int max_h=prev_h>h?prev_h:h;
        if (i==1){
          sum+=max_h+r[a.idx].num-1;
        } else{
          sum+=(r[a.idx].num>2?h*2+r[a.idx].num-2:h*r[a.idx].num);
        }
      }

      printf("%d\n", sum);
    }
    m_point last=mv[mv.size()-1];
    if (last.height==HEIGHTEST){
      sum+=(r[last.idx].num>1?h+r[last.idx].num-1:h);
    } else{
      sum+=r[last.idx].num;
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
