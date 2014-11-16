#ifndef __LEETCODE_CPP_UTILS__
#define __LEETCODE_CPP_UTILS__

#include <stdlib.h>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL){}
};

#define build_link_list_from_argv(_c, _argc, _argv)\
    for (typeof(_argc) __i=1; __i<(_argc); ++__i){\
      *_c=new ListNode(atoi((_argv)[__i]));\
      _c=&((*_c)->next);\
    }

#define delete_link_list(_head)\
    while (_head){\
      typeof(_head) __p=_head;\
      _head=_head->next;\
      delete __p;\
    }

#endif
