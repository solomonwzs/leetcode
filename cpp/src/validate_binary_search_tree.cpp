#include "leetcode.h"

using namespace std;
using namespace leetcode;


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
  Solution s;
  {
    LeetcodeTree t("5,1,4,null,null,3,6");
    debug_log("%d\n", s.isValidBST(t.root()));
  }

  return 0;
}
