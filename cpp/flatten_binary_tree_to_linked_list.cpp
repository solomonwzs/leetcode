#include <vector>
#include "utils.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
 public:
  void flatten(TreeNode *root){
    vector<TreeNode *> list;
    pre_order_traversal(root, list);
    list.push_back(NULL);

    for (unsigned i=0; i<list.size()-1; ++i){
      list[i]->left=NULL;
      list[i]->right=list[i+1];
    }
  }

 private:
  void pre_order_traversal(TreeNode *root, vector<TreeNode *> &list){
    if (root){
      list.push_back(root);
      pre_order_traversal(root->left, list);
      pre_order_traversal(root->right, list);
    }
  }
};


int main(int argc, char **argv){
  vector<TreeNode *> v;
  for (int i=1; i<=6; ++i){
    v.push_back(new TreeNode(i));
  }

  v[0]->left=v[1];
  v[0]->right=v[4];
  v[1]->left=v[2];
  v[1]->right=v[3];
  v[4]->right=v[5];

  Solution s;
  s.flatten(v[0]);

  TreeNode *p=v[0];
  while (p){
    debug_log("%d\n", p->val);
    p=p->right;
  }

  for (int i=0; i<6; ++i){
    delete v[i];
  }

  return 0;
}
