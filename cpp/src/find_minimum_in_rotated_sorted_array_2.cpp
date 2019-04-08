#include <algorithm>
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

    while (head<last-1 && num[head]>=num[last]){
      int mid=(head+last)/2;

      if (num[mid]>num[last]){
        head=mid;
      } else if (num[mid]<num[last]){
        last=mid;
      } else{
        --last;
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
  //srand(time(NULL));
  vector<int> v;

  //for (int i=0; i<100; ++i){
  //  int max=rand()%MAX+1;
  //  int len=rand()%max+1;

  //  v.clear();
  //  for (int j=0; j<len; j++){
  //    v.push_back(rand()%max+1);
  //  }
  //  sort(v.begin(), v.end());
  //}

  int arr[5]={10, 1, 10, 10, 10};
  for (int i=0; i<5; ++i){
    v.push_back(arr[i]);
  }

  Solution s;
  printf("%d\n", s.findMin(v));

  return 0;
}
