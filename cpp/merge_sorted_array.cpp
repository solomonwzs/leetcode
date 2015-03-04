#include "utils.h"

using namespace std;


void merge(int a[], int m, int b[], int n){
  int *alias=a;
  int i=m-1;
  int j=n-1;
  int k=m+n-1;
  while (k>=0){
    if (i>=0 && j>=0){
      if (a[i]>b[j]){
        alias[k--]=a[i--];
      } else{
        alias[k--]=b[j--];
      }
    } else if (i>=0){
      break;
    } else{
      for (int idx=0; idx<=j; ++idx){
        alias[idx]=b[idx];
      }
      break;
    }
  }
}

int main(int argc, char **argv){
  int a[10]={2, 4, 6, 8};
  int b[4]={1, 3, 5, 9};
  merge(a, 4, b, 4);
  for (int i=0; i<8; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
