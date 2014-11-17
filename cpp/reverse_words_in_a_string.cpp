#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Solution {
 public:
  void reverseWords(string &s){
    vector<string> v;

    const char *cs=s.c_str();
    const char *begin, *end;

    begin=cs;
    while (*begin!='\0'){
      while (*begin==' ' && *(begin++)!='\0');

      end=begin;
      while (*end!='\0' && *(++end)!=' ');

      if (*begin!='\0'){
        //printf("\"%s\"\n", s.substr(begin-cs, end-begin).c_str());
        v.insert(v.begin(), s.substr(begin-cs, end-begin));

        if (*end=='\0'){
          break;
        }
        begin=end+1;
      }
    }

    if (v.size()>0){
      s.clear();
      vector<string>::iterator it;
      for (it=v.begin(); it!=v.end(); ++it) {
        s=s+*it;
        s.push_back(' ');
      }
      s.erase(s.end()-1);
    } else{
      s.clear();
    }
  }
};


int main(){
  Solution s;
  string str="hello world!";
  s.reverseWords(str);

  printf("\"%s\"\n", str.c_str());
  return 0;
}
