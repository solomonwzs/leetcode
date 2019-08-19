#include "leetcode.h"


static int search0(int a[], int left, int right, int target){
  if (left==right){
    return a[left]==target?left:-1;
  } else if (left+1==right){
    if (a[left]==target){
      return left;
    } else if (a[right]==target){
      return right;
    } else{
      return -1;
    }
  } else {
    int mid=(left+right)/2;
    if (a[mid]==target){
      return mid;
    } else{
      if (a[left]<a[right]){
        return a[mid]>target?
            search0(a, left, mid, target):
            search0(a, mid, right, target);
      } else{
        int ret=search0(a, left, mid, target);
        return ret!=-1?ret:search0(a, mid, right, target);
      }
    }
  }
}


int search(int a[], int n, int target){
  return search0(a, 0, n-1, target);
}


int main(int argv, char **argc){
  int a[]={1};
  debug_log("%d\n", search(a, sizeof(a)/sizeof(int), 0));
  return 0;
}
