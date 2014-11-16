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
  }
};

int main(int argc, char **argv){
  ListNode *head=NULL;

  build_link_list_from_argv(head, argc, argv);
  delete_link_list(head);

  return 0;
}
