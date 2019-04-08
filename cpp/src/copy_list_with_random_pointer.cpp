#include <map>
#include <vector>
#include "utils.h"

using namespace std;

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head){
    map<RandomListNode *, RandomListNode *> m;
    RandomListNode *h=NULL;
    RandomListNode **c=&h;

    RandomListNode *p=head;
    while (p){
      *c=new RandomListNode(p->label);
      (*c)->random=p->random;
      m.insert(pair<RandomListNode *, RandomListNode *>(p, (*c)));
      c=&(*c)->next;
      p=p->next;
    }

    p=h;
    while (p){
      if (p->random){
        auto it=m.find(p->random);
        p->random=it->second;
      }

      p=p->next;
    }

    return h;
  }
};


int main(int argc, char **argv){
  vector<RandomListNode *>v;
  RandomListNode *head;
  RandomListNode **c=&head;
  for (int i=0; i<3; ++i){
    *c=new RandomListNode(i);
    v.push_back(*c);
    c=&(*c)->next;
  }
  v[0]->random=v[2];

  Solution s;
  RandomListNode *copy=s.copyRandomList(head);
  RandomListNode *p=copy;
  while (p){
    printf("%d [", p->label);
    if (p->random){
      printf("%d]\n", p->random->label);
    } else{
      printf("]\n");
    }
    p=p->next;
  }

  delete_link_list(copy);
  delete_link_list(head);
  return 0;
}
