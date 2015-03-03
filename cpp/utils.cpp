#include "utils.h"

using namespace std;

static void print_tree0(TreeNode *root);

#define is_leaf(_n) (!(_n)->left && !(_n)->right)


void print_tree(TreeNode *root){
  print_tree0(root);
  printf("\n");
}


static void print_tree0(TreeNode *root){
  if (!root){
    printf("_");
  } else{
    if (is_leaf(root)){
      printf("%d", root->val);
    } else{
      printf("{");
      print_tree0(root->left);
      printf(" %d ", root->val);
      print_tree0(root->right);
      printf("}");
    }
  }
}


void delete_tree(TreeNode *root){
  if (!root){
    return;
  } else{
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }
}


#define parser_tree_nodes(_c, _v, _q, _i) \
    if (_i>=_v.size() || _v[_i]=="#"){ \
      _c=NULL; \
    } else{ \
      _c=new TreeNode(atoi(_v[_i].c_str())); \
      _q.push(_c); \
    }

TreeNode *build_tree(string str){
  vector<string> v;
  string s;
  for (unsigned i=0; i<str.size(); ++i){
    if (str[i]==','){
      v.push_back(s);
      s.clear();
    } else if (('0'<=str[i] && str[i]<='9') || str[i]=='#'){
      s.push_back(str[i]);
    }
  }
  if (s.size()){
    v.push_back(s);
  }

  if (v.size()){
    queue<TreeNode *> pnodes;
    TreeNode *root=new TreeNode(atoi(v[0].c_str()));
    pnodes.push(root);

    unsigned index=1;
    while (index<v.size()){
      TreeNode *cur=pnodes.front();

      parser_tree_nodes(cur->left, v, pnodes, index);
      ++index;
      parser_tree_nodes(cur->right, v, pnodes, index);
      ++index;

      pnodes.pop();
    }
    return root;
  } else{
    return NULL;
  }
}


void print_binary(int i, int len){
  for (int z=len-1; z>=0; --z){
    printf("%d", ((i>>z) & 0x1));
  }
  printf("\n");
}
