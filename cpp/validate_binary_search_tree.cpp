#include "utils.h"

using namespace std;


class Solution{
 public:
  bool isValidBST(TreeNode *root){
    vector<TreeNode *> sort;
    inorder_traversal(root, sort);

    for (int i=0; i<(int)sort.size()-1; ++i){
      if (sort[i]->val>=sort[i+1]->val){
        return false;
      }
    }

    return true;
  }

 private:
  void inorder_traversal(TreeNode *node, vector<TreeNode *> &out){
    if (node){
      inorder_traversal(node->left, out);
      out.push_back(node);
      inorder_traversal(node->right, out);
    }
  }
};


int main(int argc, char **argv){
  vector<TreeNode *> v;
  new_vector_treenode(v, 7);

  v[3]->left=v[1];
  v[3]->right=v[5];
  v[1]->left=v[0];
  v[1]->right=v[2];
  v[5]->left=v[4];
  v[5]->right=v[6];

  print_tree(v[3]);
  Solution s;
  debug_log("%d\n", s.isValidBST(v[3]));

  delete_vectot_obj(v);
  return 0;
}
