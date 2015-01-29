#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "utils.h"

using namespace std;


class Solution{
 public:
  vector<int> preorderTraversal(TreeNode *root){
    vector<int> v;
    if (root){
      this->preorderTraversal0(root, &v);
    }
    return v;
  }
 private:
  void preorderTraversal0(TreeNode *node, vector<int> *v){
    v->push_back(node->val);
    if (node->left){
      this->preorderTraversal0(node->left, v);
    }
    if (node->right){
      this->preorderTraversal0(node->right, v);
    }
  }
};


static void build_tree(TreeNode **p, int argc, char **argv, int *index){
  if (*index<argc && strcmp(argv[*index], "#")!=0){
    *p=new TreeNode(atoi(argv[*index]));
    ++(*index);

    build_tree(&((*p)->left), argc, argv, index);
    build_tree(&((*p)->right), argc, argv, index);
  } else{
    ++(*index);
  }
}


static void clear_tree(TreeNode *p){
  if (p->left){
    clear_tree(p->left);
  }
  if (p->right){
    clear_tree(p->right);
  }
  //printf("%d\n", p->val);
  delete p;
}


int main(int argc, char **argv){
  TreeNode *root;
  vector<int> v;
  Solution s;

  int index=1;
  build_tree(&root, argc, argv, &index);
  v=s.preorderTraversal(root);
  for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
    printf("%d\n", *it);
  }
  clear_tree(root);

  return 0;
}
