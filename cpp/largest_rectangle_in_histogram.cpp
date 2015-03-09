#include "utils.h"

using namespace std;


int largestRectangleArea(int height[], int n){
  if (n==0){
    return 0;
  }

  int *max_height_idx=(int *)malloc(sizeof(int)*n);
  int size=0;
  int max=0;
  int i=0;
  while (i<n || size>0){
    if (i<n && (size==0 || height[i]>=height[max_height_idx[size-1]])){
      ++size;
      max_height_idx[size-1]=i;
      ++i;
    } else{
      int max_height=height[max_height_idx[size-1]];
      int left_idx=size==1?0:max_height_idx[size-2]+1;
      int width=i-left_idx;
      int area=max_height*width;
      if (max<area){
        max=area;
      }

      --size;
    }
  }

  free(max_height_idx);
  return max;
}


#define MAX 10000
int main(int argc, char **argv){
  int height[MAX];
  for (int i=0; i<MAX; ++i){
    height[i]=MAX-i;
  }
  for (int i=0; i<1000; ++i){
    largestRectangleArea(height, sizeof(height)/sizeof(int));
  }
  int height0[]={4, 2, 0, 3, 2, 5};
  debug_log("%d\n", largestRectangleArea(height0, sizeof(height0)/sizeof(int)));
  return 0;
}
