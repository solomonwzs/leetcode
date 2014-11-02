#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define MAX 10000

using namespace std;

class Solution{
 public:
  int findMin(vector<int> &num){
    int head=0;
    int last=num.size()-1;

    while (head<last-1){
      int mid=(head+last)/2;

      if (num[head]<num[mid] && num[mid]<num[last]){
        return num[head];
      } else if (num[head]<num[mid] && num[mid]>num[last]){
        if (num[head]<num[last]){
          last=mid;
        } else{
          head=mid;
        }
      } else{
        last=mid;
      }
    }

    if (head==last){
      return num[head];
    } else{
      return num[head]<num[last]?num[head]:num[last];
    }
  }
};

int main(){
  Solution s;
  vector<int> v;
  srand(time(NULL));

  for (int i=0; i<100; ++i){
    int max=rand()%MAX+1;
    int pivot=rand()%max+1;

    v.clear();
    for (int j=pivot; j<=max; ++j){
      v.push_back(j);
    }
    for (int j=1; j<=pivot-1; ++j){
      v.push_back(j);
    }

    int min=s.findMin(v);
    if (min!=1){
      printf("error, %d\n", min);
      for (int j=0; j<max; ++j){
        printf("%d ", v[j]);
      }
      printf("\n");
      return 0;
    }
  }

  printf("ok\n");
  return 0;
}
