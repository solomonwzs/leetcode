#include <vector>
#include "utils.h"

using namespace std;


class Solution{
 public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
    return build_tree(inorder, 0, postorder, 0, inorder.size());
  }

 private:
  TreeNode *build_tree(vector<int> &inorder, int pos0,
                       vector<int> &postorder, int pos1, int len){
    if (len<=0){
      return NULL;
    } else{
      int root_val=postorder[pos1+len-1];

      int mid0;
      for (mid0=pos0; mid0<pos0+len; ++mid0){
        if (inorder[mid0]==root_val){
          break;
        }
      }
      int left_pos0=pos0;
      int left_len=mid0-pos0;
      int right_pos0=mid0+1;
      int right_len=pos0+len-mid0-1;

      int left_pos1=pos1;
      int right_pos1=left_len>0?pos1+left_len:pos1;

      TreeNode *root=new TreeNode(root_val);
      root->left=build_tree(inorder, left_pos0, postorder, left_pos1, left_len);
      root->right=build_tree(inorder, right_pos0, postorder, right_pos1,
                             right_len);

      return root;
    }
  }
};


int main(int argc, char **argv){
  int a[]={3, 2, 4, 1};
  int b[]={3, 4, 2, 1};

  vector<int> inorder(a, a+sizeof(a)/sizeof(int));
  vector<int> postorder(b, b+sizeof(b)/sizeof(int));

  Solution s;
  TreeNode *root=s.buildTree(inorder, postorder);
  print_tree(root);
  delete_tree(root);

  return 0;
}
