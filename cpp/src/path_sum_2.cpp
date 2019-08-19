#include <vector>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


#define is_leaf(_p) ((_p)->left==NULL && (_p)->right==NULL)

class Solution{
 public:
  vector<vector<int> > pathSum(TreeNode *root, int sum){
    vector<vector<int> > out;
    if (root){
      vector<int> cur_path;
      pre_order_traversal(root, 0, sum, cur_path, out);
    }
    return out;
  }

 private:
  void pre_order_traversal(TreeNode *node, int cur_sum, const int target_sum,
                           vector<int> &cur_path, vector<vector<int> > &out){
    if (node){
      int sum=cur_sum+node->val;
      cur_path.push_back(node->val);
      if (is_leaf(node)){
        if (sum==target_sum){
          out.push_back(cur_path);
        }
      } else{
        pre_order_traversal(node->left, sum, target_sum, cur_path, out);
        pre_order_traversal(node->right, sum, target_sum, cur_path, out);
      }
      cur_path.pop_back();
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
  vector<vector<int> > out=s.pathSum(v[0], 22);
  for (unsigned i=0; i<out.size(); ++i){
    for (unsigned j=0; j<out[i].size(); ++j){
      printf("%d ", out[i][j]);
    }
    printf("\n");
  }

  for (int i=0; i<15; ++i){
    delete v[i];
  }

  return 0;
}
