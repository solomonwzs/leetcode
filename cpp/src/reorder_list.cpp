#include <stdio.h>
#include "utils.h"

using namespace std;


class Solution{
 public:
  void reorderList(ListNode *head){
    if (!head || !head->next){
      return;
    }

    ListNode *p=head;
    ListNode *q=p->next;
    while (q && q->next){
      p=p->next;
      q=q->next->next;
    }
    q=p->next;
    p->next=NULL;

    for (p=q->next, q->next=NULL; p; ){
      ListNode *next=p->next;
      p->next=q;
      q=p;
      p=next;
    }

    for (p=head; p && q; ){
      ListNode *h1=p; p=p->next;
      ListNode *h2=q; q=q->next;
      h1->next=h2;
      h2->next=p;
    }
  }
};


int main(int argc, char **argv){
  ListNode *head=NULL;
  Solution s;

  build_link_list_from_argv(head, argc, argv);
  s.reorderList(head);
  print_link_list(head);
  delete_link_list(head);

  return 0;
}
