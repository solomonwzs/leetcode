#include <vector>
#include "utils.h"

using namespace std;


class Solution{
 public:
  TreeNode *sortedArrayToBST(vector<int> &num){
    return sorted_array_to_bst(num, 0, num.size());
  }

 private:
  TreeNode *sorted_array_to_bst(vector<int> &sorted_list, int start, int len){
    if (len<=0){
      return NULL;
    }

    int mid=(start+len+start-1)/2;
    TreeNode *head=new TreeNode(sorted_list[mid]);

    TreeNode *left_child=sorted_array_to_bst(sorted_list, start, mid-start);
    TreeNode *right_child=sorted_array_to_bst(sorted_list, mid+1,
                                             (start+len)-(mid+1));
    head->left=left_child;
    head->right=right_child;

    return head;
  }
};


int main(int argc, char **argv){
  vector<int> num;
  for (int i=1; i<argc; ++i){
    num.push_back(atoi(argv[i]));
  }

  Solution s;
  TreeNode *root=s.sortedArrayToBST(num);
  print_tree(root);
  delete_tree(root);

  return 0;
}
