#include "leetcode.h"

using namespace std;
using namespace leetcode;


#define same_nonnull_node(_a, _b) ((_a) && (_b) && (_a)->val==(_b)->val)

#define check_nodes(_a, _b, _v, _nl) \
    if (same_nonnull_node(_a, _b)){ \
      _v.push_back(_a); \
      _v.push_back(_b); \
      _nl+=2; \
    } else if ((_a)!=NULL || (_b)!=NULL){ \
      return false; \
    }

class Solution{
 public:
  bool isSameTree(TreeNode *p, TreeNode *q){
    if (!p && !q){
      return true;
    } else if (same_nonnull_node(p, q)){
      vector<TreeNode *> v;
      v.push_back(p);
      v.push_back(q);
      int pos=0;
      int len=2;
      while (true){
        int next_len=0;

        for (int i=pos; i<pos+len; i+=2){
          TreeNode *pnode=v[i];
          TreeNode *qnode=v[i+1];

          check_nodes(pnode->left, qnode->left, v, next_len);
          check_nodes(pnode->right, qnode->right, v, next_len);
        }

        if (next_len==0){
          return true;
        } else{
          pos+=len;
          len=next_len;
        }
      }
    } else{
      return false;
    }
  }
};


int main(int argc, char **argv){
  // TreeNode *p=build_tree("2,3,3,4,5,5,4,#,#,8,9,9,8");
  // print_tree(p);
  // TreeNode *q=build_tree("2,3,3,4,5,5,4,#,8,9,9,8,#");
  // print_tree(q);

  // Solution s;
  // debug_log("%d\n", s.isSameTree(p, q));

  // delete_tree(p);
  // delete_tree(q);

  return 0;
}
