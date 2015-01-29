#include <vector>
#include "utils.h"

using namespace std;


#define is_leaf(_p) ((_p)->left==NULL && (_p)->right==NULL)

class Solution{
 public:
  bool hasPathSum(TreeNode *root, int sum){
    if (!root){
      return false;
    }

    bool ok=false;
    pre_order_traversal(root, 0, sum, ok);

    return ok;
  }

 private:
  void pre_order_traversal(TreeNode *node, int cur_sum, const int target_sum,
                           bool &ok){
    if (!ok){
      if (node){
        int sum=cur_sum+node->val;
        if (is_leaf(node) && sum==target_sum){
          ok=true;
        } else{
          pre_order_traversal(node->left, sum, target_sum, ok);
          pre_order_traversal(node->right, sum, target_sum, ok);
        }
      }
    }
  }
};


int main(int argc, char **argv){
  vector<TreeNode *> v(15);

  for (int i=0; i<15; ++i){
    v[i]=new TreeNode(i);
  }
  v[5]->left=v[4];
  v[5]->right=v[8];
  v[4]->left=v[11];
  v[11]->left=v[7];
  v[11]->right=v[2];
  v[8]->left=v[13];
  v[8]->right=v[4];
  v[4]->right=v[1];

  v[1]->left=v[2];

  Solution s;
  debug_log("%d\n", s.hasPathSum(v[1], 1));

  for (int i=0; i<15; ++i){
    delete v[i];
  }

  return 0;
}
