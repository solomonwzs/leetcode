#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Solution{
 public:
  int singleNumber(int A[], int n){
    int x=A[0];
    for (int i=1; i<n; ++i){
      x=x^A[i];
    }
    return x;
  }
};


int main(int argc, char **argv){
  void *m=malloc(sizeof(int)*(argc-1));
  int *a=(int *)m;
  for (int i=0; i<argc-1; ++i){
    a[i]=atoi(argv[i+1]);
  }

  Solution s;
  printf("%d\n", s.singleNumber(a, argc-1));

  free(m);
  return 0;
}
