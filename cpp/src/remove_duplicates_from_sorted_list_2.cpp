#include "utils.h"


struct ListNode *deleteDuplicates(struct ListNode *head){
  struct ListNode **cur=&head;

  while (*cur && (*cur)->next){
    if ((*cur)->val!=(*cur)->next->val){
      cur=&((*cur)->next);
    } else{
      int del_val=(*cur)->val;
      do{
        struct ListNode *del_node=*cur;
        *cur=del_node->next;
        free(del_node);
      } while (*cur && (*cur)->val==del_val);
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
