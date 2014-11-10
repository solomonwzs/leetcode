#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution {
 public:
  ListNode *insertionSortList(ListNode *head){
    ListNode *new_head=head;

    ListNode *p=new_head;
    while (p && p->next){
      int move=1;
      ListNode *q=p->next;

      for (ListNode **curr=&new_head; *curr!=q;){
        ListNode *entry=*curr;
        if (entry->val>q->val){
          p->next=q->next;
          *curr=q;
          q->next=entry;

          move=0;
          break;
        } else{
          curr=&entry->next;
        }
      }

      if (move){
        p=p->next;
      }
    }
    return new_head;
  }
};

int main(int argc, char **argv){
  ListNode *head=NULL, *p=NULL;
  if (argc>1){
    for (int i=1; i<argc; ++i){
      int j=atoi(argv[i]);
      if (head==NULL){
        head=new ListNode(j);
        p=head;
      } else{
        p->next=new ListNode(j);
        p=p->next;
      }
    }
  }

  Solution s;
  ListNode *q=s.insertionSortList(head);

  while (q){
    p=q;
    q=q->next;
    printf("%d\n", p->val);
    delete p;
  }

  return 0;
}
