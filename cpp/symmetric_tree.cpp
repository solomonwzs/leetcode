#include "utils.h"

using namespace std;


#define same_nonnull_node(_a, _b) ((_a) && (_b) && (_a)->val==(_b)->val)

#define check_nodes(_a, _b, _v, _nl) \
    if (same_nonnull_node(_a, _b)){ \
      _v.push_back(_a); \
      _v.push_back(_a); \
      _nl+=2; \
    } else if ((_a)!=NULL || (_b)!=NULL){ \
      return false; \
    }

class Solution{
 public:
  bool isSymmetric(TreeNode *root){
    if (!root || (!root->left && !root->right)){
      return true;
    } else if (same_nonnull_node(root->left, root->right)){
      vector<TreeNode *> v;
      v.push_back(root->left);
      v.push_back(root->right);
      int pos=0;
      int len=2;
      while (true){
        int next_len=0;

        for (int i=pos; i<pos+len; i+=2){
          TreeNode *lnode=v[i];
          TreeNode *rnode=v[i+1];

          check_nodes(lnode->left, rnode->right, v, next_len);
          check_nodes(lnode->right, rnode->left, v, next_len);
        }

        if (next_len==0){
          return true;
        } else{
          pos+=len;
          len=next_len;
        }
      }
    } else{
      return false;
    }
  }
};


int main(int argc, char **argv){
  TreeNode *root;
  root=build_tree("2,3,3,4,5,5,4,#,#,8,9,9,8");
  print_tree(root);

  Solution s;
  debug_log("%d\n", s.isSymmetric(root));

  delete_tree(root);

  return 0;
}
