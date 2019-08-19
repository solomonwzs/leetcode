#include <vector>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution{
 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
    return build_tree(preorder, 0, inorder, 0, inorder.size());
  }

 private:
  TreeNode *build_tree(vector<int> &preorder, int pos0,
                       vector<int> &inorder, int pos1, int len){
    if (len<=0){
      return NULL;
    } else{
      int root_val=preorder[pos0];

      int mid1;
      for (mid1=pos1; mid1<pos1+len; ++mid1){
        if (inorder[mid1]==root_val){
          break;
        }
      }
      int left_pos1=pos1;
      int left_len=mid1-pos1;
      int right_pos1=mid1+1;
      int right_len=pos1+len-mid1-1;

      int left_pos0=pos0+1;
      int right_pos0=left_len>0?left_pos0+left_len:pos0+1;

      TreeNode *root=new TreeNode(root_val);
      root->left=build_tree(preorder, left_pos0, inorder, left_pos1, left_len);
      root->right=build_tree(preorder, right_pos0, inorder, right_pos1,
                             right_len);

      return root;
    }
  }
};


int main(int argc, char **argv){
  vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
  vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};

  Solution s;
  TreeNode *root=s.buildTree(preorder, inorder);
  LeetcodeTree t(root);
  debug_log("[%s]\n", t.to_str().c_str());

  return 0;
}
