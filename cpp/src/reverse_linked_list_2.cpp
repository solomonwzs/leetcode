#include "utils.h"

using namespace std;


class Solution{
 public:
  ListNode *reverseBetween(ListNode *head, int m, int n){
    ListNode **cur=&head;
    for (int i=1; i<m; ++i){
      cur=&((*cur)->next);
    }
    ListNode *p=*cur; 
    ListNode *next=(*cur)->next;
    for (int i=m; i<n; ++i){
      ListNode *q=next->next;
      next->next=*cur;
      *cur=next;
      next=q;
    }
    p->next=next;

    return head;
  }
};


int main(int argc, char **argv){
  vector<ListNode *> v(5);
  for (int i=0; i<5; ++i){
    v[i]=new ListNode(i);
  }
  for (int i=0; i<5-1; ++i){
    v[i]->next=v[i+1];
  }

  Solution s;
  ListNode *new_head=s.reverseBetween(v[0], 2, 4);
  print_link_list(new_head);

  delete_link_list(new_head);
  return 0;
}
