#include "utils.h"


int removeDuplicates(int a[], int n){
  if (n<=2){
    return n;
  }

  int i=0;
  bool twice=false;
  for (int j=1; j<n; ++j){
    if (a[i]!=a[j]){
      a[++i]=a[j];
      twice=false;
    } else if (!twice){
      a[++i]=a[j];
      twice=true;
    }
  }

  return i+1;
}


int main(int argc, char **argv){
  int a[]={0,0,0,0,0,1,2,2,3,3,4,4};
  int n=removeDuplicates(a, sizeof(a)/sizeof(int));
  for (int i=0; i<n; ++i){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
