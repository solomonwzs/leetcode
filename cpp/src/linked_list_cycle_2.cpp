#include <stdio.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution{
 public:
  ListNode *detectCycle(ListNode *head){
    if (!head) return NULL;

    ListNode *p=head;
    ListNode *q=p;

    do {
      p=p->next;
      if (q->next){
        q=q->next->next;
      } else{
        return NULL;
      }

      if (p==q){
        p=head;
        while (p!=q){
          p=p->next;
          q=q->next;
        }
        return p;
      };
    } while(p && q);

    return NULL;
  }
};


#define LEN 5
int main(){
  Solution s;
  ListNode arr[LEN]={
    ListNode(0),
    ListNode(1),
    ListNode(2),
    ListNode(3),
    ListNode(4)
  };

  for (int i=0; i<LEN-1; ++i){
    arr[i].next=&arr[i+1];
  }
  arr[LEN-1].next=arr+2;
  //arr[1].next=NULL;

  printf("%d\n", s.detectCycle(arr)->val);
}
