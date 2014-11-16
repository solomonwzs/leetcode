#include <stdio.h>
#include "utils.h"

using namespace std;


class Solution{
 public:
  ListNode *sortList(ListNode *head){
    if (!head || !head->next){
      return head;
    }

    ListNode *p, *q;
    p=head;
    q=head->next;
    while (q && q->next){
      p=p->next;
      q=q->next->next;
    }
    q=p->next;
    p->next=NULL;

    return this->merge(this->sortList(head), this->sortList(q));
  }

 private:
  ListNode *merge(ListNode *head1, ListNode *head2){
    ListNode *p=head1, *q=head2;
    ListNode l(0); l.next=p;
    ListNode *prev=&l;

    while (p && q){
      if (p->val<q->val){
        prev=p;
        p=p->next;
      } else{
        prev->next=q;
        q=q->next;
        prev=prev->next;
        prev->next=p;
      }
    }
    if (q){
      prev->next=q;
    }
    return l.next;
  }
};

int main(int argc, char **argv){
  ListNode *head=NULL;

  build_link_list_from_argv(head, argc, argv);

  Solution s;
  ListNode *q=s.sortList(head);

  delete_link_list(q);

  return 0;
}
