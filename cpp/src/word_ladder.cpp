#include <queue>
#include <string>
#include <unordered_set>
#include <map>
#include "leetcode.h"

using namespace std;


#define can_find(_d, _k) ((_d).find(_k)!=(_d).end())

class Solution{
 public:
  int ladderLength(string start, string end, unordered_set<string> &dict){
    map<string, int> m;
    queue<string> q;

    m[start]=1;
    q.push(start);

    while (!q.empty()){
      string word=q.front();
      q.pop();

      if (transform_ok(word, end)){
        return m[word]+1;
      }

      for (unsigned i=0; i<word.size(); ++i){
        string tmp=word;
        for (char c='a'; c<='z'; ++c){
          tmp[i]=c;
          if (can_find(dict, tmp) && !can_find(m, tmp)){
            m[tmp]=m[word]+1;
            q.push(tmp);
          }
        }
      }
    }
    return 0;
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
