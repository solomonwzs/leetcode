#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
  Point():x(0), y(0){}
  Point(int a, int b):x(a), y(b){}
};


class Solution {
#define MAX 2147483647

 public:
  int maxPoints(vector<Point> &points){
    if (points.size()==1){
      return 1;
    }

    vector<float> slope;
    int max_points=0;
    
    for (unsigned i=0; i<points.size(); ++i){
      int same=0;
      slope.clear();

      for (unsigned j=0; j<points.size(); ++j){
        if (i==j){
          continue;
        }

        int delta_x=points[i].x-points[j].x;
        int delta_y=points[i].y-points[j].y;
        if (delta_x==0 && delta_y==0){
          ++same;
        } else if (delta_x==0){
          slope.push_back(MAX);
        } else{
          slope.push_back((float)delta_y/delta_x);
        }
      }

      float f=0;
      int len=same+1;
      sort(slope.begin(), slope.end());
      for (vector<float>::iterator it=slope.begin(); it!=slope.end(); ++it){
        if (f==*it){
          ++len;
        } else{
          f=*it;
          max_points=len>max_points?len:max_points;
          len=same+2;
        }
      }
      max_points=len>max_points?len:max_points;
    }
    return max_points;
  }
};

int main(){
  Point p[9]={Point(84, 250), Point(0, 0), Point(1, 0), Point(0, -70), Point(0, -70), Point(1, -1), Point(21, 10), Point(42, 90), Point(-42, -230)};
  vector<Point> v;
  for (int i=0; i<9; ++i){
    v.push_back(p[i]);
  }

  Solution s;
  printf("%d\n", s.maxPoints(v));
  return 0;
}
