#include <map>
#include <string.h>
#include <vector>
#include "utils.h"

using namespace std;

struct UndirectedGraphNode{
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x): label(x) {};
};

#define get_ug_node(_m, _label, _u) do{\
  auto __it=_m.find(_label);\
  if (__it==_m.end()){\
    _u=new UndirectedGraphNode(_label);\
    _m.insert(pair<int, UndirectedGraphNode *>(_label, _u));\
  } else{\
    _u=__it->second;\
  }\
} while (0)


class Solution{
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
    return NULL;
  }
};


int main(int argc, char **argv){
  map<int, UndirectedGraphNode *> m;
  for (int i=1; i<argc; ++i){
    int label=atoi(argv[i]);
    UndirectedGraphNode *node;

    get_ug_node(m, label, node);
    ++i;
    while (i<argc && strcmp(argv[i], "#")!=0){
      UndirectedGraphNode *neighbor;
      label=atoi(argv[i]);
      get_ug_node(m, label, neighbor);
      node->neighbors.push_back(neighbor);
    }
  }

  for (map<int, UndirectedGraphNode *>::iterator it=m.begin();
       it!=m.end();
       ++it){
    delete it->second;
  }
  return 0;
}
