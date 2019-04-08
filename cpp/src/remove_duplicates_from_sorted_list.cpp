#include "utils.h"


struct ListNode *deleteDuplicates(struct ListNode *head){
  struct ListNode *p=head;
  while (p && p->next){
    struct ListNode *next=p->next;
    if (p->val==next->val){
      p->next=next->next;
      free(next);
    } else{
      p=p->next;
    }
  }

  return head;
}


int main(int argc, char **argv){
  ListNode *head=NULL;
  ListNode **cur=&head;
  for (int i=1; i<argc; ++i){
    *cur=(ListNode *)malloc(sizeof(ListNode));
    (*cur)->val=atoi(argv[i]);
    (*cur)->next=NULL;
    cur=&((*cur)->next);
  }

  head=deleteDuplicates(head);
  for (ListNode *i=head; i; i=i->next){
    debug_log("%d\n", i->val);
  }

  while (head){
    ListNode *p=head;
    head=head->next;
    free(p);
  }
  return 0;
}
