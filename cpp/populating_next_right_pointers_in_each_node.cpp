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
    for (TreeLinkNode *i=root; i; i=i->left){
      TreeLinkNode *cur=i;

      if (cur->left){
        cur->left->next=cur->right;
        TreeLinkNode *pre=cur->right;
        cur=cur->next;
        while (cur){
          pre->next=cur->left;
          cur->left->next=cur->right;
          pre=cur->right;
          cur=cur->next;
        }
      }
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
  arr[2]->left=arr[5]; arr[2]->right=arr[6];

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
