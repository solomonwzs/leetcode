#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution{
 public:
  vector<TreeNode *> generateTrees(int n){
    vector<vector<TreeNode *> > cache(n+1);
    for (int i=0; i<n+1; ++i){
      cache[i]=vector<TreeNode *>(0);
    }
    cache[0].push_back(NULL);
    gen_trees0(n, cache);

    for (int i=0; i<n; ++i){
      for (unsigned j=0; j<cache[i].size(); ++j){
        delete_tree(cache[i][j]);
      }
    }

    return cache[n];
  }

 private:
  TreeNode *copy_tree(TreeNode *orig, int offset){
    if (!orig){
      return NULL;
    } else{
      TreeNode *copy=new TreeNode(orig->val+offset);
      copy->left=copy_tree(orig->left, offset);
      copy->right=copy_tree(orig->right, offset);

      return copy;
    }
  }

  void delete_tree(TreeNode *tree){
    if (tree){
      delete_tree(tree->left);
      delete_tree(tree->right);
      delete tree;
    }
  }

  vector<TreeNode *> gen_trees0(int n, vector<vector<TreeNode *> > &cache){
    if (cache[n].size()==0){
      if (n==1) {
        cache[1].push_back(new TreeNode(1));
      } else{
        for (int i=0; i<n; ++i){
          vector<TreeNode *> left_temp=gen_trees0(i, cache);
          vector<TreeNode *> right_temp=gen_trees0(n-i-1, cache);

          for (unsigned l=0; l<left_temp.size(); ++l){
            for (unsigned r=0; r<right_temp.size(); ++r){
              TreeNode *left=copy_tree(left_temp[l], 0);
              TreeNode *right=copy_tree(right_temp[r], i+1);
              TreeNode *root=new TreeNode(i+1);
              root->left=left;
              root->right=right;

              cache[n].push_back(root);
            }
          }
        }
      }
    }
    return cache[n];
  }
};


int main(int argc, char **argv){
  Solution s;
  vector<TreeNode *> out=s.generateTrees(atoi(argv[1]));
  for (unsigned i=0; i<out.size(); ++i){
    LeetcodeTree t(out[i]);
    debug_log("[%s]\n", t.to_str().c_str());
  }

  return 0;
}
