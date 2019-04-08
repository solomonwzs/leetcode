#include <stdio.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution{
 public:
  vector<string> wordBreak(string s, unordered_set<string> &dict){
    vector<vector<int>> v(s.length()+1);
    v[0].push_back(-1);

    for (unsigned i=0; i<v.size(); ++i){
      if (v[i].size()){
        for (unordered_set<string>::iterator it=dict.begin();
             it!=dict.end();
             ++it){
          unsigned len=it->length();
          unsigned j=i+len;
          if (j<v.size() && s.substr(i, len)==*it){
            v[j].push_back(i);
          }
        }
      }
    }

    vector<string> w, r;
    this->traversal(v.size()-1, s, v, w, r);

    return r;
  }

 private:
  void traversal(int idx, string s, vector<vector<int>> &v, vector<string> &w,
                 vector<string> &r){
    if (idx==0){
      string str="";
      for (int i=w.size()-1; i>0; --i){
        str.append(w[i]);
        str.append(" ");
      }
      str.append(w[0]);
      r.push_back(str);
    } else{
      for (vector<int>::iterator it=v[idx].begin();
           it!=v[idx].end();
           ++it){
        string str=s.substr(*it, idx-*it);
        w.push_back(str);
        this->traversal(*it, s, v, w, r);
        w.pop_back();
      }
    }
  }
};


int main(){
  string str="catsanddog";
  unordered_set<string> dict;
  dict.insert("cat");
  dict.insert("cats");
  dict.insert("and");
  dict.insert("sand");
  dict.insert("dog");

  Solution s;
  vector<string> v=s.wordBreak(str, dict);
  for (vector<string>::iterator it=v.begin(); it!=v.end(); ++it){
    printf("[%s]\n", it->c_str());
  }

  return 0;
}
