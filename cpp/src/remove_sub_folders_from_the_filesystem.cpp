#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct node_t {
  map<string, node_t> next;
};

vector<string> split(const string &folder) {
  vector<string> res;
  for (const char *p = folder.c_str() + 1; *p != '\0';) {
    const char *q = strchr(p, '/');
    if (q == NULL) {
      res.push_back(p);
      break;
    } else {
      res.push_back(string(p, q - p));
      p = q + 1;
    }
  }
  return res;
}

void dfs(const map<string, node_t> &t, vector<string> &path, vector<string> &ans) {
  if (t.size() == 0) {
    ans.push_back("");
    string &s = ans.back();
    for (const string &i : path) {
      s.push_back('/');
      s.append(i);
    }
  }

  for (auto it = t.begin(); it != t.end(); ++it) {
    path.push_back(it->first);
    dfs(it->second.next, path, ans);
    path.pop_back();
  }
}

class Solution {
 public:
  vector<string> removeSubfolders_v1(vector<string> &folder) {
    map<string, node_t> root;

    for (const string &f : folder) {
      vector<string> sfolder = split(f);

      map<string, node_t> *cur = &root;
      bool insert_new_node = true;
      for (unsigned i = 0; i < sfolder.size(); ++i) {
        map<string, node_t>::iterator it = cur->find(sfolder[i]);
        if (it == cur->end()) {
          if (insert_new_node || cur->size() != 0) {
            cur = &((*cur)[sfolder[i]].next);
            insert_new_node = true;
          } else {
            break;
          }
        } else {
          cur = &(it->second.next);
          insert_new_node = false;
        }
      }
      cur->clear();
    }
    vector<string> ans;
    vector<string> path;
    dfs(root, path, ans);

    return ans;
  }

  vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end());
    vector<string> ans;
    for (const string &f : folder) {
      if (ans.empty() ||
          strncmp(ans.back().c_str(), f.c_str(), ans.back().length()) != 0 ||
          (f.length() > ans.back().length() && f[ans.back().length()] != '/')) {
        ans.push_back(f);
      }
    }
    return ans;
  }
};

int main(int argc, char **argv) {
  Solution s;
  {
    auto folder = vector<string> {
      "/a","/a/b","/c/d","/c/d/e","/c/f"
    };
    auto ans = s.removeSubfolders(folder);
    printf("====\n");
    for (auto i : ans) {
      printf("%s\n", i.c_str());
    }
  }
  {
    auto folder = vector<string> {
      "/a","/a/b/c","/a/b/d"
    };
    auto ans = s.removeSubfolders(folder);
    printf("====\n");
    for (auto i : ans) {
      printf("%s\n", i.c_str());
    }
  }
  {
    auto folder = vector<string> {
      "/a/b/c","/a/b/ca","/a/b/d"
    };
    auto ans = s.removeSubfolders(folder);
    printf("====\n");
    for (auto i : ans) {
      printf("%s\n", i.c_str());
    }
  }

  return 0;
}
