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


int main(int argc, char **argv){
  TreeNode *root;
  vector<int> v;
  Solution s;

  root=build_tree(argv[1]);
  v=s.preorderTraversal(root);
  for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
    printf("%d\n", *it);
  }
  delete_tree(root);

  return 0;
}
