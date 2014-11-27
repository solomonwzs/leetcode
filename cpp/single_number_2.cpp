#include <stdio.h>
#include <stdlib.h>

using namespace std;


#define u_int64 unsigned long long
class Solution{
 public:
  int singleNumber(int A[], int n){
    u_int64 x=(unsigned)A[0];
    for (int i=1; i<n; ++i){
      x=this->t_xor(x, (unsigned)A[i]);
    }
    return (int)x;
  }

 private:
  u_int64 t_xor(u_int64 x, unsigned y){
    u_int64 s=0;
    u_int64 i=1;
    while (x>0 || y>0){
      unsigned a=x%3;
      unsigned b=y%3;
      s+=(a+b)%3*i;

      i*=3;
      x/=3;
      y/=3;
    }

    return s;
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
