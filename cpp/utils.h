#ifndef __LEETCODE_CPP_UTILS__
#define __LEETCODE_CPP_UTILS__

#include <stdlib.h>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL){}
};

#define build_link_list_from_argv(_head, _argc, _argv) do{\
  typeof(_head) *__c=&_head;\
  for (typeof(_argc) __i=1; __i<(_argc); ++__i){\
    *__c=new ListNode(atoi((_argv)[__i]));\
    __c=&((*__c)->next);\
  }\
} while(0)

#define delete_link_list(_head)\
    while (_head){\
      typeof(_head) __p=_head;\
      _head=_head->next;\
      delete __p;\
    }

#endif
