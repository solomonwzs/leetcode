#include <vector>

#include "leetcode.h"

using namespace std;
using namespace leetcode;

struct info {
  TreeNode *node;
  int level;

  info(TreeNode *n, int l) {
    node = n;
    level = l;
  }
};

class Solution {
 public:
  int maxLevelSum(TreeNode* root) {
    vector<info> l;
    l.push_back(info(root, 1));

    unsigned i = 0;
    int ans_level = 1;
    int ans_sum = 0;

    int cur_level = 1;
    int cur_sum = 0;
    while (i < l.size()) {
      info n = l[i];
      if (n.level == cur_level) {
        cur_sum += n.node->val;
      } else {
        if (cur_sum > ans_sum) {
          ans_sum = cur_sum;
          ans_level = cur_level;
        }
        cur_level = n.level;
        cur_sum = n.node->val;
      }

      if (n.node->left != NULL) {
        l.push_back(info(n.node->left, n.level + 1));
      }
      if (n.node->right != NULL) {
        l.push_back(info(n.node->right, n.level + 1));
      }

      i += 1;
    }

    if (cur_sum > ans_sum) {
      ans_sum = cur_sum;
      ans_level = cur_level;
    }
    return ans_level;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    LeetcodeTree t("1,7,0,7,8,#,#");
    printf("%d\n", s.maxLevelSum(t.root()));
  }
  return 0;
}
