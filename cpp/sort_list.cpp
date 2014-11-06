#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

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
  ListNode *q=s.sortList(head);

  while (q){
    p=q;
    q=q->next;
    printf("%d\n", p->val);
    delete p;
  }

  return 0;
}
