#include <algorithm>
#include <vector>
#include "utils.h"

using namespace std;


class Solution{
 public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root){
    vector<vector<int> > out;
    int r=0;

    if (root){
      vector<TreeNode *> list;
      list.push_back(root);
      int pos=0;
      int len=1;
      while (true){
        if (len==0){
          break;
        }

        vector<int> cur_level;
        int next_len=0;
        for (int i=pos; i<pos+len; ++i){
          cur_level.push_back(list[i]->val);
          if (list[i]->left){
            next_len++;
            list.push_back(list[i]->left);
          }
          if (list[i]->right){
            next_len++;
            list.push_back(list[i]->right);
          }
        }

        if (r){
          reverse(cur_level.begin(), cur_level.end());
        }
        r=r xor 1;
        out.push_back(cur_level);

        pos+=len;
        len=next_len;
      }
    }

    return out;
  }
};


#define VECTOR_SIZE 25
int main(int argc, char **argv){
  vector<TreeNode *> v(VECTOR_SIZE);
  for (int i=0; i<VECTOR_SIZE; ++i){
    v[i]=new TreeNode(i);
  }

  v[3]->left=v[9];
  v[3]->right=v[20];
  v[20]->left=v[15];
  v[20]->right=v[7];

  Solution s;
  vector<vector<int> > out=s.zigzagLevelOrder(v[3]);

  for (unsigned i=0; i<out.size(); ++i){
    for (unsigned j=0; j<out[i].size(); ++j){
      printf("%d ", out[i][j]);
    }
    printf("\n");
  }

  for (int i=0; i<VECTOR_SIZE; ++i){
    delete v[i];
  }
  return 0;
}
