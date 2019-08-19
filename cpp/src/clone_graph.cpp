#include <map>
#include <string.h>
#include <vector>
#include "leetcode.h"

using namespace std;

struct UndirectedGraphNode{
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x): label(x) {};
};

#define map_insert(_m, _key, _value) \
    _m.insert(pair<int, UndirectedGraphNode *>(_key, _value))


static inline void print_map(map<int, UndirectedGraphNode *> &m){
  for (map<int, UndirectedGraphNode *>::iterator it=m.begin();
       it!=m.end();
       ++it){
    UndirectedGraphNode *u=it->second;
    printf("%d\n", u->label);
    for (unsigned i=0; i<u->neighbors.size(); ++i){
      printf("%d ", u->neighbors[i]->label);
    }
    printf("\n");
  }
}


static inline int get_ug_node(map<int, UndirectedGraphNode *> &m, int label,
                              UndirectedGraphNode **node){
  auto it=m.find(label);
  if (it==m.end()){
    *node=new UndirectedGraphNode(label);
    map_insert(m, label, *node);
    return 1;
  } else{
    *node=it->second;
    return 0;
  }
}


static inline void clear_map(map<int, UndirectedGraphNode *> &m){
  for (map<int, UndirectedGraphNode *>::iterator it=m.begin(); it!=m.end();
       ++it){
    delete it->second;
  }
}


class Solution{
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
    if (node==NULL){
      return NULL;
    }

    map<int, UndirectedGraphNode *> m;
    vector<UndirectedGraphNode *> v;
    map_insert(m, node->label, node);
    v.push_back(node);

    UndirectedGraphNode *cnode=new UndirectedGraphNode(node->label);
    map<int, UndirectedGraphNode *> cmap;
    map_insert(cmap, cnode->label, cnode);

    for (unsigned i=0; i<v.size(); ++i){
      UndirectedGraphNode *cn;
      get_ug_node(cmap, v[i]->label, &cn);
      vector<UndirectedGraphNode *>neighbors=v[i]->neighbors;

      for (vector<UndirectedGraphNode *>::iterator n=neighbors.begin();
           n!=neighbors.end(); ++n){
        UndirectedGraphNode *cneighbor;
        UndirectedGraphNode *neighbor=(*n);
        int is_new;

        is_new=get_ug_node(cmap, neighbor->label, &cneighbor);
        if (is_new){
          v.push_back(neighbor);
        }

        cn->neighbors.push_back(cneighbor);
      }
    }
    return cnode;
  }
};


int main(int argc, char **argv){
  map<int, UndirectedGraphNode *> m;
  for (int i=1; i<argc; ++i){
    int label=atoi(argv[i]);
    UndirectedGraphNode *node;

    get_ug_node(m, label, &node);
    ++i;
    while (i<argc && strcmp(argv[i], "#")!=0){
      UndirectedGraphNode *neighbor;
      label=atoi(argv[i]);
      get_ug_node(m, label, &neighbor);
      node->neighbors.push_back(neighbor);
      ++i;
    }
  }

  Solution s;
  UndirectedGraphNode *cnode=s.cloneGraph(m.begin()->second);

  map<int, UndirectedGraphNode *> cmap;
  map_insert(cmap, cnode->label, cnode);
  vector<UndirectedGraphNode *> cv;
  cv.push_back(cnode);
  for (unsigned i=0; i<cv.size(); ++i){
    vector<UndirectedGraphNode *> neighbors=cv[i]->neighbors;
    for (vector<UndirectedGraphNode *>::iterator it=neighbors.begin();
         it!=neighbors.end(); ++it){
      auto n=cmap.find((*it)->label);
      if (n==cmap.end()){
        map_insert(cmap, (*it)->label, *it);
        cv.push_back(*it);
      }
    }
  }

  print_map(cmap);

  clear_map(m);
  clear_map(cmap);

  return 0;
}
