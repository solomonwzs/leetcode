#include "utils.h"
#include <algorithm>
#include <map>

using namespace std;


struct subset_info{
  vector<int> set;
  int last_num_count;
};

class Solution{
 public:
  vector<vector<int> > subsetsWithDup(vector<int> &s0){
    vector<int> s=s0;
    sort(s.begin(), s.end());

    map<int, int> stat=num_stat(s);

    vector<subset_info> list;
    subset_info e;
    e.set=vector<int>(0);
    e.last_num_count=0;
    list.push_back(e);

    for (map<int, int>::iterator i=stat.begin(); i!=stat.end(); ++i){
      e.set=vector<int>(1);
      e.set[0]=i->first;
      e.last_num_count=1;
      list.push_back(e);
    }

    unsigned idx=1;
    while (idx<list.size()){
      int last=list[idx].set.back();
      for (map<int, int>::iterator i=stat.begin(); i!=stat.end(); ++i){
        if (last==i->first){
          if (list[idx].last_num_count<i->second){
            subset_info ns=list[idx];
            ns.set.push_back(last);
            ++ns.last_num_count;

            list.push_back(ns);
          }
        } else if (last<i->first){
          subset_info ns;
          ns.set=list[idx].set;
          ns.set.push_back(i->first);
          ns.last_num_count=1;

          list.push_back(ns);
        }
      }
      ++idx;
    }

    vector<vector<int> > out(list.size());
    for (unsigned i=0; i<list.size(); ++i){
      out[i]=list[i].set;
    }

    return out;
  }

 private:
  map<int, int> num_stat(vector<int> &s){
    map<int, int> out;
    if (s.size()!=0){
      int n=s[0];
      int m=1;
      for (unsigned i=1; i<s.size(); ++i){
        if (s[i]==n){
          ++m;
        } else{
          out[n]=m;
          n=s[i];
          m=1;
        }
      }
      out[n]=m;
    }
    return out;
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
