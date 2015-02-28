#include "utils.h"
#include <algorithm>
#include <map>

using namespace std;


struct subset_with_index{
  vector<int> set;
  int index;
};

class Solution{
 public:
  vector<vector<int> > subsetsWithDup(vector<int> &S0){
    vector<int> S=S0;
    vector<subset_with_index> list;
    subset_with_index e;

    e.set=vector<int>(0);
    e.index=-1;

    list.push_back(e);

    sort(S.begin(), S.end());
    unsigned idx=0;
    while (idx<list.size()){
      subset_with_index sub=list[idx];
      map<int, int> m=gen_index_map(S, sub.index);

      for (map<int, int>::iterator i=m.begin(); i!=m.end(); ++i){
        subset_with_index s;
        s.set=sub.set;
        s.set.push_back(i->first);
        s.index=i->second;

        list.push_back(s);
      }

      ++idx;
    }


    vector<vector<int> > out;
    for (unsigned i=0; i<list.size(); ++i){
      out.push_back(list[i].set);
    }
    return out;
  }

 private:
  map<int, int> gen_index_map(vector<int> &S, int index){
    map<int, int> m;
    for (unsigned i=index+1; i<S.size(); ++i){
      if (m.find(S[i])==m.end()){
        m[S[i]]=i;
      }
    }
    return m;
  }
};


int main(int argc, char **argv){
  int a[]={4, 1, 0};
  vector<int> S(a, end_of_array(a, int));

  Solution s;
  vector<vector<int> > out=s.subsetsWithDup(S);
  for (unsigned i=0; i<out.size(); ++i){
    printf("[ ");
    for (unsigned j=0; j<out[i].size(); ++j){
      printf("%d ", out[i][j]);
    }
    printf("]\n");
  }
  return 0;
}
