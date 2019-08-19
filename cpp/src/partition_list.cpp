#include "leetcode.h"

using namespace leetcode;


struct ListNode *partition(struct ListNode *head, int x){
  struct ListNode *tail=NULL;
  struct ListNode **greater=&tail;
  struct ListNode **cur=&head;
  while (*cur){
    struct ListNode *p=*cur;
    if (p->val>=x){
      *cur=p->next;
      p->next=NULL;
      *greater=p;
      greater=&p->next;
    } else{
      cur=&p->next;
    }
  }
  *cur=tail;
  return head;
}


int main(int argc, char **argv){
  // ListNode *head=NULL;
  // build_link_list_from_argv(head, argc-1, argv);
  // int x=atoi(argv[argc-1]);

  // partition(head, x);

  // print_link_list(head);
  // delete_link_list(head);

  return 0;
}
