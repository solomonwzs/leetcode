#include <vector>
#include "utils.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};


class Solution{
 public:
  int sumNumbers(TreeNode *root){
    if (root==NULL){
      return 0;
    }

    int sum=0;
    this->traversal(root, 0, sum);
    return sum;
  }

 private:
  void traversal(TreeNode *node, int num, int &sum){
    int num1=num*10+node->val;
    if (!node->left && !node->right){
      sum+=num1;
    } else{
      if (node->left){
        this->traversal(node->left, num1, sum);
      }
      if (node->right){
        this->traversal(node->right, num1, sum);
      }
    }
  }
};


int main(int argc, char **argv){
  vector<TreeNode *> v(9);
  for (int i=0; i<9; ++i){
    v[i]=new TreeNode(i+1);
  }
  v[0]->left=v[1];
  v[0]->right=v[2];

  Solution s;
  debug_log("%d\n", s.sumNumbers(v[0]));

  for (int i=0; i<9; ++i){
    delete v[i];
  }

  return 0;
}
