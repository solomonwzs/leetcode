#include "utils.h"

using namespace std;


class Solution{
 public:
  int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    vector<int> stack;
    height.push_back(0);
    int maxArea = 0;
    for(int i=0; i<(int)height.size(); i++){
      if ( stack.size()<=0 || height[i] >= height[stack.back()] ) {
        stack.push_back(i);
        continue;
      }
      int topIdx = stack.back();
      stack.pop_back();
      int area = height[topIdx] * (stack.size()==0 ? i : i - stack.back() - 1 );
      if ( area > maxArea ) {
        maxArea = area;
      }
      i--;
    }
    return maxArea;
  }
};


int largestRectangleArea(int height[], int n){
  if (n==0){
    return 0;
  }

  bool *cal=(bool *)malloc(sizeof(bool)*n);
  for (int i=0; i<n; ++i){
    cal[i]=false;
  }

  int max=0;
  for (int i=0; i<n; ++i){
    int area=0;
    int cur_height=height[i];

    for (int j=i; !cal[j] && j<n; ++j){
      if (cur_height>=height[j]){
        cal[j]=true;
        cur_height=height[j];
        area=(j-i+1)*cur_height;
      } else{
        area+=cur_height;
      }
      if (max<area){
        max=area;
      }
    }
  }
  free(cal);
  return max;
}


#define MAX 10000
int main(int argc, char **argv){
  int height[MAX];
  for (int i=0; i<MAX; ++i){
    height[i]=MAX;
  }
  vector<int> h(height, end_of_array(height, int));
  for (int i=0; i<1000; ++i){
    largestRectangleArea(height, MAX);
    //s.largestRectangleArea(h);
  }
  //int height[]={3, 3, 3, 3, 3, 3, 3};
  //debug_log("%d\n", largestRectangleArea(height, sizeof(height)/sizeof(int)));
  return 0;
}
