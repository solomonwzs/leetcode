#include <vector>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution{
 public:
  TreeNode *sortedListToBST(ListNode *head){
    ListNode *p=head;
    vector<int> v;
    while (p){
      v.push_back(p->val);
      p=p->next;
    }
    return sorted_list_to_bst(v, 0, v.size());
  }

 private:
  TreeNode *sorted_list_to_bst(vector<int> &sorted_list, int start, int len){
    if (len<=0){
      return NULL;
    }

    int mid=(start+len+start-1)/2;
    TreeNode *head=new TreeNode(sorted_list[mid]);

    TreeNode *left_child=sorted_list_to_bst(sorted_list, start, mid-start);
    TreeNode *right_child=sorted_list_to_bst(sorted_list, mid+1,
                                             (start+len)-(mid+1));
    head->left=left_child;
    head->right=right_child;

    return head;
  }
};


int main(int argc, char **argv){
  // Solution s;
  // {
  //   // TreeNode *root=s.sortedListToBST(head);
  //   // print_tree(root);
  //   // delete_tree(root);
  //   // delete_link_list(head);
  // }
  return 0;
}
