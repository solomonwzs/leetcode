#include "utils.h"

using namespace std;


struct TreeLinkNode{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};


class Solution{
 public:
  void connect(TreeLinkNode *root){
    TreeLinkNode *level_head=root;
    while (level_head){
      TreeLinkNode *cur=NULL;
      TreeLinkNode *pre=NULL;

      TreeLinkNode *next_level_head=NULL;
      while (level_head && !level_head->left && !level_head->right){
        level_head=level_head->next;
      }
      if (level_head){
        next_level_head=level_head->left?level_head->left:level_head->right;

        cur=level_head;
        pre=next_level_head;
        if (cur->left && cur->right){
          pre->next=cur->right;
          pre=pre->next;
        }
        cur=cur->next;
      }

      while (cur){
        if (cur->left){
          pre->next=cur->left;
          pre=pre->next;
        }
        if (cur->right){
          pre->next=cur->right;
          pre=pre->next;
        }
        cur=cur->next;
      }

      level_head=next_level_head;
    }
  }
};


int main(int argc, char **argv){
  TreeLinkNode *arr[8];
  for (int i=0; i<8; ++i){
    arr[i]=new TreeLinkNode(i);
  }

  arr[0]->left=arr[1]; arr[0]->right=arr[2];
  arr[1]->left=arr[3]; arr[1]->right=arr[4];
  arr[2]->left=NULL; arr[2]->right=arr[6];

  Solution s;
  s.connect(arr[0]);

  for (TreeLinkNode *i=arr[0]; i; i=i->left){
    for (TreeLinkNode *j=i; j; j=j->next){
      printf("%d ", j->val);
    }
    printf("\n");
  }

  for (int i=0; i<8; ++i){
    delete arr[i];
  }
  return 0;
}
