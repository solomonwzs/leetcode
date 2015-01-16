#include <limits>
#include <vector>
#include "utils.h"

using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    int max=std::numeric_limits<int>::min();
    max_sub_path_sum(root, max);

    return max;
  }

 private:
  int max_sub_path_sum(TreeNode *node, int &max_out){
    if (!node){
      return 0;
    } else{
      int left=max_sub_path_sum(node->left, max_out);
      int right=max_sub_path_sum(node->right, max_out);

      if (left<0){
        left=0;
      }
      if (right<0){
        right=0;
      }

      if (node->val+left+right>max_out){
        max_out=node->val+left+right;
      }
      return node->val+(left>right?left:right);
    }
  }
};


int main(int agrc, char **argv){
  vector<TreeNode *> v(10);
  for (int i=0; i<10; ++i){
    v[i]=new TreeNode(i);
  }

  v[1]->val=2;
  v[2]->val=-1;
  v[1]->right=v[2];

  Solution s;
  debug_log("%d\n", s.maxPathSum(v[1]));

  for (int i=0; i<10; ++i){
    delete v[i];
  }
  return 0;
}
