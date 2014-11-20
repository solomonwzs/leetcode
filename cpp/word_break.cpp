#include <stdio.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution{
 public:
  bool wordBreak(string s, unordered_set<string> &dict){
    vector<bool> v;
    for (unsigned i=0; i<=s.length(); ++i){
      v.push_back(false);
    }
    v[0]=true;

    for (unsigned i=0; i<v.size(); ++i){
      if (v[i]){
        for (unordered_set<string>::iterator it=dict.begin();
             it!=dict.end();
             ++it){
          unsigned len=it->length();
          unsigned j=i+len;
          if (j<v.size() && s.substr(i, len)==*it){
            v[j]=true;
          }
        }
      }
    }

    return v[v.size()-1];
  }
};


int main(){
  string str=
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaab";
  unordered_set<string> dict;
  dict.insert("a");
  dict.insert("aa");
  dict.insert("aaa");
  dict.insert("aaaa");
  dict.insert("aaaaa");
  dict.insert("aaaaaa");

  Solution s;
  printf("%d\n", s.wordBreak(str, dict));

  return 0;
}
