#ifndef __LEETCODE_CPP_UTILS__
#define __LEETCODE_CPP_UTILS__

#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL){}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define debug_log(_fmt_, ...) \
    printf("\033[0;33m[%s:%d]\033[0m " _fmt_, __FILE__, __LINE__, ## __VA_ARGS__)

#define build_link_list_from_argv(_head, _argc, _argv) do{\
  typeof(_head) *__c=&_head;\
  for (typeof(_argc) __i=1; __i<(_argc); ++__i){\
    *__c=new (typeof *_head)(atoi((_argv)[__i]));\
    __c=&((*__c)->next);\
  }\
} while(0)

#define print_link_list(_head) \
    for (typeof(_head) __p=_head; __p; __p=__p->next){\
      printf("%d\n", __p->val);\
    }

#define delete_link_list(_head)\
    while (_head){\
      typeof(_head) __p=_head;\
      _head=_head->next;\
      delete __p;\
    }

#define new_vector_treenode(_v, _num) \
    for (int __i=0; __i<_num; ++__i){\
      (_v).push_back(new TreeNode(__i));\
    }

#define delete_vectot_obj(_v) \
    for (unsigned __i=0; __i<(_v).size(); ++__i){\
      delete (_v)[__i];\
    }

#define end_of_array(_a, _type) (_a)+sizeof(_a)/sizeof(_type)

extern void print_tree(TreeNode *root);
extern void delete_tree(TreeNode *root);

extern TreeNode *build_tree(std::string str);

#endif
