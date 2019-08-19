#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution{
 public:
  vector<int> preorderTraversal(TreeNode *root){
    vector<int> v;
    if (root){
      this->preorderTraversal0(root, &v);
    }
    return v;
  }
 private:
  void preorderTraversal0(TreeNode *node, vector<int> *v){
    v->push_back(node->val);
    if (node->left){
      this->preorderTraversal0(node->left, v);
    }
    if (node->right){
      this->preorderTraversal0(node->right, v);
    }
  }
};


int main(int argc, char **argv){
  Solution s;

  LeetcodeTree t(argv[1]);
  vector<int>v = s.preorderTraversal(t.root());
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
    printf("%d\n", *it);
  }

  return 0;
}
