#include "utils.h"

using namespace std;

#define is_leaf(_n) (!(_n)->left && !(_n)->right)


void print_tree(TreeNode *root){
  if (!root){
    printf("_");
  } else{
    if (is_leaf(root)){
      printf("%d", root->val);
    } else{
      printf("{");
      print_tree(root->left);
      printf(" %d ", root->val);
      print_tree(root->right);
      printf("}");
    }
  }
}

void delete_tree(TreeNode *root){
  if (!root){
    return;
  } else{
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }
}
