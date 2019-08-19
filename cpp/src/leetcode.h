#ifndef __LEETCODE_CPP_UTILS__
#define __LEETCODE_CPP_UTILS__

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#define debug_log(_fmt_, ...) \
    printf("\033[0;33m[%s:%d]\033[0m " _fmt_, __FILE__, __LINE__, ## __VA_ARGS__)

namespace leetcode {

struct ListNode{
  int val;
  ListNode *next;

  ListNode(int x): val(x), next(NULL){}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void delete_tree(TreeNode *root);

class LeetcodeTree {
 public:
  LeetcodeTree(const std::string &str);
  LeetcodeTree(TreeNode *root): m_root(root) {};
  ~LeetcodeTree();

  TreeNode *root() { return m_root; }
  std::string to_str();

 private:
  TreeNode *m_root = NULL;
};

void strsplit(const std::string &str, const char *seps,
              std::vector<std::string> &out);

} // namespace leetcode

#endif
