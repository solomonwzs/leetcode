#include <string>
#include <unordered_set>
#include <vector>
#include "utils.h"

using namespace std;

#define pos(_d, _n, _x, _y) (_d)[(_x)*(_n)+(_y)]


class Solution{
 public:
  int ladderLength(string start, string end, unordered_set<string> &dict){
    int n=dict.size()+2;
    vector<int> d(n*n);
    vector<string> v;

    v.push_back(start);
    v.push_back(end);
    for (unordered_set<string>::iterator i=dict.begin();
         i!=dict.end();
         ++i){
      //debug_log("%s\n", i->c_str());
      v.push_back(*i);
    }

    for (int i=0; i<n-1; ++i){
      for (int j=i+1; j<n; ++j){
        pos(d, n, i, j)=this->check_word(v[i], v[j]);
        pos(d, n, j, i)=pos(d, n, i, j);
      }
    }

    for (int i=0; i<n; ++i){
      printf("[%s] ", v[i].c_str());
    }
    printf("\n");
    for (int i=0; i<n; ++i){
      for (int j=0; j<n; ++j){
        printf("%5d ", pos(d, n, i, j));
      }
      printf("\n");
    }

    unordered_set<int> s;
    unordered_set<int> q;

    s.insert(0);
    for (int i=1; i<n; ++i){
      q.insert(i);
    }

    while (q.size()>0){
      int min=n;
      int u=-1;
      for (unordered_set<int>::iterator i=q.begin(); i!=q.end(); ++i){
        if (pos(d, n, 0, *i)!=-1 && pos(d, n, 0, *i)<min){
          u=*i;
          min=pos(d, n, 0, *i);
        }
      }
      debug_log("%s\n", v[u].c_str());

      if (u==-1){
        return 0;
      } else if (u==1){
        return min;
      } else{
        s.insert(u);
        q.erase(u);
        for (int i=1; i<n; ++i){
          if (i!=u && (pos(d, n, 0, i)==-1
                       || (pos(d, n, u, i)!=-1
                           && min+pos(d, n, u, i)<pos(d, n, 0, i)))){
            pos(d, n, 0, i)=min+pos(d, n, u, i);
            pos(d, n, i, 0)=pos(d, n, 0, i);
          }
        }
      }
    }

    return pos(d, n, 0, 1);
  }

 private:
  int check_word(string word1, string word2){
    int diff=0;
    for (unsigned i=0; i<word1.size(); ++i){
      if (word1[i]!=word2[i]){
        if (diff==0){
          diff=1;
        } else{
          return -1;
        }
      }
    }
    return diff;
  }
};


int main(int argc, char **argv){
  string start=string(argv[1]);
  string end=string(argv[2]);
  unordered_set<string> dict;
  for (int i=3; i<argc; ++i){
    dict.insert(string(argv[i]));
  }

  Solution s;
  debug_log("%d\n", s.ladderLength(start, end, dict));

  return 0;
}
