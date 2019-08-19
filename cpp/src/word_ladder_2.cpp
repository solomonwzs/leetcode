#include <queue>
#include <string>
#include <unordered_set>
#include <map>
#include "leetcode.h"

using namespace std;


#define can_find(_d, _k) ((_d).find(_k)!=(_d).end())

class Solution{
 public:
  vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict){
    map<string, int> m;
    queue<string> q;

    m[start]=1;
    q.push(start);

    vector< vector<string> > out;
    map<string, vector<string> > next;
    int min=-1;
    while (!q.empty()){
      string word=q.front();
      q.pop();
      int cur_len=m[word];

      if (transform_ok(word, end)){
        next[word].push_back(end);
        min=m[word]+1;
      } else if (min==-1 || cur_len+1<min){
        for (unsigned i=0; i<word.size(); ++i){
          string tmp=word;
          for (char c='a'; c<='z'; ++c){
            tmp[i]=c;
            if (can_find(dict, tmp)){
              if (!can_find(m, tmp)){
                next[word].push_back(tmp);
                m[tmp]=cur_len+1;
                q.push(tmp);
              } else if (m[tmp]==cur_len+1){
                next[word].push_back(tmp);
              }
            }
          }
        }
      }
    }

    if (min==-1){
      return out;
    } else{
      vector<string> mid_res;
      mid_res.push_back(start);
      traversal(start, end, next, mid_res, out);
      return out;
    }
  }

 private:
  bool transform_ok(string word1, string word2){
    int diff=0;
    for (unsigned i=0; i<word1.size(); ++i){
      if (word1[i]!=word2[i]){
        if (diff==0){
          diff=1;
        } else{
          return false;
        }
      }
    }
    return diff==1;
  }

  void traversal(string word, string end, map<string, vector<string> > &next,
                 vector<string> &mid_res,
                 vector< vector<string> > &out){
    if (word==end){
      out.push_back(mid_res);
    } else{
      vector<string> next_words=next[word];
      for (vector<string>::iterator i=next_words.begin(); i!=next_words.end();
           ++i){
        mid_res.push_back(*i);
        traversal(*i, end, next, mid_res, out);
        mid_res.pop_back();
      }
    }
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
  vector< vector<string> > out=s.findLadders(start, end, dict);

  for (unsigned i=0; i<out.size(); ++i){
    for (unsigned j=0; j<out[i].size(); ++j){
      printf("[%s] ", out[i][j].c_str());
    }
    printf("\n");
  }

  return 0;
}
