#include <vector>
#include "utils.h"

using namespace std;


class Solution{
 public:
  bool isBalanced(TreeNode *root){
    bool ok=true;
    check_depth(root, ok);
    return ok;
  }

 private:
  int check_depth(TreeNode *root, bool &ok){
    if (ok){
      if (!root){
        return 0;
      } else{
        int left_depth=check_depth(root->left, ok);
        int right_depth=check_depth(root->right, ok);

        if (abs(left_depth-right_depth)>1){
          ok=false;
        }

        return (left_depth>right_depth?left_depth:right_depth)+1;
      }
    } else{
      return 0;
    }
  }
};


int main(int argc, char **argv){
  int arr[15]={5, 4, 8, 11, 13, 4, 7, 2, 5, 1};
  vector<TreeNode *> v(15);

  for (int i=0; i<15; ++i){
    v[i]=new TreeNode(arr[i]);
  }
  v[0]->left=v[1];
  v[0]->right=v[2];
  v[1]->left=v[3];
  v[2]->left=v[4];
  v[2]->right=v[5];
  v[3]->left=v[6];
  v[3]->right=v[7];
  v[5]->left=v[8];
  v[5]->right=v[9];

  Solution s;
  debug_log("%d\n", s.isBalanced(v[0]));

  for (int i=0; i<15; ++i){
    delete v[i];
  }
  return 0;
}
