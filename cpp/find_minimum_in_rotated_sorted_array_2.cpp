#include <stdio.h>
#include <vector>

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
  int arr[8]={4, 5, 6, 7, 0, 1, 2, 3};
  vector<int> v(8);
  for (int i=0; i<8; ++i){
    v.push_back(arr[i]);
  }

  Solution s;
  printf("%d\n", s.findMin(v));

  return 0;
}
