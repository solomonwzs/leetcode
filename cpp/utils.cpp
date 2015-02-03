#include "utils.h"

using namespace std;

static void print_tree0(TreeNode *root);

#define is_leaf(_n) (!(_n)->left && !(_n)->right)


void print_tree(TreeNode *root){
  print_tree0(root);
  printf("\n");
}


static void print_tree0(TreeNode *root){
  if (!root){
    printf("_");
  } else{
    if (is_leaf(root)){
      printf("%d", root->val);
    } else{
      printf("{");
      print_tree0(root->left);
      printf(" %d ", root->val);
      print_tree0(root->right);
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
