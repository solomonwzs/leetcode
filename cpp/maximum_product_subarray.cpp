#include <stdio.h>

using namespace std;


class Solution {
 public:
  int maxProduct(int A[], int n){
    int max=A[0];
    int pmax=A[0];
    int pmin=A[0];

    for (int i=1; i<n; ++i){
      int a=pmax*A[i];
      int b=pmin*A[i];

      if (a>b){
        pmax=a;
        pmin=b;
      } else{
        pmax=b;
        pmin=a;
      }

      if (A[i]>pmax){
        pmax=A[i];
      }
      if (A[i]<pmin){
        pmin=A[i];
      }

      max=pmax>max?pmax:max;
    }
    return max;
  }
};


int main(){
  Solution s;
  int arr[3]={3, -1, 4};

  printf("%d\n", s.maxProduct(arr, 3));
  return 0;
}
