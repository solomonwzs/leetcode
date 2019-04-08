#include "utils.h"

using namespace std;


class Solution{
 public:
  vector<int> inorderTraversal(TreeNode *root){
    vector<TreeNode *> stack(0);
    vector<int> out(0);

    TreeNode *p=root;
    while (true){
      if (!p){
        if (stack.empty()){
          break;
        } else{
          p=stack.back();
          stack.pop_back();

          out.push_back(p->val);
          p=p->right;
        }
      } else if (p->left){
        stack.push_back(p);
        p=p->left;
      } else{
        out.push_back(p->val);
        p=p->right;
      }
    }

    return out;
  }
};


int main(int argc, char **argv){
  Solution s;
  TreeNode *tree=build_tree(string(argv[1]));
  vector<int> out=s.inorderTraversal(tree);
  for (unsigned i=0; i<out.size(); ++i){
    debug_log("%d\n", out[i]);
  }
  delete_tree(tree);

  return 0;
}
