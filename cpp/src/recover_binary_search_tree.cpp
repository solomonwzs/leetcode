#include <vector>
#include "utils.h"

using namespace std;


#define xor_swap(_a, _b) do{\
  _a=_a xor _b;\
  _b=_a xor _b;\
  _a=_a xor _b;\
} while(0)

class Solution{
 public:
  void recoverTree(TreeNode *root){
    vector<TreeNode *> sort;
    inorder_traversal(root, sort);

    int a=-1;
    int b=-1;
    for (int i=0; i<(int)sort.size()-1; ++i){
      if (sort[i]->val>sort[i+1]->val){
        if (a==-1){
          a=i;
        } else{
          b=i;
        }
      }
    }
    b=b==-1?a+1:b+1;
    xor_swap(sort[a]->val, sort[b]->val);
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
  v[1]->left=v[6];
  v[1]->right=v[2];
  v[5]->left=v[4];
  v[5]->right=v[0];

  print_tree(v[3]);
  Solution s;
  s.recoverTree(v[3]);
  print_tree(v[3]);

  delete_vectot_obj(v);
  return 0;
}
