#include "leetcode.h"

void strsplit_test() {
  std::vector<std::string> out;
  leetcode::strsplit("123,45,6,,87,", ",", out);
  for (auto &i : out) {
    debug_log("[%s]\n", i.c_str());
  }
}

void treenode_test() {
  leetcode::LeetcodeTree t("1,3,null,null,2");
  debug_log("[%s]\n", t.to_str().c_str());
}

int main(int argc, char **argv) {
  strsplit_test();
  treenode_test();

  return 0;
}
