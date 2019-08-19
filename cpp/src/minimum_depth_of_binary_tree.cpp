#include <vector>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


#define is_leaf(_p) ((_p)->left==NULL && (_p)->right==NULL)

class Solution{
 public:
  int minDepth(TreeNode *root){
    if (!root){
      return 0;
    }

    vector<TreeNode *> q;
    q.push_back(root);
    int depth=1;
    int pos=0;
    int len=1;
    while (true){
      for (int i=pos; i<pos+len; ++i){
        if (is_leaf(q[i])){
          return depth;
        } else{
          if (q[i]->left){
            q.push_back(q[i]->left);
          }
          if (q[i]->right){
            q.push_back(q[i]->right);
          }
        }
      }

      pos+=len;
      len=q.size()-pos;
      ++depth;
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
  //v[2]->left=v[4];
  //v[2]->right=v[5];
  v[3]->left=v[6];
  v[3]->right=v[7];
  v[5]->left=v[8];
  v[5]->right=v[9];

  Solution s;
  debug_log("%d\n", s.minDepth(v[0]));

  for (int i=0; i<15; ++i){
    delete v[i];
  }

  return 0;
}
