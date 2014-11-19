#include <stdio.h>
#include <string>
#include <unordered_set>

using namespace std;


class Solution{
 public:
  bool wordBreak(string s, unordered_set<string> &dict){
    if (s=="") return true;
    for (unordered_set<string>::iterator it=dict.begin(); it!=dict.end(); ++it){
    }
    return true;
  }
  }
};


int main(){
  string s="helloworld";
  unordered_set<string> dict;
  dict.insert("hello");
  dict.insert("world");

  return 0;
}
