#include "leetcode.h"

namespace leetcode {

void strsplit(const std::string &str, const char *seps,
              std::vector<std::string> &out) {
  size_t pos = 0;
  const char *s0 = str.c_str();
  while (pos < str.length()) {
    size_t i = str.find_first_of(seps, pos);
    if (i == std::string::npos) {
      out.push_back(std::string(s0 + pos));
      break;
    } else {
      out.push_back(std::string(s0 + pos, i - pos));
      pos = i + 1;
    }
  }
  if (pos == str.length()) {
    out.push_back("");
  }
  return;
}

void delete_tree(TreeNode *root) {
  if (root == NULL) {
    return;
  }

  std::vector<TreeNode *> p;
  p.push_back(root);
  size_t i = 0;
  while (i < p.size()) {
    TreeNode *n = p[i];

    if (n->left != NULL) {
      p.push_back(n->left);
    }
    if (n->right != NULL) {
      p.push_back(n->right);
    }

    delete n;
    i += 1;
  }
}

LeetcodeTree::LeetcodeTree(const std::string &str) {
  std::vector<std::string> arr;
  strsplit(str, ",", arr);

  if (arr.size() == 0) {
    return;
  }

  int val = atoi(arr[0].c_str());
  m_root = new TreeNode(val);
  std::vector<TreeNode *> p = {m_root};

  size_t j = 0;
  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr[i] != "null") {
      val = atoi(arr[i].c_str());
      TreeNode *node = new TreeNode(val);
      TreeNode *parent = p[j / 2];
      if (j % 2 == 0) {
        parent->left = node;
      } else {
        parent->right = node;
      }
      p.push_back(node);
    }
    j += 1;
  }
}

LeetcodeTree::~LeetcodeTree() {
  delete_tree(m_root);
}

std::string LeetcodeTree::to_str() {
  std::vector<TreeNode *> p = {m_root};
  size_t i = 0;
  while (i < p.size()) {
    TreeNode *node = p[i];
    if (node != NULL) {
      p.push_back(node->left);
      p.push_back(node->right);
    }
     i += 1;
  }

  while (i > 0 && p[i - 1] == NULL) {
    p.pop_back();
    i -= 1;
  }

  std::string s;
  for (size_t i = 0; i < p.size(); ++i) {
    if (i != 0) {
      s.push_back(',');
    }
    if (p[i] == NULL) {
      s.append("null");
    } else {
      char buf[32];
      sprintf(buf, "%d", p[i]->val);
      s.append(buf);
    }
  }

  return s;
}

} // namespace leetcode
